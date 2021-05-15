// MiPfnShareCountIsZero 
 
int __fastcall MiPfnShareCountIsZero(int a1, unsigned int a2)
{
  int v3; // r0
  int v5; // r2
  int v6; // r3
  bool v7; // zf
  int v8; // r3
  int v9; // r1
  int result; // r0
  unsigned int v11; // r2
  int v12; // r7
  int v13; // r0
  int v14; // lr
  int v15; // r1
  unsigned int v16; // r1
  unsigned int *v17; // r1
  unsigned int v18; // r3
  int v19; // r9
  unsigned int v20; // r9
  unsigned int v21; // r2
  int v22; // lr
  unsigned int v23; // r9
  int v24; // r7
  unsigned int v25; // lr
  int v26; // r7
  int v27; // r1
  char v28; // r3
  char v29; // r3
  int v30; // r3
  char v31; // r3
  int v32; // r0
  int v33; // r0
  int v34; // r0
  unsigned int v35; // [sp+0h] [bp-D0h]
  unsigned int v36; // [sp+4h] [bp-CCh]
  unsigned int v37; // [sp+10h] [bp-C0h]
  int v38; // [sp+18h] [bp-B8h] BYREF
  char v39; // [sp+1Ch] [bp-B4h]
  char v40; // [sp+1Dh] [bp-B3h]
  int v41; // [sp+20h] [bp-B0h]
  int v42; // [sp+24h] [bp-ACh]
  int v43; // [sp+28h] [bp-A8h]
  int v44; // [sp+2Ch] [bp-A4h]

  v3 = *(_DWORD *)(a1 + 20);
  if ( (v3 & 0x8000000) != 0 )
  {
    v11 = *(_DWORD *)(a1 + 8);
    if ( (v11 & 0x400) != 0 )
      v12 = (*(unsigned __int16 *)((*(_DWORD *)(a1 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(a1 + 8) & 0x3FC))) + 0x10) >> 1) & 0x1F;
    else
      v12 = (v11 >> 5) & 0x1F;
    v13 = v3 & 0xFFFFF;
    v14 = 4;
    v37 = *(_DWORD *)(a1 + 4) | 0x80000000;
    v15 = *(unsigned __int8 *)(MmPfnDatabase + 24 * v13 + 18) >> 6;
    if ( !v15 || v15 == 3 )
    {
      v14 = 12;
    }
    else if ( v15 == 2 )
    {
      return sub_50D910();
    }
    v35 = (MmProtectToPteMask[v14] & 0xFED | (v13 << 12) | 0x12) & 0xFFFFF1FF;
    v16 = (unsigned int)KeGetPcr();
    v36 = (*(_DWORD *)((v16 & 0xFFFFF000) + 0x1384) & 0xFFFFF000)
        + ((*(_DWORD *)((v16 & 0xFFFFF000) + 0x1384) & 0xFFF) << 12);
    v17 = (unsigned int *)(((v36 >> 10) & 0x3FFFFC) - 0x40000000);
    v18 = *v17;
    v19 = 0;
    __dmb(0xBu);
    *v17 = v35;
    if ( (v18 & 2) == 0 )
      v19 = 1;
    if ( (unsigned int)v17 >= 0xC0300000 && (unsigned int)v17 <= 0xC0300FFF )
    {
      v32 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v32, v32 + 4 * ((v36 >> 10) & 0xFFC), v35);
    }
    if ( v19 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
    v20 = v36 + 4 * ((v37 >> 2) & 0x3FF);
    v21 = *(_DWORD *)v20 & 0xFFFFF81C | (32 * (v12 & 0x1F | 0x40));
    if ( v20 < 0xC0000000 || v20 > 0xC03FFFFF )
    {
      *(_DWORD *)v20 = v21;
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v20 = v21;
      if ( v20 + 1070596096 <= 0xFFF )
      {
        v33 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v33, v33 + 4 * (v20 & 0xFFF), v21);
      }
    }
    v22 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384);
    v23 = (((v20 & 0xFFFFF000) >> 10) & 0x3FFFFC) - 0x40000000;
    v24 = v22 & 0xFFF;
    v25 = v22 & 0xFFFFF000;
    v26 = v24 + 1;
    if ( v23 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v23 = 0;
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v23 = 0;
      if ( v23 >= 0xC0300000 && v23 <= 0xC0300FFF )
      {
        v34 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v34, v34 + 4 * (v23 & 0xFFF), 0);
      }
    }
    if ( v26 == 16 )
    {
      v42 = 0;
      v43 = 0;
      v38 = 0;
      v41 = 33;
      v39 = 1;
      v40 = 0;
      v44 = 0;
      MiInsertTbFlushEntry(&v38, v25, 16);
      MiFlushTbList(&v38);
      *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) = v25;
    }
    else
    {
      *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) = v26 | v25;
    }
  }
  v5 = *(unsigned __int16 *)(a1 + 16);
  v6 = (unsigned __int16)(v5 - 1);
  *(_WORD *)(a1 + 16) = v6;
  v7 = v6 == 0;
  v8 = *(_DWORD *)(a1 + 12);
  if ( v7 )
  {
    if ( (v8 & 0x40000000) != 0 )
    {
      if ( (*(_BYTE *)(a1 + 19) & 0x10) != 0 )
        *(_BYTE *)(a1 + 19) &= 0xEFu;
      v9 = *(_DWORD *)(a1 + 8);
      if ( (v9 & 0x400) == 0 && ((v9 & 0x10) != 0 || (v9 & 8) != 0) && v9 )
        MiReleasePageFileInfo(MiSystemPartition, v9, 0);
      MiInsertPageInFreeOrZeroedList((a1 - MmPfnDatabase) / 24, 2);
      result = 4;
    }
    else if ( (*(_BYTE *)(a1 + 18) & 0x10) != 0 )
    {
      if ( a2 == 1 )
        v27 = 136;
      else
        v27 = 8;
      MiInsertPageInList(a1, v27, v5);
      result = 4;
    }
    else
    {
      *(_BYTE *)(a1 + 18) = *(_BYTE *)(a1 + 18) & 0xF8 | 2;
      if ( a2 <= 1 || (*(_BYTE *)(a1 + 19) & 8) != 0 || (*(_BYTE *)(a1 + 19) & 7u) >= 5 )
        MiInsertPageInList(a1, 4, v5);
      else
        MiInsertProtectedStandbyPage(a2, a1);
      result = 4;
    }
  }
  else
  {
    v7 = (v8 & 0x40000000) == 0;
    v28 = *(_BYTE *)(a1 + 18);
    if ( v7 )
    {
      v7 = (v28 & 0x10) == 0;
      v31 = v28 & 0xF8;
      if ( v7 )
        v29 = v31 | 2;
      else
        v29 = v31 | 3;
    }
    else
    {
      v29 = v28 | 7;
    }
    *(_BYTE *)(a1 + 18) = v29;
    v30 = *(_DWORD *)(a1 + 8);
    if ( (v30 & 0x400) == 0 && (v30 & 0x10) != 0 )
      byte_63F87E = 1;
    result = 3;
  }
  return result;
}
