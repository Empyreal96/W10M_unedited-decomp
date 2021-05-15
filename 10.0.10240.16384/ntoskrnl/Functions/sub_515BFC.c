// sub_515BFC 
 
void __fastcall sub_515BFC(char a1, int a2, int a3)
{
  int v3; // r7
  int v4; // lr
  int v5; // r6
  char v6; // r4

  v5 = *(_DWORD *)(v4 + 4) + a3;
  v6 = *(_BYTE *)(v5 + v3) & ~((1 << a1) - 1);
  *(_BYTE *)(v5 + v3) = v6;
  *(_BYTE *)(v5 + v3) = *(_BYTE *)(*(_DWORD *)(a2 + 4) + a3) & ((1 << a1) - 1) | v6;
  JUMPOUT(0x43498E);
}
