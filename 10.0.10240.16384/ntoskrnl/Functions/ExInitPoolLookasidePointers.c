// ExInitPoolLookasidePointers 
 
int ExInitPoolLookasidePointers()
{
  _DWORD *v0; // r4
  unsigned int v1; // r6
  _DWORD *v2; // r4
  int result; // r0

  v0 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
  if ( !v0[357] )
  {
    ExPoolLookasideListHead = (int)&ExPoolLookasideListHead;
    *(_DWORD *)algn_61A0BC = &ExPoolLookasideListHead;
    ExSystemLookasideListHead = (int)&ExSystemLookasideListHead;
    *(_DWORD *)algn_61A0C4 = &ExSystemLookasideListHead;
    ExInitializeSystemLookasideList(&ExpScratchBufferLookasideList, 512, 576, 1717723987);
  }
  v0[721] = &ExpScratchBufferLookasideList;
  v0[720] = &ExpScratchBufferLookasideList;
  v1 = 8;
  v2 = v0 + 2976;
  do
  {
    ExInitializeSystemLookasideList(v2 + 576, 0, v1, 1282371408);
    ExInitializeSystemLookasideList(v2, 512, v1, 1282371408);
    result = ExInitializeSystemLookasideList(v2 + 1152, 1, v1, 1282371408);
    v1 += 8;
    v2 += 18;
  }
  while ( v1 < 0x108 );
  return result;
}
