// ViLookasideDelete 
 
int __fastcall ViLookasideDelete(int result)
{
  int v1; // r6
  _DWORD *v2; // r5
  BOOL v3; // r1
  char v4[24]; // [sp+8h] [bp-18h] BYREF

  v1 = result;
  if ( ViLookasideInitialized )
  {
    v2 = 0;
    VfAvlInitializeLockContext((int)v4, 0);
    if ( VfAvlLookupTreeNode(ViLookasideAvl, (int)v4, v1, 0) )
    {
      v2 = (_DWORD *)VfAvlDeleteTreeNode(ViLookasideAvl, (int)v4, v1, 0);
    }
    else if ( !ViLookasideAllocationFailures && !ViLookasideAlreadyLoadedDrivers )
    {
      VerifierBugCheckIfAppropriate(196, 203, v1, 0, 0);
    }
    result = VfAvlCleanupLockContext((int)v4);
    if ( v2 )
    {
      if ( dword_9085D8 == 1 )
      {
        result = ExFreeToNPagedLookasideList((int)&ViAvlNodeLookaside, v2);
      }
      else
      {
        v3 = KeGetCurrentIrql(result) != 2;
        result = VfPoolDelayFreeIfPossible((int)v2, v3);
      }
    }
  }
  return result;
}
