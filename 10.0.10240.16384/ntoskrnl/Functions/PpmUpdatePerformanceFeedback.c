// PpmUpdatePerformanceFeedback 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PpmUpdatePerformanceFeedback(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v7; // r10
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r3
  int v11; // r2
  int v12; // r1
  unsigned int v14; // r2
  unsigned __int64 *v15; // r3
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // kr08_8
  unsigned int v18; // r5
  int v19; // r6
  int v20; // r0
  int v21; // r2
  unsigned __int64 v22; // r6
  __int64 v23; // kr10_8
  unsigned int v24; // r1
  unsigned int v25; // r0
  __int64 v26; // r6
  __int64 v27; // kr18_8
  __int64 v28; // kr20_8
  unsigned int v29; // r7 OVERLAPPED
  unsigned int v30; // r8 OVERLAPPED
  unsigned int v31; // r5
  unsigned int v32; // r4
  unsigned __int64 v33; // r2
  __int64 v34; // r0
  int v35; // r0
  unsigned int v36; // r2
  unsigned __int64 v37; // kr30_8
  int v39; // [sp+8h] [bp-50h] BYREF
  unsigned int v40; // [sp+Ch] [bp-4Ch]
  int v41; // [sp+10h] [bp-48h]
  __int64 v42; // [sp+14h] [bp-44h]
  unsigned __int64 v43; // [sp+1Ch] [bp-3Ch]
  int v44; // [sp+24h] [bp-34h]
  __int64 v45; // [sp+28h] [bp-30h] BYREF
  __int64 v46; // [sp+30h] [bp-28h] BYREF

  v4 = a2;
  v44 = a1;
  v7 = a1 + 3008;
  if ( !a2 )
  {
    if ( !*(_QWORD *)(a1 + 3056)
      && (!*(_QWORD *)(a1 + 3080)
       || *(_DWORD *)(a1 + 2312) == *(_DWORD *)(a1 + 3096) && *(_DWORD *)(a1 + 2308) == *(_DWORD *)(a1 + 3100)) )
    {
      return 1;
    }
    v4 = 0;
  }
  v8 = 0;
  v9 = 2;
  v10 = 0;
  v11 = v7;
  do
  {
    v12 = *(_DWORD *)(v11 + 24);
    if ( v12 )
    {
      if ( *(_BYTE *)(v12 + 32) )
      {
        if ( a3 )
          return sub_541F3C(v8);
        v8 = 1;
      }
      if ( v9 == 2 )
        v9 = v10;
    }
    ++v10;
    v11 += 4;
  }
  while ( v10 < 2 );
  if ( !v8 && a4 && !v4 )
    return 1;
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v41 = 0;
  }
  else
  {
    v41 = 1;
    __disable_irq();
  }
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v7);
  }
  else
  {
    do
      v14 = __ldrex((unsigned int *)v7);
    while ( __strex(1u, (unsigned int *)v7) );
    __dmb(0xBu);
    if ( v14 )
      KxWaitForSpinLockAndAcquire(v7);
  }
  __dmb(0xBu);
  v15 = (unsigned __int64 *)(v7 + 48);
  do
    v16 = __ldrexd(v15);
  while ( __strexd(0i64, v15) );
  v43 = v16;
  __dmb(0xBu);
  v17 = *(_QWORD *)(v7 + 40) + v16;
  v18 = 0;
  v40 = 0;
  *(_QWORD *)(v7 + 40) = v17;
  do
  {
    v19 = *(_DWORD *)(v7 + 4 * v18 + 24);
    if ( v19 )
    {
      v20 = *(_DWORD *)(v19 + 36);
      if ( *(_BYTE *)(v19 + 33) )
      {
        (*(void (__fastcall **)(int, int, __int64 *, __int64 *))v19)(v20, a2, &v45, &v46);
        v42 = *(_QWORD *)(v19 + 16);
        if ( v45 != v42 )
        {
          LODWORD(v34) = v45 - v42;
          *(_QWORD *)&v29 = *(_QWORD *)(v19 + 8);
          HIDWORD(v34) = *(unsigned __int8 *)(v19 + 34);
          v45 -= v42;
          v28 = v45;
          v32 = (v46 - __PAIR64__(v30, v29)) >> 32;
          LODWORD(v46) = v46 - v29;
          v31 = v46;
          v33 = __PAIR64__(v32, v46) * HIDWORD(v34);
          HIDWORD(v46) = v32;
          HIDWORD(v34) = HIDWORD(v45);
          if ( !v45 )
            __brkdiv0();
          v35 = _rt_udiv64(v34, v33);
          v36 = HIDWORD(v42);
          *(_DWORD *)(v19 + 24) = v35;
          HIDWORD(v16) = HIDWORD(v43);
          *(_QWORD *)(v19 + 16) = __PAIR64__(v36, v42) + v28;
          v37 = __PAIR64__(v30, v29) + __PAIR64__(v32, v31);
          v18 = v40;
          LODWORD(v16) = v43;
          *(_QWORD *)(v19 + 8) = v37;
        }
        v21 = *(_DWORD *)(v19 + 24);
        v39 = v21;
      }
      else
      {
        (*(void (__fastcall **)(int, int *))v19)(v20, &v39);
        v21 = v39;
      }
      v22 = v16 * (unsigned int)v21;
      *(_QWORD *)(v7 + 8 * v18 + 56) += v22;
      if ( v18 == *(unsigned __int8 *)(v7 + 96) )
        *(_QWORD *)(v7 + 72) += v22;
    }
    v40 = ++v18;
  }
  while ( v18 < 2 );
  if ( *(_BYTE *)(v7 + 96) == 2 )
    *(_QWORD *)(v7 + 72) += 100 * v16;
  v23 = *(_QWORD *)(v7 + 88);
  v24 = *(_DWORD *)(v44 + 2308) - HIDWORD(v23);
  v25 = v24 + *(_DWORD *)(v44 + 2312) - v23;
  if ( v25 )
  {
    *(_DWORD *)(v7 + 88) = *(_DWORD *)(v44 + 2312);
    v26 = *(_QWORD *)(v7 + 72);
    *(_DWORD *)(v7 + 92) = HIDWORD(v23) + v24;
    *(_DWORD *)(v7 + 72) = 0;
    *(_DWORD *)(v7 + 76) = 0;
    if ( v24 )
    {
      v27 = *(_QWORD *)(v7 + 80);
      v39 = v24 / v25;
      *(_QWORD *)(v7 + 80) = v26 * (v24 / v25) + v27;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v7);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v7 = 0;
  }
  if ( v41 )
    __enable_irq();
  return 1;
}
