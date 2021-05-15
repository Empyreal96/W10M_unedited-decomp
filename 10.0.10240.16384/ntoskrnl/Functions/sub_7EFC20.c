// sub_7EFC20 
 
void __fastcall sub_7EFC20(int a1)
{
  int v1; // r5
  int v2; // r7

  *(_DWORD *)(a1 + 4 * (*(_DWORD *)(v1 + 4) >> 29)) |= *(_DWORD *)(v1 + 4) & ~v2;
  JUMPOUT(0x784A80);
}
