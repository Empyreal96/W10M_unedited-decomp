// PopSetupFullScrenVideoNotification 
 
__int64 __fastcall PopSetupFullScrenVideoNotification(int a1, int a2, unsigned int a3, unsigned int a4)
{
  __int64 v5; // [sp+0h] [bp-10h]
  unsigned int v6[2]; // [sp+8h] [bp-8h] BYREF

  v6[0] = a3;
  v6[1] = a4;
  ExSubscribeWnfStateChange(v6, (int)WNF_SEB_FULL_SCREEN_VIDEO_PLAYBACK, 1, 0, (int)PopWnfFullscreenVideoCallback, 0);
  return v5;
}
