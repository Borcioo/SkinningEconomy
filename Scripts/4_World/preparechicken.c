modded class PrepareChicken
{	
	override void Init()
	{
		m_Name = "#skin";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 1.5;//animation length in relative time units
		m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[0] = -1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"DeadChicken_ColorBase");//you can insert multiple ingredients this way

		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1,"Sickle");//you can insert multiple ingredients this way
		InsertIngredient(1,"KukriKnife");
		InsertIngredient(1,"FangeKnife");
		InsertIngredient(1,"Hacksaw");
		InsertIngredient(1,"HandSaw");
		InsertIngredient(1,"KitchenKnife");
		InsertIngredient(1,"SteakKnife");
		InsertIngredient(1,"StoneKnife");
		InsertIngredient(1,"Cleaver");
		InsertIngredient(1,"CombatKnife");
		InsertIngredient(1,"HuntingKnife");
		InsertIngredient(1,"Machete");
		InsertIngredient(1,"CrudeMachete");
		InsertIngredient(1,"OrientalMachete");
		InsertIngredient(1,"WoodAxe");
		InsertIngredient(1,"Hatchet");
		InsertIngredient(1,"FirefighterAxe");
		InsertIngredient(1,"Sword");
		InsertIngredient(1,"AK_Bayonet");
		InsertIngredient(1,"M9A1_Bayonet");
		InsertIngredient(1,"SKS_Bayonet");
		InsertIngredient(1,"BoneKnife");
		InsertIngredient(1,"Screwdriver");

		m_IngredientAddHealth[1] = -12;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = true;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------

		AddResult("Bone");//add results here

		m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = 2;// -1 = do nothing
		m_ResultSetHealth[0] = -1;// -1 = do nothing
		m_ResultInheritsHealth[0] = 0;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = 0;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value


		// AddResult("ChickenFeather");//add results here

		// m_ResultSetFullQuantity[4] = false;//true = set full quantity, false = do nothing
		// m_ResultSetQuantity[4] = 17;// -1 = do nothing
		// m_ResultSetHealth[4] = -1;// -1 = do nothing
		// m_ResultInheritsHealth[4] = 0;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		// m_ResultInheritsColor[4] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		// m_ResultToInventory[4] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		// m_ResultUseSoftSkills[4] = false;// set 'true' to allow modification of the values by softskills on this result
		// m_ResultReplacesIngredient[4] = 0;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		//----------------------------------------------------------------------------------------------------------------------
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		ItemBase deadChicken = ingredients[0];
		ItemBase resultBones = results[0];

        ref array<map<string, string>> chickenConfig =  g_Game.GetSkinningConfig().GetChickenConfig();

        int chickenBreastMeatMinCount = chickenConfig.Get(0).Get("ChickenBreastMeatMinCount").ToInt();
        int chickenBreastMeatMaxCount = chickenConfig.Get(0).Get("ChickenBreastMeatMaxCount").ToInt();
        int chickenBreastMeatMin = chickenConfig.Get(0).Get("ChickenBreastMeatMin").ToInt();
        int chickenBreastMeatMax = chickenConfig.Get(0).Get("ChickenBreastMeatMax").ToInt();

        string chickenFeatherON = chickenConfig.Get(0).Get("ChickenFeatherON");
        int chickenFeatherMin = chickenConfig.Get(0).Get("ChickenFeatherMin").ToInt();
        int chickenFeatherMax = chickenConfig.Get(0).Get("ChickenFeatherMax").ToInt();

        string chickenBonesON = chickenConfig.Get(0).Get("chickenBonesON");
        int chickenBonesMin = chickenConfig.Get(0).Get("ChickenBonesMin").ToInt();
        int chickenBonesMax = chickenConfig.Get(0).Get("ChickenBonesMax").ToInt();


		int steakCount = Math.RandomIntInclusive(chickenBreastMeatMinCount,chickenBreastMeatMaxCount);

		for (int i=0; i < steakCount; i++)
		{
			ItemBase result = ItemBase.Cast(player.SpawnEntityOnGroundOnCursorDir("ChickenBreastMeat", DEFAULT_SPAWN_DISTANCE));
			MiscGameplayFunctions.TransferItemProperties(deadChicken, result);
			result.SetQuantityNormalized(Math.RandomFloatInclusive(chickenBreastMeatMin,chickenBreastMeatMax));
		}

        if (chickenFeatherON == "true")
        {
            ItemBase resultFeathers = ItemBase.Cast(player.SpawnEntityOnGroundOnCursorDir("ChickenFeather", DEFAULT_SPAWN_DISTANCE));
            MiscGameplayFunctions.TransferItemProperties(deadChicken, resultFeathers);
            resultFeathers.SetQuantityNormalized(Math.RandomFloatInclusive(chickenFeatherMin,chickenFeatherMax));
        }

            MiscGameplayFunctions.TransferItemProperties(deadChicken, resultBones);

        if (chickenBonesON == "true")
        {
            resultBones.SetQuantity(Math.RandomIntInclusive(chickenBonesMin,chickenBonesMax));
        } else {
			resultBones.SetQuantity(0);
		}

		PluginLifespan lifespan = PluginLifespan.Cast( GetPlugin( PluginLifespan ) );
		lifespan.UpdateBloodyHandsVisibility( player, true );
	}
};
