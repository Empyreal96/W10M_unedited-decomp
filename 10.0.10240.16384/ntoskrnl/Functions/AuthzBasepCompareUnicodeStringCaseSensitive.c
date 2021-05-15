// AuthzBasepCompareUnicodeStringCaseSensitive 
 
int __fastcall AuthzBasepCompareUnicodeStringCaseSensitive(unsigned __int16 *a1, unsigned __int16 *a2)
{
  unsigned __int16 *v2; // r4
  unsigned __int16 *v3; // r5
  unsigned int v4; // r0
  unsigned int v5; // r1
  unsigned int v6; // r3
  unsigned __int16 *v7; // r6

  v2 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
  v3 = (unsigned __int16 *)*((_DWORD *)a2 + 1);
  v4 = *a1;
  v5 = *a2;
  v6 = v4;
  if ( v4 >= v5 )
    v6 = v5;
  v7 = (unsigned __int16 *)((char *)v2 + v6);
  while ( 1 )
  {
    if ( v2 >= v7 )
      return v4 - v5;
    if ( *v2 != *v3 )
      break;
    ++v2;
    ++v3;
  }
  return *v2 - *v3;
}
