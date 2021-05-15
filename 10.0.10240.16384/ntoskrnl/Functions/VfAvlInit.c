// VfAvlInit 
 
__int64 VfAvlInit()
{
  unsigned int v0; // r1
  __int64 v2; // [sp+0h] [bp-10h]

  VfLookasideInitializeInternalNPagedList(
    (int)&ViAvlNodeLookaside,
    0,
    (int)VfUtilFreePoolCheckIRQL,
    24,
    24,
    1413572182,
    0x10u);
  __dmb(0xBu);
  do
    v0 = __ldrex((unsigned int *)&ViAvlInitialized);
  while ( __strex(1u, (unsigned int *)&ViAvlInitialized) );
  __dmb(0xBu);
  return v2;
}
