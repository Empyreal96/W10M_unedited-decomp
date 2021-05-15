// PsRemoveCreateThreadNotifyRoutine 
 
int __fastcall PsRemoveCreateThreadNotifyRoutine(int a1)
{
  unsigned int v2; // r4
  int v3; // r7
  _DWORD *i; // r6
  unsigned int *v5; // r0
  unsigned int *v6; // r5
  __int16 v7; // r3
  int v9; // r0
  unsigned int v10; // r1
  unsigned int v11; // r1
  _DWORD *v12; // r0
  __int16 v13; // r3
  unsigned int v14; // r1

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = 0;
  for ( i = PspCreateThreadNotifyRoutine; ; ++i )
  {
    v5 = (unsigned int *)ExReferenceCallBackBlock(i);
    v6 = v5;
    if ( v5 )
      break;
LABEL_6:
    if ( (unsigned int)++v3 >= 0x40 )
    {
      v7 = *(_WORD *)(v2 + 308) + 1;
      *(_WORD *)(v2 + 308) = v7;
      if ( !v7 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
        KiCheckForKernelApcDelivery((int)v5);
      return -1073741702;
    }
  }
  if ( KeReadStateSemaphore((int)v5) != a1 || !ExCompareExchangeCallBack(i, 0, (int)v6) )
  {
    v5 = ExDereferenceCallBackBlock(i, (unsigned int)v6);
    goto LABEL_6;
  }
  v9 = ExGetCallBackBlockContext((int)v6);
  __dmb(0xBu);
  if ( v9 )
  {
    do
      v10 = __ldrex(&PspCreateThreadNotifyRoutineExCount);
    while ( __strex(v10 - 1, &PspCreateThreadNotifyRoutineExCount) );
  }
  else
  {
    do
      v11 = __ldrex(&PspCreateThreadNotifyRoutineCount);
    while ( __strex(v11 - 1, &PspCreateThreadNotifyRoutineCount) );
  }
  __dmb(0xBu);
  v12 = ExDereferenceCallBackBlock(&PspCreateThreadNotifyRoutine[v3], (unsigned int)v6);
  v13 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    KiCheckForKernelApcDelivery((int)v12);
  do
    v14 = __ldrex(v6);
  while ( !v14 && __strex(1u, v6) );
  __dmb(0xBu);
  if ( v14 && v14 != 1 )
    ExfWaitForRundownProtectionRelease(v6, v14);
  ExFreePoolWithTag((unsigned int)v6);
  return 0;
}
