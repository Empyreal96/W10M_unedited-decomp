// CmpInitializeFreezeThaw 
 
int CmpInitializeFreezeThaw()
{
  int result; // r0

  CmpFreezeThawWaitListHead = (int)&CmpFreezeThawWaitListHead;
  dword_63224C = (int)&CmpFreezeThawWaitListHead;
  CmpFreezeListLock = 0;
  if ( (unsigned int)CmFreezeThawTimeoutInSeconds > 0x384 )
    result = sub_81CA2C();
  return result;
}
