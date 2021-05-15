// sub_51EFE0 
 
void __fastcall sub_51EFE0(int a1, int a2, int a3, unsigned __int8 *a4)
{
  unsigned int v4; // r1

  do
    v4 = __ldrex(a4);
  while ( __strex(v4 | 0x80, a4) );
  JUMPOUT(0x44E6DC);
}
