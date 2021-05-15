// MiInitializeNonPagedPool 
 
int MiInitializeNonPagedPool()
{
  unsigned int v0; // r4
  int v1; // r4
  int v2; // r2
  unsigned int v4; // r2
  int *v5; // r1
  int v6; // r0
  unsigned int v7; // r6
  unsigned int v8; // r10
  int v9; // r8
  unsigned int v10; // r5
  int v11; // r10
  _DWORD *v12; // r7
  unsigned int *v13; // r0
  unsigned int *v14; // r5
  int v15; // r4
  unsigned int v16; // t1
  bool v17; // cf
  char *v18; // r3
  int v19; // r0
  int v20; // r1
  void *v21; // r2
  unsigned int v22; // r10
  int v23; // r7
  int v24; // r2
  int v25; // r9
  int v26; // r0
  unsigned int v27; // r5
  unsigned int v28; // r4
  int v29; // r6
  int v30; // r4
  int v31; // r3
  int v32; // r5
  int v33; // r0
  int v34; // [sp+8h] [bp-48h]
  unsigned int v35; // [sp+Ch] [bp-44h]
  unsigned int v36; // [sp+10h] [bp-40h]
  unsigned int v37; // [sp+10h] [bp-40h]
  int v38; // [sp+14h] [bp-3Ch]
  unsigned int v39; // [sp+18h] [bp-38h]
  unsigned int v40; // [sp+1Ch] [bp-34h]
  int v41[10]; // [sp+28h] [bp-28h] BYREF

  KeQuerySystemTime(v41);
  v0 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v1 = ReadTimeStampCounter() ^ *(_DWORD *)(v0 + 3728) ^ *(_DWORD *)(v0 + 2992) ^ v41[1] ^ v41[0];
  v2 = ExGenRandom(0) ^ v1;
  if ( !v2 )
    return sub_96A9D8();
  dword_634C80 = v2;
  if ( (MiFlags & 1) == 0 && !MmSpecialPoolTag && MmProtectFreedNonPagedPool != 1 )
  {
    v4 = 4;
    dword_632A84 = 4;
    if ( (unsigned int)dword_640508 >= 0x80000 )
    {
      v4 = 32;
    }
    else
    {
      if ( (unsigned int)dword_640508 < 0x40000 )
        goto LABEL_8;
      v4 = 8;
    }
    dword_632A84 = v4;
LABEL_8:
    v5 = &dword_632A84;
    v6 = 2;
    while ( 1 )
    {
      v5[1] = v4 >> 1;
      ++v5;
      if ( !--v6 )
        break;
      v4 = dword_632A84;
    }
  }
  v7 = (MmPfnDatabase + (MxPfnAllocation << 12)) & 0x3FFFFF;
  v41[0] = MmPfnDatabase + (MxPfnAllocation << 12);
  if ( v7 )
    v35 = 0x400000 - v7;
  else
    v35 = 0;
  dword_634D50 = ((-(__int16)MmSystemRangeStart & 0xFFF) != 0) + ((unsigned int)-MmSystemRangeStart >> 12);
  v38 = dword_63389C;
  v39 = (unsigned int)-MmSystemRangeStart >> 22;
  v8 = ((v39 + 0x7FFF) >> 3) & 0x1FFFF000;
  v36 = (((v39 << 10) + 0x7FFF) >> 3) & 0x1FFFF000;
  v9 = MiReservePtes(&dword_634D58, ((v36 + 2 * v8) * (unsigned __int16)KeNumberNodes) >> 12);
  if ( !v9 )
    return 0;
  v34 = 0;
  if ( KeNumberNodes )
  {
    v10 = v36 >> 12;
    v37 = v8 >> 12;
    v40 = v10;
    v11 = 0;
    do
    {
      v12 = (_DWORD *)(v11 + dword_6337E8);
      v13 = (unsigned int *)(v11 + dword_6337E8 + 160);
      v12[34] = v38;
      v12[35] = v38;
      MiInitializeDynamicBitmap(v13, v9 << 10, v39 << 10, 3);
      v9 += 4 * v10;
      v14 = v12 + 36;
      v15 = 2;
      do
      {
        MiInitializeDynamicBitmap(v14, v9 << 10, v39, 3);
        v16 = *v14;
        v14 += 2;
        v9 += 4 * v37;
        v12[42] = v16;
        ++v12;
        --v15;
      }
      while ( v15 );
      v10 = v40;
      v17 = ++v34 >= (unsigned int)(unsigned __int16)KeNumberNodes;
      v11 += 176;
    }
    while ( !v17 );
  }
  v18 = &byte_632AF4;
  v19 = 512;
  v20 = 255;
  v21 = &unk_632CF4;
  do
    *v18++ = -1;
  while ( v18 != (char *)&unk_632CF4 );
  if ( v35 )
  {
    v22 = *(_DWORD *)((((unsigned int)v41[0] >> 20) & 0xFFC) - 1070596096);
    v23 = (v7 >> 12) + (v22 >> 12);
    v24 = *(_DWORD *)(MmPfnDatabase + 24 * v23 + 20) >> 28;
    v25 = dword_6337E8 + 176 * v24;
    v26 = MiExpandNonPagedPool(
            512,
            0x400u,
            v24,
            ((unsigned __int16)(v7 >> 12) + (unsigned __int16)(v22 >> 12)) & 0x3FF,
            0,
            v41);
    if ( v26 == -1 )
      return 0;
    v27 = *(_DWORD *)(v25 + 136) + (v26 << 12) + v7;
    v28 = ((v26 << 12) + v7) >> 12;
    RtlClearBits((_BYTE *)(v25 + 160), v28, v35 >> 12);
    *(_BYTE *)((v28 >> 13) + *(_DWORD *)(v25 + 148)) &= ~(unsigned __int8)(1 << ((v28 >> 10) & 7));
    v29 = (v27 >> 10) & 0x3FFFFC;
    v30 = ((v27 >> 20) & 0xFFC) - 1070596096;
    v31 = *(_DWORD *)v30;
    v32 = 0;
    __dmb(0xBu);
    *(_DWORD *)v30 = v22;
    if ( (v31 & 2) == 0 && (v22 & 2) != 0 )
      v32 = 1;
    if ( (unsigned int)(v30 + 1070596096) <= 0xFFF )
    {
      v33 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v33, (_DWORD *)(v33 + 4 * (v30 & 0xFFF)), v22);
    }
    if ( v32 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
    v19 = MiInitializeLargeNonPagedPoolLeafFrames(v29 - 0x40000000, v23);
    v18 = (char *)(v23 | 0x3FF);
    *(_DWORD *)(v25 + 104) = v23;
    *(_DWORD *)(v25 + 108) = v23 | 0x3FF;
  }
  MiInitializeNonPagedPoolThresholds(v19, v20, (int)v21, (int)v18);
  return 1;
}
