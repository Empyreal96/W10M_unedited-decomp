// PopTimeoutWakeTracking 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopTimeoutWakeTracking(_QWORD *a1)
{
  char *v2; // r5
  int *i; // r2
  int *v4; // r2
  int v5; // r1 OVERLAPPED
  char v7[16]; // [sp+8h] [bp-30h] BYREF
  char v8[4]; // [sp+18h] [bp-20h] BYREF
  int v9; // [sp+1Ch] [bp-1Ch]
  int v10[6]; // [sp+20h] [bp-18h] BYREF

  v8[0] = 1;
  v8[1] = 0;
  v8[2] = 4;
  v9 = 0;
  v10[1] = (int)v10;
  v10[0] = (int)v10;
  v2 = 0;
  PopAcquireWakeSourceSpinLock((unsigned int)v7);
  if ( a1 == (_QWORD *)PopCurrentWakeInfo )
  {
    PopCurrentWakeInfo = 0;
    PopPendingWakeInfo = (int)a1;
    if ( PopWakeSourceWorkInProgress )
    {
      for ( i = (int *)dword_61F2FC; i != &PopWakeSourceWorkList; i = (int *)i[1] )
      {
        if ( (_QWORD *)i[3] == a1 )
        {
          v2 = v8;
          i[4] = (int)v8;
          break;
        }
      }
    }
    PopWakeSourceLockOwner = 0;
    KeReleaseInStackQueuedSpinLock((int)v7);
    if ( v2 )
      KeWaitForSingleObject((unsigned int)v2, 0, 0, 0, 0);
    PopAcquireWakeSourceSpinLock((unsigned int)v7);
    if ( a1 == (_QWORD *)PopPendingWakeInfo )
    {
      v4 = &PopWakeInfoList;
      v5 = PopWakeInfoList;
      *a1 = *(_QWORD *)&v5;
      if ( *(int **)(v5 + 4) != &PopWakeInfoList )
        __fastfail(3u);
      *(_DWORD *)(v5 + 4) = a1;
      PopWakeInfoList = (int)a1;
      ++PopWakeInfoCount;
      PopPendingWakeInfo = 0;
      PopWakeSourceLockOwner = 0;
      KeReleaseInStackQueuedSpinLock((int)v7);
      PopFinalizeWakeInfo(a1);
      PopAcquireWakeSourceSpinLock((unsigned int)v7);
    }
  }
  PopWakeInfoDereference(a1);
  PopWakeSourceLockOwner = 0;
  return KeReleaseInStackQueuedSpinLock((int)v7);
}
