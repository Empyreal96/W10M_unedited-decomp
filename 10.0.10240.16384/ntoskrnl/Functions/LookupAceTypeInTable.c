// LookupAceTypeInTable 
 
__int16 **__fastcall LookupAceTypeInTable(int a1, __int16 *a2, int a3)
{
  __int16 **v3; // r4
  unsigned int v4; // r0
  __int16 **v5; // r5

  v3 = 0;
  v4 = 0;
  v5 = &off_618A48;
  do
  {
    if ( ((unsigned int)v5[3] & a3) == a3 && a2 == v5[2] )
      break;
    ++v4;
    v5 += 4;
  }
  while ( v4 < 0x10 );
  if ( v4 < 0x10 )
    v3 = &(&off_618A48)[4 * v4];
  return v3;
}
