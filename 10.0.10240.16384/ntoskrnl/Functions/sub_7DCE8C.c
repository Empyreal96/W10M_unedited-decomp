// sub_7DCE8C 
 
void __fastcall sub_7DCE8C(int a1)
{
  _DWORD *v1; // r4
  _DWORD *v2; // r2

  v2 = (_DWORD *)(*(_DWORD *)(a1 + 4) + a1);
  *v1 = *v2;
  v1[1] = v2[1];
  JUMPOUT(0x78B758);
}
