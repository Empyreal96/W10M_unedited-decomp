// sub_7D0A44 
 
void __fastcall sub_7D0A44(int a1, int a2)
{
  int v2; // r6
  int v3; // r9
  int v4; // r10

  memmove(v3 + 1152, a2, 0x180u);
  *(_DWORD *)(v2 + 4 * v4) = v3 + 1152;
  JUMPOUT(0x78AC0A);
}
