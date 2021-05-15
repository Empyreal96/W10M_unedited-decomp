// PopExecutionRequiredSettingCallback 
 
int __fastcall PopExecutionRequiredSettingCallback(unsigned int a1, int *a2, int a3)
{
  PopAcquirePowerRequestPushLock(1);
  if ( !memcmp((unsigned int)&GUID_EXECUTION_REQUIRED_REQUEST_TIMEOUT, a1, 16) && a3 == 4 && a2 )
  {
    PopExecutionRequiredTimeout = *a2;
    PopEnableExecutionRequiredPowerRequests();
  }
  return sub_81C4C0();
}
