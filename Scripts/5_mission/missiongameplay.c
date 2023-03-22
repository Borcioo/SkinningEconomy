modded class MissionGameplay
{


	void MissionGameplay()
	{
		GetRPCManager().AddRPC("SkinningConfig", "SkinningConfigStoreConfig", this, SingeplayerExecutionType.Client); //Add this RPC as listner to the catch the cfg sent from server.
		GetRPCManager().SendRPC("SkinningConfig", "GetSkinningConfigCfg", null, true, null); //send RPC to server once this class starts to get cfg. Identity is null in this case becuase we are sending an RPC from client, clients can't target specific identities
	}

	void SkinningConfigStoreConfig(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        ref Param1<ref SkinningConfig> data;
        if (type == CallType.Client)
		{
			if (!ctx.Read(data)) return;

			g_Game.SetSkinningConfig( data.param1 );
			Print("[SkinningConfig] MissionGameplay --> Got instance of cfg: " + data.param1);
		}
    }
};