// RtlGetFirstRange 
 
int __fastcall RtlGetFirstRange(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // r4
  _DWORD *v4; // r3
  int v6; // r3

  *a2 = a1;
  v3 = 0;
  a2[3] = a1[4];
  v4 = (_DWORD *)*a1;
  if ( (_DWORD *)*a1 == a1 )
  {
    v6 = 0;
    a2[1] = 0;
    a2[2] = 0;
    v3 = -2147483622;
  }
  else
  {
    if ( (*((_WORD *)v4 - 1) & 1) != 0 )
      return sub_8114AC();
    a2[1] = 0;
    a2[2] = v4 - 7;
    v6 = a2[2];
  }
  *a3 = v6;
  return v3;
}
