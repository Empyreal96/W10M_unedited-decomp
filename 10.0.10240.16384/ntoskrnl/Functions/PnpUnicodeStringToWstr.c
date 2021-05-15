// PnpUnicodeStringToWstr 
 
int __fastcall PnpUnicodeStringToWstr(int *a1, unsigned int *a2, unsigned __int16 *a3)
{
  int v4; // r6
  unsigned int v7; // r1
  _WORD *v8; // r5
  unsigned int v9; // r0
  unsigned int v11; // r5
  int v12; // r0
  int v13; // r9
  unsigned int v14; // r3
  _WORD *v15; // r2

  v4 = 0;
  if ( !a1 || !a3 )
    return -1073741811;
  v7 = a3[1];
  if ( v7 < 2 || (v8 = (_WORD *)*((_DWORD *)a3 + 1)) == 0 )
  {
    *a1 = 0;
    if ( a2 )
      *a2 = 0;
    return v4;
  }
  v9 = *a3;
  if ( v9 > v7 )
    return -1073741811;
  if ( !*a3 || !*v8 )
    return sub_7E7134();
  if ( (v9 != v7 || v8[(v9 >> 1) - 1]) && (v9 > v7 - 2 || (v15 = &v8[v9 >> 1], *(v15 - 1)) && *v15) )
  {
    v11 = v9 + 2;
    v12 = ExAllocatePoolWithTag(1, v9 + 2, 1970499664);
    v13 = v12;
    if ( v12 )
    {
      memmove(v12, *((_DWORD *)a3 + 1), *a3);
      v14 = *a3;
      *a1 = v13;
      *(_WORD *)(v13 + 2 * (v14 >> 1)) = 0;
      if ( a2 )
        *a2 = v11;
    }
    else
    {
      v4 = -1073741670;
    }
  }
  else
  {
    *a1 = (int)v8;
    if ( a2 )
      *a2 = v7;
  }
  return v4;
}
