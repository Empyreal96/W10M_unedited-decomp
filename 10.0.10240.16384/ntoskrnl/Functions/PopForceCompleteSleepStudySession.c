// PopForceCompleteSleepStudySession 
 
int __fastcall PopForceCompleteSleepStudySession(int result)
{
  int v1; // r5
  int v2; // r0
  int v3; // r1
  int v4; // r0
  _BYTE v5[144]; // [sp+0h] [bp-90h] BYREF

  v1 = result;
  if ( (GUID *)PopWdiCurrentScenario != &NullGuid )
  {
    if ( dword_61EAC8 )
      dword_61EAC8();
    PopFxCaptureDeviceAccounting();
    PpmSnapDripsAccountingSnapshot();
    PopAcquirePolicyLock(v2, v3);
    v4 = PopCalculateCsSummary((int)v5, v1);
    PopReleasePolicyLock(v4);
    result = PopDiagNextSleepStudySession(&NullGuid, v5);
  }
  return result;
}
