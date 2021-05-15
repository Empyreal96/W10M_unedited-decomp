// MiClearContainingMapping 
 
unsigned int __fastcall MiClearContainingMapping(int a1)
{
  int v1; // r5
  unsigned int result; // r0
  int v3; // r5
  int v4; // r4
  int v5; // r0
  unsigned int *v6; // r1

  v1 = *(_DWORD *)(a1 + 20);
  result = *(_DWORD *)(a1 + 4);
  v3 = v1 & 0xFFFFF;
  if ( (*(_DWORD *)(MmPfnDatabase + 24 * v3 + 4) | 0x80000000) == ((result & 0xFFFFF3FF | 0x800003FF) >> 10)
                                                                - 0x40000000 )
  {
    v4 = (result >> 2) & 0x3FF;
    v5 = MiMapPageInHyperSpaceWorker(v3, 0, 0x80000000);
    v6 = (unsigned int *)(v5 + 4 * v4);
    if ( (*v6 & 2) != 0 )
    {
      if ( (unsigned int)v6 >= 0xC0000000 )
        return sub_514F94();
      *v6 = *v6 & 0xFFFFFFFC | 0x400;
    }
    result = MiUnmapPageInHyperSpaceWorker(v5, 17, 0x80000000);
  }
  return result;
}
