// SmWatchDogDeviceIoComplete 
 
int __fastcall SmWatchDogDeviceIoComplete(int a1, _DWORD *a2, int a3)
{
  return SmWdWorkItemUpdate(dword_636188, a1, a2, a3);
}
