// sub_51D4E4 
 
void __fastcall sub_51D4E4(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r4

  if ( SepDuplicateClaimAttributes(a1, &a5) >= 0 )
  {
    *(_DWORD *)(v5 + 636) = a5;
    *(_DWORD *)(v5 + 176) |= 0x8000u;
  }
  JUMPOUT(0x44A6F0);
}
