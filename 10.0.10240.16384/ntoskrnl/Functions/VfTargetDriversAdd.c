// VfTargetDriversAdd 
 
int __fastcall VfTargetDriversAdd(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r3
  _DWORD *v7; // r0
  _DWORD *v8; // r7
  unsigned int v9; // r1
  _DWORD v10[8]; // [sp+0h] [bp-20h] BYREF

  v10[0] = a2;
  v10[1] = a3;
  v10[2] = a4;
  v4 = 1;
  if ( VfSafeMode )
    return 0;
  v5 = ViTargetInitialized;
  __dmb(0xBu);
  if ( !v5 )
    return 0;
  if ( a3 )
    return sub_518AD8();
  v7 = (_DWORD *)VfAvlReserveNode(&ViTargetDriversAvl, a1, a2);
  v8 = v7;
  if ( v7 )
  {
    v7[6] = 0;
    v7[2] = 0;
    v7[3] = 0;
    v7[4] = 0;
    v7[5] = 0;
    VfThunkAddTargetNotify();
    VfAvlInitializeLockContext(v10, 0);
    VfAvlInsertReservedTreeNode(&ViTargetDriversAvl, v10, v8);
    VfAvlCleanupLockContext(v10);
  }
  else
  {
    __dmb(0xBu);
    do
      v9 = __ldrex(ViTargetAllocationFailures);
    while ( __strex(1u, ViTargetAllocationFailures) );
    __dmb(0xBu);
    v4 = 0;
  }
  return v4;
}
