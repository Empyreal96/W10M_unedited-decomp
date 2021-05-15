// sub_7E9894 
 
void __fastcall sub_7E9894(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v5; // r7
  unsigned int *v6; // r2
  unsigned int v7; // r0

  v6 = (unsigned int *)((a4 & ~v5) + 756);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 + v4, v6) );
  JUMPOUT(0x70300C);
}
