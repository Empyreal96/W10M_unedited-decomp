// sub_81CA34 
 
void sub_81CA34()
{
  int v0; // r5
  int v1; // r4
  _DWORD *v2; // r0
  _DWORD *v3; // r0
  _DWORD *v4; // r2
  _DWORD *i; // r3
  int v6; // r2
  _DWORD *j; // r3

  v1 = *(_DWORD *)(v0 + 8);
  if ( v1 )
  {
    v2 = *(_DWORD **)(v1 + 8);
    if ( *(_WORD *)v2 != 2051 )
    {
      v3 = RtlRealSuccessor(v2 + 3);
      if ( !v3 )
      {
        v4 = (_DWORD *)(v1 + 12);
        for ( i = *(_DWORD **)(v1 + 12); i != v4; i = (_DWORD *)*i )
          v4 = i;
        v6 = *(v4 - 2);
        if ( *(__int16 *)(v6 + 2) <= 0 )
          JUMPOUT(0x7BD07E);
        v3 = (_DWORD *)(v6 + 12);
        for ( j = *(_DWORD **)(v6 + 16); j; j = (_DWORD *)j[1] )
          v3 = j;
      }
      v2 = v3 - 3;
    }
    *(_DWORD *)(v0 + 8) = v2;
    JUMPOUT(0x7BD080);
  }
  JUMPOUT(0x7BD070);
}
