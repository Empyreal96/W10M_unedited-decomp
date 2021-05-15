// PopUserShutdownCancelled 
 
int __fastcall PopUserShutdownCancelled(int a1)
{
  int v2; // r4
  int result; // r0
  int v4; // r1

  v2 = 0;
  PopAcquirePolicyLock();
  if ( PopUserShutdownInProgress )
  {
    KeCancelTimer((int)PopUserShutdownDelayTimer);
    PopUserShutdownInProgress = 0;
    v2 = 1;
  }
  result = PopReleasePolicyLock();
  if ( dword_61EAA8 )
  {
    result = dword_61EAA8(a1);
    v2 = result;
  }
  if ( v2 )
    result = PpmEndHighPerfRequest(2, v4);
  return result;
}
