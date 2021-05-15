// PiDmCompareObjects 
 
int __fastcall PiDmCompareObjects(int a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // r0
  _DWORD *v4; // r1
  unsigned int v5; // r3
  unsigned int v6; // r2
  unsigned __int16 *v8; // r1
  int v9; // r0
  int v10; // r0

  v3 = (_DWORD *)*a2;
  v4 = (_DWORD *)*a3;
  if ( v3 == (_DWORD *)*a3 )
    return 2;
  v5 = v3[4];
  v6 = v4[4];
  if ( v5 < v6 )
    return 0;
  if ( v5 > v6 )
    return 1;
  if ( v3[5] == 3 )
  {
    v8 = (unsigned __int16 *)(v4[3] + 8);
    v9 = v3[3] + 8;
  }
  else
  {
    v8 = (unsigned __int16 *)v4[3];
    v9 = v3[3];
  }
  v10 = wcsicmp(v9, v8);
  if ( v10 < 0 )
    return 0;
  if ( v10 > 0 )
    return 1;
  return 2;
}
