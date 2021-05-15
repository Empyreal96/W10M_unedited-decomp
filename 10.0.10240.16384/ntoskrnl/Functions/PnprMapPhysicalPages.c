// PnprMapPhysicalPages 
 
int __fastcall PnprMapPhysicalPages(int *a1, __int64 a2, __int64 *a3, int *a4)
{
  int v6; // r1
  int v7; // r3
  int v8; // r3
  int result; // r0
  __int64 v10; // r4
  int v11; // r2
  _DWORD *v12; // r0
  int v13; // r2
  int i; // r3
  int v15; // r0
  int v16; // r3
  int v17; // r2
  int v18; // r2
  int v19; // r3
  int *varg_r0; // [sp+20h] [bp+8h]

  varg_r0 = a1;
  v6 = PnprContext;
  if ( (*(_DWORD *)(PnprContext + 48) & 4) == 0 )
  {
    v7 = *(_DWORD *)(PnprContext + 608);
    if ( !v7 )
      v7 = 4062;
    *(_DWORD *)(PnprContext + 608) = v7;
    v8 = *(_DWORD *)(v6 + 612);
    if ( !v8 )
      v8 = 8;
    result = -1073741798;
LABEL_28:
    *(_DWORD *)(v6 + 612) = v8;
    return result;
  }
  if ( (a2 & 0xFFF) != 0 || (v10 = *a3) == 0 || (v10 & 0xFFF) != 0 )
  {
    v19 = *(_DWORD *)(PnprContext + 608);
    if ( !v19 )
      v19 = 4070;
    *(_DWORD *)(PnprContext + 608) = v19;
    v8 = *(_DWORD *)(v6 + 612);
    if ( !v8 )
      v8 = 8;
    result = -1073741811;
    goto LABEL_28;
  }
  if ( (unsigned __int64)v10 > 0x10000 )
    v10 = 0x10000i64;
  if ( (*(_WORD *)(*a1 + 6) & 1) != 0 )
    MmUnmapReservedMapping(a1[1], 1366322768, *a1);
  v11 = *a1;
  *(_WORD *)(v11 + 4) = 4 * (((unsigned int)(v10 + 4095) >> 12) + 7);
  *(_DWORD *)v11 = 0;
  *(_WORD *)(v11 + 6) = 0;
  *(_DWORD *)(v11 + 16) = 0;
  *(_DWORD *)(v11 + 20) = v10;
  *(_DWORD *)(v11 + 24) = 0;
  v12 = (_DWORD *)(*a1 + 28);
  v13 = a2 >> 12;
  for ( i = v10 >> 12; i; --i )
    *v12++ = v13++;
  *(_WORD *)(*a1 + 6) |= *((_WORD *)a1 + 4);
  v15 = MmMapLockedPagesWithReservedMapping(a1[1], 1366322768, (_DWORD *)*a1, 1);
  if ( v15 )
  {
    *a4 = v15;
    *a3 = v10;
    result = 0;
  }
  else
  {
    v16 = PnprContext;
    v17 = *(_DWORD *)(PnprContext + 608);
    if ( !v17 )
      v17 = 4125;
    *(_DWORD *)(PnprContext + 608) = v17;
    v18 = *(_DWORD *)(v16 + 612);
    if ( !v18 )
      v18 = 10;
    result = -1073741670;
    *(_DWORD *)(v16 + 612) = v18;
  }
  return result;
}
