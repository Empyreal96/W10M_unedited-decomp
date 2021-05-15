// KeGetSchedulingGroupSize 
 
int KeGetSchedulingGroupSize()
{
  return 248 * KeMaximumProcessors + 128;
}
