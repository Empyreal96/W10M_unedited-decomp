// sub_522B60 
 
void sub_522B60()
{
  unsigned __int8 *v0; // r5
  unsigned int v1; // r2

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( (*(_DWORD *)v0 & 0x80) != 0 );
  do
    v1 = __ldrex(v0);
  while ( __strex(v1 | 0x80, v0) );
  JUMPOUT(0x457CB4);
}
