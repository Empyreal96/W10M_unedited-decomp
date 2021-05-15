// sub_521020 
 
void __fastcall sub_521020(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r0

  v4 = *(_DWORD *)(a3 + 8);
  if ( (v4 & a2) != 0 )
    *(_DWORD *)(a3 + 8) = v4 & ~a2;
  *(_DWORD *)(a3 + 8) &= ~v3;
  JUMPOUT(0x4542FA);
}
