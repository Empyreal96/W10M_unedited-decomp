// sub_7FB418 
 
void sub_7FB418()
{
  int v0; // r4

  if ( (*(_DWORD *)(v0 + 176) & 0x8000) != 0 )
    SepDeleteClaimAttributes();
  *(_DWORD *)(v0 + 636) = 0;
  JUMPOUT(0x72E8A4);
}
