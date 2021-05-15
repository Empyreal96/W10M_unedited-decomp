// ExpWorkerFactoryInitialization 
 
int ExpWorkerFactoryInitialization()
{
  int v0; // r3
  int v1; // r2
  int v3; // r4
  int v4; // [sp+10h] [bp-70h] BYREF
  int v5[22]; // [sp+18h] [bp-68h] BYREF

  v0 = 600;
  v1 = ExpWorkerFactoryThreadCreationTimeoutInSeconds;
  if ( !ExpWorkerFactoryThreadCreationTimeoutInSeconds )
    return sub_96C500();
  if ( (unsigned int)ExpWorkerFactoryThreadCreationTimeoutInSeconds > 0x258 )
  {
    v1 = 600;
    ExpWorkerFactoryThreadCreationTimeoutInSeconds = 600;
  }
  if ( !ExpWorkerFactoryThreadIdleTimeoutInSeconds )
  {
    v0 = 1;
    goto LABEL_11;
  }
  if ( (unsigned int)ExpWorkerFactoryThreadIdleTimeoutInSeconds > 0x258 )
LABEL_11:
    ExpWorkerFactoryThreadIdleTimeoutInSeconds = v0;
  ExpWorkerFactoryDeferredLongTimeout = -10000000i64 * v1;
  ExpWorkerFactoryDeferredMediumTimeout = -1200000;
  unk_619E14 = -1;
  ExpWorkerFactoryDeferredShortTimeout = -300000;
  unk_619E1C = -1;
  ExpWorkerFactoryThreadCreationList[0] = 0i64;
  KeInitializeQueue((int)&ExpWorkerFactoryManagerQueue, 0);
  KeInitializeTimerEx(ExpWorkerFactoryThreadCreationTimer, 1);
  KeRegisterObjectNotification(
    (unsigned int)ExpWorkerFactoryThreadCreationTimer,
    (unsigned int)&ExpWorkerFactoryManagerQueue,
    (int)&ExpWorkerFactoryThreadCreationBlock);
  __dmb(0xBu);
  ExpWorkerFactoryThreadCreationState = 0;
  memset(v5, 0, sizeof(v5));
  LOWORD(v5[0]) = 88;
  v5[2] = 256;
  v5[3] = 131080;
  v5[4] = 131076;
  v5[5] = 131075;
  v5[6] = 983295;
  v5[9] = 512;
  v5[11] = 248;
  v5[7] = 983295;
  v5[14] = (int)ExpCloseWorkerFactory;
  v5[15] = (int)ExpDeleteWorkerFactory;
  v3 = ObCreateObjectType();
  if ( v3 >= 0 )
  {
    v3 = PsCreateSystemThread((int)&v4, 0x1FFFFF, 0);
    if ( v3 >= 0 )
      ZwClose();
  }
  return v3;
}
