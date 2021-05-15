// sub_8DFAB8 
 
void __fastcall sub_8DFAB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r5
  int v8; // r1

  BgpFwFreeMemory(v7);
  if ( a7 )
    BgpTxtDestroyRegion(a7, v8);
  JUMPOUT(0x8DDF02);
}
