// KeUpdateGroupSchedulingConstants 
 
int KeUpdateGroupSchedulingConstants()
{
  __int64 v0; // r0

  LODWORD(v0) = _rt_udiv64(1000i64, *((_QWORD *)KiProcessorBlock + 121));
  KiCycleDivisorShortTerm = v0 * (unsigned int)PsDfssShortTermSharingMS;
  KiCycleDivisorLongTerm = v0 * (unsigned int)PsDfssLongTermSharingMS;
  KiCyclesPerGeneration = v0 * (unsigned int)PsDfssGenerationLengthMS;
  KiGroupSchedulingNumerator = PsDfssLongTermFraction1024;
  if ( !KeMaximumIncrement )
    __brkdiv0();
  KiGenerationTicks = _rt_udiv64((unsigned int)KeMaximumIncrement, 10000i64 * (unsigned int)PsDfssGenerationLengthMS);
  return KiAssignSchedulingGroupWeights(0, 1, 0);
}
