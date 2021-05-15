// HvFreeCell 
 
unsigned int __fastcall HvFreeCell(int a1, unsigned int a2)
{
  unsigned int v2; // r7
  unsigned int v5; // r8
  int v6; // r0
  unsigned int v7; // r2
  _DWORD *v9; // r0
  _DWORD *v10; // r8
  unsigned int v11; // r0
  unsigned int v12; // r7
  _DWORD *v13; // r4
  _DWORD *v14; // r9
  _DWORD *v15; // r8
  char *v16; // r10
  int v17; // r10
  unsigned int v18; // r6
  int v19; // r3
  bool v20; // zf
  int v21; // r8
  int v22; // r0
  unsigned int *v23; // r4
  unsigned int v24; // r1
  _DWORD *v25; // r1
  int v26; // r2
  int v27; // r1
  _DWORD *v28; // r7
  int v29; // r2
  int v30; // r3
  char v31[4]; // [sp+8h] [bp-40h] BYREF
  _DWORD *v32; // [sp+Ch] [bp-3Ch] BYREF
  _DWORD *v33; // [sp+10h] [bp-38h]
  int v34; // [sp+14h] [bp-34h]
  char v35; // [sp+18h] [bp-30h] BYREF
  _DWORD v36[10]; // [sp+20h] [bp-28h] BYREF

  v32 = 0;
  v2 = *(_DWORD *)(a1 + 1868);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = KeAbPreAcquire(v2, 0, 0);
  do
    v7 = __ldrex((unsigned __int8 *)v2);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)v2) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    return sub_803758(v6);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  *(_DWORD *)(v2 + 4) = v5;
  v9 = (_DWORD *)HvpGetCellMap(a1, a2);
  v10 = v9;
  v33 = v9;
  if ( !v9 )
    KeBugCheckEx(81, 1, a1, a2, 1828);
  v34 = a2 >> 31;
  v11 = HvpMapEntryGetBinAddress((int)v9, v9, v31, &v32);
  v12 = v11;
  if ( (v10[1] & 4) != 0 )
    HvClearBinTrimStatus(a1, v11);
  v13 = (_DWORD *)(*v10 + (a2 & 0xFFF) + v12);
  v14 = v36;
  v15 = 0;
  *v13 = -*v13;
  v16 = &v35;
  do
  {
    if ( HvpIsFreeNeighbor(a1, v12, v13, &v32, a2 >> 31) != 1 )
      break;
    v25 = v32;
    v15 = (_DWORD *)((char *)v15 + 1);
    if ( v32 <= v13 )
    {
      v29 = *v32;
      *v14++ = a2 - *v32;
      v30 = *v13;
      *(_DWORD *)v16 = v29;
      v16 += 4;
      v13 = v25;
      *v25 = v30 + v29;
    }
    else
    {
      v26 = *v13;
      v27 = *v32;
      *v14++ = *v13 + a2;
      *v13 = v26 + v27;
      *(_DWORD *)v16 = v27;
      v16 += 4;
    }
  }
  while ( (unsigned int)v15 < 2 );
  v17 = v34;
  v32 = v15;
  v18 = 0;
  v19 = *(_DWORD *)(v12 + 4);
  v32 = v15;
  v20 = v15 == 0;
  v21 = (int)v33;
  v34 = v19 + (v34 << 31) - v12;
  if ( !v20 )
  {
    v28 = v32;
    do
      HvpRemoveFreeCellHint(a1, v36[v18++]);
    while ( v18 < (unsigned int)v28 );
    v21 = (int)v33;
  }
  v22 = HvpEnlistFreeCell(a1, (char *)v13 + v34, *v13, v17, 1);
  if ( v31[0] )
    HvpMapEntryReleaseBinAddress(v22, v21);
  v23 = *(unsigned int **)(a1 + 1868);
  v23[1] = 0;
  __dmb(0xBu);
  do
    v24 = __ldrex(v23);
  while ( !v24 && __strex(1u, v23) );
  if ( v24 )
    ExpReleaseFastMutexContended(v23, v24);
  return KeAbPostRelease((unsigned int)v23);
}
