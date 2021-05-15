// ExGenRandom 
 
int __fastcall ExGenRandom(int a1)
{
  int v2; // r8
  unsigned int v4; // r2
  int *v5; // r5
  __int64 v6; // r0
  int v7; // r6
  char *v8; // r3
  int v9; // r2

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50EBF8();
  do
    v4 = __ldrex((unsigned int *)&ExpLFGRngLock);
  while ( __strex(1u, (unsigned int *)&ExpLFGRngLock) );
  __dmb(0xBu);
  if ( v4 )
    KxWaitForSpinLockAndAcquire(&ExpLFGRngLock);
  if ( a1 == 1 && ExpRemainingLeftoverBootRngData )
  {
    v7 = ExpLeftoverBootRngData[--ExpRemainingLeftoverBootRngData];
    v8 = (char *)&ExpLeftoverBootRngData[ExpRemainingLeftoverBootRngData];
    v9 = 4;
    do
    {
      *v8++ = 0;
      --v9;
    }
    while ( v9 );
  }
  else
  {
    v5 = &ExpLFGRngState[57 * a1];
    LODWORD(v6) = v5[55] + 1;
    HIDWORD(v6) = v5[56] + 1;
    if ( v5[55] == 54 )
      LODWORD(v6) = 0;
    if ( v5[56] == 54 )
      HIDWORD(v6) = 0;
    v7 = v5[(_DWORD)v6] - v5[HIDWORD(v6)];
    v5[(_DWORD)v6] = v7;
    *(_QWORD *)(v5 + 55) = v6;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ExpLFGRngLock);
  }
  else
  {
    __dmb(0xBu);
    ExpLFGRngLock = 0;
  }
  KfLowerIrql(v2);
  return ExpRNGAuxiliarySeed ^ v7;
}
