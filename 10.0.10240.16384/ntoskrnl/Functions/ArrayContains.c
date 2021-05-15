// ArrayContains 
 
int __fastcall ArrayContains(int a1, unsigned int a2, int a3, unsigned int a4)
{
  int v4; // r4
  unsigned int v9; // r6
  unsigned int i; // r7

  v4 = 0;
  if ( !a2 || !a4 || !a1 || !a3 || a4 > a2 || (a2 & 0xF) != 0 || (a4 & 0xF) != 0 )
    return 0;
  v9 = 0;
  do
  {
    if ( v9 >= a2 )
      break;
    for ( i = 0; i < a4; i += 16 )
    {
      if ( !memcmp(v9 + a1, i + a3, 16) )
        v4 = 1;
    }
    v9 += 16;
  }
  while ( !v4 );
  return v4;
}
