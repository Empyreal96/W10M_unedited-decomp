// MiMapNewWorkingSetPage 
 
int __fastcall MiMapNewWorkingSetPage(int a1, unsigned int a2)
{
  int v2; // r7
  unsigned int v3; // r4
  char *v4; // r1
  int v6; // r2
  _DWORD *v7; // t1
  int v8; // r6
  unsigned int v9; // r0
  int v10; // r2
  int v11; // r3
  int v12; // r0
  int v13; // r9
  int v14; // r10
  int v15; // r0
  unsigned int v16; // r3
  unsigned int v17; // r2
  int v18; // r3
  int v19; // r6
  int v21; // r0
  int v22; // r0
  int v23; // r0
  unsigned int *v24; // r2
  unsigned int v25; // r0
  unsigned int *v26; // r2
  unsigned int v27; // r0
  int v28; // [sp+0h] [bp-30h]
  char v29; // [sp+4h] [bp-2Ch] BYREF
  _WORD *v30; // [sp+8h] [bp-28h] BYREF
  unsigned __int16 v31; // [sp+Ch] [bp-24h]
  unsigned __int16 v32; // [sp+Eh] [bp-22h]

  v2 = 1;
  v3 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v4 = &v29;
  v6 = 1;
  v28 = ((v3 >> 10) & 0x3FFFFC) - 0x40000000;
  while ( 1 )
  {
    v7 = (_DWORD *)*((_DWORD *)v4 - 1);
    v4 -= 4;
    --v6;
    if ( (*v7 & 2) == 0 )
      break;
    if ( !v6 )
      goto LABEL_4;
  }
  v2 = v6 + 2;
LABEL_4:
  v8 = 0;
  if ( (*(_BYTE *)(a1 + 112) & 7u) >= 2 || *(_DWORD *)(a1 + 72) >= (unsigned int)(*(_DWORD *)(a1 + 76) + v2) )
  {
    v8 = 8;
  }
  else
  {
    if ( !MiChargeCommit(&MiSystemPartition, 1, 1) )
      goto LABEL_39;
    if ( !MiChargeResident(&MiSystemPartition, 1, 128) )
      JUMPOUT(0x5104CC);
    do
      v9 = __ldrex(&dword_634A2C[4]);
    while ( __strex(v9 + 1, &dword_634A2C[4]) );
  }
  MI_INITIALIZE_COLOR_BASE(a1, 0, &v30);
  v10 = (unsigned __int16)(*v30 + 1);
  v11 = v31;
  *v30 = v10;
  v12 = MiGetPage(&MiSystemPartition, v10 & v11 | v32, 194);
  v28 = v12;
  if ( v12 == -1 )
  {
LABEL_31:
    if ( !v8 )
      return sub_5104B4(v12);
LABEL_39:
    JUMPOUT(0x5104D4);
  }
  v13 = 3 * v12;
  v14 = MmPfnDatabase;
  if ( !MiMakeZeroedPageTables(v3, v3, v8 | 0x40) )
  {
    v12 = MiReleaseFreshPage(v14 + 8 * v13);
    goto LABEL_31;
  }
  v30 = (_WORD *)(v3 + 0x40000000);
  if ( v3 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)v3 = 128;
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v3 = 128;
    if ( v3 + 1070596096 <= 0xFFF )
    {
      v22 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v22, v22 + 4 * (v3 & 0xFFF), 128);
    }
  }
  MiInitializePfn(v14 + 8 * v13, v3, 4, 16);
  if ( (*(_BYTE *)(a1 + 112) & 7u) >= 2 )
  {
    v21 = MiDetermineUserGlobalPteMask(v3);
    v16 = (dword_681120 & 0x3ED | (v28 << 12) | v21) & 0xFFFFF3FF;
  }
  else
  {
    v15 = MiDetermineUserGlobalPteMask(v3);
    v16 = dword_681120 & 0xFED | (v28 << 12) | v15;
  }
  v17 = (v16 | 0x12) & 0xFFFFFDFF;
  if ( (unsigned int)v30 > 0x3FFFFF )
  {
    *(_DWORD *)v3 = v17;
  }
  else
  {
    v18 = *(_DWORD *)v3;
    v19 = 0;
    __dmb(0xBu);
    if ( (v18 & 2) == 0 )
      v19 = 1;
    *(_DWORD *)v3 = v17;
    if ( v3 + 1070596096 <= 0xFFF )
    {
      v23 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v23, v23 + 4 * (v3 & 0xFFF), v17);
    }
    if ( v19 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  if ( (*(_BYTE *)(a1 + 112) & 7) == 1 )
  {
    v24 = (unsigned int *)(a1 - 3220);
    do
      v25 = __ldrex(v24);
    while ( __strex(v25 + 1, v24) );
    v26 = (unsigned int *)(a1 - 3216);
    do
      v27 = __ldrex(v26);
    while ( __strex(v27 + 1, v26) );
  }
  else
  {
    *(_DWORD *)(a1 + 76) += v2;
  }
  return 1;
}
