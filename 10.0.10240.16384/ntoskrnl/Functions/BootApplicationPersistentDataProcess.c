// BootApplicationPersistentDataProcess 
 
int __fastcall BootApplicationPersistentDataProcess(int result)
{
  int v1; // r0
  int v2; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r0
  int v8; // r0

  if ( (int *)dword_6475C0 != &dword_6475C0 )
  {
    if ( result )
    {
      if ( result == 1 )
        result = sub_96D76C();
    }
    else
    {
      v1 = BapdpProcessWmdResults();
      v2 = BapdpProcessResumeInformation(v1);
      v3 = BapdpProcessBitlockerStatus(v2);
      v4 = BapdpProcessSecureBootPolicy(v3);
      v5 = BapdpProcessSiData(v4);
      v6 = BapdpProcessSystemIntegrityPolicy(v5);
      v7 = BapdpProcessEDrvHintInfo(v6);
      v8 = BapdpProcessFwUpdateResults(v7);
      result = BapdpProcessBootMetadata(v8);
    }
  }
  return result;
}
