// sub_7D0E64 
 
void __fastcall sub_7D0E64(int a1, int a2, unsigned int *a3, int a4, int a5, int a6, unsigned __int16 a7)
{
  unsigned int v7; // r0

  do
    v7 = __ldrex(a3);
  while ( __strex(a7, a3) );
  JUMPOUT(0x78B1E8);
}
