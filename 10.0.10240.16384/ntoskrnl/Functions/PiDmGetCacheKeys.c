// PiDmGetCacheKeys 
 
int __fastcall PiDmGetCacheKeys(int result, _DWORD *a2, int *a3)
{
  int v3; // r3

  switch ( result )
  {
    case 1:
      *a2 = &PiDmCachedDeviceKeys;
      v3 = 9;
      break;
    case 3:
      *a2 = &PiDmCachedDeviceInterfaceKeys;
      v3 = 1;
      break;
    case 5:
      *a2 = &PiDmCachedDeviceContainerKeys;
      v3 = 3;
      break;
    default:
      v3 = 0;
      *a2 = 0;
      break;
  }
  *a3 = v3;
  return result;
}
