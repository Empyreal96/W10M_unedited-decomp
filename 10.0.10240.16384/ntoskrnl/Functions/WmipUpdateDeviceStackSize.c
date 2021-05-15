// WmipUpdateDeviceStackSize 
 
int __fastcall WmipUpdateDeviceStackSize(char a1)
{
  int v1; // r4

  v1 = a1;
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  if ( *(char *)(WmipServiceDeviceObject + 48) < v1 )
    *(_BYTE *)(WmipServiceDeviceObject + 48) = v1;
  return KeReleaseMutex((int)&WmipSMMutex);
}
