// PnprAddDeviceResources 
 
int __fastcall PnprAddDeviceResources(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r5
  int v6; // r4
  int result; // r0
  int v8; // r0
  int v9; // [sp+0h] [bp-18h] BYREF
  _DWORD v10[5]; // [sp+4h] [bp-14h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v4 = *(_DWORD *)(a1 + 16);
  v6 = *((_DWORD *)a2 + 1);
  if ( PnprIsMemoryDevice(v4, *a2) )
    return PnprAddMemoryResources(v4, v6 + 20);
  v8 = PnprIsProcessorDevice(v4, *a2, v10, &v9);
  if ( v8 )
    result = PnprAddProcessorResources(v8, v10[0], v9, v6 + 16);
  else
    result = 0;
  return result;
}
