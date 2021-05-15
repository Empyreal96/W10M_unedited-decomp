// IopInvalidDeviceRequest 
 
int __fastcall IopInvalidDeviceRequest(int a1, int a2)
{
  *(_DWORD *)(a2 + 24) = -1073741808;
  pIofCompleteRequest(a2, 0);
  return -1073741808;
}
