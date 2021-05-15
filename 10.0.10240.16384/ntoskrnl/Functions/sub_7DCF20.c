// sub_7DCF20 
 
void __fastcall sub_7DCF20(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r6

  if ( !BcdUtilGetBootOption(a4 + a3 + v4, v5) )
    JUMPOUT(0x78BAF0);
  JUMPOUT(0x78BAF8);
}
