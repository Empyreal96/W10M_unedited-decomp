// VerifierExDeleteResourceLite 
 
int __fastcall VerifierExDeleteResourceLite(int a1)
{
  int v2; // r3
  _DWORD *v3; // r6
  int v4; // r3
  int v5; // r3
  int v6; // r0
  BOOL v7; // r1
  int result; // r0
  _DWORD *v9; // r2
  unsigned int v10; // r5
  unsigned int v11; // r4
  unsigned int v12; // r1
  char v13[24]; // [sp+8h] [bp-18h] BYREF

  v2 = ViResourceInitialized;
  __dmb(0xBu);
  if ( v2 && VfAvlHasAnyNodes((int)ViResourceAvl) )
  {
    v3 = 0;
    VfAvlInitializeLockContext((int)v13, 0);
    if ( VfAvlLookupTreeNode(ViResourceAvl, (int)v13, a1, 0) )
    {
      v3 = (_DWORD *)VfAvlDeleteTreeNode(ViResourceAvl, (int)v13, a1, 0);
    }
    else
    {
      v4 = ViResourceNotTracked;
      __dmb(0xBu);
      if ( !v4 )
      {
        v5 = ViResourcesAlreadyLoadedDrivers;
        __dmb(0xBu);
        if ( !v5 )
          VerifierBugCheckIfAppropriate(196, 209, a1, 0, 0);
      }
    }
    v6 = VfAvlCleanupLockContext((int)v13);
    if ( v3 )
    {
      if ( dword_9085C0 == 1 )
      {
        ExFreeToNPagedLookasideList((int)&ViAvlNodeLookaside, v3);
      }
      else
      {
        v7 = KeGetCurrentIrql(v6) != 2;
        VfPoolDelayFreeIfPossible((int)v3, v7);
      }
    }
  }
  result = pXdvExDeleteResourceLite(a1);
  if ( (MmVerifierData & 0x800) != 0 && result >= 0 )
  {
    v9 = (_DWORD *)a1;
    v10 = a1 + 56;
    v11 = 0;
    if ( (unsigned int)v9 > v10 )
      v12 = 0;
    else
      v12 = (v10 - (unsigned int)v9 + 3) >> 2;
    if ( v12 )
    {
      do
      {
        ++v11;
        *v9++ = MmBadPointer;
      }
      while ( v11 < v12 );
    }
  }
  return result;
}
