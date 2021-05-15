// MiScrubPage 
 
int __fastcall MiScrubPage(int a1, int a2, int a3)
{
  int v5; // r0
  int v6; // r4
  int v7; // r7
  int v8; // r0
  int result; // r0

  v5 = MiGetPteFromCopyList((__int64 *)a1, (a3 - MmPfnDatabase) / 24, -1);
  v6 = v5;
  if ( a2 )
    memmove(a2, v5 << 10, 0x1000u);
  v7 = RtlScrubMemory(v6 << 10);
  if ( a2 )
  {
    memmove(v6 << 10, a2, 0x1000u);
    KeSweepIcacheRange(1, v6 << 10, 0x1000u);
  }
  if ( (unsigned int)(v6 + 0x40000000) > 0x3FFFFF )
  {
    *(_DWORD *)v6 = 0;
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v6 = 0;
    if ( (unsigned int)(v6 + 1070596096) <= 0xFFF )
    {
      v8 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v8, (_DWORD *)(v8 + 4 * (v6 & 0xFFF)), 0);
    }
  }
  result = v7;
  ++*(_DWORD *)(a1 + 24);
  return result;
}
