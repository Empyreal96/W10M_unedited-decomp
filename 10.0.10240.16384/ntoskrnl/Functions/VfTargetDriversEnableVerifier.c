// VfTargetDriversEnableVerifier 
 
int __fastcall VfTargetDriversEnableVerifier(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v6; // r3
  unsigned int v7; // r5
  int v8; // r0
  _DWORD v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v4 = 0;
  if ( !VfSafeMode )
  {
    v6 = ViTargetInitialized;
    __dmb(0xBu);
    if ( v6 )
    {
      v7 = ViTargetDriversAllocateVerifiedData(a2);
      if ( v7 )
      {
        VfAvlInitializeLockContext((int)v10, 0);
        v8 = VfAvlLookupTreeNode((int *)&ViTargetDriversAvl, (int)v10, a1, 1);
        if ( v8 )
        {
          *(_DWORD *)(v8 + 24) = v7;
          ++dword_61D2B4;
          v4 = 1;
        }
        VfAvlCleanupLockContext((int)v10);
        if ( !v4 )
          ExFreePoolWithTag(v7);
      }
    }
  }
  return v4;
}
