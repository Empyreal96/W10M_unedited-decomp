// SwapContext 
 
int __fastcall SwapContext(int a1, int a2, char a3, int a4)
{
  __int64 v4; // d0
  __int64 v5; // d1
  __int64 v6; // d2
  __int64 v7; // d3
  __int64 v8; // d4
  __int64 v9; // d5
  __int64 v10; // d6
  __int64 v11; // d7
  __int64 v12; // d8
  __int64 v13; // d9
  __int64 v14; // d10
  __int64 v15; // d11
  __int64 v16; // d12
  __int64 v17; // d13
  __int64 v18; // d14
  __int64 v19; // d15
  __int64 v20; // d16
  __int64 v21; // d17
  __int64 v22; // d18
  __int64 v23; // d19
  __int64 v24; // d20
  __int64 v25; // d21
  __int64 v26; // d22
  __int64 v27; // d23
  __int64 v28; // d24
  __int64 v29; // d25
  __int64 v30; // d26
  __int64 v31; // d27
  __int64 v32; // d28
  __int64 v33; // d29
  __int64 v34; // d30
  __int64 v35; // d31
  int i; // r0
  int v39; // r5
  int v40; // r1
  int v41; // r0
  int v42; // r2
  unsigned __int64 *v49; // r2
  unsigned __int64 v50; // kr00_8
  unsigned __int64 v51; // r0
  __int64 v52; // r2
  __int64 v53; // r0
  unsigned int *v54; // r0
  int v55; // r7
  unsigned int v56; // r2
  int v57; // r7
  unsigned int *v58; // r1
  unsigned int v59; // r2
  unsigned int v60; // r0
  int v61; // r1
  int v63; // [sp+0h] [bp-10h] BYREF

  LOBYTE(v63) = a3;
  *(_DWORD *)(a1 + 1080) = __mrc(15, 0, 13, 0, 2);
  for ( i = *(unsigned __int8 *)(a2 + 73); *(_BYTE *)(a2 + 73); i = *(unsigned __int8 *)(a2 + 73) )
    __yield();
  v39 = a2 + i;
  *(_BYTE *)(v39 + 73) = 1;
  __disable_irq();
  __mcr(15, 0, (a2 + i) | 2, 13, 0, 3);
  v40 = *(unsigned __int8 *)(a1 + 133);
  v41 = *(unsigned __int8 *)(v39 + 133);
  if ( *(_BYTE *)(a1 + 133) )
  {
    v42 = *(_DWORD *)(a1 + 320);
    __asm { VMRS            R3, FPSCR }
    *(_DWORD *)(v42 + 4) = _R3;
    v42 += 16;
    *(_QWORD *)v42 = v4;
    *(_QWORD *)(v42 + 8) = v5;
    *(_QWORD *)(v42 + 16) = v6;
    *(_QWORD *)(v42 + 24) = v7;
    *(_QWORD *)(v42 + 32) = v8;
    *(_QWORD *)(v42 + 40) = v9;
    *(_QWORD *)(v42 + 48) = v10;
    *(_QWORD *)(v42 + 56) = v11;
    *(_QWORD *)(v42 + 64) = v12;
    *(_QWORD *)(v42 + 72) = v13;
    *(_QWORD *)(v42 + 80) = v14;
    *(_QWORD *)(v42 + 88) = v15;
    *(_QWORD *)(v42 + 96) = v16;
    *(_QWORD *)(v42 + 104) = v17;
    *(_QWORD *)(v42 + 112) = v18;
    *(_QWORD *)(v42 + 120) = v19;
    v42 += 128;
    *(_QWORD *)v42 = v20;
    *(_QWORD *)(v42 + 8) = v21;
    *(_QWORD *)(v42 + 16) = v22;
    *(_QWORD *)(v42 + 24) = v23;
    *(_QWORD *)(v42 + 32) = v24;
    *(_QWORD *)(v42 + 40) = v25;
    *(_QWORD *)(v42 + 48) = v26;
    *(_QWORD *)(v42 + 56) = v27;
    *(_QWORD *)(v42 + 64) = v28;
    *(_QWORD *)(v42 + 72) = v29;
    *(_QWORD *)(v42 + 80) = v30;
    *(_QWORD *)(v42 + 88) = v31;
    *(_QWORD *)(v42 + 96) = v32;
    *(_QWORD *)(v42 + 104) = v33;
    *(_QWORD *)(v42 + 112) = v34;
    *(_QWORD *)(v42 + 120) = v35;
  }
  if ( v41 )
  {
    if ( !v40 )
    {
      __mcr(15, 0, __mrc(15, 0, 1, 0, 2) | 0xF00000, 1, 0, 2);
      __isb(0xFu);
    }
    _R0 = *(_DWORD *)(*(_DWORD *)(v39 + 320) + 4) & 0xFFC8FFFF;
    __asm { VMSR            FPSCR, R0 }
  }
  else if ( v40 )
  {
    __mcr(15, 0, __mrc(15, 0, 1, 0, 2) & 0xFF0FFFFF, 1, 0, 2);
    __isb(0xFu);
  }
  v49 = (unsigned __int64 *)(a4 + 2416);
  do
  {
    v50 = __ldrexd(v49);
    v51 = __PAIR64__(HIDWORD(v50), __mrc(15, 0, 9, 13, 0));
    if ( ((v50 ^ v51) & 0x80000000) != 0i64 )
      HIDWORD(v51) = HIDWORD(v50) + ((unsigned int)v50 >> 31);
  }
  while ( __strexd(v51, v49) );
  v52 = *(_QWORD *)(a4 + 2376);
  *(_QWORD *)(a4 + 2376) = v51;
  v53 = v51 - v52;
  *(_QWORD *)(a4 + 2744) += v53;
  if ( (*(_BYTE *)(v39 + 2) & 0x36) != 0 )
  {
    KiBeginThreadAccountingPeriod(a4, v39, v53, HIDWORD(v53));
  }
  else
  {
    --*(_BYTE *)(a4 + 16);
    __enable_irq();
  }
  ++*(_DWORD *)(a4 + 1588);
  *(_DWORD *)(a1 + 64) = &v63;
  v54 = *(unsigned int **)(v39 + 116);
  if ( v54 != *(unsigned int **)(a1 + 116) )
  {
    v55 = 1 << *(_BYTE *)(a4 + 1053);
    do
      v56 = __ldrex(v54);
    while ( __strex(v56 | v55, v54 + 24) == 1 );
    KxSwapProcess();
    v57 = 1 << *(_BYTE *)(a4 + 1053);
    do
    {
      v58 = *(unsigned int **)(a1 + 116);
      v59 = __ldrex(v58);
    }
    while ( __strex(v59 & ~v57, v58 + 24) == 1 );
  }
  *(_DWORD *)(a4 + 1732) = *(_DWORD *)(v39 + 32);
  if ( (dword_682604 & 4) != 0 )
    EtwTraceContextSwap(a1, v39);
  __dmb(0xBu);
  *(_BYTE *)(a1 + 73) = 0;
  v60 = *(_DWORD *)(v39 + 156);
  *(_DWORD *)(a4 - 1384) = v60;
  if ( !v60 )
    v60 = *(_DWORD *)(v39 + 1080);
  __mcr(15, 0, v60, 13, 0, 2);
  if ( (*(_DWORD *)(a4 + 1756) & 0x10001) != 0 )
  {
    v63 = 0;
    KeBugCheckEx(184, a1, v39);
  }
  ++*(_DWORD *)(v39 + 128);
  v61 = *(unsigned __int8 *)(v39 + 121);
  if ( v61 == 1 )
  {
    v61 = 1;
    if ( *(unsigned __int16 *)(v39 + 310) | (unsigned __int8)v63 )
    {
      KiRequestSoftwareInterrupt(a4, 1);
      v61 = 0;
    }
  }
  return v61;
}
