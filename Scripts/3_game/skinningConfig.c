class SkinningConfig
{
	static const string MODCONFIG_ROOT_FOLDER = "$profile:SkinningConfig/";
    static const string CONFIG_PATH = MODCONFIG_ROOT_FOLDER + "Skinning_Settings_v101.json";

	private ref array<map<string, string>> ChickenConfig;
    private ref array<map<string, string>> Animal_CervusElaphusF
    private ref array<map<string, string>> Animal_CervusElaphus
    private ref array<map<string, string>> Animal_BosTaurus
    private ref array<map<string, string>> Animal_BosTaurusF
    private ref array<map<string, string>> Animal_CanisLupus
    private ref array<map<string, string>> Animal_CapraHircus
    private ref array<map<string, string>> Animal_CapraHircusF
    private ref array<map<string, string>> Animal_CapreolusCapreolus
    private ref array<map<string, string>> Animal_CapreolusCapreolusF
    private ref array<map<string, string>> Animal_OvisAries
    private ref array<map<string, string>> Animal_OvisAriesF
    private ref array<map<string, string>> Animal_SusDomesticus
    private ref array<map<string, string>> Animal_SusScrofa
    private ref array<map<string, string>> Animal_UrsusArctos

    static ref array<map<string, string>> emptyArray;

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

        Animal_CervusElaphusF = new array<map<string, string>>;
        map<string, string> deerF = new map<string, string>;
        deerF.Insert("ObtainedSteaks", "1");
        deerF.Insert("ObtainedGuts", "1");
        deerF.Insert("ObtainedPelt", "1");
        deerF.Insert("ObtainedBones", "1");
        deerF.Insert("ObtainedLard", "1");
        Animal_CervusElaphusF.Insert(deerF);

		Animal_CervusElaphus = new array<map<string, string>>;
        map<string, string> deer = new map<string, string>;
        deer.Insert("ObtainedSteaks", "1");
        deer.Insert("ObtainedGuts", "1");
        deer.Insert("ObtainedPelt", "1");
        deer.Insert("ObtainedBones", "1");
        deer.Insert("ObtainedLard", "1");
        Animal_CervusElaphus.Insert(deer);

        Animal_BosTaurus = new array<map<string, string>>;
        map<string, string> cow = new map<string, string>;
        cow.Insert("ObtainedSteaks", "1");
        cow.Insert("ObtainedPelt", "1");
        cow.Insert("ObtainedGuts", "1");
        cow.Insert("ObtainedBones", "1");
        cow.Insert("ObtainedLard", "1");
        Animal_BosTaurus.Insert(cow);

        Animal_BosTaurusF = new array<map<string, string>>;
        map<string, string> cowF = new map<string, string>;
        cowF.Insert("ObtainedSteaks", "1");
        cowF.Insert("ObtainedPelt", "1");
        cowF.Insert("ObtainedGuts", "1");
        cowF.Insert("ObtainedBones", "1");
        cowF.Insert("ObtainedLard", "1");
        Animal_BosTaurusF.Insert(cowF);

        Animal_CanisLupus = new array<map<string, string>>;
        map<string, string> wolf = new map<string, string>;
        wolf.Insert("ObtainedSteaks", "1");
        wolf.Insert("ObtainedPelt", "1");
        wolf.Insert("ObtainedGuts", "1");
        wolf.Insert("ObtainedBones", "1");
        wolf.Insert("ObtainedLard", "1");
        Animal_CanisLupus.Insert(wolf);

        Animal_CapraHircus = new array<map<string, string>>;
        map<string, string> goat = new map<string, string>;
        goat.Insert("ObtainedSteaks", "1");
        goat.Insert("ObtainedPelt", "1");
        goat.Insert("ObtainedGuts", "1");
        goat.Insert("ObtainedBones", "1");
        goat.Insert("ObtainedLard", "1");
        Animal_CapraHircus.Insert(goat);

        Animal_CapraHircusF = new array<map<string, string>>;
        map<string, string> goatF = new map<string, string>;
        goatF.Insert("ObtainedSteaks", "1");
        goatF.Insert("ObtainedPelt", "1");
        goatF.Insert("ObtainedGuts", "1");
        goatF.Insert("ObtainedBones", "1");
        goatF.Insert("ObtainedLard", "1");
        Animal_CapraHircusF.Insert(goatF);

        Animal_CapreolusCapreolus = new array<map<string, string>>;
        map<string, string> rabbit = new map<string, string>;
        rabbit.Insert("ObtainedSteaks", "1");
        rabbit.Insert("ObtainedPelt", "1");
        rabbit.Insert("ObtainedGuts", "1");
        rabbit.Insert("ObtainedBones", "1");
        rabbit.Insert("ObtainedLard", "1");
        Animal_CapreolusCapreolus.Insert(rabbit);

        Animal_CapreolusCapreolusF = new array<map<string, string>>;
        map<string, string> rabbitF = new map<string, string>;
        rabbitF.Insert("ObtainedSteaks", "1");
        rabbitF.Insert("ObtainedPelt", "1");
        rabbitF.Insert("ObtainedGuts", "1");
        rabbitF.Insert("ObtainedBones", "1");
        rabbitF.Insert("ObtainedLard", "1");
        Animal_CapreolusCapreolusF.Insert(rabbitF);

        Animal_OvisAries = new array<map<string, string>>;
        map<string, string> sheep = new map<string, string>;
        sheep.Insert("ObtainedSteaks", "1");
        sheep.Insert("ObtainedPelt", "1");
        sheep.Insert("ObtainedGuts", "1");
        sheep.Insert("ObtainedBones", "1");
        sheep.Insert("ObtainedLard", "1");
        Animal_OvisAries.Insert(sheep);

        Animal_OvisAriesF = new array<map<string, string>>;
        map<string, string> sheepF = new map<string, string>;
        sheepF.Insert("ObtainedSteaks", "1");
        sheepF.Insert("ObtainedPelt", "1");
        sheepF.Insert("ObtainedGuts", "1");
        sheepF.Insert("ObtainedBones", "1");
        sheepF.Insert("ObtainedLard", "1");
        Animal_OvisAriesF.Insert(sheepF);

        Animal_SusDomesticus = new array<map<string, string>>;
        map<string, string> pig = new map<string, string>;
        pig.Insert("ObtainedSteaks", "1");
        pig.Insert("ObtainedPelt", "1");
        pig.Insert("ObtainedGuts", "1");
        pig.Insert("ObtainedBones", "1");
        pig.Insert("ObtainedLard", "1");
        Animal_SusDomesticus.Insert(pig);

        Animal_SusScrofa = new array<map<string, string>>;
        map<string, string> pigF = new map<string, string>;
        pigF.Insert("ObtainedSteaks", "1");
        pigF.Insert("ObtainedPelt", "1");
        pigF.Insert("ObtainedGuts", "1");
        pigF.Insert("ObtainedBones", "1");
        pigF.Insert("ObtainedLard", "1");
        Animal_SusScrofa.Insert(pigF);

        Animal_UrsusArctos = new array<map<string, string>>;
        map<string, string> bear = new map<string, string>;
        bear.Insert("ObtainedSteaks", "1");
        bear.Insert("ObtainedPelt", "1");
        bear.Insert("ObtainedGuts", "1");
        bear.Insert("ObtainedBones", "1");
        bear.Insert("ObtainedLard", "1");
        Animal_UrsusArctos.Insert(bear);

        Save();
    }



    ref array<map<string, string>> GetChickenConfig()
	{
		return ChickenConfig;
	}

    array<map<string, string>> GetAnimalConfig(string animal)
    {
        ref map<string, array<map<string, string>>> animalDict = new map<string, array<map<string, string>>>;
        animalDict.Insert("Animal_CervusElaphusF", Animal_CervusElaphusF);
        animalDict.Insert("Animal_CervusElaphus", Animal_CervusElaphus);
        animalDict.Insert("Animal_BosTaurus", Animal_BosTaurus);
        animalDict.Insert("Animal_BosTaurus_Brown", Animal_BosTaurus);
        animalDict.Insert("Animal_BosTaurus_White", Animal_BosTaurus);
        animalDict.Insert("Animal_BosTaurus_Spotted", Animal_BosTaurus);
        animalDict.Insert("Animal_BosTaurusF", Animal_BosTaurusF);
        animalDict.Insert("Animal_BosTaurusF_Brown", Animal_BosTaurusF);
        animalDict.Insert("Animal_BosTaurusF_White", Animal_BosTaurusF);
        animalDict.Insert("Animal_BosTaurusF_Spotted", Animal_BosTaurusF);
        animalDict.Insert("Animal_CanisLupus", Animal_CanisLupus);
        animalDict.Insert("Animal_CanisLupus_Grey", Animal_CanisLupus);
        animalDict.Insert("Animal_CanisLupus_White", Animal_CanisLupus);
        animalDict.Insert("Animal_CapraHircus", Animal_CapraHircus);
        animalDict.Insert("Animal_CapraHircus_Brown", Animal_CapraHircus);
        animalDict.Insert("Animal_CapraHircus_Black", Animal_CapraHircus);
        animalDict.Insert("Animal_CapraHircus_White", Animal_CapraHircus);
        animalDict.Insert("Animal_CapraHircusF", Animal_CapraHircusF);
        animalDict.Insert("Animal_CapreolusCapreolus", Animal_CapreolusCapreolus);
        animalDict.Insert("Animal_CapreolusCapreolusF", Animal_CapreolusCapreolusF);
        animalDict.Insert("Animal_OvisAries", Animal_OvisAries);
        animalDict.Insert("Animal_OvisAriesF", Animal_OvisAriesF);
        animalDict.Insert("Animal_SusDomesticus", Animal_SusDomesticus);
        animalDict.Insert("Animal_SusScrofa", Animal_SusScrofa);
        animalDict.Insert("Animal_UrsusArctos", Animal_UrsusArctos);

        if (animalDict.Contains(animal))
        {
            return animalDict.Get(animal);
        }

        return new array<map<string, string>>();
    }
}
