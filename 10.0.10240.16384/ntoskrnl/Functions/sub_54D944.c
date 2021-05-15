// sub_54D944 
 
void __fastcall sub_54D944(int a1, int a2, int a3)
{
  int v3; // r4

  __mcr(15, 0, a3 | v3, 1, 0, 2);
  __isb(0xFu);
  JUMPOUT(0x4E234E);
}
