// BgpTxtRegionSize 
 
int __fastcall BgpTxtRegionSize(_DWORD *a1)
{
  _DWORD *v2; // r3
  int v3; // r5
  _DWORD *v4; // r3

  if ( !a1 || (a1[12] & 1) == 0 )
    return 0;
  v2 = (_DWORD *)a1[5];
  v3 = 80;
  if ( v2 )
    v3 = BgpGxReservePoolRectangleSize(*v2, v2[1], v2[2]) + 80;
  v4 = (_DWORD *)a1[6];
  if ( v4 )
    v3 += BgpGxReservePoolRectangleSize(*v4, v4[1], v4[2]);
  return v3;
}
