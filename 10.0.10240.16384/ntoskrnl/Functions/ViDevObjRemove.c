// ViDevObjRemove 
 
int __fastcall ViDevObjRemove(int result)
{
  int v1; // r6
  int v2; // r3
  _DWORD *v3; // r4
  int v4; // r0
  BOOL v5; // r1
  char v6[24]; // [sp+8h] [bp-18h] BYREF

  v1 = result;
  v2 = ViDevObjInitialized;
  __dmb(0xBu);
  if ( v2 )
  {
    v3 = 0;
    VfAvlInitializeLockContext((int)v6, 0);
    v4 = VfAvlLookupTreeNode(ViDevObjAvl, (int)v6, v1, 0);
    if ( v4 )
    {
      if ( (*(_DWORD *)(v4 + 8) & 1) != 0 && (MmVerifierData & 0x800) != 0 )
        VerifierBugCheckIfAppropriate(196, 219, v1, 0, 0);
      v3 = (_DWORD *)VfAvlDeleteTreeNode(ViDevObjAvl, (int)v6, v1, 0);
    }
    result = VfAvlCleanupLockContext((int)v6);
    if ( v3 )
    {
      if ( dword_9081E8 == 1 )
      {
        result = ExFreeToNPagedLookasideList((int)&ViAvlNodeLookaside, v3);
      }
      else
      {
        v5 = KeGetCurrentIrql(result) != 2;
        result = VfPoolDelayFreeIfPossible((int)v3, v5);
      }
    }
  }
  return result;
}
