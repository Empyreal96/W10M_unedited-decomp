// KsepIsShimRegistered 
 
int __fastcall KsepIsShimRegistered(int a1, unsigned int a2)
{
  _DWORD *v3; // r7
  _DWORD *v4; // r5
  _DWORD *v5; // r6
  int v6; // r2

  if ( a2 && a1 )
  {
    v3 = (_DWORD *)(a1 + 12);
    v4 = *(_DWORD **)(a1 + 12);
    while ( v4 != v3 )
    {
      v5 = v4;
      v6 = v4[4];
      v4 = (_DWORD *)*v4;
      if ( (v6 & 4) == 0 && !memcmp(*(_DWORD *)(v5[2] + 4), a2, 4) )
        return sub_7CF324();
    }
  }
  return 0;
}
