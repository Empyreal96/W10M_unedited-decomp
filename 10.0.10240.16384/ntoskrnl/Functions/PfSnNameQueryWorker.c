// PfSnNameQueryWorker 
 
unsigned int *__fastcall PfSnNameQueryWorker(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned int *v5; // r4
  unsigned __int8 *v6; // r6
  int v7; // r10
  unsigned int *result; // r0
  unsigned int v9; // r2
  unsigned int v10; // r0
  _DWORD *v11; // r6
  int v12; // r6
  unsigned int v13; // r4
  unsigned int v14; // r2
  unsigned int v15; // r1
  unsigned int v16; // r1
  int v17[8]; // [sp+0h] [bp-20h] BYREF

  v17[0] = a4;
  v5 = a1 + 98;
  while ( 1 )
  {
    v6 = (unsigned __int8 *)v5 + 3;
    v7 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return (unsigned int *)sub_53EFB8();
    do
      v9 = __ldrex(v6);
    while ( __strex(v9 | 0x80, v6) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v5);
    while ( 1 )
    {
      v10 = *v5;
      if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v10 & 0x40000000) == 0 )
      {
        do
          v16 = __ldrex(v5);
        while ( v16 == v10 && __strex(v10 | 0x40000000, v5) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    v11 = (_DWORD *)a1[93];
    if ( !v11 )
      break;
    a1[93] = *v11;
    *v11 = 0;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5);
    }
    else
    {
      __dmb(0xBu);
      *v5 = 0;
    }
    KfLowerIrql(v7);
    v12 = v11[1];
    if ( (*(int (__fastcall **)(_DWORD, int, int *))(dword_637348 + 8))(a1[66], v12, v17) >= 0 )
      PfSnVolumeKeyQuery(a1, v17[0], v12);
    ObfDereferenceObjectWithTag(v12);
  }
  a1[97] = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5);
  }
  else
  {
    __dmb(0xBu);
    *v5 = 0;
  }
  KfLowerIrql(v7);
  result = a1 + 67;
  __pld(a1 + 67);
  v13 = a1[67] & 0xFFFFFFFE;
  __dmb(0xBu);
  v14 = v13 - 2;
  do
    v15 = __ldrex(result);
  while ( v15 == v13 && __strex(v14, result) );
  if ( v15 != v13 )
    result = (unsigned int *)ExfReleaseRundownProtection(result, v15, v14);
  return result;
}
