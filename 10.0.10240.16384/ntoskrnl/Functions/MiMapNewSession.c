// MiMapNewSession 
 
int __fastcall MiMapNewSession(unsigned int a1)
{
  unsigned int v1; // r10
  unsigned int *v2; // r9
  int v3; // r4
  unsigned int *v4; // r0
  int v5; // r6
  unsigned int *v6; // r9
  int v7; // r10
  unsigned int v8; // r1
  int v9; // r10
  unsigned int v10; // r3
  unsigned int v11; // r0
  int *v12; // r4
  unsigned int *v13; // r8
  int v14; // r7
  int *v15; // r2
  unsigned int v16; // r7
  int v17; // r7
  int *v18; // r5
  int v19; // r4
  unsigned int v20; // r6
  int v21; // r2
  int v22; // r3
  unsigned int v24; // r3
  int v25; // r7
  int v26; // r3
  int v27; // r5
  int v28; // r3
  int v29; // r5
  int v30; // r3
  int v31; // r4
  int v32; // [sp+0h] [bp-40h]
  unsigned int *v34; // [sp+8h] [bp-38h]
  unsigned int v35; // [sp+Ch] [bp-34h]
  unsigned int v36; // [sp+Ch] [bp-34h]
  unsigned int v37; // [sp+10h] [bp-30h]
  _WORD *v38; // [sp+18h] [bp-28h] BYREF
  unsigned __int16 v39; // [sp+1Ch] [bp-24h]
  unsigned __int16 v40; // [sp+1Eh] [bp-22h]

  v1 = a1;
  v35 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v2 = 0;
  MI_INITIALIZE_COLOR_BASE(0, 0, (int)&v38);
  v3 = 6;
  do
  {
    v4 = (unsigned int *)MiGetSystemPage((int)&v38);
    *v4 = (unsigned int)v2;
    v2 = v4;
    --v3;
  }
  while ( v3 );
  v32 = ((int)v4 - MmPfnDatabase) / 24;
  v34 = (unsigned int *)((((unsigned int)MmSessionSpace >> 20) & 0xFFC) - 1070596096);
  v5 = (int)v4;
  v6 = (unsigned int *)*v4;
  *v4 = v1;
  v7 = ((int)v4 - MmPfnDatabase) / 24;
  v8 = dword_681128 & 0x1EC | (MiDetermineUserGlobalPteMask(0) | (v7 << 12)) & 0xFFFFF9FF | 0x813;
  if ( (unsigned int)v34 < 0xC0000000 || (unsigned int)v34 > 0xC03FFFFF )
  {
    *v34 = v8;
  }
  else
  {
    v24 = *v34;
    v25 = 0;
    __dmb(0xBu);
    *v34 = v8;
    if ( (v24 & 2) == 0 && (v8 & 2) != 0 )
      v25 = 1;
    if ( (unsigned int)(v34 + 267649024) <= 0xFFF )
      MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v8, (__int16)v34);
    if ( v25 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  MiInitializePfnForOtherProcess(v7, (int)v34, v32, 0);
  MiMarkPageActive(v5);
  v9 = 3;
  LOWORD(v5) = (dword_681120 & 0x1ED | MiDetermineUserGlobalPteMask(v35)) & 0xF1FF | 0x12;
  v10 = (((unsigned int)MmSessionSpace >> 10) & 0x3FFFFC) - 0x40000000;
  v11 = v35 - v10;
  v36 = v10;
  v37 = v11;
  v12 = (int *)v10;
  do
  {
    v13 = v6;
    v6 = (unsigned int *)*v6;
    v14 = ((int)v13 - MmPfnDatabase) / 24;
    v15 = (int *)((char *)v12 + v11);
    *v13 = a1;
    v5 = v5 & 0xFFF | (v14 << 12);
    if ( (unsigned int)v12 + v11 < 0xC0000000 || (unsigned int)v15 > 0xC03FFFFF )
    {
      *v15 = v5;
    }
    else
    {
      v26 = *v15;
      v27 = 0;
      __dmb(0xBu);
      *v15 = v5;
      if ( (v26 & 2) == 0 && (v5 & 2) != 0 )
        v27 = 1;
      if ( (unsigned int)v12 + v11 + 1070596096 <= 0xFFF )
        MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v5, (__int16)v15);
      if ( v27 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    v16 = dword_681120 & 0x1ED | (MiDetermineUserGlobalPteMask(0) | (v14 << 12)) & 0xFFFFF9FF | 0x812;
    MiInitializePfn((int)v13, v12, 4u, 4);
    if ( (unsigned int)v12 < 0xC0000000 || (unsigned int)v12 > 0xC03FFFFF )
    {
      *v12 = v16;
    }
    else
    {
      v28 = *v12;
      v29 = 0;
      __dmb(0xBu);
      *v12 = v16;
      if ( (v28 & 2) == 0 )
        v29 = 1;
      if ( (unsigned int)(v12 + 267649024) <= 0xFFF )
        MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v16, (__int16)v12);
      if ( v29 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    v11 = v37;
    ++v12;
    --v9;
  }
  while ( v9 );
  v17 = 2;
  v18 = (int *)(v36 + 12);
  do
  {
    v19 = (int)v6;
    v6 = (unsigned int *)*v6;
    v20 = dword_681120 & 0x1ED | (MiDetermineUserGlobalPteMask(0) | (((v19 - MmPfnDatabase) / 24) << 12)) & 0xFFFFF9FF | 0x812;
    MiInitializePfn(v19, v18, 4u, 4);
    if ( (unsigned int)v18 < 0xC0000000 || (unsigned int)v18 > 0xC03FFFFF )
    {
      *v18 = v20;
    }
    else
    {
      v30 = *v18;
      v31 = 0;
      __dmb(0xBu);
      *v18 = v20;
      if ( (v30 & 2) == 0 )
        v31 = 1;
      if ( (unsigned int)(v18 + 267649024) <= 0xFFF )
        MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v20, (__int16)v18);
      if ( v31 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    ++v18;
    --v17;
  }
  while ( v17 );
  v21 = (unsigned __int16)(*v38 + 1);
  v22 = v39;
  *v38 = v21;
  return v21 & v22 | v40;
}
