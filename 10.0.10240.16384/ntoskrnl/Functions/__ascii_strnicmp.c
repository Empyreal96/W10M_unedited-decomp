// __ascii_strnicmp 
 
int __fastcall _ascii_strnicmp(unsigned __int8 *a1, unsigned __int8 *a2, int a3)
{
  int v3; // r4
  int v4; // t1
  int v5; // r5
  int v6; // t1
  unsigned int v7; // r3

  if ( !a3 )
    return 0;
  do
  {
    v4 = *a1++;
    v3 = v4;
    v6 = *a2++;
    v5 = v6;
    v7 = v6 - 65;
    if ( (unsigned int)(v3 - 65) <= 0x19 )
      v3 += 32;
    if ( v7 <= 0x19 )
      v5 += 32;
    --a3;
  }
  while ( a3 && v3 && v3 == v5 );
  return v3 - v5;
}
