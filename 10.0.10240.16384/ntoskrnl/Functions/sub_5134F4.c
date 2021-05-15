// sub_5134F4 
 
void __fastcall sub_5134F4(int a1, unsigned __int8 *a2, int a3)
{
  int v3; // r9
  int v4; // r3
  unsigned int v5; // r2

  do
  {
    __dmb(0xAu);
    __yield();
    v4 = *(_DWORD *)(v3 + 12);
    __dmb(0xBu);
  }
  while ( (v4 & a3) != 0 );
  do
    v5 = __ldrex(a2);
  while ( __strex(v5 | 0x80, a2) );
  JUMPOUT(0x42E566);
}
