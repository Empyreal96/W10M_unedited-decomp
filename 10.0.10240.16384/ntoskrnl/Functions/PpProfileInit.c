// PpProfileInit 
 
void PpProfileInit()
{
  PiProfileDeviceListHead = (int)&PiProfileDeviceListHead;
  *(_DWORD *)algn_62FB34 = &PiProfileDeviceListHead;
  PiProfileDeviceListLock = 1;
  dword_62FB44 = 0;
  unk_62FB48 = 0;
  byte_62FB4C = 1;
  byte_62FB4D = 0;
  byte_62FB4E = 4;
  dword_62FB50 = 0;
  dword_62FB58 = (int)&dword_62FB54;
  dword_62FB54 = (int)&dword_62FB54;
  PiProfileDeviceCount = 0;
  PiProfileChangeSemaphore = 5;
  byte_62FB62 = 5;
  dword_62FB64 = 1;
  dword_62FB6C = (int)&dword_62FB68;
  dword_62FB68 = (int)&dword_62FB68;
  dword_62FB70 = 1;
}
