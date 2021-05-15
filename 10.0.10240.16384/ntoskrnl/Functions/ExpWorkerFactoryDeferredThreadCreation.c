// ExpWorkerFactoryDeferredThreadCreation 
 
void __fastcall __spoils<R2,R3,R12> ExpWorkerFactoryDeferredThreadCreation(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r5
  _DWORD *v5; // r4
  int v6; // r0
  _DWORD v7[6]; // [sp+0h] [bp-18h] BYREF

  v7[2] = a3;
  v7[3] = a4;
  __dmb(0xBu);
  ExpWorkerFactoryThreadCreationState = 0;
  v4 = (_DWORD *)RtlpInterlockedFlushSList(ExpWorkerFactoryThreadCreationList);
  while ( v4 )
  {
    v5 = v4;
    v6 = v4[1];
    v4 = (_DWORD *)*v4;
    KeAcquireInStackQueuedSpinLock(v6, v7);
    v5[22] &= 0xFFFFFFF7;
    ExpWorkerFactoryCheckCreate(v5, v7, 1);
    ObfDereferenceObjectWithTag(v5);
  }
}
