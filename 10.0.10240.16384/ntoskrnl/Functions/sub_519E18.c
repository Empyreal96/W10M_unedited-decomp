// sub_519E18 
 
void __fastcall sub_519E18(int a1, int a2, char a3)
{
  unsigned int v3; // r6

  if ( v3 > 7 )
  {
    if ( !*(_BYTE *)(a2 + 3161) && (a3 & 0x1E) == 0 && *(_DWORD *)(a2 + 1412) == *(_DWORD *)(a2 + 1420) )
      JUMPOUT(0x43E54C);
    JUMPOUT(0x43E514);
  }
  JUMPOUT(0x43E50A);
}
