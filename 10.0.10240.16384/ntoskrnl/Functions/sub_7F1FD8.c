// sub_7F1FD8 
 
void sub_7F1FD8()
{
  int v0; // r6
  int v1; // r9
  unsigned int v2; // r4
  int v3; // r8
  _DWORD *i; // r7
  unsigned int *v5; // r0
  unsigned int *v6; // r5
  int v7; // r10
  __int16 v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r1
  _DWORD *v11; // r0
  __int16 v12; // r3
  unsigned int v13; // r1

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = 0;
  for ( i = PspCreateProcessNotifyRoutine; ; ++i )
  {
    v5 = (unsigned int *)ExReferenceCallBackBlock(i);
    v6 = v5;
    if ( v5 )
      break;
LABEL_7:
    if ( (unsigned int)++v3 >= 0x40 )
    {
      v8 = *(_WORD *)(v2 + 308) + 1;
      *(_WORD *)(v2 + 308) = v8;
      if ( !v8 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
        KiCheckForKernelApcDelivery((int)v5);
      JUMPOUT(0x78E2F8);
    }
  }
  v7 = ExGetCallBackBlockContext((int)v5);
  if ( KeReadStateSemaphore((int)v6) == v1 )
  {
    if ( v7 )
    {
      if ( !v0 )
        goto LABEL_6;
    }
    else if ( v0 )
    {
      goto LABEL_6;
    }
    if ( ExCompareExchangeCallBack(i, 0, (int)v6) )
    {
      __dmb(0xBu);
      if ( v0 )
      {
        do
          v10 = __ldrex(&PspCreateProcessNotifyRoutineExCount);
        while ( __strex(v10 - 1, &PspCreateProcessNotifyRoutineExCount) );
      }
      else
      {
        do
          v9 = __ldrex(&PspCreateProcessNotifyRoutineCount);
        while ( __strex(v9 - 1, &PspCreateProcessNotifyRoutineCount) );
      }
      __dmb(0xBu);
      v11 = ExDereferenceCallBackBlock(&PspCreateProcessNotifyRoutine[v3], (unsigned int)v6);
      v12 = *(_WORD *)(v2 + 308) + 1;
      *(_WORD *)(v2 + 308) = v12;
      if ( !v12 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
        KiCheckForKernelApcDelivery((int)v11);
      do
        v13 = __ldrex(v6);
      while ( !v13 && __strex(1u, v6) );
      __dmb(0xBu);
      if ( v13 && v13 != 1 )
        ExfWaitForRundownProtectionRelease(v6, v13);
      ExFreePoolWithTag((unsigned int)v6);
      JUMPOUT(0x78E2F6);
    }
  }
LABEL_6:
  v5 = ExDereferenceCallBackBlock(i, (unsigned int)v6);
  goto LABEL_7;
}
