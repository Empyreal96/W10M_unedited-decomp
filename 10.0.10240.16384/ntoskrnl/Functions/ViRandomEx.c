// ViRandomEx 
 
unsigned int ViRandomEx()
{
  int v0; // r5
  unsigned int result; // r0

  v0 = ViRandomExAuxVarY & 0x7F;
  ViRandomExAuxVarY = ViRandomExConstantVector[v0];
  result = (2147483629 * ViRandomSeed + 2147483587) % 0x7FFFFFFFu;
  ViRandomSeed = result;
  ViRandomExConstantVector[v0] = result;
  return result;
}
