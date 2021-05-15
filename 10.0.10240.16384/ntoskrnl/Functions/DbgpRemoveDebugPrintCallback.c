// DbgpRemoveDebugPrintCallback 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall DbgpRemoveDebugPrintCallback(void *a1)
{
  int v2; // r10
  int v3; // r0
  unsigned int v4; // r2
  unsigned int v5; // r1
  void **i; // r0
  void **v7; // r6
  unsigned int v8; // r1
  unsigned int v9; // r1
  unsigned int v10; // r2
  unsigned int *v11; // r0
  unsigned int v12; // r1
  void ***v13; // r1 OVERLAPPED
  void ***v14; // r2 OVERLAPPED
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  unsigned int v19; // r1
  unsigned int v20; // r2
  int vars4; // [sp+24h] [bp+4h]

  v2 = KfRaiseIrql(12);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&RtlpDebugPrintCallbackLock);
  }
  else
  {
    v3 = RtlpDebugPrintCallbackLock & 0x7FFFFFFF;
    v4 = (RtlpDebugPrintCallbackLock & 0x7FFFFFFF) + 1;
    do
      v5 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
    while ( v5 == v3 && __strex(v4, (unsigned int *)&RtlpDebugPrintCallbackLock) );
    __dmb(0xBu);
    if ( v5 != v3 )
      ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&RtlpDebugPrintCallbackLock);
  }
  for ( i = (void **)RtlpDebugPrintCallbackList; ; i = (void **)*i )
  {
    if ( i == &RtlpDebugPrintCallbackList )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&RtlpDebugPrintCallbackLock);
      }
      else
      {
        __dmb(0xBu);
        do
          v19 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
        while ( __strex(v19 & 0xBFFFFFFF, (unsigned int *)&RtlpDebugPrintCallbackLock) );
        __dmb(0xBu);
        do
          v20 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
        while ( __strex(v20 - 1, (unsigned int *)&RtlpDebugPrintCallbackLock) );
      }
      KfLowerIrql(v2);
      return -1073741275;
    }
    v7 = i - 3;
    if ( *(i - 1) == a1 )
    {
      __dmb(0xBu);
      do
        v8 = __ldrex((unsigned int *)v7);
      while ( __strex(v8 | 1, (unsigned int *)v7) );
      __dmb(0xBu);
      if ( (v8 & 1) == 0 )
        break;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&RtlpDebugPrintCallbackLock);
  }
  else
  {
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
    while ( __strex(v9 & 0xBFFFFFFF, (unsigned int *)&RtlpDebugPrintCallbackLock) );
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
    while ( __strex(v10 - 1, (unsigned int *)&RtlpDebugPrintCallbackLock) );
  }
  v11 = (unsigned int *)(v7 + 1);
  do
    v12 = __ldrex(v11);
  while ( !v12 && __strex(1u, v11) );
  __dmb(0xBu);
  if ( v12 && v12 != 1 )
    ExfWaitForRundownProtectionRelease(v11, v12);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&RtlpDebugPrintCallbackLock);
  }
  else
  {
    do
      v15 = __ldrex((unsigned __int8 *)&RtlpDebugPrintCallbackLock + 3);
    while ( __strex(v15 | 0x80, (unsigned __int8 *)&RtlpDebugPrintCallbackLock + 3) );
    __dmb(0xBu);
    if ( v15 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&RtlpDebugPrintCallbackLock);
    while ( 1 )
    {
      v16 = RtlpDebugPrintCallbackLock;
      if ( (RtlpDebugPrintCallbackLock & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (RtlpDebugPrintCallbackLock & 0x40000000) == 0 )
      {
        do
          v17 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
        while ( v17 == v16 && __strex(v16 | 0x40000000, (unsigned int *)&RtlpDebugPrintCallbackLock) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  *(_QWORD *)&v13 = *(_QWORD *)(v7 + 3);
  if ( v13[1] != v7 + 3 || *v14 != v7 + 3 )
    __fastfail(3u);
  *v14 = (void **)v13;
  v13[1] = (void **)v14;
  if ( v14 == v13 )
    RtlpDebugPrintCallbacksActive = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&RtlpDebugPrintCallbackLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    RtlpDebugPrintCallbackLock = 0;
  }
  KfLowerIrql(v2);
  ExFreePoolWithTag(v7);
  return 0;
}
