// ViLookasideAdd 
 
int __fastcall ViLookasideAdd(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r7
  unsigned int v6; // r2
  _DWORD *v7; // r5
  int v8; // r3
  int v9; // r0
  BOOL v10; // r1
  int v12; // [sp+0h] [bp-20h]
  _DWORD v13[6]; // [sp+8h] [bp-18h] BYREF

  v12 = a1;
  v13[0] = a3;
  v13[1] = a4;
  if ( ViLookasideInitialized )
  {
    v5 = VfAvlReserveNode(ViLookasideAvl, a1, 0);
    if ( v5 )
    {
      v7 = 0;
      VfAvlInitializeLockContext((int)v13, 0);
      if ( VfAvlLookupTreeNode(ViLookasideAvl, (int)v13, a1, 0) )
      {
        if ( !ViLookasideAllocationFailures && !ViLookasideAlreadyLoadedDrivers )
          VerifierBugCheckIfAppropriate(196, 202, a1, 0, 0);
        v7 = (_DWORD *)VfAvlDeleteTreeNode(ViLookasideAvl, (int)v13, a1, 0);
      }
      VfAvlInsertReservedTreeNode((int)ViLookasideAvl, (int)v13, v5, v8);
      v9 = VfAvlCleanupLockContext((int)v13);
      if ( v7 )
      {
        if ( dword_9085D8 == 1 )
        {
          ExFreeToNPagedLookasideList((int)&ViAvlNodeLookaside, v7);
        }
        else
        {
          v10 = KeGetCurrentIrql(v9) != 2;
          VfPoolDelayFreeIfPossible((int)v7, v10);
        }
      }
    }
    else
    {
      __dmb(0xBu);
      do
        v6 = __ldrex((unsigned int *)&ViLookasideAllocationFailures);
      while ( __strex(1u, (unsigned int *)&ViLookasideAllocationFailures) );
      __dmb(0xBu);
    }
  }
  return v12;
}
