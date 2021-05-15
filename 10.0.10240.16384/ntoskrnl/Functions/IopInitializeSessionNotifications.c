// IopInitializeSessionNotifications 
 
int IopInitializeSessionNotifications()
{
  _BYTE v1[8]; // [sp+0h] [bp-28h] BYREF
  int v2[8]; // [sp+8h] [bp-20h] BYREF

  IopSessionNotificationQueueHead = (int)&IopSessionNotificationQueueHead;
  dword_63172C = (int)&IopSessionNotificationQueueHead;
  IopSessionNotificationLock = 0;
  RtlInitUnicodeString((unsigned int)v1, L"\\Callback\\IoSessionNotifications");
  v2[0] = 24;
  v2[1] = 0;
  v2[3] = 80;
  v2[2] = (int)v1;
  v2[4] = 0;
  v2[5] = 0;
  return ExCreateCallback(&IopSessionCallbackObject, v2, 1, 1);
}
