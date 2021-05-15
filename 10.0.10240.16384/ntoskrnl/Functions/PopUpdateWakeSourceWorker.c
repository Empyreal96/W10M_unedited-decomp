// PopUpdateWakeSourceWorker 
 
// local variable allocation has failed, the output may be wrong!
int *PopUpdateWakeSourceWorker()
{
  int *v0; // r4
  int v1; // r0
  int v2; // r5
  int v3; // r1
  int v4; // r7
  int **v5; // r0
  int *v6; // r1
  int *v7; // r1
  __int64 v8; // kr00_8
  int v9; // r3
  int **v10; // r0
  int v11; // r0
  int *v12; // r1 OVERLAPPED
  int **v13; // r2 OVERLAPPED
  int *result; // r0
  int *v15; // r1 OVERLAPPED
  int *v16; // [sp+0h] [bp-38h] BYREF
  int *v17; // [sp+4h] [bp-34h] BYREF
  int *v18; // [sp+8h] [bp-30h] BYREF
  int **v19; // [sp+Ch] [bp-2Ch]
  char v20[40]; // [sp+10h] [bp-28h] BYREF

  v19 = &v18;
  v18 = (int *)&v18;
  PopAcquireWakeSourceSpinLock((unsigned int)v20);
  while ( 1 )
  {
    v0 = (int *)PopWakeSourceWorkList;
    if ( (int *)PopWakeSourceWorkList == &PopWakeSourceWorkList )
      break;
    PopWakeSourceLockOwner = 0;
    v1 = KeReleaseInStackQueuedSpinLock((int)v20);
    v2 = v0[3];
    PnpLockDeviceActionQueue(v1, v3);
    v4 = PopProcessWakeSourceWork(v0, &v16, &v17);
    PnpUnlockDeviceActionQueue();
    ObfDereferenceObjectWithTag(v0[2]);
    PopAcquireWakeSourceSpinLock((unsigned int)v20);
    if ( v2 != PopCurrentWakeInfo && v2 != PopPendingWakeInfo || v4 < 0 )
    {
      v7 = v16;
LABEL_12:
      if ( v7 )
      {
        v10 = v19;
        *v7 = (int)&v18;
        v7[1] = (int)v10;
        if ( *v10 != (int *)&v18 )
          __fastfail(3u);
        *v10 = v7;
        v19 = (int **)v7;
      }
      goto LABEL_15;
    }
    v5 = *(int ***)(v2 + 16);
    v6 = v16;
    *v16 = v2 + 12;
    v6[1] = (int)v5;
    if ( *v5 != (int *)(v2 + 12) )
      __fastfail(3u);
    *v5 = v6;
    *(_DWORD *)(v2 + 16) = v6;
    v7 = v17;
    ++*(_DWORD *)(v2 + 20);
    v16 = 0;
    if ( v7 )
    {
      v8 = *(_QWORD *)v7;
      if ( *(int **)(*v7 + 4) != v7 || *(int **)HIDWORD(v8) != v7 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v8) = v8;
      *(_DWORD *)(v8 + 4) = HIDWORD(v8);
      v9 = *(_DWORD *)(v2 + 20);
      v16 = v7;
      *(_DWORD *)(v2 + 20) = v9 - 1;
      goto LABEL_12;
    }
LABEL_15:
    PopWakeInfoDereference(v2);
    v11 = v0[4];
    if ( v11 )
      KeSetEvent(v11, 0, 0);
    *(_QWORD *)&v12 = *(_QWORD *)v0;
    if ( *(int **)(*v0 + 4) != v0 || *v13 != v0 )
      __fastfail(3u);
    *v13 = v12;
    v12[1] = (int)v13;
    ExFreePoolWithTag(v0);
  }
  PopWakeSourceWorkInProgress = 0;
  PopWakeSourceLockOwner = 0;
  KeReleaseInStackQueuedSpinLock((int)v20);
  while ( 1 )
  {
    result = v18;
    if ( v18 == (int *)&v18 )
      break;
    *(_QWORD *)&v15 = *(_QWORD *)v18;
    if ( (int **)v18[1] != &v18 || (int *)v15[1] != v18 )
      __fastfail(3u);
    v18 = v15;
    v15[1] = (int)&v18;
    PopFreeWakeSource();
  }
  return result;
}
