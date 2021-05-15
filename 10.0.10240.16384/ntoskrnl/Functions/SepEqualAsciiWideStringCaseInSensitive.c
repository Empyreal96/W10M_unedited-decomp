// SepEqualAsciiWideStringCaseInSensitive 
 
int __fastcall SepEqualAsciiWideStringCaseInSensitive(unsigned __int16 *a1, unsigned __int16 *a2)
{
  unsigned int v2; // r4
  char *v3; // r0
  char *v4; // r1
  char *i; // r5
  int v6; // r1
  unsigned int v7; // r3
  unsigned int v8; // r2

  v2 = *a1;
  if ( v2 != *a2 )
    return 0;
  v3 = (char *)*((_DWORD *)a1 + 1);
  v4 = (char *)*((_DWORD *)a2 + 1);
  for ( i = &v3[v2]; v2 >= 4; v4 += 4 )
  {
    if ( *(_DWORD *)v3 != *(_DWORD *)v4 )
      break;
    v2 -= 4;
    if ( !v2 )
      return 1;
    v3 += 4;
  }
  if ( v3 >= i )
    return 1;
  v6 = v4 - v3;
  while ( 1 )
  {
    v7 = *(unsigned __int16 *)v3;
    v8 = *(unsigned __int16 *)&v3[v6];
    if ( v7 != v8 )
    {
      if ( v7 >= 0x61 && v7 <= 0x7A )
        v7 -= 32;
      if ( v8 >= 0x61 && v8 <= 0x7A )
        v8 -= 32;
      if ( v7 != v8 )
        break;
    }
    v3 += 2;
    if ( v3 >= i )
      return 1;
  }
  return 0;
}
