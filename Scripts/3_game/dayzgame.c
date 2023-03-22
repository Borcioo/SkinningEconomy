modded class DayZGame
{
    private ref SkinningConfig m_SkinningConfig;

    ref SkinningConfig GetSkinningConfig()
    {
        if (m_SkinningConfig)
        {
            return m_SkinningConfig;
        }

	    return null;
    }

    void SetSkinningConfig(ref SkinningConfig cfg)
	{
		m_SkinningConfig = cfg;
	}
}