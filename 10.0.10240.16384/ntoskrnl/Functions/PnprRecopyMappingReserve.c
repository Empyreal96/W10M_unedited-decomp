// PnprRecopyMappingReserve 
 
int __fastcall PnprRecopyMappingReserve(int *a1)
{
  int v1; // r7
  unsigned int v2; // r4
  int v4; // r2
  int v5; // r3
  int result; // r0
  int v7; // r3
  int v8; // r2
  int v9; // r2

  v1 = 0;
  v2 = 0;
  while ( 1 )
  {
    v4 = ((v2 + a1[1]) >> 20) & 0xFFC;
    v5 = *(_DWORD *)(v4 - 1070596096) >> 12;
    if ( v5 != v1 )
    {
      v1 = *(_DWORD *)(v4 - 1070596096) >> 12;
      result = PnprMarkOrMirrorPages(v5 << 12, 0, 4096, 0);
      if ( result < 0 )
        break;
    }
    v2 += 4096;
    if ( v2 >= 0x10000 )
    {
      PnprRecopyAddress(*a1, 28, v4, v5);
      return 0;
    }
  }
  v7 = PnprContext;
  v8 = *(_DWORD *)(PnprContext + 608);
  if ( !v8 )
    v8 = 5712;
  *(_DWORD *)(PnprContext + 608) = v8;
  v9 = *(_DWORD *)(v7 + 612);
  if ( !v9 )
    v9 = 1;
  *(_DWORD *)(v7 + 612) = v9;
  return result;
}
