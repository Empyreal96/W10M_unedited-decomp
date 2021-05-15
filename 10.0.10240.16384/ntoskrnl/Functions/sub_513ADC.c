// sub_513ADC 
 
void sub_513ADC()
{
  int v0; // r6
  unsigned __int8 *v1; // lr
  int v2; // r3
  unsigned int v3; // r2

  while ( 1 )
  {
    do
    {
      __dmb(0xAu);
      __yield();
      v2 = *(_DWORD *)(v0 + 12);
      __dmb(0xBu);
    }
    while ( v2 < 0 );
    do
      v3 = __ldrex(v1);
    while ( __strex(v3 | 0x80, v1) );
    __dmb(0xBu);
    if ( !(v3 >> 7) )
      JUMPOUT(0x42F7A6);
  }
}
