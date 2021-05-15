// AuthzBasepEqualUnicodeStringCaseSensitive 
 
BOOL __fastcall AuthzBasepEqualUnicodeStringCaseSensitive(unsigned __int16 *a1, unsigned __int16 *a2)
{
  int v2; // r2
  BOOL v3; // r3

  v2 = *a1;
  if ( v2 == *a2 )
    v3 = memcmp(*((_DWORD *)a1 + 1), *((_DWORD *)a2 + 1), v2) == 0;
  else
    v3 = 0;
  return v3;
}
