// PiPnpRtlInterfaceFilterCallback 
 
int __fastcall PiPnpRtlInterfaceFilterCallback(int a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned int v5; // r4
  int v6; // r7
  int v7; // r2
  int v9; // r9
  int (__fastcall *v11)(int, unsigned __int16 *, int, _DWORD); // r4
  char v12[4]; // [sp+20h] [bp-40h] BYREF
  int v13; // [sp+24h] [bp-3Ch] BYREF
  unsigned int v14; // [sp+28h] [bp-38h] BYREF
  int v15; // [sp+2Ch] [bp-34h]
  char v16[48]; // [sp+30h] [bp-30h] BYREF

  v5 = *(_DWORD *)a4;
  v15 = a3;
  v6 = 0;
  v7 = 0;
  v9 = a1;
  if ( !v5
    || PnpGetObjectProperty(
         PiPnpRtlCtx,
         (int)a2,
         3,
         0,
         0,
         (int)DEVPKEY_DeviceInterface_ClassGuid,
         (int)&v13,
         (int)v16,
         16,
         (int)&v14,
         0) >= 0
    && v13 == 13
    && v14 >= 0x10
    && (a1 = memcmp(*(_DWORD *)a4, (unsigned int)v16, 16)) == 0 )
  {
    if ( *(_DWORD *)(a4 + 4) )
      return sub_7C6BCC(a1, a2, v7);
    if ( !*(_BYTE *)(a4 + 8) || CmIsDeviceInterfaceEnabled(v9, a2, v7, (int)v12) >= 0 && v12[0] )
    {
      v6 = 1;
      v11 = *(int (__fastcall **)(int, unsigned __int16 *, int, _DWORD))(a4 + 12);
      if ( v11 )
        v6 = v11(v9, a2, v15, *(_DWORD *)(a4 + 16));
    }
  }
  return v6;
}
