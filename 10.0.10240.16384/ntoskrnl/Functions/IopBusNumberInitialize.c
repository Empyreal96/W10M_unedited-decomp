// IopBusNumberInitialize 
 
int IopBusNumberInitialize()
{
  dword_63027C = (int)IopBusNumberUnpackRequirement;
  dword_630280 = (int)IopBusNumberPackResource;
  dword_630284 = (int)IopBusNumberUnpackResource;
  dword_630288 = (int)IopBusNumberScoreRequirement;
  return ArbInitializeArbiterInstance();
}
