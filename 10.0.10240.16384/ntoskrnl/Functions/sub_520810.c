// sub_520810 
 
void __fastcall sub_520810(int a1, _DWORD *a2)
{
  _DWORD *v2; // r5
  _DWORD *v3; // r2

  v3 = *(_DWORD **)(a1 + 104);
  *a2 = v3[7];
  *v2 = v3[8];
  v2[1] = v3[9];
  JUMPOUT(0x4528FE);
}
