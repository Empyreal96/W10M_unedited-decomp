// SmUniqueIdParseProductName 
 
int __fastcall SmUniqueIdParseProductName(char *a1, int a2, int a3)
{
  _WORD *v3; // r5
  int v4; // r8
  char *v7; // r0
  char *v9; // r7
  int v10; // r4
  char *v11; // r0
  char *v12; // r4
  int v13; // r3
  _WORD *i; // r0

  v3 = (_WORD *)a2;
  v4 = a2;
  v7 = wcsstr(a1, (char *)L"&Ven_");
  if ( !v7 )
    return -1073700864;
  v9 = v7 + 10;
  v10 = ((char *)wcschr((_WORD *)v7 + 5, 38) - (v7 + 10)) >> 1;
  if ( v10 )
  {
    if ( StringCbCopyNW(v3, a3, v9, 2 * v10) < 0 || StringCbCatW(v3, a3) < 0 )
      return -1073741789;
    v4 = (int)&v3[v10 + 1];
    a3 = a3 - 2 * v10 - 2;
  }
  v11 = wcsstr(a1, (char *)L"&Prod_");
  if ( !v11 )
    return -1073700864;
  v12 = v11 + 12;
  v13 = ((char *)wcschr((_WORD *)v11 + 6, 38) - (v11 + 12)) >> 1;
  if ( v13 && StringCbCopyNW(v4, a3, v12, 2 * v13) < 0 )
    return -1073741789;
  for ( i = v3; ; *i = 32 )
  {
    i = wcschr(i, 95);
    if ( !i )
      break;
  }
  return 0;
}
