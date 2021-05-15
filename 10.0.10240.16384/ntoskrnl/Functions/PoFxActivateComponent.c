// PoFxActivateComponent 
 
unsigned int *__fastcall PoFxActivateComponent(unsigned int *result, unsigned int a2, char a3)
{
  unsigned int *v5; // r5
  int v6; // r9
  int v7; // r6
  unsigned int v8; // r3
  char *v9; // r4
  unsigned int v10; // r2
  signed int v11; // r2
  unsigned int v12; // r1
  unsigned int *v13; // r5
  int v14; // r8
  unsigned int v15; // r2
  char v16; // [sp+8h] [bp-38h] BYREF

  v5 = result;
  v6 = a3 & 1;
  if ( (a3 & 1) != 0 )
  {
    result = (unsigned int *)KeGetCurrentIrql(result);
    if ( (unsigned int)result >= 2 )
      sub_50E198();
  }
  if ( (a3 & 3) == 3 )
    PopFxBugCheck(1556, v5, a2, 1);
  if ( a2 >= v5[97] )
    JUMPOUT(0x50E1A6);
  v7 = *(_DWORD *)(v5[98] + 4 * a2);
  v8 = v5[96];
  __dmb(0xBu);
  if ( (v8 & 1) == 0 )
  {
    result = (unsigned int *)(v7 + 52);
    if ( (a3 & 2) != 0 )
      v9 = 0;
    else
      v9 = &v16;
    __dmb(0xBu);
    do
    {
      v10 = __ldrex(result);
      v11 = v10 + 1;
    }
    while ( __strex(v11, result) );
    __dmb(0xBu);
    if ( v11 == 1 )
    {
      __dmb(0xBu);
      do
        v12 = __ldrex(result);
      while ( __strex(v12 + 1, result) );
      __dmb(0xBu);
      result = (unsigned int *)PopFxActivateComponentWorker(v5, v7, 0, v9);
    }
    else
    {
      if ( v11 < 0 )
        return result;
      if ( (v11 & 0x40000000) != 0 )
      {
        v13 = (unsigned int *)(v7 + 80);
        v14 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
          JUMPOUT(0x50E1B4);
        do
          v15 = __ldrex(v13);
        while ( __strex(1u, v13) );
        __dmb(0xBu);
        if ( v15 )
          KxWaitForSpinLockAndAcquire(v7 + 80);
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v7 + 80);
        }
        else
        {
          __dmb(0xBu);
          *v13 = 0;
        }
        result = (unsigned int *)KfLowerIrql(v14);
      }
    }
    if ( v6 )
      result = (unsigned int *)KeWaitForSingleObject(v7 + 64, 0, 0, 0, 0);
  }
  return result;
}
