// WmipWriteWnodeToObject 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall WmipWriteWnodeToObject(int a1, unsigned int *a2, int a3, int a4)
{
  int v7; // r8
  int v8; // r1
  int v9; // r2
  int v10; // r6
  int v11; // r5
  int v12; // r1
  unsigned int *v14; // r4
  unsigned int v15; // r5
  unsigned int v16; // r4 OVERLAPPED
  int v17; // r0
  int v18; // r3
  int v19; // r3
  _DWORD v20[10]; // [sp+0h] [bp-28h] BYREF

  v20[0] = a2;
  v20[1] = a3;
  v20[2] = a4;
  v7 = 0;
  KeAcquireInStackQueuedSpinLock(&WmipCancelSpinLock, v20);
  v10 = *(_DWORD *)(a1 + 48);
  if ( v10 )
  {
    WmipClearIrpObjectList(*(_DWORD *)(a1 + 48), v8, v9);
    __dmb(0xBu);
    v14 = (unsigned int *)(v10 + 56);
    do
      v15 = __ldrex(v14);
    while ( __strex(0, v14) );
    __dmb(0xBu);
    if ( !v15 )
      v10 = 0;
  }
  KeReleaseInStackQueuedSpinLock(v20);
  v11 = 1;
  if ( !v10 )
    goto LABEL_3;
  v16 = *a2;
  v17 = *(_DWORD *)(v10 + 12);
  if ( *a2 > *(_DWORD *)(*(_DWORD *)(v10 + 96) + 8) )
  {
    *(_DWORD *)v17 = 56;
    v19 = 32;
    *(_QWORD *)(v17 + 44) = *(_QWORD *)(&v16 - 1);
    v16 = 56;
  }
  else
  {
    memmove(v17, (int)a2, *a2);
    v7 = 0;
    v11 = 0;
  }
  v18 = 0;
  *(_QWORD *)(v10 + 24) = *(_QWORD *)(&v16 - 1);
  pIofCompleteRequest(v10, 0);
  if ( v11 )
  {
LABEL_3:
    if ( a3 )
      v12 = a1 + 60;
    else
      v12 = a1 + 80;
    v7 = WmipQueueNotification(a1, v12, a2);
  }
  return v7;
}
