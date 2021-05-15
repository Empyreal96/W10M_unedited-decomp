// IoUnregisterPlugPlayNotification 
 
int __fastcall IoUnregisterPlugPlayNotification(int a1)
{
  return PnpUnregisterPlugPlayNotification(a1, 0);
}
