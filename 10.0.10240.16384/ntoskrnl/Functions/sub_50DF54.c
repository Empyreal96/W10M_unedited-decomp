// sub_50DF54 
 
void __fastcall sub_50DF54(int a1, int a2)
{
  unsigned __int8 *v2; // r3
  unsigned int v3; // r2

  v2 = (unsigned __int8 *)(a2 + 81);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 8, v2) );
  JUMPOUT(0x4A8CC0);
}
