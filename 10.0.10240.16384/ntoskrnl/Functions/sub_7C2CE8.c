// sub_7C2CE8 
 
void __fastcall sub_7C2CE8(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  unsigned int *v5; // r2
  unsigned int v6; // r0

  __dmb(0xBu);
  v5 = (unsigned int *)(a4 + v4);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x400000, v5) );
  __dmb(0xBu);
  JUMPOUT(0x6B03E2);
}
