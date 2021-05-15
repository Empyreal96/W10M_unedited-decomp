// sub_7DBAC4 
 
void __fastcall sub_7DBAC4(int a1, int a2, _DWORD *a3, int a4, int a5, int a6)
{
  char v6; // zf
  int v7; // r1

  if ( !v6 )
    __fastfail(0xEu);
  v7 = a3[22];
  a5 = a3[1];
  a6 = a3[2];
  SepDeReferenceLogonSession(&a5, v7);
  JUMPOUT(0x6E49BE);
}
