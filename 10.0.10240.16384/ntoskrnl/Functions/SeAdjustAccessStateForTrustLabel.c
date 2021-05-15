// SeAdjustAccessStateForTrustLabel 
 
void __fastcall SeAdjustAccessStateForTrustLabel(int a1, int a2, int a3)
{
  if ( (*(_DWORD *)(a3 + 12) & 6) != 0 )
  {
    if ( SepGetProcessTrustLabelAce(a2) )
      sub_7DC1CC();
  }
}
