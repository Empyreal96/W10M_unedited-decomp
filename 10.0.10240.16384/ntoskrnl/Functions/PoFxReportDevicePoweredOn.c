// PoFxReportDevicePoweredOn 
 
int __fastcall PoFxReportDevicePoweredOn(_DWORD *a1)
{
  int v2; // r7
  unsigned int *v3; // r8
  unsigned int v4; // r1
  unsigned int *v5; // r6
  int v6; // r10
  int result; // r0
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  unsigned int *v11; // r0
  int v12; // r4
  unsigned int v13; // r1
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r1
  unsigned int v17; // r3
  int v18; // r8
  unsigned int i; // r7

  v2 = a1[7];
  __dmb(0xBu);
  v3 = a1 + 4;
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 & 0xFFFFFFFD, v3) );
  __dmb(0xBu);
  if ( (v4 & 2) != 0 )
  {
    __dmb(0xBu);
    do
      v14 = __ldrex(v3);
    while ( __strex(v14, v3) );
    __dmb(0xBu);
    PopPepDeviceDState(a1[8], 1, 1, (v14 & 1) != 0);
    PopDiagTraceFxDevicePowerState(v2, 1);
  }
  v5 = (unsigned int *)(v2 + 44);
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_53EEFC();
  v8 = (unsigned __int8 *)(v2 + 47);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  __dmb(0xBu);
  if ( v9 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v2 + 44));
  while ( 1 )
  {
    v10 = *v5;
    if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v10 & 0x40000000) == 0 )
    {
      do
        v13 = __ldrex(v5);
      while ( v13 == v10 && __strex(v10 | 0x40000000, v5) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v11 = (unsigned int *)(v2 + 68);
  do
    v12 = __ldrex(v11);
  while ( __strex(0, v11) );
  if ( v12 > 0 )
  {
    v15 = *(_DWORD *)(a1[7] + 64);
    if ( v12 > v15 )
      PopFxBugCheck(1538, v2, v12, 0);
    __dmb(0xBu);
    do
      v16 = __ldrex(v3);
    while ( __strex(v16 & 0xFFFFFFFE, v3) );
    __dmb(0xBu);
    *(_DWORD *)(a1[7] + 64) = v15 - v12;
    if ( (*(_DWORD *)(a1[7] + 168) & 4) != 0 )
    {
      v17 = a1[97];
      v18 = v12;
      do
      {
        for ( i = 0; i < v17; ++i )
        {
          PoFxIdleComponent(a1, i, 2);
          v17 = a1[97];
        }
        --v18;
      }
      while ( v18 );
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
  if ( !v12 )
    result = PopFxCompleteDevicePowerRequired(a1, 0);
  return result;
}
