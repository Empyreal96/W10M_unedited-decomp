// sub_81AB04 
 
void __fastcall sub_81AB04(int a1, int a2, int a3)
{
  *(_DWORD *)(a2 + 40) = a3 + 2;
  *(_WORD *)(a2 + 12) = 1;
  JUMPOUT(0x7B7F9E);
}
