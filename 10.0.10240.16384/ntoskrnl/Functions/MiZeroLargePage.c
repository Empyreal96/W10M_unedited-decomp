// MiZeroLargePage 
 
int __fastcall MiZeroLargePage(int a1, unsigned int *a2)
{
  int v3; // r6
  unsigned int v4; // r0

  v3 = MiMapPagesToZero(*a2, (int *)(MmPfnDatabase + 24 * ((a1 - MmPfnDatabase) / 24)), 1);
  v4 = RtlCompareMemoryUlong(v3, 0x400000, 0);
  if ( v4 != 0x400000 )
    KeZeroPages((_DWORD *)(v3 + (v4 >> 12 << 12)), (1024 - (v4 >> 12)) << 12);
  return MiReleaseZeroingVa(a2);
}
