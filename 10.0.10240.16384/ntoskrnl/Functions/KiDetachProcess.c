// KiDetachProcess 
 
int __fastcall KiDetachProcess(int a1, int a2)
{
  unsigned int v4; // r4
  int v5; // r5
  int v6; // r0
  int v7; // r8
  unsigned int *v8; // r10
  unsigned int v9; // r2
  int result; // r0
  _DWORD *v11; // r0
  _DWORD *v12; // r1
  __int64 v13; // r2
  _DWORD *v14; // r3
  int v15; // r6
  unsigned int v16; // r3
  int v17; // r2
  int v18; // r1
  int v19; // r7
  int v20; // r10
  unsigned __int8 *v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // r0
  unsigned int v24; // r1
  unsigned int *v25; // r6
  unsigned int v26; // r2
  unsigned int v27; // r2
  unsigned int *v28; // r1
  unsigned int v29; // r3
  unsigned __int8 *v30; // r3
  unsigned int v31; // r2
  __int64 v32; // kr00_8
  unsigned int *v33; // r0
  unsigned int v34; // r2
  unsigned int v35; // r2
  unsigned int v36; // r2
  int v37; // [sp+4h] [bp-34h]
  unsigned int v38; // [sp+8h] [bp-30h]
  unsigned int v39; // [sp+14h] [bp-24h]

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_DWORD *)(v4 + 0x74);
  v6 = KfRaiseIrql(2);
  v7 = v6;
  v8 = (unsigned int *)(v4 + 44);
  while ( 1 )
  {
    do
      v9 = __ldrex(v8);
    while ( __strex(1u, v8) );
    __dmb(0xBu);
    if ( !v9 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v8 );
  }
  if ( *(_BYTE *)(v4 + 121) )
    return sub_50CCD4(v6, 1);
  if ( !*(_BYTE *)(v4 + 362)
    || (*(_BYTE *)(v4 + 120) & 1) != 0
    || (v11 = (_DWORD *)(v4 + 100), *(_DWORD *)(v4 + 100) != v4 + 100)
    || *(_DWORD *)(v4 + 108) != v4 + 108 )
  {
    KeBugCheck(6);
  }
  *(_DWORD *)(v4 + 76) |= 0x800u;
  v12 = (_DWORD *)(v4 + 372);
  if ( a1 == v4 + 372 )
  {
    *(_DWORD *)(v4 + 116) = *(_DWORD *)(v4 + 388);
    *(_BYTE *)(v4 + 120) = *(_BYTE *)(v4 + 392);
    *(_BYTE *)(v4 + 121) = *(_BYTE *)(v4 + 393);
    *(_BYTE *)(v4 + 122) = *(_BYTE *)(v4 + 394);
    LODWORD(v13) = *v12;
    if ( (_DWORD *)*v12 == v12 )
    {
      *v11 = v11;
      *(_DWORD *)(v4 + 104) = v4 + 100;
      *(_BYTE *)(v4 + 121) = 0;
    }
    else
    {
      HIDWORD(v13) = *(_DWORD *)(v4 + 376);
      *(_QWORD *)v11 = v13;
      *(_DWORD *)(v13 + 4) = v11;
      *(_DWORD *)HIDWORD(v13) = v11;
    }
    v14 = (_DWORD *)(v4 + 108);
    if ( *(_DWORD *)(v4 + 380) == v4 + 380 )
    {
      *v14 = v14;
      *(_DWORD *)(v4 + 112) = v4 + 108;
      *(_BYTE *)(v4 + 122) = 0;
    }
    else
    {
      v32 = *(_QWORD *)(v4 + 380);
      *(_QWORD *)(v4 + 108) = v32;
      *(_DWORD *)(v32 + 4) = v14;
      *(_DWORD *)HIDWORD(v32) = v14;
    }
    *(_DWORD *)(v4 + 388) = 0;
    *(_BYTE *)(v4 + 362) = 0;
  }
  else
  {
    KiMoveApcState(a1, v4 + 100);
  }
  __dmb(0xBu);
  *v8 = 0;
  v15 = *(_DWORD *)(v4 + 116);
  v37 = v15;
  v16 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v17 = *(unsigned __int8 *)(v16 + 2460);
  v18 = *(unsigned __int8 *)(v16 + 2461);
  __dmb(0xBu);
  v19 = 1 << (v18 & 7);
  v20 = (v18 >> 3) + 4 * (v17 + 24);
  v21 = (unsigned __int8 *)(v20 + v15);
  do
    v22 = __ldrex(v21);
  while ( __strex(v22 | v19, v21) );
  __dmb(0xBu);
  v23 = *(_DWORD *)(v15 + 28);
  v24 = *(_DWORD *)(v15 + 36);
  v39 = v23;
  v38 = v23 & 0xFFFFC000;
  v25 = (unsigned int *)&KiAsidTable[32 * v24];
  do
  {
    v26 = __ldrex(v25);
    v27 = v26 + 1;
  }
  while ( __strex(v27, v25) );
  if ( (v27 & 0xFFFFC000) != (v23 & 0xFFFFC000) )
  {
    v33 = (unsigned int *)&KiAsidTable[32 * v24];
    do
    {
      do
        v34 = __ldrex(v33);
      while ( __strex(v34 - 1, v33) );
      KiAsidAlloc(v37);
      v24 = *(_DWORD *)(v37 + 36);
      v33 = (unsigned int *)&KiAsidTable[32 * v24];
      do
      {
        v35 = __ldrex(v33);
        v36 = v35 + 1;
      }
      while ( __strex(v36, v33) );
    }
    while ( (v36 & 0xFFFFC000) != v38 );
    v23 = v39;
  }
  if ( KiAsidA9Errata )
  {
    __dsb(0xFu);
    __mcr(15, 0, 0xFFu, 13, 0, 1);
    __isb(0xFu);
    __mcr(15, 0, v23, 2, 0, 0);
    __isb(0xFu);
    __dsb(0xFu);
  }
  else
  {
    __mcr(15, 0, 0xFFu, 13, 0, 1);
    __isb(0xFu);
    __mcr(15, 0, v23, 2, 0, 0);
    __isb(0xFu);
  }
  __mcr(15, 0, v24, 13, 0, 1);
  __isb(0xFu);
  v28 = (unsigned int *)&KiAsidTable[32 * *(_DWORD *)(v5 + 36)];
  do
    v29 = __ldrex(v28);
  while ( __strex(v29 - 1, v28) );
  __dmb(0xBu);
  v30 = (unsigned __int8 *)(v20 + v5);
  do
    v31 = __ldrex(v30);
  while ( __strex(v31 & ~(_BYTE)v19, v30) );
  __dmb(0xBu);
  *(_DWORD *)(v4 + 76) &= 0xFFFFF7FF;
  result = KfLowerIrql(v7);
  if ( !a2 )
    result = KiDecrementProcessStackCount(v5);
  if ( *(_DWORD *)(v4 + 100) != v4 + 100 )
  {
    *(_BYTE *)(v4 + 121) = 1;
    result = HalRequestSoftwareInterrupt(1);
  }
  return result;
}
