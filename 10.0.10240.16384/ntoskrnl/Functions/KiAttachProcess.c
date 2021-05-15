// KiAttachProcess 
 
int __fastcall KiAttachProcess(int a1, int a2, int a3, int a4, int a5)
{
  int v9; // r1
  _DWORD *v10; // r3
  unsigned int *v11; // r2
  unsigned int v12; // r0
  int v13; // r5
  unsigned int v14; // r3
  int v15; // r2
  int v16; // r1
  int v17; // r10
  int v18; // lr
  unsigned __int8 *v19; // r1
  unsigned int v20; // r0
  unsigned int v21; // r4
  unsigned int v22; // r1
  unsigned int *v23; // r7
  unsigned int v24; // r2
  unsigned int v25; // r2
  unsigned int *v26; // r1
  unsigned int v27; // r0
  unsigned __int8 *v28; // r3
  unsigned int v29; // r2
  unsigned int *v31; // r5
  int v32; // r0
  unsigned int v33; // r2
  _DWORD *v34; // r3
  unsigned int *v35; // r0
  unsigned int v36; // r2
  unsigned int v37; // r2
  unsigned int v38; // r2
  __int64 v39; // kr00_8

  *(_DWORD *)(a5 + 16) = *(_DWORD *)(a1 + 116);
  *(_BYTE *)(a5 + 20) = *(_BYTE *)(a1 + 120);
  *(_BYTE *)(a5 + 21) = *(_BYTE *)(a1 + 121);
  *(_BYTE *)(a5 + 22) = *(_BYTE *)(a1 + 122);
  v9 = *(_DWORD *)(a1 + 100);
  if ( v9 == a1 + 100 )
  {
    *(_DWORD *)a5 = a5;
    *(_DWORD *)(a5 + 4) = a5;
    *(_BYTE *)(a5 + 21) = 0;
  }
  else
  {
    v34 = *(_DWORD **)(a1 + 104);
    *(_DWORD *)a5 = v9;
    *(_DWORD *)(a5 + 4) = v34;
    *(_DWORD *)(v9 + 4) = a5;
    *v34 = a5;
  }
  v10 = (_DWORD *)(a5 + 8);
  if ( *(_DWORD *)(a1 + 108) == a1 + 108 )
  {
    *v10 = v10;
    *(_DWORD *)(a5 + 12) = a5 + 8;
    *(_BYTE *)(a5 + 22) = 0;
  }
  else
  {
    v39 = *(_QWORD *)(a1 + 108);
    *(_QWORD *)(a5 + 8) = v39;
    *(_DWORD *)(v39 + 4) = v10;
    *(_DWORD *)HIDWORD(v39) = v10;
  }
  *(_DWORD *)(a1 + 100) = a1 + 100;
  *(_DWORD *)(a1 + 104) = a1 + 100;
  *(_DWORD *)(a1 + 108) = a1 + 108;
  *(_DWORD *)(a1 + 112) = a1 + 108;
  *(_BYTE *)(a1 + 120) = 0;
  *(_BYTE *)(a1 + 121) = 0;
  *(_BYTE *)(a1 + 122) = 0;
  if ( a5 == a1 + 372 )
    *(_BYTE *)(a1 + 362) = 1;
  if ( !a4 )
  {
    __dmb(0xBu);
    v11 = (unsigned int *)(a2 + 116);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 + 8, v11) );
    __dmb(0xBu);
    if ( (v12 & 7) != 0 )
    {
      __dmb(0xBu);
      v31 = (unsigned int *)(a1 + 44);
      *(_DWORD *)(a1 + 44) = 0;
      KiInSwapSingleProcess(a1, a2, a3);
      v32 = KfRaiseIrql(2);
      do
        v33 = __ldrex(v31);
      while ( __strex(1u, v31) );
      __dmb(0xBu);
      if ( v33 )
        return sub_50CE50(v32, 1);
    }
  }
  *(_DWORD *)(a1 + 76) |= 0x800u;
  *(_DWORD *)(a1 + 116) = a2;
  __dmb(0xBu);
  *(_DWORD *)(a1 + 44) = 0;
  v13 = *(_DWORD *)(a5 + 16);
  v14 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v15 = *(unsigned __int8 *)(v14 + 2460);
  v16 = *(unsigned __int8 *)(v14 + 2461);
  __dmb(0xBu);
  v17 = 1 << (v16 & 7);
  v18 = (v16 >> 3) + 4 * (v15 + 24);
  v19 = (unsigned __int8 *)(v18 + a2);
  do
    v20 = __ldrex(v19);
  while ( __strex(v20 | v17, v19) );
  __dmb(0xBu);
  v21 = *(_DWORD *)(a2 + 28);
  v22 = *(_DWORD *)(a2 + 36);
  v23 = (unsigned int *)&KiAsidTable[32 * v22];
  do
  {
    v24 = __ldrex(v23);
    v25 = v24 + 1;
  }
  while ( __strex(v25, v23) );
  if ( (v25 & 0xFFFFC000) != (v21 & 0xFFFFC000) )
  {
    v35 = (unsigned int *)&KiAsidTable[32 * v22];
    do
    {
      do
        v36 = __ldrex(v35);
      while ( __strex(v36 - 1, v35) );
      KiAsidAlloc(a2);
      v22 = *(_DWORD *)(a2 + 36);
      v35 = (unsigned int *)&KiAsidTable[32 * v22];
      do
      {
        v37 = __ldrex(v35);
        v38 = v37 + 1;
      }
      while ( __strex(v38, v35) );
    }
    while ( (v38 & 0xFFFFC000) != (v21 & 0xFFFFC000) );
  }
  if ( KiAsidA9Errata )
  {
    __dsb(0xFu);
    __mcr(15, 0, 0xFFu, 13, 0, 1);
    __isb(0xFu);
    __mcr(15, 0, v21, 2, 0, 0);
    __isb(0xFu);
    __dsb(0xFu);
  }
  else
  {
    __mcr(15, 0, 0xFFu, 13, 0, 1);
    __isb(0xFu);
    __mcr(15, 0, v21, 2, 0, 0);
    __isb(0xFu);
  }
  __mcr(15, 0, v22, 13, 0, 1);
  __isb(0xFu);
  v26 = (unsigned int *)&KiAsidTable[32 * *(_DWORD *)(v13 + 36)];
  do
    v27 = __ldrex(v26);
  while ( __strex(v27 - 1, v26) );
  __dmb(0xBu);
  v28 = (unsigned __int8 *)(v18 + v13);
  do
    v29 = __ldrex(v28);
  while ( __strex(v29 & ~(_BYTE)v17, v28) );
  __dmb(0xBu);
  *(_DWORD *)(a1 + 76) &= 0xFFFFF7FF;
  return KfLowerIrql(a3);
}
