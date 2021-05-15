// PopPepGetDevicePlatformStateDependents 
 
int __fastcall PopPepGetDevicePlatformStateDependents(unsigned int *a1, _DWORD *a2)
{
  unsigned int *v4; // r4
  int v5; // r9
  int v6; // r0
  unsigned int v7; // r1
  BOOL v8; // r6
  unsigned int v9; // r1
  unsigned int v10; // r2
  unsigned int *v11; // r1
  int v12; // r0
  unsigned int v13; // r3
  unsigned int v14; // r0
  unsigned int *v15; // r1
  unsigned int v16; // r6
  int v17; // r4
  int v18; // r2

  *a2 = 0;
  v4 = a1 + 11;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v4);
  }
  else
  {
    v6 = *v4 & 0x7FFFFFFF;
    do
      v7 = __ldrex(v4);
    while ( v7 == v6 && __strex(v6 + 1, v4) );
    __dmb(0xBu);
    if ( v7 != v6 )
      ExpWaitForSpinLockSharedAndAcquire(v4);
  }
  v8 = a1[28] == 2;
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
  KfLowerIrql(v5);
  if ( v8 )
  {
    v11 = a1;
    v12 = 3;
    do
    {
      v13 = v11[24];
      ++v11;
      *a2 |= v13;
      --v12;
    }
    while ( v12 );
    v14 = 0;
    if ( a1[30] )
    {
      v15 = a1 + 32;
      do
      {
        v16 = 0;
        if ( v15[39] )
        {
          v17 = 0;
          do
          {
            ++v16;
            v18 = *(_DWORD *)(v15[40] + v17 + 16);
            v17 += 24;
            *a2 |= v18;
          }
          while ( v16 < v15[39] );
        }
        ++v14;
        v15 += 42;
      }
      while ( v14 < a1[30] );
    }
  }
  return 0;
}
