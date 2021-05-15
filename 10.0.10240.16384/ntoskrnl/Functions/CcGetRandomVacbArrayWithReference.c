// CcGetRandomVacbArrayWithReference 
 
int CcGetRandomVacbArrayWithReference()
{
  unsigned int v0; // r1
  unsigned int i; // r1
  int v2; // r4
  int v3; // r5
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r1

  v0 = RtlRandomEx(&CcRandomSeed);
  if ( CcVacbArraysHighestUsedIndex == -1 )
    __brkdiv0();
  for ( i = v0 % (CcVacbArraysHighestUsedIndex + 1); ; i = v6 % (CcVacbArraysHighestUsedIndex + 1) )
  {
    v2 = i;
    if ( !*(_DWORD *)(CcVacbArrays + 4 * i) )
      goto LABEL_7;
    v3 = KeAcquireQueuedSpinLock(4);
    v4 = CcReferenceVacbArray(v2);
    v5 = v4;
    if ( v4 )
      break;
    KeReleaseQueuedSpinLock(4, v3);
LABEL_7:
    v6 = RtlRandomEx(&CcRandomSeed);
    if ( CcVacbArraysHighestUsedIndex == -1 )
      __brkdiv0();
  }
  CcRecalculateVacbArrayHighwaterMark(v4);
  KeReleaseQueuedSpinLock(4, v3);
  return v5;
}
