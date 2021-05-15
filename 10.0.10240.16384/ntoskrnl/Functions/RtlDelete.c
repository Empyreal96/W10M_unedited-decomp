// RtlDelete 
 
int __fastcall RtlDelete(_DWORD *a1)
{
  int v2; // r0
  _DWORD *v3; // r2
  _DWORD *v4; // r1
  _DWORD *v5; // r3
  _DWORD *v6; // r0
  _DWORD *v8; // r3

  if ( !a1[1] )
    goto LABEL_23;
  if ( a1[2] )
  {
    v2 = RtlSubtreePredecessor();
    SwapSplayLinks(v2, a1);
  }
  v3 = (_DWORD *)a1[1];
  if ( !v3 )
  {
LABEL_23:
    if ( !a1[2] )
    {
      v6 = (_DWORD *)*a1;
      if ( (_DWORD *)*a1 == a1 )
        return 0;
      if ( (_DWORD *)v6[1] == a1 )
        v8 = v6 + 1;
      else
        v8 = v6 + 2;
      *v8 = 0;
      return RtlSplay(v6);
    }
    v3 = (_DWORD *)a1[2];
  }
  v4 = (_DWORD *)*a1;
  if ( (_DWORD *)*a1 == a1 )
  {
    *v3 = v3;
    return (int)v3;
  }
  if ( (_DWORD *)v4[1] == a1 )
    v5 = v4 + 1;
  else
    v5 = v4 + 2;
  *v5 = v3;
  v6 = (_DWORD *)*a1;
  *v3 = *a1;
  return RtlSplay(v6);
}
