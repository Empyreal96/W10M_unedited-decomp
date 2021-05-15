// PiDcHandleDeviceEvent 
 
int __fastcall PiDcHandleDeviceEvent(int a1)
{
  int v1; // r6
  int v2; // r4
  unsigned int v3; // r7
  int v4; // r5
  int result; // r0
  char v6[4]; // [sp+20h] [bp-88h] BYREF
  int v7; // [sp+24h] [bp-84h] BYREF
  int v8[2]; // [sp+28h] [bp-80h] BYREF
  char v9[16]; // [sp+30h] [bp-78h] BYREF
  char v10[104]; // [sp+40h] [bp-68h] BYREF

  v1 = a1;
  v2 = 0;
  v3 = 0;
  if ( !*(_DWORD *)(a1 + 44) )
    goto LABEL_7;
  v4 = a1;
  while ( *(_DWORD *)(v4 + 68)
       || *(_DWORD *)(v4 + 72)
       || !RtlLookupElementGenericTableAvl((int)&PiDcUpdateProperties, v4 + 48) )
  {
    ++v3;
    v4 += 28;
    if ( v3 >= *(_DWORD *)(v1 + 44) )
      goto LABEL_7;
  }
  v2 = PnpGetObjectProperty(
         PiPnpRtlCtx,
         *(_DWORD *)(*(_DWORD *)(v1 + 8) + 12),
         1,
         0,
         0,
         (int)DEVPKEY_Device_ContainerId,
         (int)v8,
         (int)v9,
         16,
         (int)&v7,
         0);
  if ( v2 >= 0
    && v8[0] == 13
    && v7 == 16
    && (v2 = PnpStringFromGuid((int)v9, (int)v10), v2 >= 0)
    && (v2 = PnpGetObjectProperty(
               PiPnpRtlCtx,
               (int)v10,
               5,
               0,
               0,
               (int)DEVPKEY_DeviceContainer_IsLocalMachine,
               (int)v8,
               (int)v6,
               1,
               (int)&v7,
               0),
        v2 >= 0)
    && v8[0] == 17
    && v7 == 1
    && v6[0] != -1 )
  {
    result = sub_7EEA7C();
  }
  else
  {
LABEL_7:
    result = v2;
  }
  return result;
}
