// PdcPoPerfOverride 
 
int PdcPoPerfOverride()
{
  int v0; // r1

  PpmBeginHighPerfRequest();
  return PpmEndHighPerfRequest(1, v0);
}
