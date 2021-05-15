// MiInitializeStaticCombining 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiInitializeStaticCombining(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r0
  _QWORD *v6; // r4
  int v7; // r0
  _DWORD *v8; // r2 OVERLAPPED
  int v9; // r1 OVERLAPPED
  _DWORD v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a1;
  v11[1] = a2;
  v11[2] = a3;
  v11[3] = a4;
  v5 = ExAllocatePoolWithTag(-2147483647, 262120);
  a1[45] = v5;
  if ( !v5 )
    return -1073741670;
  a1[46] = v5 + 262120;
  v6 = (_QWORD *)MiInsertNewCombineBlocks(a1, v5);
  if ( !v6 )
    return -1073741670;
  v7 = KeAcquireInStackQueuedSpinLock(a1 + 11, (unsigned int)v11);
  v8 = a1 + 9;
  v9 = a1[9];
  *v6 = *(_QWORD *)&v9;
  if ( *(_DWORD **)(v9 + 4) != a1 + 9 )
    sub_54F8B0(v7);
  *(_DWORD *)(v9 + 4) = v6;
  *v8 = v6;
  KeReleaseInStackQueuedSpinLock((int)v11);
  return 0;
}
