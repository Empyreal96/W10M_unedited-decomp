// MmUnmapIoSpace 
 
int __fastcall MmUnmapIoSpace(unsigned int a1, int a2)
{
  unsigned int v3; // r5
  int result; // r0
  int v6; // r0
  int v7; // r6

  v3 = (a1 & 0xFFF) + a2 + 4095;
  if ( (dword_681258 & 1) != 0 )
    return sub_50A004();
  v6 = MiMappingHasIoTracker(a1);
  v7 = *(_DWORD *)(((a1 >> 20) & 0xFFC) - 1070596096);
  if ( v6 == 1 )
    MiZeroAndFlushPtes(a1, v3 >> 12);
  if ( (v7 & 0x400) != 0 )
    result = MiUnmapLargePages(a1, a2, 9);
  else
    result = MiReleasePtes(&dword_634D58, ((a1 >> 10) & 0x3FFFFC) - 0x40000000, v3 >> 12);
  return result;
}
