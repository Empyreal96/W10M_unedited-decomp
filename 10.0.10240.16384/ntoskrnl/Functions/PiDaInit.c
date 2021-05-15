// PiDaInit 
 
int PiDaInit()
{
  int v1[2]; // [sp+0h] [bp-8h] BYREF

  v1[0] = 2359330;
  v1[1] = (int)L"\\Driver\\DeviceApi";
  return IoCreateDriver(v1, (int (__fastcall *)(_BYTE *, _DWORD))PiDaDriverEntry);
}
