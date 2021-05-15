// BgpTxtAdjustStaticRegion 
 
int __fastcall BgpTxtAdjustStaticRegion(_DWORD *a1, _DWORD *a2, int *a3)
{
  _DWORD *v5; // r0
  int v6; // r2

  if ( !a1 || !a2 && !a3 || (a1[12] & 1) == 0 )
    return -1073741811;
  if ( a2 )
  {
    *a1 = *a2;
    a1[1] = a2[1];
  }
  if ( a3 )
  {
    v5 = (_DWORD *)a1[5];
    if ( v5 )
    {
      v6 = *a3;
      if ( a1[7] != *a3 )
      {
        a1[7] = v6;
        BgpGxFillRectangle(v5, v6);
      }
    }
    a1[8] = a3[1];
  }
  return 0;
}
