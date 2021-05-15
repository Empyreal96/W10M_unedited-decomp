// __ascii_stricmp 
 
int __fastcall _ascii_stricmp(unsigned __int8 *a1, unsigned __int8 *a2)
{
  int v2; // r2
  int v3; // t1
  int v4; // r4
  int v5; // t1
  unsigned int v6; // r3

  do
  {
    v3 = *a1++;
    v2 = v3;
    v5 = *a2++;
    v4 = v5;
    v6 = v5 - 65;
    if ( (unsigned int)(v2 - 65) <= 0x19 )
      v2 += 32;
    if ( v6 <= 0x19 )
      v4 += 32;
  }
  while ( v2 && v2 == v4 );
  return v2 - v4;
}
