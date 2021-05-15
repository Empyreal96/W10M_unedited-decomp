// BgpTxtDestroyRegion 
 
int __fastcall BgpTxtDestroyRegion(int result, int a2)
{
  int v2; // r4
  int v3; // r0
  int v4; // r0

  v2 = result;
  if ( result && (*(_DWORD *)(result + 48) & 1) != 0 )
  {
    v3 = *(_DWORD *)(result + 20);
    if ( v3 )
      BgpGxRectangleDestroy(v3);
    v4 = *(_DWORD *)(v2 + 24);
    if ( v4 )
      v4 = BgpGxRectangleDestroy(v4);
    if ( (*(_DWORD *)(v2 + 44) & 1) != 0 )
    {
      if ( *((void ***)TxtpTextCache + 1) != &TxtpTextCache )
        __fastfail(3u);
      result = sub_8DFB18(v4, a2, *(_DWORD *)TxtpTextCache);
    }
    else
    {
      result = BgpFwFreeMemory(v2);
    }
  }
  return result;
}
