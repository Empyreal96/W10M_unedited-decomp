// sub_527B14 
 
void __fastcall sub_527B14(int a1, unsigned __int8 *a2)
{
  int *v2; // r6
  int v3; // r3
  unsigned int v4; // r2

  do
  {
    __dmb(0xAu);
    __yield();
    v3 = *v2;
    __dmb(0xBu);
  }
  while ( (v3 & 0x80000000) != 0 );
  do
    v4 = __ldrex(a2);
  while ( __strex(v4 | 0x80, a2) );
  JUMPOUT(0x4DC50C);
}
