// IovUtilHasDispatchHandler 
 
BOOL __fastcall IovUtilHasDispatchHandler(int a1, int a2)
{
  return *(_DWORD *)(a1 + 4 * a2 + 56) != (_DWORD)IopInvalidDeviceRequest;
}
