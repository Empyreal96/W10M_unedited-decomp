// VfTargetDriversGetNode 
 
int __fastcall VfTargetDriversGetNode(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r3
  int v6; // r2
  _DWORD v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[1] = a3;
  v8[2] = a4;
  v4 = 0;
  if ( !VfSafeMode )
  {
    v5 = ViTargetInitialized;
    __dmb(0xBu);
    if ( v5 )
    {
      VfAvlInitializeLockContext((int)v8, 1);
      v4 = VfAvlLookupTreeNode((int *)&ViTargetDriversAvl, (int)v8, v6, 1);
      VfAvlCleanupLockContext((int)v8);
    }
  }
  return v4;
}
