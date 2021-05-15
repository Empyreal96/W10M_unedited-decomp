// FsRtlDeregisterUncProvider 
 
int __fastcall FsRtlDeregisterUncProvider(int result)
{
  if ( result != -1 && result )
  {
    result = ZwClose();
    if ( result >= 0 )
    {
      KeWaitForSingleObject((unsigned int)&FsRtlpUncSemaphore, 0, 0, 0, 0);
      --FsRtlpRedirs;
      result = KeReleaseSemaphore((int)&FsRtlpUncSemaphore, 0, 1);
    }
  }
  return result;
}
