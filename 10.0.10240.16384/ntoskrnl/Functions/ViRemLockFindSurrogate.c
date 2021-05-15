// ViRemLockFindSurrogate 
 
int __fastcall ViRemLockFindSurrogate(int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v5; // r4
  _DWORD v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[1] = a3;
  v7[2] = a4;
  VfAvlInitializeLockContext((int)v7, 1);
  v5 = VfAvlLookupTreeNode(ViRemLockAvl, (int)v7, v4, 24);
  VfAvlCleanupLockContext((int)v7);
  return v5;
}
