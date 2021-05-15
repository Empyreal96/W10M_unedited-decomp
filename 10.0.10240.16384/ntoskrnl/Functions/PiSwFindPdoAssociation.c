// PiSwFindPdoAssociation 
 
_DWORD *__fastcall PiSwFindPdoAssociation(int a1, int a2, int a3)
{
  _DWORD *v3; // r3
  _DWORD *v4; // r4
  int v5; // r0

  v3 = *(_DWORD **)(a1 + 68);
  v4 = (_DWORD *)(a1 + 68);
  while ( v3 != v4 )
  {
    if ( a3 )
      v5 = v3[2];
    else
      v5 = v3[3];
    if ( v5 == a2 )
      return v3;
    v3 = (_DWORD *)*v3;
  }
  return 0;
}
