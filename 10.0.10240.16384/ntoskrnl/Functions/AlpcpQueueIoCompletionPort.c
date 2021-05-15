// AlpcpQueueIoCompletionPort 
 
int __fastcall AlpcpQueueIoCompletionPort(_DWORD *a1, int a2, int a3)
{
  _DWORD *v3; // r6
  int v7; // r0
  _DWORD *v8; // r5
  int v9; // r5
  int result; // r0
  unsigned int *v11; // r4
  unsigned int v12; // r2
  int v13; // r2
  char v14[40]; // [sp+10h] [bp-28h] BYREF

  v3 = (_DWORD *)a1[6];
  v7 = KeAcquireInStackQueuedSpinLock(v3, v14);
  if ( v3[2] >= v3[1] )
  {
    v9 = 0;
    if ( a2 )
      return sub_520BF8(v7);
    ++v3[3];
  }
  else
  {
    v8 = (_DWORD *)v3[6];
    if ( v8 )
      v3[6] = *v8;
    v9 = v8[1];
    ++v3[2];
  }
  result = KeReleaseInStackQueuedSpinLock(v14);
  if ( a3 )
  {
    v11 = a1 + 52;
    __dmb(0xBu);
    do
      v12 = __ldrex(v11);
    while ( v12 == 17 && __strex(0, v11) );
    if ( v12 != 17 )
      ExfReleasePushLockShared(a1 + 52, 0);
    result = KeAbPostRelease(a1 + 52);
  }
  if ( v9 )
  {
    if ( a2 )
      v13 = -1;
    else
      v13 = 0;
    result = IoSetIoCompletionEx2(a1[4], a1[5], v13, 0);
  }
  return result;
}
