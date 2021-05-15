// sub_51BBDC 
 
void __fastcall sub_51BBDC(int a1, int a2)
{
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 64) = a2 + 9;
  JUMPOUT(0x444C02);
}
