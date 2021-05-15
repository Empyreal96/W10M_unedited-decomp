// sub_515058 
 
void __fastcall sub_515058(int a1, int a2, int a3)
{
  unsigned __int8 *v3; // r6
  unsigned int v4; // r2

  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( (*(_DWORD *)v3 & a3) != 0 );
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 | 0x80, v3) );
  __dmb(0xBu);
  JUMPOUT(0x4326DA);
}
