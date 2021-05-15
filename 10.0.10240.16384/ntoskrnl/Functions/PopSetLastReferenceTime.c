// PopSetLastReferenceTime 
 
int PopSetLastReferenceTime()
{
  int result; // r0

  KeQuerySystemTime(&algn_637422[6]);
  result = RtlComputeCrc32(0, (int)&algn_637422[6], 8u);
  dword_637430 = result;
  return result;
}
