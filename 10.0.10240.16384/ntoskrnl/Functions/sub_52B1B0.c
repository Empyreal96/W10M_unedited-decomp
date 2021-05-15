// sub_52B1B0 
 
void __fastcall sub_52B1B0(unsigned __int8 *a1)
{
  unsigned int v1; // r2

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( (*(_DWORD *)a1 & 0x80) != 0 );
  do
    v1 = __ldrex(a1);
  while ( __strex(v1 | 0x80, a1) );
  JUMPOUT(0x46C86A);
}
