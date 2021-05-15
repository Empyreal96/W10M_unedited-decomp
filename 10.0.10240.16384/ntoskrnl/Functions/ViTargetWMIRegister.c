// ViTargetWMIRegister 
 
int __fastcall ViTargetWMIRegister(int a1, int a2, int a3, int a4)
{
  int v5; // r2
  int v6; // r0
  int v7; // r3
  _DWORD v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[1] = a3;
  v9[2] = a4;
  VfAvlInitializeLockContext((int)v9, 1);
  v6 = VfAvlLookupTreeNode((int *)&ViTargetDriversAvl, (int)v9, v5, 1);
  if ( v6 )
  {
    v7 = *(_DWORD *)(v6 + 24);
    if ( v7 )
      *(_DWORD *)(v7 + 4) = a1;
  }
  return VfAvlCleanupLockContext((int)v9);
}
