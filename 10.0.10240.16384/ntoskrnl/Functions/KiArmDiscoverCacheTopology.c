// KiArmDiscoverCacheTopology 
 
int __fastcall KiArmDiscoverCacheTopology(int a1)
{
  int v1; // r7
  int v2; // r0
  unsigned int v3; // r3
  unsigned int v4; // r5
  int v5; // r3
  __int64 v6; // kr00_8
  __int64 v7; // kr08_8
  unsigned int v8; // r1
  int v9; // r3
  unsigned __int64 v10; // r2
  unsigned __int64 v11; // r2
  int v12; // r8
  unsigned int v13; // r3
  unsigned int v14; // r5
  int v15; // r3
  __int64 v16; // kr20_8
  __int64 v17; // kr28_8
  unsigned int v18; // r1
  int v19; // r3
  unsigned __int64 v20; // r2
  int v21; // r2
  unsigned int v22; // r3
  unsigned int v23; // r6
  int v24; // r3
  __int64 v25; // kr40_8
  int v26; // r5
  unsigned int v27; // r1
  unsigned int v28; // r3
  unsigned __int64 v29; // r2
  int v30; // r2
  int v31; // r0
  unsigned int v32; // r3
  unsigned int v33; // r5
  int v34; // r3
  __int64 v35; // kr60_8
  __int64 v36; // kr68_8
  unsigned int v37; // r1
  int v38; // r3
  unsigned __int64 v39; // r2
  int v40; // r2
  unsigned int v41; // r3
  unsigned int v42; // r7
  int v43; // r3
  __int64 v44; // kr80_8
  int v45; // r5
  unsigned int v46; // r1
  unsigned int v47; // r3
  unsigned __int64 v48; // r2
  int v49; // r2
  int v50; // r4
  int v51; // r3
  int v54; // [sp+Ch] [bp-2Ch]
  int v55; // [sp+Ch] [bp-2Ch]
  int v56; // [sp+10h] [bp-28h]
  int v57; // [sp+14h] [bp-24h]

  v1 = a1;
  v2 = KdDisableDebugger();
  __disable_irq();
  v57 = v2;
  if ( !KdDebuggerNotPresent )
  {
    while ( 1 )
      ;
  }
  __enable_irq();
  v3 = __mrc(15, 0, 9, 13, 0);
  v4 = v3 << 29;
  v5 = v3 ^ (v3 >> 3);
  v6 = 67117057i64 * (unsigned int)v5;
  v7 = 1880096896i64 * (unsigned int)v5 + 67117057i64 * v4;
  v8 = (1880096896i64 * v4 + (unsigned __int64)HIDWORD(v7)) >> 32;
  v9 = 1880096896 * v4 + HIDWORD(v7);
  if ( (unsigned int)(v7 + HIDWORD(v6)) < HIDWORD(v6) )
    v8 = (__PAIR64__(v8, v9++) + 1) >> 32;
  LODWORD(v10) = v6 ^ v9;
  HIDWORD(v10) = (v7 + HIDWORD(v6)) ^ v8;
  _rt_udiv64(10i64, v10);
  if ( v11 >= 6 || MEMORY[0xFFFF92E8] <= 0x28000u && v1 )
    v12 = 1;
  else
    v12 = 2;
  v13 = __mrc(15, 0, 9, 13, 0);
  v14 = v13 << 29;
  v15 = v13 ^ (v13 >> 3);
  v16 = 67117057i64 * (unsigned int)v15;
  v17 = 1880096896i64 * (unsigned int)v15 + 67117057i64 * v14;
  v18 = (1880096896i64 * v14 + (unsigned __int64)HIDWORD(v17)) >> 32;
  v19 = 1880096896 * v14 + HIDWORD(v17);
  if ( (unsigned int)(v17 + HIDWORD(v16)) < HIDWORD(v16) )
    v18 = (__PAIR64__(v18, v19++) + 1) >> 32;
  LODWORD(v20) = v16 ^ v19;
  HIDWORD(v20) = (v17 + HIDWORD(v16)) ^ v18;
  _rt_udiv64(13i64, v20);
  v54 = v21;
  v22 = __mrc(15, 0, 9, 13, 0);
  v23 = v22 << 29;
  v24 = v22 ^ (v22 >> 3);
  v25 = 67117057i64 * (unsigned int)v24;
  v26 = 1880096896 * v24 + 67117057 * v23;
  v27 = (1880096896i64 * v23 + ((1880096896i64 * (unsigned int)v24 + 67117057 * (unsigned __int64)v23) >> 32)) >> 32;
  v28 = 1880096896 * v23 + ((1880096896i64 * (unsigned int)v24 + 67117057 * (unsigned __int64)v23) >> 32);
  if ( (unsigned int)(v26 + HIDWORD(v25)) < HIDWORD(v25) )
    v27 = (__PAIR64__(v27, v28++) + 1) >> 32;
  LODWORD(v29) = v25 ^ v28;
  HIDWORD(v29) = (v26 + HIDWORD(v25)) ^ v27;
  _rt_udiv64(6i64, v29);
  v56 = v30;
  v31 = sub_931184(v54, v30, v12, a1, 1);
  if ( !v31 )
    goto LABEL_26;
  if ( v12 == 2 )
  {
    v32 = __mrc(15, 0, 9, 13, 0);
    v33 = v32 << 29;
    v34 = v32 ^ (v32 >> 3);
    v35 = 67117057i64 * (unsigned int)v34;
    v36 = 1880096896i64 * (unsigned int)v34 + 67117057i64 * v33;
    v37 = (1880096896i64 * v33 + (unsigned __int64)HIDWORD(v36)) >> 32;
    v38 = 1880096896 * v33 + HIDWORD(v36);
    if ( (unsigned int)(v36 + HIDWORD(v35)) < HIDWORD(v35) )
      v37 = (__PAIR64__(v37, v38++) + 1) >> 32;
    LODWORD(v39) = v35 ^ v38;
    HIDWORD(v39) = (v36 + HIDWORD(v35)) ^ v37;
    _rt_udiv64(13i64, v39);
    v55 = v40;
    do
    {
      v41 = __mrc(15, 0, 9, 13, 0);
      v42 = v41 << 29;
      v43 = v41 ^ (v41 >> 3);
      v44 = 67117057i64 * (unsigned int)v43;
      v45 = 1880096896 * v43 + 67117057 * v42;
      v46 = (1880096896i64 * v42 + ((1880096896i64 * (unsigned int)v43 + 67117057 * (unsigned __int64)v42) >> 32)) >> 32;
      v47 = 1880096896 * v42 + ((1880096896i64 * (unsigned int)v43 + 67117057 * (unsigned __int64)v42) >> 32);
      if ( (unsigned int)(v45 + HIDWORD(v44)) < HIDWORD(v44) )
        v46 = (__PAIR64__(v46, v47++) + 1) >> 32;
      LODWORD(v48) = v44 ^ v47;
      HIDWORD(v48) = (v45 + HIDWORD(v44)) ^ v46;
      _rt_udiv64(6i64, v48);
    }
    while ( v56 && v49 == v56 );
    v31 = sub_931184(v55, v49, 2, a1, 0);
  }
  if ( v31 )
    v50 = 1;
  else
LABEL_26:
    v50 = 0;
  __disable_irq();
  if ( !KdDebuggerNotPresent )
  {
    while ( 1 )
      ;
  }
  __enable_irq();
  KiCacheRequiresLazyExecuteFlush = 0;
  __disable_irq();
  if ( !KdDebuggerNotPresent )
  {
    while ( 1 )
      ;
  }
  v51 = v57;
  __enable_irq();
  if ( v51 >= 0 )
    KdEnableDebugger();
  return v50;
}
