// MiResolveFileOnlyFault 
 
int __fastcall MiResolveFileOnlyFault(unsigned int a1)
{
  unsigned int v2; // r6
  unsigned int v3; // r3
  int v4; // r7
  int v5; // r2
  int v7; // r9
  int v8; // r4
  int v9; // r1
  unsigned __int8 *v10; // r0
  unsigned int v11; // r2
  int v12; // r3
  unsigned int *v13; // r2
  unsigned int v14; // r0
  unsigned int v15; // r0
  char v16; // r10
  int v17; // r4
  unsigned __int8 *v18; // r1
  unsigned int v19; // r2
  int v20; // r3
  int v21; // r3
  int v22; // r6
  int v23; // r0
  unsigned int v24; // r7
  unsigned int v25; // r3
  int v26; // r6
  int v27; // r0
  unsigned int *v28; // r2
  unsigned int v29; // r0
  int v30; // [sp+0h] [bp-20h]

  v2 = *(_DWORD *)a1;
  v3 = *(_DWORD *)a1 & 0xFFFFF800;
  v4 = v3 | (2 * (*(_DWORD *)a1 & 0x3FC));
  v5 = *(_DWORD *)(v4 + 0xC);
  if ( !v5 )
    return -1073532109;
  v7 = *(_DWORD *)(v5 + 4 * ((int)(a1 - *(_DWORD *)((v3 | (2 * (*(_DWORD *)a1 & 0x3FC))) + 4)) >> 2) + 4);
  if ( v7 < 0 )
    return -1073532109;
  v8 = *(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000) >> 12;
  v30 = v8;
  MiReferenceControlAreaPfn(*(_DWORD **)v4, v4, 1);
  v9 = MmPfnDatabase + 24 * v8;
  v10 = (unsigned __int8 *)(v9 + 15);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 0x80, v10) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v11 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v12 = *(_DWORD *)(v9 + 12);
      __dmb(0xBu);
    }
    while ( (v12 & 0x80000000) != 0 );
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
  }
  *(_DWORD *)(v9 + 12) = *(_DWORD *)(v9 + 12) & 0xC0000000 | (*(_DWORD *)(v9 + 12) + 1) & 0x3FFFFFFF;
  __dmb(0xBu);
  v13 = (unsigned int *)(v9 + 12);
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 & 0x7FFFFFFF, v13) );
  v15 = MiGetEffectivePagePriorityThread((_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0));
  v16 = v15;
  if ( v15 > 5 )
    v16 = 5;
  v17 = MmPfnDatabase + 24 * v7;
  v18 = (unsigned __int8 *)(v17 + 15);
  do
    v19 = __ldrex(v18);
  while ( __strex(v19 | 0x80, v18) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v19 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v20 = *(_DWORD *)(v17 + 12);
      __dmb(0xBu);
    }
    while ( (v20 & 0x80000000) != 0 );
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 | 0x80, v18) );
  }
  *(_DWORD *)v17 = 0;
  *(_WORD *)(v17 + 16) = 1;
  v21 = *(_DWORD *)(v17 + 12);
  *(_DWORD *)(v17 + 8) = v2;
  *(_DWORD *)(v17 + 12) = v21 & 0xC0000000 | 1;
  *(_DWORD *)(v17 + 20) = *(_DWORD *)(v17 + 20) & 0xFFF00000 | v30 & 0xFFFFF | 0x8000000;
  if ( (v2 & 0x400) != 0 )
    v22 = (*(unsigned __int16 *)(v4 + 16) >> 1) & 0x1F;
  else
    v22 = (v2 >> 5) & 0x1F;
  v23 = MiDetermineUserGlobalPteMask(a1);
  *(_DWORD *)(v17 + 4) = a1;
  v24 = (MmProtectToPteMask[v22] & 0x3ED | (v7 << 12) | v23) & 0xFFFFF3FF | 0x12;
  *(_BYTE *)(v17 + 19) ^= (*(_BYTE *)(v17 + 19) ^ v16) & 7;
  if ( a1 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)a1 = v24;
  }
  else
  {
    v25 = *(_DWORD *)a1;
    v26 = 0;
    __dmb(0xBu);
    if ( (v25 & 2) == 0 )
      v26 = 1;
    *(_DWORD *)a1 = v24;
    if ( a1 + 1070596096 <= 0xFFF )
    {
      v27 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v27, (_DWORD *)(v27 + 4 * (a1 & 0xFFF)), v24);
    }
    if ( v26 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  *(_BYTE *)(v17 + 18) = *(_BYTE *)(v17 + 18) & 0xF8 | 6;
  __dmb(0xBu);
  v28 = (unsigned int *)(v17 + 12);
  do
    v29 = __ldrex(v28);
  while ( __strex(v29 & 0x7FFFFFFF, v28) );
  return 0;
}
