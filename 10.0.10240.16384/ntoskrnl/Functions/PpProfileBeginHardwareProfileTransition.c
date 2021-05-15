// PpProfileBeginHardwareProfileTransition 
 
int __fastcall PpProfileBeginHardwareProfileTransition(int result)
{
  if ( !result )
    result = KeWaitForSingleObject((unsigned int)&PiProfileChangeSemaphore, 0, 0, 0, 0);
  return result;
}
