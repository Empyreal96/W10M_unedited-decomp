// PnprCopyReservedMapping 
 
int PnprCopyReservedMapping()
{
  _DWORD *v0; // r7
  unsigned int v1; // r5
  int v2; // r2
  int v3; // r3
  int v4; // r4
  unsigned int v5; // r6
  unsigned int v6; // r4
  unsigned int i; // r6
  int v8; // r2
  unsigned int v9; // r8
  __int64 v10; // r0
  int result; // r0
  int v12; // r3
  _DWORD *v13; // r4
  int v14; // r6
  unsigned int v15; // r8
  __int64 v16; // r0
  unsigned int v17; // r4
  unsigned int v18; // r6
  int v19; // r2
  unsigned int v20; // r8
  __int64 v21; // r0
  int v22; // r2
  int v23; // r4
  int v24; // r0
  int v25; // r3
  int v26; // r2
  int v27; // r2
  __int64 v28; // [sp+0h] [bp-B0h] BYREF
  unsigned int v29; // [sp+8h] [bp-A8h] BYREF
  int v30; // [sp+Ch] [bp-A4h]
  int v31[16]; // [sp+10h] [bp-A0h] BYREF
  int v32[24]; // [sp+50h] [bp-60h] BYREF

  v0 = (_DWORD *)(*(_DWORD *)(PnprContext + 108) + 12 * *(_DWORD *)(PnprContext + 128));
  if ( (*(_WORD *)(*v0 + 6) & 1) != 0 )
    MmUnmapReservedMapping(v0[1], 1366322768, *v0);
  memset(v31, 0, sizeof(v31));
  memset(v32, 0, 64);
  v1 = 0;
  MmGetPhysicalAddress((int)&v29, *v0 & 0xFFFFF000, v2, v3);
  v5 = v29;
  v4 = v30;
  if ( PnprGetPageDestination(v29, v30, &v28) >= 0 && v28 != 0x7FFFFFFFFFFFFFFFi64 )
  {
    v31[0] = (v4 << 20) | (v5 >> 12);
    v32[0] = v28 >> 12;
    v1 = 1;
  }
  v6 = v0[1];
  for ( i = v6 + 0x10000; v6 < i; v6 += 4096 )
  {
    v8 = *(_DWORD *)(((v6 >> 20) & 0xFFC) - 1070596096) >> 12;
    if ( !v1 || v8 != *(&v30 + v1) )
    {
      v9 = v8 << 12;
      if ( PnprGetPageDestination(v8 << 12, 0, &v28) >= 0 )
      {
        v10 = v28;
        if ( v28 != 0x7FFFFFFFFFFFFFFFi64 )
        {
          if ( v1 >= 0x10 )
            return -1073741811;
          v31[v1] = v9 >> 12;
          v32[v1++] = v10 >> 12;
        }
      }
    }
  }
  v12 = *(_DWORD *)(PnprContext + 104);
  v13 = (_DWORD *)(v12 + 12 * *(_DWORD *)(PnprContext + 128));
  MmGetPhysicalAddress((int)&v29, *v13 & 0xFFFFF000, 3 * *(_DWORD *)(PnprContext + 128), v12);
  v15 = v29;
  v14 = v30;
  if ( PnprGetPageDestination(v29, v30, &v28) >= 0 )
  {
    v16 = v28;
    if ( v28 != 0x7FFFFFFFFFFFFFFFi64 )
    {
      if ( v1 >= 0x10 )
        return -1073741811;
      v31[v1] = (v14 << 20) | (v15 >> 12);
      v32[v1++] = v16 >> 12;
    }
  }
  v17 = v13[1];
  v18 = v17 + 0x10000;
  while ( v17 < v18 )
  {
    v19 = *(_DWORD *)(((v17 >> 20) & 0xFFC) - 1070596096) >> 12;
    if ( v1 > 0x10 )
      return -1073741811;
    if ( !v1 || v19 != *(&v30 + v1) )
    {
      v20 = v19 << 12;
      if ( PnprGetPageDestination(v19 << 12, 0, &v28) >= 0 )
      {
        v21 = v28;
        if ( v28 != 0x7FFFFFFFFFFFFFFFi64 )
        {
          if ( v1 >= 0x10 )
            return -1073741811;
          v31[v1] = v20 >> 12;
          v32[v1++] = v21 >> 12;
        }
      }
    }
    v17 += 4096;
  }
  if ( !v1 )
    return 0;
  v22 = *v0;
  *(_WORD *)(v22 + 4) = 4 * ((((v1 << 13) + 4095) >> 12) + 7);
  *(_DWORD *)v22 = 0;
  *(_WORD *)(v22 + 6) = 0;
  *(_DWORD *)(v22 + 16) = 0;
  *(_DWORD *)(v22 + 20) = v1 << 13;
  *(_DWORD *)(v22 + 24) = 0;
  v23 = *v0 + 28;
  memmove(v23, (int)v31, 4 * v1);
  memmove(v23 + 4 * v1, (int)v32, 4 * v1);
  *(_WORD *)(*v0 + 6) |= *((_WORD *)v0 + 4);
  v24 = MmMapLockedPagesWithReservedMapping(v0[1], 1366322768, *v0, 1);
  if ( v24 )
  {
    memmove(v24 + (v1 << 12), v24, v1 << 12);
    return 0;
  }
  v25 = PnprContext;
  v26 = *(_DWORD *)(PnprContext + 608);
  if ( !v26 )
    v26 = 5965;
  *(_DWORD *)(PnprContext + 608) = v26;
  v27 = *(_DWORD *)(v25 + 612);
  if ( !v27 )
    v27 = 10;
  result = -1073741670;
  *(_DWORD *)(v25 + 612) = v27;
  return result;
}
