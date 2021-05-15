// sub_50EC3C 
 
void __fastcall sub_50EC3C(int a1, unsigned int a2)
{
  unsigned int *v2; // r5
  int v3; // r7
  unsigned int v4; // r4

  while ( 1 )
  {
    __dmb(0xBu);
    do
      v4 = __ldrex(v2);
    while ( v4 == a2 && __strex(a2 - 4, v2) );
    __dmb(0xBu);
    if ( v4 == a2 )
      JUMPOUT(0x4CC11A);
    a2 = v4;
    if ( (v4 & v3) == 0 )
      JUMPOUT(0x4CC0A0);
  }
}
