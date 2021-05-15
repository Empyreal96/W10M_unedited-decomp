// MiAllocateWsle 
 
int __fastcall MiAllocateWsle(int a1, unsigned int a2, int a3, int a4, unsigned int a5, int a6)
{
  _DWORD *v6; // r8
  unsigned int *v9; // r1
  unsigned int v10; // r0
  int v11; // r6
  unsigned int v13; // r2
  unsigned int v14; // r3
  unsigned int *v15; // r2
  unsigned int v16; // r6
  unsigned int v17; // lr
  unsigned int v18; // r10
  unsigned int v19; // r8
  unsigned int v20; // r0
  unsigned int v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // r3
  unsigned int v24; // r9
  int v25; // r1
  unsigned int v26; // r2
  unsigned int v27; // r3
  int v28; // lr
  int v29; // r10
  int v30; // r3
  int v31; // r4
  int v32; // r0
  int *v33; // r2
  unsigned int v34; // r1
  int v35; // r0
  int v36; // r1
  int v37; // r1
  _DWORD *v40; // [sp+10h] [bp-20h]
  int varg_r0; // [sp+38h] [bp+8h]
  unsigned int varg_r1; // [sp+3Ch] [bp+Ch]
  int varg_r2; // [sp+40h] [bp+10h]
  int varg_r3; // [sp+44h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v6 = *(_DWORD **)(a1 + 92);
  v40 = v6;
  if ( v6[9] == 4 && (*(_DWORD *)(a1 + 60) >= 0x40000u || (*(_BYTE *)(a1 + 112) & 0x40) != 0) )
    MiConvertToLinkedWsles(a1);
  ++*(_DWORD *)(a1 + 100);
  v9 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2952);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 + 1, v9) );
  v11 = *(_DWORD *)a2;
  if ( *(_DWORD *)(a1 + 52) >= *(_DWORD *)(a1 + 48) )
  {
    if ( *(_DWORD *)(a1 + 108) )
      return sub_5363FC();
    v13 = *(_DWORD *)(a1 + 60);
    v14 = *(_DWORD *)(*(_DWORD *)(a1 + 92) + 4);
    if ( v13 > v14 && v13 - v14 >= 3 * ((unsigned int)dword_640508 >> 2) )
      JUMPOUT(0x536400);
    if ( (*(_BYTE *)(a1 + 112) & 0x40) != 0 && *(_DWORD *)(a1 + 52) >= *(_DWORD *)(a1 + 68) )
    {
      if ( *(_DWORD *)(*(_DWORD *)(a1 + 92) + 36) == 16 )
      {
        MiReplaceWorkingSetEntryLarge(a1, 0);
        MiSimpleAging(a1);
      }
      else
      {
        MiReplaceWorkingSetEntrySmall(a1, 0);
      }
    }
  }
  if ( *v6 != 0xFFFFF || MiAddWorkingSetPage(a1) || (MiDoReplacement(a1, 1), *v6 != 0xFFFFF) )
  {
    if ( v11 != *(_DWORD *)a2 )
    {
      ++dword_634408;
      return 0;
    }
    v15 = *(unsigned int **)(a1 + 92);
    v16 = *v15;
    v17 = v15[4];
    if ( *v15 > v17 )
      KeBugCheckEx(26, 20480, v15);
    v18 = v15[9];
    v19 = v15[63];
    v20 = *(_DWORD *)(v18 * v16 + v19);
    if ( (v20 & 1) != 0 || (*(_DWORD *)(v18 * v16 + v19) & 0xFFE) != 4094 )
      KeBugCheckEx(26, 20481, v15);
    v21 = v20 >> 12;
    if ( v20 >> 12 != 0xFFFFF )
    {
      if ( v21 > v17 )
        KeBugCheckEx(26, 20482, v15);
      v22 = *(_DWORD *)(v18 * v21 + v19);
      if ( (v22 & 1) != 0 || (((unsigned __int16)v16 ^ (unsigned __int16)(v22 >> 1)) & 0x7FF) != 0 )
        KeBugCheckEx(26, 20483, v15);
      *(_DWORD *)(v18 * v21 + v19) = v22 | 0xFFE;
    }
    v23 = v15[2];
    *v15 = v21;
    if ( v16 > v23 )
      v15[2] = v16;
    v24 = a2 << 10;
    v25 = *(_DWORD *)(a1 + 60) + 1;
    *(_DWORD *)(a1 + 60) = v25;
    if ( a2 << 10 < 0xC0000000 || v24 > 0xC03FFFFF )
      ++*(_DWORD *)(a1 + 52);
    v26 = *(_DWORD *)(a1 + 52);
    if ( v26 > *(_DWORD *)(a1 + 84) )
      *(_DWORD *)(a1 + 84) = v26;
    v27 = *(_BYTE *)(a1 + 112) & 7;
    if ( v27 >= 2 )
    {
      v33 = &MiState[v27 - 2];
      v34 = v25 + dword_634680;
      if ( v34 > v33[1793] )
        v33[1793] = v34;
    }
    v28 = a5;
    if ( (a5 & 2) == 0 )
    {
      v29 = a3;
LABEL_41:
      v32 = MiUpdateWsle(v16, v24, a1, v29, a4);
      if ( v16 != v32 )
        v16 = v32;
      if ( a4 )
        *(_DWORD *)(v40[9] * v16 + v40[63]) |= a4;
      if ( (dword_682604 & 0x8000001) != 0 )
        MiLogAllocateWsleEvent(v29, *(_BYTE *)(a1 + 112) & 7, v24);
      return v16;
    }
    if ( (int *)a1 == &dword_634E00 )
    {
      v28 = a5 | 1;
      a5 |= 1u;
    }
    else if ( (MiFlags & 0x30000) != 0
           && (a5 & 1) == 0
           && (v24 < 0xC0000000 || v24 > 0xC03FFFFF)
           && ((BYTE2(MiFlags) & 3u) > 1 || (*(_BYTE *)(a1 + 112) & 7) != 0) )
    {
      v29 = a3;
      if ( (MiFlags & 0x40000) == 0 )
      {
        v36 = 0;
        if ( (*(_BYTE *)(a3 + 23) & 7) != 3 )
          v36 = 2;
        if ( (a5 & 0x80) != 0 )
          v36 |= 1u;
        if ( v36 )
        {
          MiMarkPfnVerified(a3, v36);
          v28 = a5;
        }
      }
      goto LABEL_33;
    }
    v29 = a3;
LABEL_33:
    if ( a2 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)a2 = v28;
    }
    else
    {
      v30 = *(_DWORD *)a2;
      v31 = 0;
      __dmb(0xBu);
      *(_DWORD *)a2 = v28;
      if ( (v30 & 2) == 0 && (v28 & 2) != 0 )
        v31 = 1;
      if ( a2 >= 0xC0300000 && a2 <= 0xC0300FFF )
      {
        v35 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v35, v35 + 4 * (a2 & 0xFFF), v28);
      }
      if ( v31 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    if ( a6 )
    {
      __mrc(15, 0, 13, 0, 3);
      v37 = *(_DWORD *)(a6 + 24);
      if ( ((v37 & 1) == 0 || (a5 & 0x200) == 0) && ((v37 & 2) == 0 || (a5 & 1) == 0) )
        *(_DWORD *)(a6 + 20) = a5 >> 12;
    }
    goto LABEL_41;
  }
  ++dword_634404;
  return 0;
}
