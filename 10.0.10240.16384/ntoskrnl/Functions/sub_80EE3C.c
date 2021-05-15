// sub_80EE3C 
 
void __fastcall sub_80EE3C(int a1, int a2)
{
  _DWORD *v2; // r4
  int v3; // r5

  *(_DWORD *)(v3 + 4) = a2 + 8;
  *(_WORD *)v3 = 8;
  *(_WORD *)(v3 + 2) = 8;
  *v2 |= 0x2000u;
  JUMPOUT(0x799052);
}
