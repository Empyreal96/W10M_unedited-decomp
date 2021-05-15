// PopSetupAudioEventNotification 
 
int PopSetupAudioEventNotification()
{
  unsigned int v0; // r4
  int result; // r0
  unsigned int v2; // [sp+8h] [bp-30h] BYREF
  int v3[2]; // [sp+10h] [bp-28h] BYREF
  int v4[8]; // [sp+18h] [bp-20h] BYREF

  v4[0] = (int)WNF_SEB_OFFLOADED_AUDIO;
  v3[0] = 301;
  v0 = 0;
  v4[1] = (int)WNF_SEB_NON_OFFLOADED_AUDIO;
  v3[1] = 302;
  do
  {
    result = ExSubscribeWnfStateChange(
               &v2,
               v4[v0],
               1,
               0,
               (int)PopWnfAudioCallback,
               (int)&PopPowerSettingValues + v3[v0]);
    ++v0;
  }
  while ( v0 < 2 );
  return result;
}
