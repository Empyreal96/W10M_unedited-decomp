// VfDevObjMarkDeviceRemoved 
 
void __fastcall VfDevObjMarkDeviceRemoved(int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v5; // r0
  unsigned int *v6; // r2
  unsigned int v7; // r0
  _DWORD v8[2]; // [sp+0h] [bp-8h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  if ( (MmVerifierData & 0x10) != 0 )
  {
    VfAvlInitializeLockContext((int)v8, 1);
    v5 = VfAvlLookupTreeNode(ViDevObjAvl, (int)v8, v4, 0);
    if ( v5 )
    {
      __dmb(0xBu);
      v6 = (unsigned int *)(v5 + 8);
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 | 2, v6) );
      __dmb(0xBu);
    }
    VfAvlCleanupLockContext((int)v8);
  }
}
