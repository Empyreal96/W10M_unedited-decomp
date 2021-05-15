// sub_50CDC0 
 
void sub_50CDC0()
{
  unsigned __int8 *v0; // r4
  unsigned int v1; // r2

  while ( 1 )
  {
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)v0 & 0x80) != 0 );
    do
      v1 = __ldrex(v0);
    while ( __strex(v1 | 0x80, v0) );
    __dmb(0xBu);
    if ( !(v1 >> 7) )
      JUMPOUT(0x481E6C);
  }
}
