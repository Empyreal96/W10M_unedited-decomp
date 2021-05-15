// ExpDeleteWorkerFactory 
 
int __fastcall ExpDeleteWorkerFactory(int a1, int a2, int a3, int a4)
{
  int v5; // r3
  int v6; // r6
  BOOL v7; // r5
  int result; // r0
  _DWORD v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[1] = a3;
  v9[2] = a4;
  KeAcquireInStackQueuedSpinLock(*(unsigned int **)(a1 + 4), (unsigned int)v9);
  *(_BYTE *)(*(_DWORD *)(a1 + 4) + 22) = 1;
  v5 = *(_DWORD *)(a1 + 4);
  v6 = *(_DWORD *)(v5 + 4);
  v7 = *(_BYTE *)(v5 + 20) == 0;
  KeReleaseInStackQueuedSpinLock((int)v9);
  ObfDereferenceObjectWithTag(*(_DWORD *)(a1 + 20));
  ObCloseHandle(*(_DWORD *)(a1 + 16));
  result = ObfDereferenceObjectWithTag(v6);
  if ( v7 )
  {
    IoFreeMiniCompletionPacket(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 8));
    result = ExFreePoolWithTag(*(_DWORD *)(a1 + 4), 0);
  }
  return result;
}
