// PsRemoveLoadImageNotifyRoutine 
 
int __fastcall PsRemoveLoadImageNotifyRoutine(int a1)
{
  unsigned int v2; // r4
  int v3; // r7
  _DWORD *i; // r6
  unsigned int *v5; // r0
  unsigned int *v6; // r5
  __int16 v7; // r3
  unsigned int v9; // r1
  _DWORD *v10; // r0
  __int16 v11; // r3
  unsigned int v12; // r1

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = 0;
  for ( i = PspLoadImageNotifyRoutine; ; ++i )
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
  __dmb(0xBu);
  do
    v9 = __ldrex(&PspLoadImageNotifyRoutineCount);
  while ( __strex(v9 - 1, &PspLoadImageNotifyRoutineCount) );
  __dmb(0xBu);
  v10 = ExDereferenceCallBackBlock(&PspLoadImageNotifyRoutine[v3], (unsigned int)v6);
  v11 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    KiCheckForKernelApcDelivery((int)v10);
  do
    v12 = __ldrex(v6);
  while ( !v12 && __strex(1u, v6) );
  __dmb(0xBu);
  if ( v12 && v12 != 1 )
    ExfWaitForRundownProtectionRelease(v6, v12);
  ExFreePoolWithTag((unsigned int)v6);
  return 0;
}
