## Mod can be use as server side mod, from test there is no errors, and all works serverside


# Description

With this mod, you can control the amounts of items obtained from skinning animals by editing a JSON file. The mod is designed to be resistant to new additions, meaning that if an animal is not included in the config file, default settings will be used. This allows for easy customization of the game mechanics related to animal hunting and survival, while preserving the balance and consistency of the gameplay. Whether you want to tweak the amount of meat, fat, bones, or other materials obtained from a specific animal. This mod provides a flexible and intuitive solution. Just edit the JSON file according to your preferences, and enjoy a more personalized DayZ experience!

**and yesssss chickens too!!!!**

# Configuration

When the mod is launched for the first time, it generates a folder named "SkinningConfig" that contains a file called "Skinning_Settings_vXXX.json". The user should open this file and customize its contents to fit their preferences.

The file consists of several sections, each one pertaining to a different animal. The user can modify the values of various parameters for each animal, such as the minimum and maximum amounts of feathers, bones, and meat obtained from skinning, or the presence or absence of certain items. For example, the "ChickenConfig" section allows the user to set the minimum and maximum amounts of feathers and bones obtained from skinning a chicken, as well as the minimum and maximum amounts of breast meat and the number of pieces obtained.

The other animal sections follow a similar format, with different parameters depending on the animal. For instance, the "Animal_CervusElaphus" section allows the user to set the number of steaks, bones, guts, lard, and pelt obtained from skinning a red deer.

By modifying the values of these parameters, the user can customize the game mechanics related to animal skinning to their liking, creating a more personalized and immersive gameplay experience.

## Part of config

```
{
"ChickenConfig": [
{
"ChickenFeatherMin": "0.2",
"ChickenBonesMin": "0.2",
"ChickenFeatherMax": "1",
"ChickenBreastMeatMaxCount": "1",
"ChickenBonesMax": "1",
"ChickenBreastMeatMin": "0.8",
"ChickenBreastMeatMinCount": "1",
"ChickenBreastMeatMax": "1",
"ChickenFeatherON": "true",
"ChickenBonesON": "true"
}
],
"Animal_CervusElaphusF": [
{
"ObtainedSteaks": "2",
"ObtainedBones": "1",
"ObtainedGuts": "2",
"ObtainedLard": "1",
"ObtainedPelt": "1"
}
],
"Animal_CervusElaphus": [
{
"ObtainedSteaks": "1",
"ObtainedBones": "3",
"ObtainedGuts": "6",
"ObtainedLard": "2",
"ObtainedPelt": "1"
}
],
}
```

Deleting an animal from config (for example):

```
"Animal_CervusElaphus": [
{
"ObtainedSteaks": "1",
"ObtainedBones": "3",
"ObtainedGuts": "6",
"ObtainedLard": "2",
"ObtainedPelt": "1"
}
],
```

will disable edit for it and DayZ will use just default values. 

# Known Issues

No problems at the moment, but test the mod locally first.

# Usage & Terms

This item is not authorized for the following conditions:

- Posting on Steam, except under the Steam account "Borcio".
- Hosting on any download server other than SE's current workshop download.
- Hosting on any launcher for distribution other than SE's current workshop download.
- To be packaged in any form other than SE's current workshop download.
- To create derivative works.

Permission is not granted for this mod to be included in any server pack or mod pack.

Monetization while using this mod is approved.


# Thx Wardog thank you for helping me learn!!


