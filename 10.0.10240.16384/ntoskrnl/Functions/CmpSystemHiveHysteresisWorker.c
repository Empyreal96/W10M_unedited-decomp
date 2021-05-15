// CmpSystemHiveHysteresisWorker 
 
unsigned int __fastcall CmpSystemHiveHysteresisWorker(unsigned int a1)
{
  unsigned int result; // r0

  result = ExFreePoolWithTag(a1);
  if ( CmpSystemHiveHysteresisCallback )
    result = CmpSystemHiveHysteresisCallback(CmpSystemHiveHysteresisContext, CmpSystemHiveHysteresisHitRatio);
  return result;
}
