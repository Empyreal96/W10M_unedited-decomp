// sub_550060 
 
void __fastcall sub_550060(int a1, unsigned __int8 *a2)
{
  int v2; // r4
  int v3; // r6
  int v4; // r3
  unsigned int v5; // r2

  do
  {
    __dmb(0xAu);
    __yield();
    v4 = *(_DWORD *)(v2 + 12);
    __dmb(0xBu);
  }
  while ( (v4 & v3) != 0 );
  do
    v5 = __ldrex(a2);
  while ( __strex(v5 | 0x80, a2) );
  __dmb(0xBu);
  JUMPOUT(0x4EBCF4);
}
