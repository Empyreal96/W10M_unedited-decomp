// VfCheckForResource 
 
int __fastcall VfCheckForResource(int a1, int a2)
{
  int v4; // r3
  _DWORD *v6; // r1
  unsigned int v7; // r0
  int i; // r2
  int *v9; // r0
  int *v10; // r5
  int v11; // r3
  unsigned int v12; // r1
  _DWORD *v13; // r5
  int v14; // r0
  BOOL v15; // r1
  int v16; // [sp+8h] [bp-20h] BYREF
  char v17[24]; // [sp+10h] [bp-18h] BYREF

  v4 = ViResourceInitialized;
  __dmb(0xBu);
  if ( v4 )
  {
    v6 = &VfPoolDelayFreeData;
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    for ( i = 0; i < 2; ++i )
    {
      if ( v7 == v6[6] )
        return 1;
      v6 += 12;
    }
    if ( !VfAvlHasAnyNodes((int)ViResourceAvl) )
      return 1;
    v16 = 0;
    VfAvlInitializeLockContext((int)v17, 1);
    v9 = (int *)VfAvlLookupTreeNode(ViResourceAvl, (int)v17, a1, a2);
    v10 = v9;
    if ( v9 )
    {
      v11 = ViResourcesAlreadyLoadedDrivers;
      __dmb(0xBu);
      if ( !v11 )
        VerifierBugCheckIfAppropriate(196, 210, *v9, a1, a2);
      v16 = *v10;
    }
    VfAvlCleanupLockContext((int)v17);
    if ( !v16 )
      return 1;
    __dmb(0xBu);
    do
      v12 = __ldrex(&ViResourceStaleNodes);
    while ( __strex(v12 + 1, &ViResourceStaleNodes) );
    __dmb(0xBu);
    VfAvlInitializeLockContext((int)v17, 0);
    v13 = (_DWORD *)VfAvlDeleteTreeNode(ViResourceAvl, (int)v17, (int)&v16, 0);
    v14 = VfAvlCleanupLockContext((int)v17);
    if ( v13 )
    {
      if ( dword_9085C0 == 1 )
      {
        ExFreeToNPagedLookasideList((int)&ViAvlNodeLookaside, v13);
      }
      else
      {
        v15 = KeGetCurrentIrql(v14) != 2;
        VfPoolDelayFreeIfPossible((int)v13, v15);
      }
    }
  }
  return 0;
}
