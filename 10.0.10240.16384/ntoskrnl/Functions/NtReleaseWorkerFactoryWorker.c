// NtReleaseWorkerFactoryWorker 
 
int __fastcall NtReleaseWorkerFactoryWorker(int a1)
{
  int v1; // r3
  int result; // r0
  int v3; // r4
  int v4; // r2
  int v5; // r5
  int v6; // r3
  int v7; // r2
  int v8; // r6
  int v9; // [sp+10h] [bp-28h] BYREF
  char v10[32]; // [sp+18h] [bp-20h] BYREF

  v1 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  result = ObReferenceObjectByHandle(a1, 1, ExpWorkerFactoryObjectType, v1, &v9, 0);
  if ( result >= 0 )
  {
    v3 = v9;
    KeAcquireInStackQueuedSpinLock(*(_DWORD *)(v9 + 4), v10);
    v4 = *(_DWORD *)(v3 + 4);
    v5 = 0;
    if ( *(_BYTE *)(v4 + 21) )
    {
      v8 = 128;
    }
    else
    {
      v6 = *(_DWORD *)(v4 + 12);
      if ( v6 == -1 )
      {
        v8 = -1073741823;
      }
      else
      {
        *(_DWORD *)(v4 + 12) = v6 + 1;
        v7 = *(_DWORD *)(v3 + 4);
        if ( !*(_BYTE *)(v7 + 20) )
        {
          *(_BYTE *)(v7 + 20) = 1;
          v5 = 1;
        }
        v8 = 0;
        if ( v5 && (*(_DWORD *)(v3 + 88) & 0x200) != 0 )
          ExpLeaveWorkerFactoryAwayMode(v3);
      }
    }
    KeReleaseInStackQueuedSpinLock(v10);
    if ( v5 )
    {
      IoSetIoCompletionEx2(*(_DWORD *)(*(_DWORD *)(v3 + 4) + 4), 0, 0, 0);
      ExpWorkerFactoryCheckCreate(v3, 0, 0);
    }
    ObfDereferenceObjectWithTag(v3);
    result = v8;
  }
  return result;
}
