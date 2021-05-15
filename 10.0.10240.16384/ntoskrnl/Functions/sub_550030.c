// sub_550030 
 
void __fastcall sub_550030(int a1, unsigned __int8 *a2)
{
  int *v2; // r4
  int v3; // r3
  unsigned int v4; // r2

  while ( 1 )
  {
    do
    {
      __dmb(0xAu);
      __yield();
      v3 = *v2;
      __dmb(0xBu);
    }
    while ( v3 < 0 );
    do
      v4 = __ldrex(a2);
    while ( __strex(v4 | 0x80, a2) );
    __dmb(0xBu);
    if ( !(v4 >> 7) )
      JUMPOUT(0x4EBC5C);
  }
}
