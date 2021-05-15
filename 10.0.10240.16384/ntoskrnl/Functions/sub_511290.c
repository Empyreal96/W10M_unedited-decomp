// sub_511290 
 
void __fastcall sub_511290(int a1, int a2, int a3, char a4)
{
  int v4; // r4

  if ( a2 || (a4 & 1) != 0 )
    SmKmStoreHelperWaitForCommand(v4, 0, 0, 0);
  JUMPOUT(0x429D80);
}
