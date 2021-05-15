// PopFxIncrementDeviceSleepCount 
 
int __fastcall PopFxIncrementDeviceSleepCount(int result)
{
  _DWORD *v1; // r5
  unsigned int *v2; // r4
  int v3; // r7
  int v4; // r2
  int v5; // r3
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r1
  int vars4; // [sp+1Ch] [bp+4h]

  if ( result )
    v1 = *(_DWORD **)(*(_DWORD *)(result + 176) + 20);
  else
    v1 = 0;
  if ( v1 )
  {
    v2 = v1 + 11;
    v3 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v1 + 11);
    }
    else
    {
      v6 = (unsigned __int8 *)v1 + 47;
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 | 0x80, v6) );
      __dmb(0xBu);
      if ( v7 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v1 + 11);
      while ( 1 )
      {
        v8 = *v2;
        if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v8 & 0x40000000) == 0 )
        {
          do
            v9 = __ldrex(v2);
          while ( v9 == v8 && __strex(v8 | 0x40000000, v2) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v4 = v1[17];
    if ( (v1[42] & 4) == 0 || (v5 = *(_DWORD *)(v1[10] + 384), __dmb(0xBu), (v5 & 1) == 0) )
      v1[17] = v4 + 1;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v1 + 11, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v2 = 0;
    }
    result = KfLowerIrql(v3);
  }
  return result;
}
