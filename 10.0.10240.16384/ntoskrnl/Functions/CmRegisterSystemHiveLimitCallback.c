// CmRegisterSystemHiveLimitCallback 
 
int __fastcall CmRegisterSystemHiveLimitCallback(int a1, int a2, int a3)
{
  unsigned int v3; // r4

  if ( off_60E8A4 )
  {
    if ( !CmSystemHiveLimitSize )
      __brkdiv0();
    v3 = 100 * (*(_DWORD *)(*((_DWORD *)off_60E8A4 + 8) + 40) + 4096) / (unsigned int)CmSystemHiveLimitSize;
  }
  else
  {
    v3 = 0;
  }
  if ( !CmpSystemHiveHysteresisCallback )
  {
    CmpSystemHiveHysteresisLow = 80;
    CmpSystemHiveHysteresisHigh = 90;
    CmpSystemHiveHysteresisContext = a3;
    CmpSystemHiveHysteresisCallback = (int)PpSystemHiveLimitCallback;
    CmpSystemHiveHysteresisLowSeen = 1;
    if ( v3 >= 0x5A )
      return sub_81BD04();
    CmpSystemHiveHysteresisHighSeen = 0;
  }
  return v3;
}
