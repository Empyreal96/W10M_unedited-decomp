// PoFxIdleDevice 
 
int __fastcall PoFxIdleDevice(int result)
{
  _DWORD *v1; // r4
  unsigned int *v2; // r5
  int v3; // r8
  unsigned __int8 *v4; // r3
  unsigned int v5; // r1
  unsigned int v6; // r0
  int v7; // r2
  int v8; // r3
  _DWORD *v9; // r4
  unsigned int i; // r6
  unsigned int v11; // r1
  int v12; // [sp+0h] [bp-38h] BYREF

  if ( !result )
    return sub_5189EC();
  v1 = *(_DWORD **)(*(_DWORD *)(result + 176) + 20);
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
      v4 = (unsigned __int8 *)v1 + 47;
      do
        v5 = __ldrex(v4);
      while ( __strex(v5 | 0x80, v4) );
      __dmb(0xBu);
      if ( v5 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v1 + 11);
      while ( 1 )
      {
        v6 = *v2;
        if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v6 & 0x40000000) == 0 )
        {
          do
            v11 = __ldrex(v2);
          while ( v11 == v6 && __strex(v6 | 0x40000000, v2) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v7 = v1[16];
    if ( (v1[42] & 4) == 0 || (v8 = *(_DWORD *)(v1[10] + 384), __dmb(0xBu), (v8 & 1) == 0) )
    {
      v1[16] = v7 - 1;
      if ( (v1[42] & 4) != 0 )
      {
        v9 = (_DWORD *)v1[10];
        for ( i = 0; i < v9[97]; ++i )
          PopFxIdleComponent(v9, i, 2, (int)&v12);
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2);
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
