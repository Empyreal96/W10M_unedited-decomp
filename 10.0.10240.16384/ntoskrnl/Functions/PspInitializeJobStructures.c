// PspInitializeJobStructures 
 
int PspInitializeJobStructures()
{
  off_920168 = &PspJobList;
  PspJobList = &PspJobList;
  PspJobListLock = 0;
  PspJobAssignmentLock = 0;
  dword_61DA18 = (int)PspJobNotificationWorker;
  dword_61DA1C = 0;
  PspJobNotificationItem = 0;
  dword_61D9F8 = (int)PspJobTimeLimitsWork;
  dword_61D9FC = 0;
  PspJobTimeLimitsWorkItem = 0;
  if ( PspJobNoWakeChargeLimit )
    JUMPOUT(0x970AC4);
  return sub_970AC0();
}
