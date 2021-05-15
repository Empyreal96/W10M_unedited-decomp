// sub_527534 
 
void sub_527534()
{
  unsigned int *v0; // r4
  unsigned int v1; // r2
  signed int v2; // r2
  unsigned int v3; // r2

  __dmb(0xBu);
  do
  {
    v1 = __ldrex(v0);
    v2 = v1 + 1;
  }
  while ( __strex(v2, v0) );
  __dmb(0xBu);
  if ( v2 > CcAggressiveZeroThreshold )
  {
    __dmb(0xBu);
    do
      v3 = __ldrex(v0);
    while ( __strex(v3 - 1, v0) );
    __dmb(0xBu);
  }
  JUMPOUT(0x4D8A7C);
}
