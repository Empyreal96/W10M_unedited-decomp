// DbgEnumerateCallback 
 
int __fastcall DbgEnumerateCallback(void ****a1)
{
  int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r1
  void ***v5; // r3
  void ***v6; // r8
  void **v7; // r6
  int v8; // r10
  unsigned int *v9; // r0
  unsigned int v10; // r4
  unsigned int v11; // r1
  unsigned int v12; // r1
  unsigned int v13; // r2
  unsigned int *v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r1

  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&RtlpDebugPrintCallbackLock);
  }
  else
  {
    v2 = RtlpDebugPrintCallbackLock & 0x7FFFFFFF;
    v3 = (RtlpDebugPrintCallbackLock & 0x7FFFFFFF) + 1;
    do
      v4 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
    while ( v4 == v2 && __strex(v3, (unsigned int *)&RtlpDebugPrintCallbackLock) );
    __dmb(0xBu);
    if ( v4 != v2 )
      ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&RtlpDebugPrintCallbackLock);
  }
  v5 = *a1;
  if ( *a1 )
  {
    v6 = *a1;
  }
  else
  {
    v5 = (void ***)&RtlpDebugPrintCallbackList;
    v6 = 0;
  }
  v7 = *v5;
  v8 = 0;
  while ( v7 != &RtlpDebugPrintCallbackList )
  {
    v9 = (unsigned int *)(v7 - 2);
    __pld(v7 - 2);
    v10 = (unsigned int)*(v7 - 2) & 0xFFFFFFFE;
    do
      v11 = __ldrex(v9);
    while ( v11 == v10 && __strex(v10 + 2, v9) );
    __dmb(0xBu);
    if ( v11 == v10 || ExfAcquireRundownProtection(v9) )
    {
      v8 = (int)*(v7 - 1);
      *a1 = (void ***)v7;
      break;
    }
    v7 = (void **)*v7;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&RtlpDebugPrintCallbackLock);
  }
  else
  {
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
    while ( __strex(v12 & 0xBFFFFFFF, (unsigned int *)&RtlpDebugPrintCallbackLock) );
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
    while ( __strex(v13 - 1, (unsigned int *)&RtlpDebugPrintCallbackLock) );
  }
  if ( v6 )
  {
    v14 = (unsigned int *)(v6 - 2);
    __pld(v6 - 2);
    v15 = (unsigned int)*(v6 - 2) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v16 = __ldrex(v14);
    while ( v16 == v15 && __strex(v15 - 2, v14) );
    if ( v16 != v15 )
      ExfReleaseRundownProtection((unsigned __int8 *)v14);
  }
  return v8;
}
