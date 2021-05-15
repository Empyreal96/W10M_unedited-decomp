// ViRemLockDeleteFirstTreeNode 
 
int __fastcall ViRemLockDeleteFirstTreeNode(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r5
  int v6; // r2
  int *v7; // r0
  int *v8; // r4
  int v9; // r0
  BOOL v11; // r1
  _DWORD v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a2;
  v12[1] = a3;
  v12[2] = a4;
  v5 = 0;
  VfAvlInitializeLockContext((int)v12, 0);
  v7 = (int *)VfAvlLookupTreeNode(ViRemLockAvl, (int)v12, v6, a2);
  v8 = v7;
  if ( v7 )
    v5 = (_DWORD *)VfAvlDeleteTreeNode(ViRemLockAvl, (int)v12, *v7, 0);
  v9 = VfAvlCleanupLockContext((int)v12);
  if ( !v8 )
    return 0;
  if ( v5 )
  {
    if ( dword_908590 == 1 )
    {
      ExFreeToNPagedLookasideList((int)&ViAvlNodeLookaside, v5);
    }
    else
    {
      v11 = KeGetCurrentIrql(v9) != 2;
      VfPoolDelayFreeIfPossible((int)v5, v11);
    }
  }
  return 1;
}
