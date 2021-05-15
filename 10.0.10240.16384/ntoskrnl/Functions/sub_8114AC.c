// sub_8114AC 
 
void __fastcall sub_8114AC(int a1, int a2)
{
  *(_DWORD *)(a2 + 4) = a1 + 16;
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(a1 + 16) - 28;
  JUMPOUT(0x79F986);
}
