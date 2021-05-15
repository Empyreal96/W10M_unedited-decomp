// VfDevObjIsDeviceRemoved 
 
int __fastcall VfDevObjIsDeviceRemoved(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r2
  int v6; // r0
  _DWORD v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[1] = a3;
  v8[2] = a4;
  if ( (MmVerifierData & 0x10) == 0 )
    return 1;
  v4 = 1;
  VfAvlInitializeLockContext((int)v8, 1);
  v6 = VfAvlLookupTreeNode(ViDevObjAvl, (int)v8, v5, 0);
  if ( v6 && (*(_DWORD *)(v6 + 8) & 2) == 0 )
    v4 = 0;
  VfAvlCleanupLockContext((int)v8);
  return v4;
}
