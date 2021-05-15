// PopFxActivateDevice 
 
int __fastcall PopFxActivateDevice(int a1, int a2)
{
  int result; // r0
  _DWORD *v4; // r6
  unsigned int *v5; // r5
  int v6; // r9
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  int v10; // r2
  int v11; // r3
  unsigned int *v12; // r4
  unsigned int i; // r6
  int v14; // r5
  unsigned int j; // r6
  unsigned int *v16; // r2
  unsigned int v17; // r1
  unsigned int v18; // r1
  unsigned int v19; // r1
  unsigned int *v20; // r2
  unsigned int v21; // r0

  if ( !a1 )
    return sub_50F338();
  v4 = *(_DWORD **)(*(_DWORD *)(a1 + 176) + 20);
  v5 = v4 + 11;
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v4 + 11);
  }
  else
  {
    v7 = (unsigned __int8 *)v4 + 47;
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
    __dmb(0xBu);
    if ( v8 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v4 + 11);
    while ( 1 )
    {
      v9 = *v5;
      if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v9 & 0x40000000) == 0 )
      {
        do
          v19 = __ldrex(v5);
        while ( v19 == v9 && __strex(v9 | 0x40000000, v5) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v10 = v4[16];
  if ( (v4[42] & 4) != 0 && (v11 = *(_DWORD *)(v4[10] + 384), __dmb(0xBu), (v11 & 1) != 0) )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v4 + 11);
    }
    else
    {
      __dmb(0xBu);
      *v5 = 0;
    }
    result = KfLowerIrql(v6);
  }
  else
  {
    v4[16] = v10 + 1;
    v12 = 0;
    if ( (v4[42] & 4) != 0 )
    {
      v12 = (unsigned int *)v4[10];
      PopFxAddRefDevice((int)v12);
      for ( i = 0; i < v12[97]; ++i )
        PoFxActivateComponent(v12, i, 2);
      if ( a2 )
      {
        __dmb(0xBu);
        v20 = v12 + 4;
        do
          v21 = __ldrex(v20);
        while ( __strex(v21 | 1, v20) );
        __dmb(0xBu);
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5);
    }
    else
    {
      __dmb(0xBu);
      *v5 = 0;
    }
    result = KfLowerIrql(v6);
    if ( v12 )
    {
      for ( j = 0; j < v12[97]; ++j )
      {
        v14 = *(_DWORD *)(v12[98] + 4 * j);
        if ( (*(_DWORD *)(v14 + 52) & 0x3FFFFFFF) == 0 )
          PopFxBugCheck(1544, *(_DWORD *)(v12[98] + 4 * j), v14 + 52, 0);
        KeWaitForSingleObject(v14 + 64, 0, 0, 0, 0);
        if ( (*(_DWORD *)(v14 + 52) & 0x80000000) == 0 )
          PopFxBugCheck(1544, v14, v14 + 52, 0);
      }
      result = KeWaitForSingleObject((unsigned int)(v12 + 80), 0, 0, 0, 0);
      __dmb(0xBu);
      v16 = v12 + 28;
      do
      {
        v17 = __ldrex(v16);
        v18 = v17 - 1;
      }
      while ( __strex(v18, v16) );
      __dmb(0xBu);
      if ( !v18 )
        result = KeSetEvent((int)(v12 + 29), 0, 0);
    }
  }
  return result;
}
