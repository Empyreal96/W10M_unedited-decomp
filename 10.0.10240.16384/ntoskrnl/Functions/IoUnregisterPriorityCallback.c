// IoUnregisterPriorityCallback 
 
_DWORD *__fastcall IoUnregisterPriorityCallback(_DWORD *result)
{
  _DWORD *v1; // r7
  unsigned int v2; // r4
  unsigned int v3; // r8
  _DWORD *v4; // r6
  unsigned int v5; // r5
  unsigned int v6; // r1
  _DWORD *v7; // r0
  __int16 v8; // r3
  __int16 v9; // r3

  v1 = result;
  if ( (result[2] & 0x200) != 0 )
  {
    v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v2 + 308);
    v3 = 0;
    v4 = IopUpdatePriorityCallbackRoutine;
    do
    {
      result = (_DWORD *)ExReferenceCallBackBlock(v4);
      v5 = (unsigned int)result;
      if ( result )
      {
        if ( (_DWORD *)result[4] == v1 )
        {
          result = (_DWORD *)ExCompareExchangeCallBack(v4, 0, (int)result);
          if ( result )
          {
            __dmb(0xBu);
            do
              v6 = __ldrex(&IopUpdatePriorityCallbackRoutineCount);
            while ( __strex(v6 - 1, &IopUpdatePriorityCallbackRoutineCount) );
            __dmb(0xBu);
            v7 = ExDereferenceCallBackBlock(&IopUpdatePriorityCallbackRoutine[v3], v5);
            v8 = *(_WORD *)(v2 + 308) + 1;
            *(_WORD *)(v2 + 308) = v8;
            if ( !v8 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
              KiCheckForKernelApcDelivery((int)v7);
            ExWaitForCallBacks(v5);
            result = (_DWORD *)RtlpSysVolFree(v5);
            v1[2] &= 0xFFFFFDFF;
            return result;
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
    v9 = *(_WORD *)(v2 + 308) + 1;
    *(_WORD *)(v2 + 308) = v9;
    if ( !v9 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
      result = (_DWORD *)KiCheckForKernelApcDelivery((int)result);
  }
  return result;
}
