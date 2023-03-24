modded class ActionSkinning: ActionContinuousBase
{
	// Spawns the loot according to the Skinning class in the dead agent's config
	override void OnFinishProgressServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		
		// Prepare to read config variables
		string item_to_spawn;
		string cfg_skinning_organ_class;
		
		
		// Mark the body as skinned to forbid another skinning action on it
		EntityAI body;
		Class.CastTo(body,  targetObject );
		vector body_pos = body.GetPosition();
		body.SetAsSkinned();
		
		if (body.IsInherited(PlayerBase))
		{
			// This section drops all clothes (and attachments) from the dead player before deleting their body
			PlayerBase body_PB = PlayerBase.Cast(body);
			
			if (body_PB.IsRestrained() && body_PB.GetHumanInventory().GetEntityInHands())
			{
				MiscGameplayFunctions.TransformRestrainItem(body_PB.GetHumanInventory().GetEntityInHands(), null, action_data.m_Player, body_PB);
				/*
				EntityAI item_in_hands = action_data.m_MainItem;
				body_PB.SetRestrained(false);
				string new_item_name = MiscGameplayFunctions.ObtainRestrainItemTargetClassname(item_in_hands);			
				MiscGameplayFunctions.TurnItemInHandsIntoItemEx(body_PB, new UnrestrainSelfPlayer(item_in_hands, new_item_name));
				*/
			}
			//Remove splint if target is wearing one
			if (body_PB.IsWearingSplint())
			{
				EntityAI entity = action_data.m_Player.SpawnEntityOnGroundOnCursorDir("Splint", 0.5);
				EntityAI attachment;
				ItemBase new_item = ItemBase.Cast(entity);
				Class.CastTo(attachment, body_PB.GetItemOnSlot("Splint_Right"));
				if ( attachment && attachment.GetType() == "Splint_Applied" )
				{
					if (new_item)
					{
						MiscGameplayFunctions.TransferItemProperties(attachment,new_item);
						
						if (GetGame().IsServer())
						{
							//Lower health level of splint after use
							if (new_item.GetHealthLevel() < 4)
							{
								int newDmgLevel = new_item.GetHealthLevel() + 1;
								
								float max = new_item.GetMaxHealth("","");
								
								switch ( newDmgLevel )
								{
									case GameConstants.STATE_BADLY_DAMAGED:
										new_item.SetHealth( "", "", max * GameConstants.DAMAGE_BADLY_DAMAGED_VALUE );
										break;
				
									case GameConstants.STATE_DAMAGED:
										new_item.SetHealth( "", "", max * GameConstants.DAMAGE_DAMAGED_VALUE );
										break;
				
									case GameConstants.STATE_WORN:
										new_item.SetHealth( "", "", max * GameConstants.DAMAGE_WORN_VALUE );
										break;
									
									case GameConstants.STATE_RUINED:
										new_item.SetHealth( "", "", max * GameConstants.DAMAGE_RUINED_VALUE );
										break;
									
									default:
										break;
								}
							}
						}
					}
					attachment.Delete();
				}
			}
			
			/*
			DropEquipAndDestroyRootLambda lambda(body_PB, "", action_data.m_Player);
			action_data.m_Player.ServerReplaceItemWithNew(lambda);
			*/
			int deadBodyLifetime;
			if ( GetCEApi() )
			{
				deadBodyLifetime = GetCEApi().GetCEGlobalInt( "CleanupLifetimeDeadPlayer" );
				if ( deadBodyLifetime <= 0 )
				{
					deadBodyLifetime = 3600;
				}
			}
			array<EntityAI> children = new array<EntityAI>;
			body_PB.GetInventory().EnumerateInventory(InventoryTraversalType.LEVELORDER, children);
			int count = children.Count();
			for (int i = 0; i < count; ++i)
			{
				EntityAI child = children.Get(i);
				if ( child )
				{
					body_PB.GetInventory().DropEntity(InventoryMode.SERVER, body_PB, child);
					child.SetLifetime( deadBodyLifetime );
				}
			}
		}

		GetGame().ObjectDelete(body);


		string cfg_animal_class_path = "cfgVehicles " + body.GetType() + " " + "Skinning ";
		string cfg_animal_class = body.GetType();
		string cfg_animal_item
		int child_count = g_Game.ConfigGetChildrenCount( cfg_animal_class_path );


		for ( int i1 = 0; i1 < child_count; i1++ )
		{

			g_Game.ConfigGetChildName(cfg_animal_class_path, i1, cfg_skinning_organ_class);
			cfg_animal_item = cfg_skinning_organ_class;
			cfg_skinning_organ_class = cfg_animal_class_path + cfg_skinning_organ_class + " ";
			g_Game.ConfigGetText(cfg_skinning_organ_class + "item", item_to_spawn);

			array<map<string, string>> animal_json_config =  g_Game.GetSkinningConfig().GetAnimalConfig(cfg_animal_class);


			if ( item_to_spawn != "" )
			{
				int def_item_count = g_Game.ConfigGetInt( cfg_skinning_organ_class + "count" );
				int item_count = def_item_count;
				bool is_modded = false;

				if ( animal_json_config.Count() > 0)
				{
					item_count = animal_json_config.Get(0).Get(cfg_animal_item).ToInt();
					is_modded = true;
				}


				array<string> itemZones = new array<string>;
				float zoneDmg = 0;
				GetGame().ConfigGetTextArray( cfg_skinning_organ_class + "itemZones", itemZones);

				if (is_modded == false)
				{

				array<float> itemCount = new array<float>;
				GetGame().ConfigGetFloatArray( cfg_skinning_organ_class + "countByZone", itemCount);

				 	if ( itemCount.Count() > 0 )
			 		{
						item_count = 0;
						for ( int z = 0; z < itemZones.Count(); z++ )
						{
							zoneDmg = targetObject.GetHealth01(itemZones[z], "Health");
							zoneDmg *= itemCount[z];
							item_count += Math.Floor( zoneDmg ) ;
						}
					}
				}

				for ( int i2 = 0; i2 < item_count; i2++ )
				{
					ItemBase spawn_result = CreateOrgan( action_data.m_Player, body_pos, item_to_spawn, cfg_skinning_organ_class, action_data.m_MainItem );

					float qtCoeff = GetGame().ConfigGetFloat( cfg_skinning_organ_class + "quantityCoef");
					if(qtCoeff > 0)
					{
						float avgDmgZones = 0;
						for(int c2 = 0; c2 < itemZones.Count(); c2++ )
						{
							avgDmgZones += targetObject.GetHealth01(itemZones[c2], "Health");
						}
						avgDmgZones = avgDmgZones/itemZones.Count(); // Evaluate the average Health

						if(spawn_result)
							spawn_result.SetHealth01("","", avgDmgZones);
					}

					if ( ( item_to_spawn == "Lard" ) || ( item_to_spawn == "Guts" ) )
					{
						if ( body.IsKindOf( "SurvivorBase" ) )
						{
							spawn_result.InsertAgent(eAgents.BRAIN, 1);
						}
					}
				}
			}
		}

		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, UADamageApplied.SKINNING);

		PluginLifespan module_lifespan = PluginLifespan.Cast( GetPlugin( PluginLifespan ) );
		module_lifespan.UpdateBloodyHandsVisibility( action_data.m_Player, true );

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}

	// Spawns an organ defined in the given config
	override ItemBase CreateOrgan( PlayerBase player, vector body_pos, string item_to_spawn, string cfg_skinning_organ_class, ItemBase tool)
	{
		// Create item from config
		ItemBase added_item;
		vector pos_rnd = body_pos + Vector(Math.RandomFloat01() - 0.5, 0, Math.RandomFloat01() - 0.5);
		Class.CastTo(added_item,  GetGame().CreateObjectEx( item_to_spawn, pos_rnd, ECE_PLACE_ON_SURFACE ) );

		// Check if skinning is configured for this body
		if (!added_item)
			return NULL;

		// Set randomized position
		added_item.PlaceOnSurface();

		// Set item's quantity from config, if it's defined there.
		float item_quantity = 0;
		array<float> quant_min_max = new array<float>;
		array<float> quant_min_max_coef = new array<float>;

		GetGame().ConfigGetFloatArray( cfg_skinning_organ_class + "quantityMinMax", quant_min_max);
		GetGame().ConfigGetFloatArray( cfg_skinning_organ_class + "quantityMinMaxCoef", quant_min_max_coef);

		// Read config for quantity value
		if (quant_min_max.Count() > 0)
		{
			float soft_skill_manipulated_value = ( quant_min_max.Get(0)+ quant_min_max.Get(1) ) / 2;
			float min_quantity = player.GetSoftSkillsManager().AddSpecialtyBonus( soft_skill_manipulated_value, this.GetSpecialtyWeight() );
			item_quantity = Math.RandomFloat(min_quantity, quant_min_max.Get(1));
		}

		if (quant_min_max_coef.Count() > 0)
		{
			float coef = Math.RandomFloat(quant_min_max_coef.Get(0), quant_min_max_coef.Get(1));
			item_quantity = added_item.GetQuantityMax() * coef;
		}

		if ( GetGame().ConfigGetFloat( cfg_skinning_organ_class + "quantity" ) > 0 )
			item_quantity = g_Game.ConfigGetFloat( cfg_skinning_organ_class + "quantity" );

		if ( GetGame().ConfigGetFloat( cfg_skinning_organ_class + "quantityCoef" ) > 0 )
		{
			float coef2 = g_Game.ConfigGetFloat( cfg_skinning_organ_class + "quantityCoef" );
			item_quantity = added_item.GetQuantityMax() * coef2;
		}
		
		if ( item_quantity > 0 )
		{
			item_quantity = Math.Round(item_quantity);
			added_item.SetQuantity( item_quantity, false );
		}
		
		// Transfer tool's damage to the item's condition
		float item_apply_tool_damage_coef = GetGame().ConfigGetFloat( cfg_skinning_organ_class + "transferToolDamageCoef" );
		
		if ( item_apply_tool_damage_coef > 0 )
		{
			float tool_dmg_coef = 1 - tool.GetHealth01();
			float organ_dmg_coef = tool_dmg_coef * item_apply_tool_damage_coef;
			added_item.DecreaseHealthCoef( organ_dmg_coef );
		}
		
		added_item.InsertAgent(eAgents.SALMONELLA, 1);
		return added_item;
	}
	
	override void OnFinishProgressClient( ActionData action_data )
	{
		super.OnFinishProgressClient( action_data );
		
		if ( action_data.m_Target ) 
		{
			Object target_obj = action_data.m_Target.GetObject();
			
			if ( target_obj.IsKindOf( "Animal_CapreolusCapreolus" ) || target_obj.IsKindOf( "Animal_CapreolusCapreolusF" ) || target_obj.IsKindOf( "Animal_CervusElaphus" ) || target_obj.IsKindOf( "Animal_CervusElaphusF" ) )
			{
				GetGame().GetAnalyticsClient().OnActionFinishedGutDeer();
			}
		}
	}
};