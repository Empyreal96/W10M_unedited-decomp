// VfErrorReleaseTriageInformation 
 
int VfErrorReleaseTriageInformation()
{
  int result; // r0
  unsigned int v1; // r1

  __dmb(0xBu);
  result = 0;
  do
    v1 = __ldrex(&VfErrorBugcheckDataReady);
  while ( __strex(0, &VfErrorBugcheckDataReady) );
  __dmb(0xBu);
  return result;
}
