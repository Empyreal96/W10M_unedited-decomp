// sub_8AA934 
 
int __fastcall sub_8AA934(int a1)
{
  int v1; // r0
  int v2; // r1
  int v3; // r1

  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  *(_BYTE *)(a1 + 28) = 0;
  *(_BYTE *)(a1 + 29) = 0;
  *(_BYTE *)(a1 + 30) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  v1 = ((int (*)(void))sub_8AA96C)();
  sub_8AA96C(v1 + 36);
  sub_8AA96C(v2 + 48);
  return sub_8AA96C(v3 + 60);
}
