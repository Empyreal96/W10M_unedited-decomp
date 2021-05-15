// ExpWorkerFactoryManagerThread 
 
void __noreturn ExpWorkerFactoryManagerThread()
{
  int v0; // r0
  int v1; // r1
  int v2; // r2
  int v3; // r3
  int *v4; // r4
  int *v5; // r4
  int v6; // r5
  unsigned int v7; // r3
  unsigned int v8; // r2
  int v9; // r5
  int v10; // r0
  unsigned int v11; // r3
  int v12; // r3
  int *v13; // [sp+8h] [bp-30h] BYREF
  int v14[10]; // [sp+10h] [bp-28h] BYREF

  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v0 = KeRemoveQueueEx((int)&ExpWorkerFactoryManagerQueue, 0, 0, 0, &v13, 1u);
        v4 = v13;
        if ( v13 != (int *)&ExpWorkerFactoryThreadCreationBlock )
          break;
        ExpWorkerFactoryDeferredThreadCreation(v0, v1, v2, v3);
        KeRegisterObjectNotification(
          (unsigned int)&ExpWorkerFactoryThreadCreationTimer,
          (unsigned int)&ExpWorkerFactoryManagerQueue,
          (int)&ExpWorkerFactoryThreadCreationBlock);
      }
      if ( v13[6] )
        break;
      KeAcquireInStackQueuedSpinLock((unsigned int *)*(v13 - 54), (unsigned int)v14);
      v11 = *(v4 - 33) & 0xFFFFFBFF;
      *(v4 - 33) = v11;
      if ( (v11 & 0x200) != 0 && ExpTryEnterWorkerFactoryAwayMode(v4 - 55) )
        ExpWorkerFactoryCheckCreate(v4 - 55, v14, 0, v12);
      else
        KeReleaseInStackQueuedSpinLock((int)v14);
      v10 = (int)(v4 - 55);
LABEL_14:
      ObfDereferenceObjectWithTag(v10);
    }
    v5 = v13 - 48;
    v6 = *(v13 - 47);
    KeAcquireInStackQueuedSpinLock((unsigned int *)v6, (unsigned int)v14);
    if ( !v5[20] )
    {
      v7 = v5[16];
      v8 = v5[14];
      if ( v7 > v8 )
        KeTimeOutQueueWaiters(*(_DWORD *)(v6 + 4), -*((_QWORD *)v5 + 6), v7 - v8);
    }
    if ( *(_BYTE *)(v6 + 21) )
    {
      v9 = 1;
    }
    else
    {
      v9 = 0;
      KeRegisterObjectNotification((unsigned int)(v5 + 26), (unsigned int)&ExpWorkerFactoryManagerQueue, (int)(v5 + 48));
    }
    KeReleaseInStackQueuedSpinLock((int)v14);
    if ( v9 )
    {
      v10 = (int)v5;
      goto LABEL_14;
    }
  }
}
