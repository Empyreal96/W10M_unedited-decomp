// ViFaultsTracesInitialize 
 
int ViFaultsTracesInitialize()
{
  int v0; // r1
  int result; // r0

  v0 = ViFaultTracesLength;
  if ( (unsigned int)ViFaultTracesLength > 0x101000 )
  {
    v0 = 1052672;
    ViFaultTracesLength = 1052672;
  }
  result = ExAllocatePoolWithTagPriority(512, 36 * v0, 1953786950, 32);
  ViFaultTraces = result;
  return result;
}
