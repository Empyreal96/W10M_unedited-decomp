// ExpShutdownWorkerFactory 
 
int __fastcall ExpShutdownWorkerFactory(_DWORD *a1)
{
  unsigned __int8 v2; // r6
  int v3; // r3
  _DWORD *v4; // r5
  int v5; // r0
  int v6; // r2
  int v7; // r5
  int result; // r0
  char v9[32]; // [sp+10h] [bp-20h] BYREF

  KeAcquireInStackQueuedSpinLock(a1[1], v9);
  v2 = 0;
  a1[22] = a1[22] & 0xFFFFFFF8 | 4;
  v3 = 0;
  do
  {
    v4 = &a1[v3];
    v5 = v4[8];
    if ( v5 )
    {
      ObfDereferenceObjectWithTag(v5);
      v4[8] = 0;
    }
    v3 = ++v2;
  }
  while ( v2 < 4u );
  if ( (a1[22] & 0x200) != 0 )
    ExpLeaveWorkerFactoryAwayMode(a1);
  if ( KeDeregisterObjectNotification(a1 + 26, a1 + 48) )
    ObfDereferenceObjectWithTag(a1);
  *(_BYTE *)(a1[1] + 21) = 1;
  v6 = a1[1];
  a1[14] = 0;
  a1[15] = 0;
  if ( !*(_DWORD *)(v6 + 16) || *(_BYTE *)(v6 + 20) )
  {
    v7 = 0;
  }
  else
  {
    *(_BYTE *)(v6 + 20) = 1;
    v7 = 1;
  }
  KeReleaseInStackQueuedSpinLock(v9);
  result = KeCancelTimer2(a1 + 26, 0);
  if ( v7 )
    result = IoSetIoCompletionEx(*(_DWORD *)(a1[1] + 4), 0, 0, 0);
  return result;
}
