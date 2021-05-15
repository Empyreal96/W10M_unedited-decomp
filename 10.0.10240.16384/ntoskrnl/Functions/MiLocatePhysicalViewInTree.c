// MiLocatePhysicalViewInTree 
 
_DWORD *__fastcall MiLocatePhysicalViewInTree(int a1, _DWORD *a2)
{
  _DWORD *v2; // r4
  int v4; // r0

  v2 = (_DWORD *)*a2;
  while ( v2 )
  {
    v4 = MiPhysicalViewCompareVpn(a1, v2);
    if ( v4 >= 0 )
    {
      if ( v4 <= 0 )
        return v2;
      v2 = (_DWORD *)v2[1];
    }
    else
    {
      v2 = (_DWORD *)*v2;
    }
  }
  return v2;
}
