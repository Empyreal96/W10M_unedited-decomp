// IopIsReportedAlready 
 
int __fastcall IopIsReportedAlready(int a1, int a2, unsigned __int16 *a3, int a4, _DWORD *a5)
{
  int v7; // r1
  unsigned int v9; // r6
  int v10; // r5
  int v12; // r0
  int v13[2]; // [sp+10h] [bp-250h] BYREF
  unsigned int v14; // [sp+18h] [bp-248h] BYREF
  int v15; // [sp+1Ch] [bp-244h] BYREF
  char v16[8]; // [sp+20h] [bp-240h] BYREF
  unsigned __int16 v17[2]; // [sp+28h] [bp-238h] BYREF
  const __int16 *v18; // [sp+2Ch] [bp-234h]
  int v19; // [sp+30h] [bp-230h] BYREF
  unsigned __int16 *v20; // [sp+34h] [bp-22Ch]
  int v21; // [sp+38h] [bp-228h]
  unsigned __int16 v22[272]; // [sp+40h] [bp-220h] BYREF

  v20 = a3;
  v15 = 512;
  *a5 = 0;
  v7 = *(_DWORD *)(a1 + 4);
  v13[0] = 0;
  v19 = 0;
  v9 = 0;
  v13[1] = 0;
  v14 = 0;
  v10 = 0;
  if ( CmGetDeviceRegProp(PiPnpRtlCtx, v7, a2, 5, (int)&v19, (int)v22, (int)&v15) >= 0
    && v19 == 1
    && v15
    && RtlInitUnicodeStringEx((int)v17, v22) >= 0
    && RtlEqualUnicodeString(v20, v17, 1) )
  {
    if ( CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(a1 + 4), 20, 0, 131097, 0, (int)v16, 0) >= 0 )
      return sub_80CC64();
    if ( !a4 )
      *a5 = 1;
  }
  if ( CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(a1 + 4), 19, 0, 983103, 0, (int)v13, 0) >= 0 )
  {
    v12 = IopGetRegistryValue(v13[0], L"DeviceReported", 0, (int *)&v14);
    v9 = v14;
    if ( v12 >= 0 )
      goto LABEL_21;
  }
  if ( *a5 )
  {
    if ( v13[0] || CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(a1 + 4), 19, 0, 983103, 1u, (int)v13, 0) >= 0 )
    {
      v17[1] = 30;
      v17[0] = 28;
      v21 = 1;
      v18 = L"DeviceReported";
      if ( ZwSetValueKey() >= 0 )
      {
        v10 = 1;
        goto LABEL_16;
      }
    }
LABEL_21:
    v10 = 0;
  }
LABEL_16:
  if ( v13[0] )
    ZwClose();
  if ( v9 )
    ExFreePoolWithTag(v9);
  return v10;
}
