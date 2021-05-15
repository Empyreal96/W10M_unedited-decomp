// PiPnpRtlGetDeviceRelatedDeviceRoutine 
 
int __fastcall PiPnpRtlGetDeviceRelatedDeviceRoutine(int a1, int *a2, int a3, int a4, int a5, _DWORD *a6, int a7)
{
  int result; // r0
  int v11[5]; // [sp+0h] [bp-28h] BYREF

  if ( !a2 || !a6 || a7 )
    return -1073741811;
  memset(v11, 0, sizeof(v11));
  v11[0] = *a2;
  v11[1] = a2[1];
  v11[2] = a3;
  v11[3] = a4;
  v11[4] = a5;
  result = ZwPlugPlayControl();
  *a6 = v11[4] + 1;
  return result;
}
