// IopPortInitialize 
 
int IopPortInitialize()
{
  dword_6304FC = (int)IopPortFindSuitableRange;
  dword_630500 = (int)IopPortAddAllocation;
  dword_630504 = (int)IopPortBacktrackAllocation;
  dword_6304BC = (int)IopGenericUnpackRequirement;
  dword_6304C0 = (int)IopGenericPackResource;
  dword_6304C4 = (int)IopGenericUnpackResource;
  dword_6304C8 = (int)IopGenericScoreRequirement;
  return ArbInitializeArbiterInstance();
}
