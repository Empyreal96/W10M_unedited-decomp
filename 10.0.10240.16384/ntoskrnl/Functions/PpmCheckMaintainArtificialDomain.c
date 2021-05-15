// PpmCheckMaintainArtificialDomain 
 
int PpmCheckMaintainArtificialDomain()
{
  int result; // r0

  if ( PpmPerfArtificialDomainEnabled )
    result = sub_52608C();
  else
    result = 1;
  return result;
}
