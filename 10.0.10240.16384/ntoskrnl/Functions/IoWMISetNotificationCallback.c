// IoWMISetNotificationCallback 
 
int __fastcall IoWMISetNotificationCallback(int a1, int a2, int a3)
{
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  *(_DWORD *)(a1 + 48) = a2;
  *(_DWORD *)(a1 + 52) = a3;
  KeReleaseMutex((int)&WmipSMMutex);
  return 0;
}
