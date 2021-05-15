// IovpValidateDeviceObject 
 
BOOL __fastcall IovpValidateDeviceObject(int a1)
{
  return a1 && *(_WORD *)a1 == 3 && *(_DWORD *)(a1 + 8) && *(int *)(a1 + 4) >= 0;
}
