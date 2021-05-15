// VerifierIoInitializeRemoveLockEx 
 
int __fastcall VerifierIoInitializeRemoveLockEx(int a1, int a2, int a3, int a4, int a5)
{
  int v7; // r4
  int v9; // r0
  unsigned int v10; // r1
  int v11; // r4
  _DWORD *v12; // r0
  _DWORD *v13; // r6
  unsigned int v14; // r2
  int v15; // r5
  int result; // r0
  _BYTE *v17; // r0
  int v18; // r3
  char v20[40]; // [sp+10h] [bp-28h] BYREF

  v7 = ViRemLockInitialized;
  __dmb(0xBu);
  if ( !v7 )
    goto LABEL_11;
  v9 = ViRemLockFindSurrogate(a1);
  if ( v9 )
  {
    VerifierBugCheckIfAppropriate(196, 215, v9 + 8, a1, 0);
    do
      v10 = __ldrex(&ViRemLockReusedCount);
    while ( __strex(v10 + 1, &ViRemLockReusedCount) );
    ViRemLockDeleteFirstTreeNode(a1, a5);
  }
  v11 = 0;
  if ( (MmVerifierData & 0x10) == 0 )
    goto LABEL_11;
  v12 = VfAvlReserveNode(ViRemLockAvl, a1, a5);
  v13 = v12;
  if ( !v12 )
  {
    __dmb(0xBu);
    do
      v14 = __ldrex(&ViRemLockAllocationFailures);
    while ( __strex(1u, &ViRemLockAllocationFailures) );
    __dmb(0xBu);
LABEL_11:
    v15 = a2;
    return pXdvIoInitializeRemoveLockEx(a1, v15, a3, a4, a5);
  }
  v17 = v12 + 2;
  if ( a5 == 88 )
  {
    memset(v17, 0, 88);
    v15 = a2;
  }
  else
  {
    v15 = a2;
    pXdvIoInitializeRemoveLockEx(v17, a2, a3, a4, 88);
    v11 = 1;
  }
  VfAvlInitializeLockContext((int)v20, 0);
  VfAvlInsertReservedTreeNode((int)ViRemLockAvl, (int)v20, v13, v18);
  result = VfAvlCleanupLockContext((int)v20);
  if ( !v11 )
    return pXdvIoInitializeRemoveLockEx(a1, v15, a3, a4, a5);
  return result;
}
