// KiUpdateSystemTime 
 
int __fastcall KiUpdateSystemTime(unsigned int a1, unsigned int a2, int a3, char a4)
{
  char v4; // r6
  int v8; // r9
  int v9; // r1
  unsigned int v10; // r2
  unsigned int v11; // r0
  int v12; // r1
  int result; // r0
  int v14; // r4
  unsigned int v15; // r6
  int v16; // r0
  unsigned int v17; // kr30_4
  unsigned int v18; // kr10_4
  unsigned __int64 v19; // kr38_8
  int v20; // r4
  __int64 v21; // kr50_8
  int v22; // r10
  unsigned __int64 v23; // kr58_8
  unsigned __int64 v25[5]; // [sp+18h] [bp-28h] BYREF

  v4 = a4;
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v8 = 0;
  }
  else
  {
    __disable_irq();
    v8 = 1;
  }
  RtlWriteAcquireTickLock((unsigned __int64 *)0xFFFF9340);
  KeQueryPerformanceCounter(v25, 0);
  v9 = 0;
  v10 = 0;
  if ( v25[0] > MEMORY[0xFFFF9348] )
  {
    v11 = (v25[0] - MEMORY[0xFFFF9348]) >> 32;
    v12 = LODWORD(v25[0]) - MEMORY[0xFFFF9348];
    if ( MEMORY[0xFFFF9368] )
      return sub_519A28(v11, v12, 0);
    v15 = (MEMORY[0xFFFF935C] * (unsigned __int64)(unsigned int)v12) >> 32;
    v14 = MEMORY[0xFFFF935C] * v12;
    if ( v11 )
    {
      v22 = 0;
      v23 = MEMORY[0xFFFF9358] * (unsigned __int64)v11 + __PAIR64__(v15, v14);
      if ( v23 < __PAIR64__(v15, v14) )
        v22 = 1;
      v10 = (__PAIR64__(v22, HIDWORD(v23)) + v11 * (unsigned __int64)MEMORY[0xFFFF935C]) >> 32;
      v9 = HIDWORD(v23) + v11 * MEMORY[0xFFFF935C];
      HIDWORD(KiSystemTimeErrorAccumulator) += v23;
      if ( HIDWORD(KiSystemTimeErrorAccumulator) < (unsigned int)v23 )
        v10 = (__PAIR64__(v10, v9++) + 1) >> 32;
    }
    else
    {
      v16 = MEMORY[0xFFFF9358] * v12;
      v17 = (MEMORY[0xFFFF9358] * (unsigned __int64)(unsigned int)v12) >> 32;
      v9 = (__PAIR64__(v15, (MEMORY[0xFFFF9358] * (unsigned __int64)(unsigned int)v12) >> 32) + (unsigned int)v14) >> 32;
      v18 = KiSystemTimeErrorAccumulator;
      LODWORD(KiSystemTimeErrorAccumulator) = v16 + KiSystemTimeErrorAccumulator;
      v19 = __PAIR64__(HIDWORD(KiSystemTimeErrorAccumulator), v16) + __PAIR64__(v17, v18);
      HIDWORD(KiSystemTimeErrorAccumulator) = (__PAIR64__(HIDWORD(KiSystemTimeErrorAccumulator), v16)
                                             + __PAIR64__(v17, v18)) >> 32;
      if ( v19 < __PAIR64__(v17, v16) )
        ++v9;
      v10 = 0;
    }
    v4 = a4;
  }
  result = (__PAIR64__(v10, v9) + MEMORY[0xFFFF9014]) >> 32;
  v20 = v9 + MEMORY[0xFFFF9014];
  if ( a1 | a2 )
  {
    result = (MEMORY[0xFFFF9014] + __PAIR64__(a2, a1)) >> 32;
    v20 = MEMORY[0xFFFF9014] + a1;
    KiSystemTimeErrorAccumulator = 0i64;
  }
  MEMORY[0xFFFF9348] = v25[0];
  MEMORY[0xFFFF901C] = result;
  __dmb(0xBu);
  MEMORY[0xFFFF9014] = v20;
  __dmb(0xBu);
  MEMORY[0xFFFF9018] = result;
  if ( a3 )
  {
    MEMORY[0xFFFF9358] = *(_DWORD *)(a3 + 8);
    MEMORY[0xFFFF935C] = *(_DWORD *)(a3 + 12);
    MEMORY[0xFFFF9368] = *(_BYTE *)(a3 + 16);
  }
  v21 = MEMORY[0xFFFF9340];
  __dmb(0xBu);
  MEMORY[0xFFFF9340] = v21 + 1;
  if ( (v4 & 1) == 0 )
  {
    if ( (v4 & 4) != 0 )
    {
      LODWORD(KeBootTime) = v20;
      HIDWORD(KeBootTime) = result;
      KeBootTimeBias = 0i64;
    }
    else
    {
      KeBootTime += __PAIR64__(a2, a1);
      KeBootTimeBias += __PAIR64__(a2, a1);
    }
  }
  if ( v8 )
    __enable_irq();
  return result;
}
