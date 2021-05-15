// _CmGetDeviceInterfaceMappedPropertyFromComposite 
 
int __fastcall CmGetDeviceInterfaceMappedPropertyFromComposite(int a1, unsigned __int16 *a2, int a3, unsigned int a4, _DWORD *a5, _BYTE *a6, unsigned int a7, _DWORD *a8)
{
  _BYTE *v8; // r8
  int v10; // r4
  unsigned int v12; // r5
  int v13; // r5
  int v14; // r9
  int v15; // r0
  int v16; // [sp+20h] [bp-30h] BYREF
  unsigned __int16 *v17; // [sp+24h] [bp-2Ch]
  int v18; // [sp+28h] [bp-28h]
  unsigned int v19; // [sp+2Ch] [bp-24h] BYREF
  int v20[8]; // [sp+30h] [bp-20h] BYREF

  v17 = a2;
  v18 = a3;
  v8 = a6;
  v10 = 0;
  *a5 = 0;
  v19 = a1;
  *a8 = 0;
  if ( !a6 )
    return sub_7C731C();
  if ( !a7 )
    v8 = 0;
  v12 = *(_DWORD *)(a4 + 16);
  if ( v12 < 2 )
    return -1073741264;
  if ( v12 == 10 && !memcmp(a4, (unsigned int)DEVPKEY_NAME, 16) )
  {
    v10 = PnpGetObjectProperty(
            v19,
            (int)v17,
            3,
            v18,
            0,
            (int)DEVPKEY_DeviceInterface_FriendlyName,
            (int)a5,
            (int)v8,
            a7,
            (int)&v16,
            0);
LABEL_20:
    if ( !v10 || v10 == -1073741789 )
      *a8 = v16;
    return v10;
  }
  if ( v12 == 4 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceInterface_ClassGuid, 16) )
  {
    *a8 = 16;
    *a5 = 13;
    if ( a7 < 0x10 )
      v10 = -1073741789;
    else
      v10 = CmGetDeviceInterfaceClassGuid(0, v17, v8);
  }
  else
  {
    if ( v12 == 5 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceInterface_ReferenceString, 16) )
    {
      v15 = CmGetDeviceInterfaceReferenceString(0, v17, v8, a7 >> 1, &v19);
      v10 = v15;
      if ( v15 == -1073741772 )
        return -1073741275;
      if ( !v15 || v15 == -1073741789 )
      {
        if ( RtlULongLongToULong(2 * v19, (unsigned __int64)v19 >> 31, &v16) >= 0 )
        {
          *a8 = v16;
          *a5 = 18;
        }
        else
        {
          v10 = -1073741595;
        }
      }
      return v10;
    }
    if ( v12 == 2 && !memcmp(a4, (unsigned int)DEVPKEY_Device_ContainerId, 16) )
    {
      v13 = ExAllocatePoolWithTag(1, 400, 1380994640);
      if ( v13 )
      {
        v14 = v19;
        v10 = PnpGetObjectProperty(
                v19,
                (int)v17,
                3,
                v18,
                0,
                (int)DEVPKEY_Device_InstanceId,
                (int)v20,
                v13,
                400,
                (int)&v16,
                0);
        if ( v10 >= 0 )
        {
          if ( v20[0] != 18
            || (v10 = PnpGetObjectProperty(
                        v14,
                        v13,
                        1,
                        0,
                        0,
                        (int)DEVPKEY_Device_ContainerId,
                        (int)a5,
                        (int)v8,
                        a7,
                        (int)&v16,
                        0),
                v10 == -1073741772) )
          {
            v10 = -1073741275;
          }
        }
        ExFreePoolWithTag(v13);
        goto LABEL_20;
      }
      v10 = -1073741801;
    }
  }
  return v10;
}
