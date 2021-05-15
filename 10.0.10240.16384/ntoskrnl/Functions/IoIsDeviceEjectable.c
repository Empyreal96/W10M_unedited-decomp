// IoIsDeviceEjectable 
 
BOOL __fastcall IoIsDeviceEjectable(int a1)
{
  return (*(_DWORD *)(a1 + 32) & 4) != 0 || InitWinPEModeType < 0;
}
