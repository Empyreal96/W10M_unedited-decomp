// ObpInitInfoBlockOffsets 
 
void ObpInitInfoBlockOffsets()
{
  unsigned int i; // r2
  unsigned __int8 v1; // r3

  for ( i = 0; i < 0x100; ++i )
  {
    v1 = 0;
    if ( (i & 1) != 0 )
      v1 = 16;
    if ( (i & 2) != 0 )
      v1 += 16;
    if ( (i & 4) != 0 )
      v1 += 8;
    if ( (i & 8) != 0 )
      v1 += 16;
    if ( (i & 0x10) != 0 )
      v1 += 8;
    if ( (i & 0x20) != 0 )
      v1 += 8;
    if ( (i & 0x40) != 0 )
      v1 += 16;
    if ( (i & 0x80) != 0 )
      v1 += 4;
    ObpInfoMaskToOffset[i] = v1;
  }
}
