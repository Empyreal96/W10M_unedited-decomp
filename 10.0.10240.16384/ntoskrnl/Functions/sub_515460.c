// sub_515460 
 
void __fastcall sub_515460(int a1, int a2, int a3, unsigned __int8 *a4)
{
  unsigned int v4; // r4

  do
    v4 = __ldrex(a4);
  while ( __strex(v4 | 4, a4) );
  __dmb(0xBu);
  JUMPOUT(0x433000);
}
