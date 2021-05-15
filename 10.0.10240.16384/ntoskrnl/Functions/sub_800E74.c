// sub_800E74 
 
void sub_800E74()
{
  int v0; // r4
  char v1; // r5
  unsigned int v2; // r6

  if ( (v1 & 1) != 0 )
    PsReturnProcessPageFileQuota(v0, v2);
  if ( (v1 & 2) != 0 )
    MiReturnProcessCommitment(v0, v2);
  if ( (v1 & 4) != 0 )
    PspChangeJobMemoryUsageByProcess(16);
  MiCommitRequestFailed(v0);
  JUMPOUT(0x73C790);
}
