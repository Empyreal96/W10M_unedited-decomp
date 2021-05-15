// LookupAceFlagsInTable 
 
__int16 **__fastcall LookupAceFlagsInTable(int a1, __int16 *a2, int a3)
{
  __int16 **v3; // r4
  unsigned int v4; // r0
  __int16 **v5; // r5

  v3 = 0;
  v4 = 0;
  v5 = &off_6189D8;
  do
  {
    if ( ((unsigned int)v5[3] & a3) == a3 && a2 == v5[2] )
      break;
    ++v4;
    v5 += 4;
  }
  while ( v4 < 7 );
  if ( v4 < 7 )
    v3 = &(&off_6189D8)[4 * v4];
  return v3;
}
