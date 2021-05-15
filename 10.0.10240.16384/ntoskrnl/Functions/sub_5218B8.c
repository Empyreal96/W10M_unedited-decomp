// sub_5218B8 
 
void sub_5218B8()
{
  int v0; // r4
  int v1; // r8
  int v2; // r9

  *(_WORD *)((*(_DWORD *)(v0 + 8) & 0xFFF) + v1 - 2) += HIWORD(v2);
  JUMPOUT(0x455A48);
}
