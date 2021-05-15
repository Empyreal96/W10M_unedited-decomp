// MiExceptionForMappedVa 
 
int __fastcall MiExceptionForMappedVa(unsigned int a1)
{
  int v1; // r7
  int v2; // r10
  char *v3; // r6
  unsigned int *v4; // r5
  int v5; // r0
  unsigned int v6; // r1
  _DWORD *v7; // r4
  int v8; // r0
  unsigned int v9; // r1
  unsigned int v10; // r2
  int v11; // r4
  unsigned int v12; // r1
  unsigned int v13; // r2
  int v15; // [sp+0h] [bp-28h]

  v1 = 0;
  v2 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v3 = algn_632F64;
  v4 = dword_634F00;
  while ( 1 )
  {
    v15 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v4);
    }
    else
    {
      v5 = *v4 & 0x7FFFFFFF;
      do
        v6 = __ldrex(v4);
      while ( v6 == v5 && __strex(v5 + 1, v4) );
      __dmb(0xBu);
      if ( v6 != v5 )
        ExpWaitForSpinLockSharedAndAcquire(v4);
    }
    v7 = (_DWORD *)*((_DWORD *)v3 + 2);
    if ( v7 )
    {
      do
      {
        v8 = MiSystemViewCompareVa(a1, (int)v7);
        if ( v8 >= 0 )
        {
          if ( v8 <= 0 )
            break;
          v7 = (_DWORD *)v7[1];
        }
        else
        {
          v7 = (_DWORD *)*v7;
        }
      }
      while ( v7 );
      if ( v7 )
        break;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v4);
    }
    else
    {
      __dmb(0xBu);
      do
        v9 = __ldrex(v4);
      while ( __strex(v9 & 0xBFFFFFFF, v4) );
      __dmb(0xBu);
      do
        v10 = __ldrex(v4);
      while ( __strex(v10 - 1, v4) );
    }
    KfLowerIrql(v15);
    if ( v3 != algn_632F64 )
      return v1;
    v11 = *(_DWORD *)(v2 + 324);
    if ( !v11 || PsIsSystemProcess(v2) )
      return v1;
    v4 = (unsigned int *)(v11 + 3248);
    v3 = (char *)(v11 + 3200);
  }
  if ( (v7[8] & 2) != 0 )
    v1 = 1;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v4);
  }
  else
  {
    __dmb(0xBu);
    do
      v12 = __ldrex(v4);
    while ( __strex(v12 & 0xBFFFFFFF, v4) );
    __dmb(0xBu);
    do
      v13 = __ldrex(v4);
    while ( __strex(v13 - 1, v4) );
  }
  KfLowerIrql(v15);
  return v1;
}
