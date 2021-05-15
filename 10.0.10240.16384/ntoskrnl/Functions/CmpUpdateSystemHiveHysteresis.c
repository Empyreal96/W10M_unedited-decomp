// CmpUpdateSystemHiveHysteresis 
 
unsigned int __fastcall CmpUpdateSystemHiveHysteresis(unsigned int result, unsigned int a2, unsigned int a3)
{
  unsigned int v4; // r1

  if ( CmpSystemHiveHysteresisCallback && (void *)result == off_60E8A4 )
  {
    v4 = 100 * (a2 + 4096);
    if ( !CmSystemHiveLimitSize )
      __brkdiv0();
    result = v4 / CmSystemHiveLimitSize;
    if ( a2 <= a3 )
      JUMPOUT(0x80A384);
    if ( !CmpSystemHiveHysteresisHighSeen && result > CmpSystemHiveHysteresisHigh )
      result = sub_80A380();
  }
  return result;
}
