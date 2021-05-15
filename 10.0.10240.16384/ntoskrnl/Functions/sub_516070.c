// sub_516070 
 
void sub_516070()
{
  unsigned __int8 *v0; // r6
  int v1; // lr
  unsigned int v2; // r2

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( (*(_DWORD *)v0 & v1) != 0 );
  do
    v2 = __ldrex(v0);
  while ( __strex(v2 | 0x80, v0) );
  JUMPOUT(0x434FFE);
}
