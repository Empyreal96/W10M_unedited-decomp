// sub_7F1770 
 
void __fastcall sub_7F1770(int a1, int a2, int a3)
{
  *(_BYTE *)(a3 + 31) = 0;
  PopResetCurrentPolicies();
  JUMPOUT(0x78C902);
}
