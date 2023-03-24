class CfgPatches
{
	class SkinningEconomy
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
		};
	};
};
class CfgMods
{
	class SkinningEconomy
	{
		dir="SE";
		picture="SE/GUI/textures/se_icon.paa";
		logo = "SE/GUI//textures/se_icon.paa";
		logoSmall = "SE/GUI//textures/se_icon.paa";
		logoOver = "SE/GUI//textures/se_icon.paa";
		action="https://github.com/Borcioo/SkinningEconomy";
		hideName=0;
		hidePicture=0;
		name="SkinningEconomy";
		credits="Borek";
		author="Borek";
		authorID="76561197995908678";
		tooltip = "Skinning Economy";
		overview = "This is a SkinningEconomy for DayZ SA. You finally have control over animal skinning drops";
		version="1.0.1";
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
					"SE/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"SE/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"SE/Scripts/5_Mission"
				};
			};
		};
	};
};
