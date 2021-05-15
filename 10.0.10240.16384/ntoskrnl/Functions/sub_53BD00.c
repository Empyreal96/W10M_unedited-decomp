// sub_53BD00 
 
void __fastcall sub_53BD00(int a1)
{
  int v1; // r4

  *(_DWORD *)(a1 + 12) = *(_DWORD *)(a1 + 12) & 0xFFF00000 | v1 & 0xFFFFF;
  JUMPOUT(0x49DF6A);
}
