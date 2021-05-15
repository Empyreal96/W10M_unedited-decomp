// PoUnregisterCoalescingCallback 
 
unsigned int *__fastcall PoUnregisterCoalescingCallback(unsigned int *a1)
{
  unsigned int v2; // r4
  unsigned int v3; // r7
  _DWORD *v4; // r6
  unsigned int *result; // r0
  unsigned int *v6; // r5
  unsigned int v7; // r1
  _DWORD *v8; // r0
  __int16 v9; // r3
  unsigned int v10; // r1
  __int16 v11; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = 0;
  v4 = PopCoalescingCallbackRoutine;
  do
  {
    result = (unsigned int *)ExReferenceCallBackBlock(v4);
    v6 = result;
    if ( result )
    {
      if ( result == a1 )
      {
        result = (unsigned int *)ExCompareExchangeCallBack(v4, 0, (int)result);
        if ( result )
        {
          __dmb(0xBu);
          do
            v7 = __ldrex(&PopCoalescingCallbackRoutineCount);
          while ( __strex(v7 - 1, &PopCoalescingCallbackRoutineCount) );
          __dmb(0xBu);
          v8 = ExDereferenceCallBackBlock(&PopCoalescingCallbackRoutine[v3], (unsigned int)v6);
          v9 = *(_WORD *)(v2 + 308) + 1;
          *(_WORD *)(v2 + 308) = v9;
          if ( !v9 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
            KiCheckForKernelApcDelivery((int)v8);
          do
            v10 = __ldrex(v6);
          while ( !v10 && __strex(1u, v6) );
          __dmb(0xBu);
          if ( v10 )
          {
            if ( v10 != 1 )
              ExfWaitForRundownProtectionRelease(v6, v10);
          }
          return (unsigned int *)ExFreePoolWithTag((unsigned int)v6);
        }
      }
      else
      {
        result = ExDereferenceCallBackBlock(v4, (unsigned int)result);
      }
    }
    ++v3;
    ++v4;
  }
  while ( v3 < 8 );
  v11 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    result = (unsigned int *)KiCheckForKernelApcDelivery((int)result);
  return result;
}
