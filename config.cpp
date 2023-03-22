class CfgPatches
{
	class SkinningEconomy
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Tools"
		};
	};
};
class CfgMods
{
	class SkinningEconomy
	{
		dir="SkinningEconomy";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="SkinningEconomy";
		credits="Borek";
		author="Borek";
		authorID="0";
		version="1";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"SkinningEconomy/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"SkinningEconomy/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"SkinningEconomy/Scripts/5_Mission"
				};
			};
		};
	};
};
