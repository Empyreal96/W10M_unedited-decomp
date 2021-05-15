// KiUpdateTimeAssist 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiUpdateTimeAssist(int *a1, int *a2, int *a3)
{
  unsigned int v4; // r5 OVERLAPPED
  unsigned int v5; // r6 OVERLAPPED
  unsigned __int64 v6; // kr08_8
  int v7; // r5
  int v8; // lr
  unsigned __int64 v9; // r0
  unsigned int v10; // r0
  int v11; // r1
  int v12; // r4
  unsigned int v13; // r6
  int v14; // r7
  unsigned int v15; // kr20_4
  unsigned __int64 v16; // kr48_8
  unsigned __int64 v17; // kr50_8
  unsigned __int64 v18; // r0
  unsigned int v19; // r0
  int v20; // r1
  int v21; // r4
  unsigned int v22; // r6
  int v23; // r7
  unsigned int v24; // kr24_4
  unsigned __int64 v25; // kr78_8
  unsigned __int64 v26; // kr80_8
  int *v27; // r6
  int v28; // r2
  int v29; // r3
  int v30; // r2
  int v31; // r3
  int v32; // r3
  int v33; // r3
  int v34; // r3
  int v35; // r5
  __int64 v36; // kr90_8
  int v37; // r7
  unsigned int v38; // r10
  __int64 v39; // r0
  __int64 v40; // r2
  unsigned __int64 v41; // krA8_8
  int v42; // r3
  int v43; // r3
  int v44; // r2
  int v45; // r2
  __int64 v46; // krB0_8
  int v49; // [sp+10h] [bp-30h]
  int v50; // [sp+18h] [bp-28h] BYREF
  int v51; // [sp+1Ch] [bp-24h]

  *(_QWORD *)&v4 = MEMORY[0xFFFF9340];
  while ( 1 )
  {
    while ( (v4 & 1) != 0 )
    {
      *(_QWORD *)&v4 = MEMORY[0xFFFF9340];
      __dmb(0xAu);
      __yield();
    }
    do
      v6 = __ldrexd((unsigned __int64 *)0xFFFF9340);
    while ( v6 == __PAIR64__(v5, v4) && __strexd(__PAIR64__(v5, v4) + 1, (unsigned __int64 *)0xFFFF9340) );
    __dmb(0xBu);
    if ( v6 == __PAIR64__(v5, v4) )
      break;
    v5 = HIDWORD(v6);
    v4 = v6;
    __dmb(0xAu);
    __yield();
  }
  if ( a1 )
  {
    v8 = a1[1];
    v7 = *a1;
  }
  else
  {
    KeQueryPerformanceCounter(&v50, 0);
    v7 = v50;
    v8 = v51;
  }
  v9 = 0i64;
  if ( __PAIR64__(v8, v7) > MEMORY[0xFFFF9348] )
  {
    v10 = (__PAIR64__(v8, v7) - MEMORY[0xFFFF9348]) >> 32;
    v11 = v7 - MEMORY[0xFFFF9348];
    if ( MEMORY[0xFFFF9368] )
    {
      v10 = __PAIR64__(v10, v11) << MEMORY[0xFFFF9368] >> 32;
      v11 <<= MEMORY[0xFFFF9368];
    }
    v13 = (MEMORY[0xFFFF935C] * (unsigned __int64)(unsigned int)v11) >> 32;
    v12 = MEMORY[0xFFFF935C] * v11;
    if ( v10 )
    {
      v17 = MEMORY[0xFFFF9358] * (unsigned __int64)v10 + __PAIR64__(v13, v12);
      v9 = v10 * (unsigned __int64)MEMORY[0xFFFF935C] + __PAIR64__(v17 < __PAIR64__(v13, v12), HIDWORD(v17));
      HIDWORD(KiSystemTimeErrorAccumulator) += v17;
      if ( HIDWORD(KiSystemTimeErrorAccumulator) < (unsigned int)v17 )
        ++v9;
    }
    else
    {
      v14 = MEMORY[0xFFFF9358] * v11;
      LODWORD(v9) = (__PAIR64__(v13, (MEMORY[0xFFFF9358] * (unsigned __int64)(unsigned int)v11) >> 32)
                   + (unsigned int)v12) >> 32;
      HIDWORD(v9) = (MEMORY[0xFFFF9358] * (unsigned __int64)(unsigned int)v11) >> 32;
      v15 = KiSystemTimeErrorAccumulator;
      LODWORD(KiSystemTimeErrorAccumulator) = v14 + KiSystemTimeErrorAccumulator;
      v16 = __PAIR64__(HIDWORD(KiSystemTimeErrorAccumulator), v14) + __PAIR64__(HIDWORD(v9), v15);
      HIDWORD(KiSystemTimeErrorAccumulator) = (__PAIR64__(HIDWORD(KiSystemTimeErrorAccumulator), v14)
                                             + __PAIR64__(HIDWORD(v9), v15)) >> 32;
      if ( v16 < __PAIR64__(HIDWORD(v9), v14) )
        LODWORD(v9) = v9 + 1;
      HIDWORD(v9) = 0;
    }
  }
  v50 = MEMORY[0xFFFF9014] + v9;
  v49 = (MEMORY[0xFFFF9014] + v9) >> 32;
  v18 = 0i64;
  if ( __PAIR64__(v8, v7) > MEMORY[0xFFFF9350] )
  {
    v19 = (__PAIR64__(v8, v7) - MEMORY[0xFFFF9350]) >> 32;
    v20 = v7 - MEMORY[0xFFFF9350];
    if ( MEMORY[0xFFFF9369] )
    {
      v19 = __PAIR64__(v19, v20) << MEMORY[0xFFFF9369] >> 32;
      v20 <<= MEMORY[0xFFFF9369];
    }
    v22 = (MEMORY[0xFFFF9364] * (unsigned __int64)(unsigned int)v20) >> 32;
    v21 = MEMORY[0xFFFF9364] * v20;
    if ( v19 )
    {
      v26 = MEMORY[0xFFFF9360] * (unsigned __int64)v19 + __PAIR64__(v22, v21);
      v18 = v19 * (unsigned __int64)MEMORY[0xFFFF9364] + __PAIR64__(v26 < __PAIR64__(v22, v21), HIDWORD(v26));
      HIDWORD(KiInterruptTimeErrorAccumulator) += v26;
      if ( HIDWORD(KiInterruptTimeErrorAccumulator) < (unsigned int)v26 )
        ++v18;
    }
    else
    {
      v23 = MEMORY[0xFFFF9360] * v20;
      LODWORD(v18) = (__PAIR64__(v22, (MEMORY[0xFFFF9360] * (unsigned __int64)(unsigned int)v20) >> 32)
                    + (unsigned int)v21) >> 32;
      HIDWORD(v18) = (MEMORY[0xFFFF9360] * (unsigned __int64)(unsigned int)v20) >> 32;
      v24 = KiInterruptTimeErrorAccumulator;
      LODWORD(KiInterruptTimeErrorAccumulator) = v23 + KiInterruptTimeErrorAccumulator;
      v25 = __PAIR64__(HIDWORD(KiInterruptTimeErrorAccumulator), v23) + __PAIR64__(HIDWORD(v18), v24);
      HIDWORD(KiInterruptTimeErrorAccumulator) = (__PAIR64__(HIDWORD(KiInterruptTimeErrorAccumulator), v23)
                                                + __PAIR64__(HIDWORD(v18), v24)) >> 32;
      if ( v25 < __PAIR64__(HIDWORD(v18), v23) )
        LODWORD(v18) = v18 + 1;
      HIDWORD(v18) = 0;
    }
  }
  v27 = a2;
  *(_QWORD *)a2 = MEMORY[0xFFFF9008] + v18;
  v28 = v49;
  MEMORY[0xFFFF901C] = v49;
  __dmb(0xBu);
  MEMORY[0xFFFF9014] = v50;
  __dmb(0xBu);
  MEMORY[0xFFFF9018] = v28;
  MEMORY[0xFFFF9010] = v27[1];
  v29 = *v27;
  __dmb(0xBu);
  MEMORY[0xFFFF9008] = v29;
  v30 = v27[1];
  __dmb(0xBu);
  MEMORY[0xFFFF900C] = v30;
  MEMORY[0xFFFF9348] = v7;
  MEMORY[0xFFFF934C] = v8;
  MEMORY[0xFFFF9350] = v7;
  MEMORY[0xFFFF9354] = v8;
  v31 = dword_690384;
  __dmb(0xBu);
  a3[1] = v31;
  v32 = KeTickCount;
  __dmb(0xBu);
  for ( *a3 = v32; a3[1] != dword_690388; *a3 = v34 )
  {
    __dmb(0xAu);
    __yield();
    v33 = dword_690384;
    __dmb(0xBu);
    a3[1] = v33;
    v34 = KeTickCount;
    __dmb(0xBu);
  }
  v36 = (unsigned int)KiTickOffset - v18;
  v35 = v36;
  if ( v36 <= 0 )
  {
    v18 = 1i64;
    v37 = KeMaximumIncrement;
    v38 = (v36 + (unsigned __int64)(unsigned int)KeMaximumIncrement) >> 32;
    v35 = v36 + KeMaximumIncrement;
    if ( v36 + (unsigned int)KeMaximumIncrement <= 0 )
    {
      if ( !KeMaximumIncrement )
        __brkdiv0();
      v39 = (unsigned int)_rt_udiv64((unsigned int)KeMaximumIncrement, -__SPAIR64__(v38, v35));
      LODWORD(v40) = v37 * ++v39;
      HIDWORD(v40) = (v39 * (unsigned __int64)(unsigned int)v37) >> 32;
      HIDWORD(v40) = (__PAIR64__(v38, v35) + v40) >> 32;
      v35 += v40;
      v18 = v39 + 1;
      v51 = HIDWORD(v40);
    }
    v41 = *(_QWORD *)a3 + v18;
    *(_QWORD *)a3 = v41;
    dword_690388 = HIDWORD(v41);
    v42 = *a3;
    __dmb(0xBu);
    KeTickCount = v42;
    v43 = a3[1];
    __dmb(0xBu);
    dword_690384 = v43;
    MEMORY[0xFFFF9328] = a3[1];
    v44 = *a3;
    __dmb(0xBu);
    MEMORY[0xFFFF9320] = v44;
    v45 = a3[1];
    __dmb(0xBu);
    MEMORY[0xFFFF9324] = v45;
  }
  v46 = MEMORY[0xFFFF9340];
  __dmb(0xBu);
  MEMORY[0xFFFF9340] = v46 + 1;
  KiTickOffset = v35;
  return v18;
}
