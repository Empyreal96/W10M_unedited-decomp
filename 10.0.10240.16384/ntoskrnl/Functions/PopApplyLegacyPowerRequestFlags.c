// PopApplyLegacyPowerRequestFlags 
 
int __fastcall PopApplyLegacyPowerRequestFlags(int result, char a2, char a3, int a4)
{
  int v6; // r4

  v6 = result;
  if ( (a3 & 1) != 0 )
  {
    if ( (a2 & 1) != 0 )
      result = PoSetPowerRequestInternal(result, 1u, a3, a4);
    else
      result = PoClearPowerRequestInternal(result, 1u, a3, a4);
  }
  if ( (a3 & 2) != 0 )
  {
    if ( (a2 & 2) != 0 )
      result = PoSetPowerRequestInternal(v6, 0, a3, a4);
    else
      result = PoClearPowerRequestInternal(v6, 0, a3, a4);
  }
  if ( (a3 & 0x40) != 0 )
  {
    if ( (a2 & 0x40) != 0 )
      result = PoSetPowerRequestInternal(v6, 2u, a3, a4);
    else
      result = PoClearPowerRequestInternal(v6, 2u, a3, a4);
  }
  return result;
}
