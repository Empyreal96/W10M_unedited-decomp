// PiPnpRtlGatherInterfaceDeleteInfo 
 
int __fastcall PiPnpRtlGatherInterfaceDeleteInfo(int a1, int **a2)
{
  unsigned int v4; // r6
  int *v5; // r0
  int v6; // r4
  int v7; // r0
  int v8; // r0
  int v9; // r0
  int v10; // r0
  int v11; // r0
  int v12; // r0
  int v14; // [sp+4h] [bp-ACh]
  char v15[4]; // [sp+20h] [bp-90h] BYREF
  int v16; // [sp+24h] [bp-8Ch] BYREF
  _DWORD v17[2]; // [sp+28h] [bp-88h] BYREF
  char v18[16]; // [sp+30h] [bp-80h] BYREF
  char v19[112]; // [sp+40h] [bp-70h] BYREF

  v4 = 0;
  v16 = 0;
  v5 = (int *)ExAllocatePoolWithTag(1, 16, 1198550608);
  *a2 = v5;
  if ( v5 )
  {
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
    v5[3] = 0;
    v7 = PiDmGetObject(3, a1, *a2);
    v6 = v7;
    if ( v7 != -1073741772 && v7 < 0 )
      goto LABEL_24;
    v8 = PnpGetObjectProperty(
           PiPnpRtlCtx,
           a1,
           3,
           0,
           0,
           (int)DEVPKEY_DeviceInterface_ClassGuid,
           (int)v15,
           (int)v18,
           16,
           (int)v17,
           0);
    v6 = v8;
    if ( v8 != -1073741772 && v8 != -1073741275 )
    {
      if ( v8 < 0 )
        goto LABEL_24;
      if ( PnpStringFromGuid((int)v18, (int)v19) >= 0 )
      {
        v9 = PiDmGetObject(4, (int)v19, *a2 + 1);
        v6 = v9;
        if ( v9 != -1073741772 && v9 < 0 )
          goto LABEL_24;
      }
    }
    v10 = PnpGetObjectProperty(
            1198550608,
            200,
            a1,
            3,
            0,
            v14,
            (int)DEVPKEY_Device_InstanceId,
            (int)v15,
            (unsigned int *)&v16,
            v17,
            0);
    v6 = v10;
    v4 = v16;
    if ( v10 != -1073741772 && v10 != -1073741275 )
    {
      if ( v10 < 0 )
        goto LABEL_24;
      v11 = PiDmGetObject(1, v16, *a2 + 2);
      v6 = v11;
      if ( v11 != -1073741772 && v11 < 0 )
        goto LABEL_24;
    }
    v12 = PnpGetObjectProperty(
            PiPnpRtlCtx,
            a1,
            3,
            0,
            0,
            (int)DEVPKEY_Device_ContainerId,
            (int)v15,
            (int)v18,
            16,
            (int)v17,
            0);
    v6 = v12;
    if ( v12 == -1073741772 || v12 == -1073741275 )
    {
      v6 = 0;
    }
    else
    {
      if ( v12 < 0 )
        goto LABEL_24;
      v6 = PnpStringFromGuid((int)v18, (int)v19);
      if ( v6 < 0 )
        goto LABEL_24;
      v6 = PiDmGetObject(5, (int)v19, *a2 + 3);
      if ( v6 == -1073741772 )
      {
        v6 = 0;
        goto LABEL_25;
      }
    }
    if ( v6 >= 0 )
      goto LABEL_25;
    goto LABEL_24;
  }
  v6 = -1073741670;
LABEL_24:
  PiPnpRtlFreeInterfaceDeleteInfo(*a2);
  *a2 = 0;
LABEL_25:
  if ( v4 )
    ExFreePoolWithTag(v4);
  return v6;
}
