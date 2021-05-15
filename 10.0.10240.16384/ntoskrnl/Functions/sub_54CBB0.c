// sub_54CBB0 
 
void sub_54CBB0()
{
  int v0; // r6
  unsigned __int8 *v1; // r1
  int v2; // r3
  unsigned int v3; // r2

  v1 = (unsigned __int8 *)(v0 + 15);
  while ( 1 )
  {
    do
    {
      __dmb(0xAu);
      __yield();
      v2 = *(_DWORD *)(v0 + 12);
      __dmb(0xBu);
    }
    while ( (v2 & 0x80000000) != 0 );
    do
      v3 = __ldrex(v1);
    while ( __strex(v3 | 0x80, v1) );
    __dmb(0xBu);
    if ( !(v3 >> 7) )
      JUMPOUT(0x4D6A22);
  }
}
