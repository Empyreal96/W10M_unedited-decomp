// KiSetupTimeIncrement 
 
unsigned int __fastcall KiSetupTimeIncrement(unsigned __int64 a1, unsigned int a2)
{
  int v2; // r4
  unsigned int v3; // r3
  unsigned int v4; // r2
  int v5; // r7
  __int64 v6; // r0
  __int128 v7; // r0
  unsigned int result; // r0
  char v9[8]; // [sp+0h] [bp-28h] BYREF
  int v10[2]; // [sp+8h] [bp-20h] BYREF
  int v11; // [sp+10h] [bp-18h] BYREF
  int v12; // [sp+14h] [bp-14h]

  if ( a2 > 0x1388 )
    KeMinimumIncrement = a2;
  else
    KeMinimumIncrement = 5000;
  v2 = 156250;
  if ( a1 < 0x2625A )
  {
    v12 = HIDWORD(a1);
    v2 = a1;
  }
  else
  {
    v12 = 0;
  }
  KeMaximumIncrement = v2;
  v3 = KiMinDynamicTickDuration;
  if ( a2 > KiMinDynamicTickDuration )
  {
    v3 = a2;
    KiMinDynamicTickDuration = a2;
  }
  v5 = HIDWORD(KiMaxDynamicTickDuration);
  v4 = KiMaxDynamicTickDuration;
  if ( a1 < KiMaxDynamicTickDuration )
  {
    KiMaxDynamicTickDuration = a1;
    v5 = HIDWORD(a1);
    v4 = a1;
  }
  if ( !v5 && v4 < v3 )
    KiMaxDynamicTickDuration = v3;
  KiTickOffset = v2;
  KeTimeAdjustment = v2;
  v6 = RtlpComputeFraction(1, v2, v9);
  KiMaximumIncrementShiftCount = -v9[0];
  KiMaximumIncrementReciprocal = v6;
  KeQueryPerformanceCounter(&v11, v10);
  *(_QWORD *)&v7 = RtlGenerateQpcToIncrementConstants(v10[0], v9);
  MEMORY[0xFFFF9300] = v10[0];
  MEMORY[0xFFFF9304] = v10[1];
  MEMORY[0xFFFF9360] = v7;
  MEMORY[0xFFFF9369] = v9[0];
  MEMORY[0xFFFF9358] = v7;
  DWORD1(v7) = v11;
  MEMORY[0xFFFF9368] = v9[0];
  DWORD2(v7) = v12;
  MEMORY[0xFFFF9348] = *(_QWORD *)((char *)&v7 + 4);
  MEMORY[0xFFFF9350] = *(_QWORD *)((char *)&v7 + 4);
  if ( !KeMaximumIncrement )
    __brkdiv0();
  result = (unsigned int)dword_989680 / KeMaximumIncrement;
  KiBalanceSetManagerPeriod = (unsigned int)dword_989680 / KeMaximumIncrement;
  KiBalanceSetManagerCount = (unsigned int)dword_989680 / KeMaximumIncrement;
  return result;
}
