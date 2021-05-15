// _CmSetDeviceMappedPropertyFromDriverKeyRegValue 
 
int __fastcall CmSetDeviceMappedPropertyFromDriverKeyRegValue(int a1, int a2, unsigned int a3, int (*a4)[5], int a5)
{
  int v6; // r10
  int (**v7)[5]; // r9
  unsigned int i; // r7
  int (**v10)[5]; // r6
  unsigned int v11; // r1
  int (*v12)[5]; // t1
  int v14; // r4
  int v15; // r5
  int v16; // r0
  int v17; // r2
  int v18; // r3
  int v19; // r0
  int v20; // [sp+10h] [bp-58h] BYREF
  int v21; // [sp+14h] [bp-54h] BYREF
  int v22; // [sp+18h] [bp-50h]
  int v23; // [sp+1Ch] [bp-4Ch]
  __int16 v24[2]; // [sp+20h] [bp-48h] BYREF
  unsigned __int16 v25[28]; // [sp+30h] [bp-38h] BYREF

  v6 = *(_DWORD *)(a3 + 16);
  v7 = &off_8C97B0;
  v21 = a5;
  v22 = a1;
  v20 = 0;
  v23 = a2;
  for ( i = 0; i < 0xD; ++i )
  {
    v10 = v7;
    v12 = *v7;
    v7 += 4;
    v11 = (unsigned int)v12;
    if ( v6 == (*v12)[4] && !memcmp(a3, v11, 16) )
      break;
    v10 = 0;
  }
  if ( !v10 )
    return -1073741802;
  if ( a4 != v10[1] )
    return sub_7E15A8();
  v14 = CmOpenDeviceRegKey(v22, v23, 18, 0, 2, 1u, (int)&v20, 0);
  if ( v14 >= 0 )
  {
    v15 = v21;
    v16 = RegRtlSetValue(v20, (unsigned __int16 *)v10[2]);
    if ( v16 == -1073741444 )
    {
      v14 = -1073741772;
    }
    else if ( v16 < 0 )
    {
      v14 = v16;
    }
    else if ( *(_DWORD *)(a3 + 16) == 2 && !memcmp(a3, (unsigned int)DEVPKEY_Device_DriverDate, 16) )
    {
      RtlTimeToTimeFields(v15, v24, v17, v18);
      if ( RtlStringCchPrintfW(v25, 0xBu, (int)L"%d-%d-%d", v24[1]) >= 0 )
      {
        v19 = RtlUnalignedStringCchLengthW(v25, 11, &v21);
        if ( v19 >= 0 )
          PnpCtxRegSetValue(v19, v20, (int)L"DriverDate", 1, (int)v25, 2 * (v21 + 1));
      }
    }
  }
  if ( v20 )
    ZwClose();
  return v14;
}
