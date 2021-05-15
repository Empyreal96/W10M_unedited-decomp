// IopIrqInitialize 
 
int IopIrqInitialize()
{
  dword_63033C = (int)IopIrqUnpackRequirement;
  dword_630340 = (int)IopIrqPackResource;
  dword_630344 = (int)IopIrqUnpackResource;
  dword_630348 = (int)IopIrqScoreRequirement;
  return ArbInitializeArbiterInstance();
}
