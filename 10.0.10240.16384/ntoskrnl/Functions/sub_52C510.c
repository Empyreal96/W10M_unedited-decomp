// sub_52C510 
 
void __fastcall sub_52C510(unsigned int *a1)
{
  int v1; // r6
  unsigned int v2; // r7
  int v3; // lr
  unsigned int v4; // r1
  unsigned int v5; // r2

  while ( 1 )
  {
    v4 = v2;
    __dmb(0xBu);
    do
      v5 = __ldrex(a1);
    while ( v5 == v2 && __strex(v2 & ~v1 | (v3 << 8), a1) );
    v2 = v5;
    __dmb(0xBu);
    if ( v4 == v5 )
      JUMPOUT(0x471B30);
  }
}
