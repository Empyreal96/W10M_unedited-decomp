// MiBuildWakeList 
 
int __fastcall MiBuildWakeList(int a1, int a2)
{
  _DWORD *v2; // r2
  _DWORD *v3; // r4
  _DWORD *v4; // r5
  __int64 v6; // kr00_8

  v2 = *(_DWORD **)(a1 + 44);
  v3 = 0;
  v4 = (_DWORD *)(a1 + 44);
  if ( !v2 )
    return (int)v3;
  while ( 1 )
  {
    v6 = *(_QWORD *)v2;
    if ( (v2[1] & a2) == 0 )
    {
      v4 = v2;
      goto LABEL_7;
    }
    if ( (a2 & 4) != 0 )
      return sub_546BAC(v6);
    *v2 = v3;
    v3 = v2;
    *v4 = v6;
LABEL_7:
    v2 = (_DWORD *)v6;
    if ( !(_DWORD)v6 )
      return (int)v3;
  }
}
