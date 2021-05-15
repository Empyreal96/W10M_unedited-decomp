// sub_96B6F8 
 
void __fastcall sub_96B6F8(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r5
  int v6; // r8
  int v7; // r10

  *(_DWORD *)(v7 + 4 * v6) += MxComputePfnPagesNeeded(a5, v5);
  JUMPOUT(0x9570C6);
}
