// sub_7C23DC 
 
void __fastcall sub_7C23DC(int a1, int a2)
{
  int v2; // r4

  memmove(a1, a2, 4 * (*(unsigned __int8 *)(a2 + 1) + 2));
  *(_DWORD *)(v2 + 156) = *(_DWORD *)(v2 + 160);
  JUMPOUT(0x6ACA18);
}
