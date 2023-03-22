class SkinningConfig
{
	static const string MODCONFIG_ROOT_FOLDER = "$profile:SkinningConfig/";
    static const string CONFIG_PATH = MODCONFIG_ROOT_FOLDER + "Skinning_Settings.json";

	private ref array<map<string, string>> ChickenConfig;

void SkinningConfig()
{
    if (!GetGame().IsServer()) return;

    if (!FileExist(MODCONFIG_ROOT_FOLDER))
    {
        MakeDirectory(MODCONFIG_ROOT_FOLDER);
    }

    if (!FileExist(CONFIG_PATH))
    {
        CreateDefaultConfig();
    }

    LoadConfig();
}

	bool LoadConfig()
    {
        if (FileExist(CONFIG_PATH))
        {
            JsonFileLoader<SkinningConfig>.JsonLoadFile(CONFIG_PATH, this);
            return true;
        }
        return false;
    }

	protected void Save()
    {
        JsonFileLoader<SkinningConfig>.JsonSaveFile(CONFIG_PATH, this);
    }

    protected void CreateDefaultConfig()
    {

        ChickenConfig = new array<map<string, string>>;
        map<string, string> chicken = new map<string, string>;
        chicken.Insert("ChickenBreastMeatMinCount", "1");
        chicken.Insert("ChickenBreastMeatMaxCount", "1");
        chicken.Insert("ChickenBreastMeatMin", "0.8");
        chicken.Insert("ChickenBreastMeatMax", "1");
        chicken.Insert("ChickenFeatherON", "true");
        chicken.Insert("ChickenFeatherMin", "0.2");
        chicken.Insert("ChickenFeatherMax", "1");
        chicken.Insert("ChickenBonesON", "true");
        chicken.Insert("ChickenBonesMin", "0.2");
        chicken.Insert("ChickenBonesMax", "1");
        ChickenConfig.Insert(chicken);

        Save();
    }



    ref array<map<string, string>> GetChickenConfig()
	{
		return ChickenConfig;
	}
}
