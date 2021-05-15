// sub_50ED74 
 
void sub_50ED74()
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
  __dmb(0xBu);
  JUMPOUT(0x4D19CA);
}
