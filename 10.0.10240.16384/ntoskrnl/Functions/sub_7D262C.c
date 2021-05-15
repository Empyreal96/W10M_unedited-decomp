// sub_7D262C 
 
void __fastcall sub_7D262C(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  bool v5; // zf
  unsigned __int64 v6; // r2

  v5 = *(_DWORD *)(a4 + 8) == a4 + 8;
  LODWORD(v6) = *(_DWORD *)(v4 + 32);
  HIDWORD(v6) = *(_DWORD *)(v6 + 144);
  if ( v5 )
    HIDWORD(v6) &= ~a2;
  else
    HIDWORD(v6) |= a2;
  *(_DWORD *)(v6 + 144) = HIDWORD(v6);
  HvMarkBaseBlockDirty(v4, v6);
  JUMPOUT(0x6D18C4);
}
