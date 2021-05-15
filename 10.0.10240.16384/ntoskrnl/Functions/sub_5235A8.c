// sub_5235A8 
 
void __fastcall sub_5235A8(int a1, _DWORD *a2)
{
  int v2; // r4
  _DWORD *v3; // r7
  int v4; // r8
  int v5; // r9

  *v3 = (v2 & 0xFFFFF800 | ((_WORD)v2 - ((_WORD)v5 - (_WORD)v4)) & 0x7FF) + ((v5 - v4) << 12);
  *a2 |= v5;
  a2[1] = *v3;
  JUMPOUT(0x459AB4);
}
