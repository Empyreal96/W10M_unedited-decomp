// MiUpdateForkMaps 
 
unsigned int __fastcall MiUpdateForkMaps(int *a1, unsigned int a2, unsigned int a3, _DWORD *a4, _WORD *a5, unsigned __int8 a6)
{
  unsigned int v8; // r0
  unsigned int v9; // r5
  int v10; // r8
  int v11; // r0
  int v12; // r3
  int v13; // r0
  int *v14; // r6
  int v15; // r4
  int v16; // r3
  int v17; // r7
  int v18; // r0
  int v19; // r2
  int v20; // r2
  int v22; // [sp+8h] [bp-30h]
  unsigned int v23; // [sp+10h] [bp-28h]
  int v24; // [sp+14h] [bp-24h] BYREF
  _DWORD *v25; // [sp+18h] [bp-20h]

  v25 = a4;
  v8 = MiGetNextPageTable(a2, a3, 0, a6, 1, &v24);
  v9 = v8;
  if ( !v8 )
    return a3 + 4;
  v10 = *(_DWORD *)(((v8 >> 10) & 0x3FFFFC) - 0x40000000);
  if ( ((a1[4] ^ v8) & 0xFFFFF000) == 0 )
  {
    v11 = a1[2];
LABEL_20:
    v20 = v9 & 0xFFF | v11;
    a1[3] = v20;
    MiMakeSystemAddressValid(v9, 0, v20, a6, 1);
    return v9;
  }
  v12 = *a1;
  a1[4] = v8;
  v23 = ((v8 >> 10) & 0x3FFFFC) - 0x40000000;
  v22 = *(_DWORD *)(v12 + 24) >> 12;
  v13 = MiMapSinglePage(a1[5], v22, 1073741856);
  v24 = v23;
  v14 = (int *)(v13 + 4 * ((v23 >> 2) & 0x3FF));
  if ( *v14 )
  {
    v15 = (unsigned int)*v14 >> 12;
    goto LABEL_19;
  }
  if ( (v10 & 0x400) == 0 )
  {
    MiDoneWithThisPageGetAnother(a1 + 1, a5, *a1, a6);
    v15 = a1[1];
    MiBuildForkPageTable(v15, v24, v14, v22, 0);
    ++*v25;
LABEL_19:
    v11 = MiMapSinglePage(a1[5], v15, 1073741856);
    v19 = a1[7];
    a1[2] = v11;
    a1[6] = v19 + 2 * ((v9 << 10 >> 22) + 224);
    goto LABEL_20;
  }
  if ( (unsigned int)(v14 + 0x10000000) > 0x3FFFFF )
  {
    *v14 = v10;
  }
  else
  {
    v16 = *v14;
    v17 = 0;
    __dmb(0xBu);
    *v14 = v10;
    if ( (v16 & 2) == 0 && (v10 & 2) != 0 )
      v17 = 1;
    if ( (unsigned int)(v14 + 267649024) <= 0xFFF )
    {
      v18 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v18, (_DWORD *)(v18 + 4 * ((unsigned __int16)v14 & 0xFFF)), v10);
    }
    if ( v17 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  v9 += 4096;
  return v9;
}
