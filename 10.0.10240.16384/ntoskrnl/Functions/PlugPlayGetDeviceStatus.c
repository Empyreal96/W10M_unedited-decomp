// PlugPlayGetDeviceStatus 
 
int __fastcall PlugPlayGetDeviceStatus(int *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, int a5)
{
  int result; // r0
  int v10[7]; // [sp+0h] [bp-30h] BYREF

  if ( !a1 || !a2 || !a3 || !a4 )
    return -1073741811;
  memset(v10, 0, sizeof(v10));
  v10[0] = *a1;
  v10[1] = a1[1];
  v10[2] = 0;
  v10[3] = 0;
  v10[4] = 0;
  v10[6] = 0;
  v10[5] = a5;
  result = ZwPlugPlayControl();
  if ( result >= 0 )
  {
    *a2 = v10[3];
    *a3 = v10[4];
    *a4 = v10[6];
  }
  return result;
}
