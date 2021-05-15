// PiRearrangeDeviceInstances 
 
int __fastcall PiRearrangeDeviceInstances(int a1)
{
  int v2; // r3
  __int16 v3; // r3
  int v4; // r3
  __int16 v5; // r3
  unsigned int v6; // r4
  int result; // r0
  int v8[2]; // [sp+10h] [bp-70h] BYREF
  __int16 v9; // [sp+18h] [bp-68h]
  __int16 v10; // [sp+1Ah] [bp-66h]
  unsigned __int16 *v11; // [sp+1Ch] [bp-64h]
  unsigned int v12; // [sp+20h] [bp-60h] BYREF
  unsigned __int16 v13[20]; // [sp+58h] [bp-28h] BYREF

  v12 = 0;
  ZwQueryKey();
  v8[0] = (int)v13;
  RtlStringCchPrintfExW((int)v13, 10, v8, 0, 0, L"%u");
  v2 = (v8[0] - (int)v13) >> 1;
  v10 = 20;
  if ( v2 == -1 )
    v3 = 20;
  else
    v3 = 2 * v2;
  v9 = v3;
  v11 = v13;
  if ( IopGetRegistryValue(a1, v13, 0, (int *)&v12) < 0 )
  {
    result = v12;
  }
  else
  {
    ZwDeleteValueKey();
    v8[0] = (int)v13;
    RtlStringCchPrintfExW((int)v13, 10, v8, 0, 0, L"%u");
    v4 = (v8[0] - (int)v13) >> 1;
    v10 = 20;
    if ( v4 == -1 )
      v5 = 20;
    else
      v5 = 2 * v4;
    v6 = v12;
    v9 = v5;
    v11 = v13;
    ZwSetValueKey();
    ExFreePoolWithTag(v6);
    result = 0;
  }
  if ( result )
    result = sub_7F0E2C();
  return result;
}
