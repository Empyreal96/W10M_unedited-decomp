// SepAdtOpenRegAndSetupNotification 
 
int SepAdtOpenRegAndSetupNotification()
{
  int result; // r0

  result = SepRegOpenKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa", 529, &SepAdtRegNotifyHandle);
  if ( result >= 0 )
  {
    dword_649F1C = (int)SepAdtRegNotificationCallback;
    dword_649F20 = 0;
    SepAdtLsaRegWatchWorkItem = 0;
    result = NtNotifyChangeKey(
               SepAdtRegNotifyHandle,
               0,
               (int)&SepAdtLsaRegWatchWorkItem,
               1,
               (int)&SepAdtIoStatusBlock,
               5,
               0,
               0,
               0,
               1u);
  }
  return result;
}
