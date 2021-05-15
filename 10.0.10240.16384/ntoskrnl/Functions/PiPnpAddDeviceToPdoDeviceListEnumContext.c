// PiPnpAddDeviceToPdoDeviceListEnumContext 
 
int __fastcall PiPnpAddDeviceToPdoDeviceListEnumContext(int *a1, int a2)
{
  _DWORD *v3; // r3
  int v5; // r6
  _DWORD *v6; // r0
  int v7; // r5
  int v9; // r1

  v3 = (_DWORD *)a1[1];
  if ( !v3 || *v3 == *a1 )
  {
    v5 = *a1 + 256;
    v6 = (_DWORD *)ExAllocatePoolWithTag(1, 4 * (*a1 + 257), 538996816);
    v7 = (int)v6;
    if ( !v6 )
      return -1073741670;
    *v6 = 0;
    memset(&v6[*a1 + 1], 0, 1024);
    v9 = a1[1];
    if ( v9 )
    {
      memmove(v7, v9, 4 * (*a1 + 1));
      ExFreePoolWithTag(a1[1]);
    }
    *a1 = v5;
    a1[1] = v7;
  }
  *(_DWORD *)(a1[1] + 4 * (*(_DWORD *)a1[1])++ + 4) = a2;
  return 0;
}
