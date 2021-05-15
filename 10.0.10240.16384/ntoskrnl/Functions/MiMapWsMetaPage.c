// MiMapWsMetaPage 
 
int __fastcall MiMapWsMetaPage(int a1, unsigned int a2)
{
  unsigned int v3; // r4
  int result; // r0
  unsigned int v5; // r3
  __int16 v6; // r1
  int v7; // r0
  int v8; // r10
  _WORD *v9; // r7
  int v10; // r3
  int v11; // r2
  char *v12; // r1
  int v13; // r9
  _DWORD *v14; // t1
  unsigned int v15; // r2
  int v16; // r3
  int v17; // r5
  unsigned int v18; // r0
  int v19; // r0
  int v20; // r0
  _WORD *v21; // [sp+0h] [bp-30h] BYREF
  __int16 v22; // [sp+4h] [bp-2Ch]
  unsigned __int16 v23; // [sp+6h] [bp-2Ah]
  unsigned int v24; // [sp+8h] [bp-28h]
  unsigned int v25; // [sp+Ch] [bp-24h]
  char v26; // [sp+10h] [bp-20h] BYREF

  if ( (*(_BYTE *)(a1 + 115) & 2) != 0
    || (v3 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000, !MiChargeCommit((int)MiSystemPartition, 1u, 1)) )
  {
    JUMPOUT(0x53DADA);
  }
  if ( !MiChargeResident(MiSystemPartition, 1, 128) )
    return sub_53DACC();
  do
    v5 = __ldrex(&dword_634A04[9]);
  while ( __strex(v5 + 1, &dword_634A04[9]) );
  MI_INITIALIZE_COLOR_BASE(a1, 0, &v21);
  v6 = *v21 + 1;
  *v21 = v6;
  v7 = MiGetPage((int)MiSystemPartition, (unsigned __int16)(v6 & v22) | v23, 2);
  v8 = v7;
  if ( v7 == -1 )
  {
LABEL_27:
    MiReturnResidentAvailable(1);
    do
      v18 = __ldrex(&dword_634A2C[8]);
    while ( __strex(v18 + 1, &dword_634A2C[8]) );
    MiReturnCommit(MiSystemPartition, 1);
    result = 0;
  }
  else
  {
    v9 = (_WORD *)(MmPfnDatabase + 24 * v7);
    v10 = *((_DWORD *)v9 + 2);
    v21 = v9;
    if ( v10 )
    {
      MiZeroPhysicalPage(v7, 1, 1);
      *((_DWORD *)v9 + 2) = 0;
    }
    v11 = 2;
    v12 = &v26;
    v24 = v3;
    v25 = ((v3 >> 10) & 0x3FFFFC) - 0x40000000;
    v13 = 1;
    while ( 1 )
    {
      v14 = (_DWORD *)*((_DWORD *)v12 - 1);
      v12 -= 4;
      --v11;
      if ( (*v14 & 2) == 0 )
        break;
      if ( v11 == 1 )
        goto LABEL_12;
    }
    v13 = v11 + 1;
    if ( (unsigned int)(v11 + 1) > 1 && !MiMakeZeroedPageTables(v3, v3, 64) )
    {
      MiReleaseFreshPage(v9);
      goto LABEL_27;
    }
LABEL_12:
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
        v19 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v19, (_DWORD *)(v19 + 4 * (v3 & 0xFFF)), 128);
      }
    }
    MiInitializePfn(v21, v3, 4, 16);
    v15 = (dword_681120 & 0xDED | (v8 << 12) | MiDetermineUserGlobalPteMask(v3)) & 0xFFFFFDFF | 0x12;
    if ( v3 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v3 = v15;
    }
    else
    {
      v16 = *(_DWORD *)v3;
      v17 = 0;
      __dmb(0xBu);
      if ( (v16 & 2) == 0 )
        v17 = 1;
      *(_DWORD *)v3 = v15;
      if ( v3 + 1070596096 <= 0xFFF )
      {
        v20 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v20, (_DWORD *)(v20 + 4 * (v3 & 0xFFF)), v15);
      }
      if ( v17 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    result = v13;
  }
  return result;
}
