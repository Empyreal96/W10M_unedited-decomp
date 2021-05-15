// KeInitializeDeviceQueue 
 
int __fastcall KeInitializeDeviceQueue(int result)
{
  *(_WORD *)result = 20;
  *(_WORD *)(result + 2) = 20;
  *(_DWORD *)(result + 4) = result + 4;
  *(_DWORD *)(result + 8) = result + 4;
  *(_DWORD *)(result + 12) = 0;
  *(_BYTE *)(result + 16) = 0;
  return result;
}
