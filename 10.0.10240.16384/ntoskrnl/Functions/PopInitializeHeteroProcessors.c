// PopInitializeHeteroProcessors 
 
int PopInitializeHeteroProcessors()
{
  _BYTE *v0; // r0
  int result; // r0
  _BYTE v2[24]; // [sp-10h] [bp-18h] BYREF

  if ( PopConfigureHeteroProcessors(v2) )
    v0 = v2;
  else
    v0 = 0;
  result = KeConfigureHeteroProcessors((int)v0);
  if ( result )
    return sub_7D0A64();
  if ( !PopHeteroSystem )
  {
    result = 0;
    PpmHeteroPolicy = 0;
  }
  if ( PpmPerfArtificialDomainSetting == -1 )
    PpmPerfArtificialDomainEnabled = PopHeteroSystem;
  return result;
}
