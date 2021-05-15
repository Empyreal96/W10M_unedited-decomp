// sub_50A604 
 
void __fastcall sub_50A604(int a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r2
  unsigned int v5; // r1

  v4 = (unsigned int *)(a4 + 48);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 + 1, v4) );
  __dmb(0xBu);
  JUMPOUT(0x4D9990);
}
