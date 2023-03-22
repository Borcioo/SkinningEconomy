modded class MissionServer
{
    private ref SkinningConfig m_SkinningConfig;

    void MissionServer()
    {
        GetRPCManager().AddRPC("SkinningConfig", "GetSkinningConfigCfg", this, SingeplayerExecutionType.Server);
    }

    override void OnInit()
    {
        super.OnInit();

        Print("[SkinningConfig] Server Cfg loading...");

        m_SkinningConfig = new SkinningConfig();
        g_Game.SetSkinningConfig( m_SkinningConfig );
    }

    void GetSkinningConfigCfg(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type == CallType.Server && sender != null)
        {
            Print("[SkinningConfig] MissionServer --> Sending instance of cfg to client: " + sender.GetName());
            GetRPCManager().SendRPC("SkinningConfig", "SkinningConfigStoreConfig", new Param1<ref SkinningConfig>( m_SkinningConfig ), true, sender);
        }
    }

};
