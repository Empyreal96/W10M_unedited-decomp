// sub_52B0D4 
 
void sub_52B0D4()
{
  unsigned __int8 *v0; // r6
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
  JUMPOUT(0x46C442);
}
