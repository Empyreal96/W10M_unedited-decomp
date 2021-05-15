// DbgpInsertDebugPrintCallback 
 
int __fastcall DbgpInsertDebugPrintCallback(int a1)
{
  _DWORD *v2; // r0
  _DWORD *v3; // r6
  int v4; // r7
  unsigned int v6; // r1
  int v7; // r0
  void ***v8; // r0
  unsigned int v9; // r1

  v2 = (_DWORD *)ExAllocatePoolWithTag(512, 20);
  v3 = v2;
  if ( !v2 )
    return -1073741670;
  *v2 = 0;
  v2[1] = 0;
  v2[2] = a1;
  v4 = KfRaiseIrql(12);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_519D00();
  do
    v6 = __ldrex((unsigned __int8 *)&RtlpDebugPrintCallbackLock + 3);
  while ( __strex(v6 | 0x80, (unsigned __int8 *)&RtlpDebugPrintCallbackLock + 3) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&RtlpDebugPrintCallbackLock);
  while ( 1 )
  {
    v7 = RtlpDebugPrintCallbackLock;
    if ( (RtlpDebugPrintCallbackLock & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (RtlpDebugPrintCallbackLock & 0x40000000) == 0 )
    {
      do
        v9 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
      while ( v9 == v7 && __strex(v7 | 0x40000000, (unsigned int *)&RtlpDebugPrintCallbackLock) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v8 = (void ***)off_6174C0[0];
  v3[3] = &RtlpDebugPrintCallbackList;
  v3[4] = v8;
  if ( *v8 != &RtlpDebugPrintCallbackList )
    __fastfail(3u);
  *v8 = (void **)(v3 + 3);
  off_6174C0[0] = (void **)(v3 + 3);
  RtlpDebugPrintCallbacksActive = 1;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&RtlpDebugPrintCallbackLock);
  }
  else
  {
    __dmb(0xBu);
    RtlpDebugPrintCallbackLock = 0;
  }
  KfLowerIrql(v4);
  return 0;
}
