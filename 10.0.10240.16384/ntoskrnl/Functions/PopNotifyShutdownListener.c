// PopNotifyShutdownListener 
 
int PopNotifyShutdownListener()
{
  int result; // r0

  if ( PopShutdownNotificationCallback )
    result = (*(int (__fastcall **)(_DWORD))PopShutdownNotificationCallback)(*(_DWORD *)(PopShutdownNotificationCallback
                                                                                       + 4));
  return result;
}
