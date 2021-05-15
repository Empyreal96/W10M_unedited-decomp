// IoUnregisterPlugPlayNotificationEx 
 
int __fastcall IoUnregisterPlugPlayNotificationEx(int a1)
{
  return PnpUnregisterPlugPlayNotification(a1, 1);
}
