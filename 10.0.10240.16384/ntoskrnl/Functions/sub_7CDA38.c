// sub_7CDA38 
 
void __fastcall sub_7CDA38(int a1)
{
  int v1; // r5

  *(_WORD *)v1 = *(_WORD *)a1;
  *(_DWORD *)(v1 + 4) = *(_DWORD *)(a1 + 4);
  JUMPOUT(0x771CC6);
}
