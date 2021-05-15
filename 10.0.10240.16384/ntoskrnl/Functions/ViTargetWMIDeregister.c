// ViTargetWMIDeregister 
 
int __fastcall ViTargetWMIDeregister(int a1, int a2, int a3, int a4)
{
  int v5; // r2
  int v6; // r0
  int v7; // r2
  int v8; // r3
  _DWORD v10[4]; // [sp+0h] [bp-10h] BYREF

  v10[1] = a3;
  v10[2] = a4;
  VfAvlInitializeLockContext((int)v10, 0);
  v6 = VfAvlLookupTreeNode((int *)&ViTargetDriversAvl, (int)v10, v5, 1);
  if ( v6 && (v7 = *(_DWORD *)(v6 + 24)) != 0 && *(_DWORD *)(v7 + 4) == a1 )
  {
    *(_DWORD *)(v7 + 4) = 0;
  }
  else
  {
    v8 = ViTargetWMIRegistrationMismatches + 1;
    __dmb(0xBu);
    ViTargetWMIRegistrationMismatches = v8;
    VfAvlEnumerateNodes(v6, v10);
  }
  return VfAvlCleanupLockContext((int)v10);
}
