// HvpIsHiveEligibleForSystemCacheBacking 
 
BOOL __fastcall HvpIsHiveEligibleForSystemCacheBacking(int a1, int a2, int a3)
{
  int v3; // r3
  BOOL result; // r0

  result = 0;
  if ( CmpSystemCacheBackedHivesAllowed )
  {
    if ( (MEMORY[0xFFFF92D0] & 0x10000) != 0 )
    {
      v3 = *(_DWORD *)(a1 + 92);
      if ( (v3 & 0x20000) != 0
        && (v3 & 1) == 0
        && (v3 & 0x8000) == 0
        && (v3 & 2) == 0
        && !CmpIsHiveOnRemovableDisk(a1, a2, a3, v3) )
      {
        result = 1;
      }
    }
  }
  return result;
}
