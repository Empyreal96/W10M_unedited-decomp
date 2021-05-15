// ViDevObjAdd 
 
int __fastcall ViDevObjAdd(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r3
  _DWORD *v6; // r2
  unsigned int v7; // r2
  _DWORD *v8; // r2
  int v9; // r3
  _DWORD v11[4]; // [sp+0h] [bp-10h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  v4 = 1;
  v5 = ViDevObjInitialized;
  __dmb(0xBu);
  if ( v5 )
  {
    v6 = VfAvlReserveNode(ViDevObjAvl, a1, 184);
    if ( v6 )
    {
      v6[2] = 0;
      VfAvlInitializeLockContext((int)v11, 0);
      VfAvlInsertReservedTreeNode((int)ViDevObjAvl, (int)v11, v8, v9);
      VfAvlCleanupLockContext((int)v11);
      return v4;
    }
    __dmb(0xBu);
    do
      v7 = __ldrex(&ViDevObjAllocationFailures);
    while ( __strex(1u, &ViDevObjAllocationFailures) );
    __dmb(0xBu);
  }
  return 0;
}
