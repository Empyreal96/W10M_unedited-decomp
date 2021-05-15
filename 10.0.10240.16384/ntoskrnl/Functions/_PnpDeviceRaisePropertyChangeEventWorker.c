// _PnpDeviceRaisePropertyChangeEventWorker 
 
int __fastcall PnpDeviceRaisePropertyChangeEventWorker(int a1, int a2, int a3, int a4, unsigned int a5, int (__fastcall *a6)(int, int, int, int, int))
{
  int v10; // r7
  BOOL v11; // r7
  int v12; // r8
  int result; // r0
  int v14; // r0
  int v15; // [sp+20h] [bp-B0h] BYREF
  int v16; // [sp+24h] [bp-ACh]
  unsigned int v17; // [sp+28h] [bp-A8h]
  int (__fastcall *v18)(int, int, int, int, int); // [sp+30h] [bp-A0h] BYREF
  unsigned int v19; // [sp+34h] [bp-9Ch]
  int (***v20)[5]; // [sp+38h] [bp-98h]
  int v21; // [sp+3Ch] [bp-94h]
  int v22; // [sp+40h] [bp-90h]
  char v23[4]; // [sp+44h] [bp-8Ch] BYREF
  char v24[8]; // [sp+48h] [bp-88h] BYREF
  char v25[16]; // [sp+50h] [bp-80h] BYREF
  char v26[112]; // [sp+60h] [bp-70h] BYREF

  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v11 = 0;
  if ( !a4 )
  {
    if ( (v10 = *(_DWORD *)(a5 + 16), v10 == 6) && !memcmp(a5, (unsigned int)DEVPKEY_Device_SessionId, 16)
      || v10 == 100 && !memcmp(a5, (unsigned int)DEVPKEY_Device_RestrictedSD, 16) )
    {
      v11 = 1;
    }
  }
  if ( v11 )
  {
    v15 = 0;
    a6(a1, a2, 1, 5, (int)&v15);
  }
  v15 = a3;
  v16 = a4;
  v17 = a5;
  a6(a1, a2, 1, 4, (int)&v15);
  PnpNotifyDerivedKeys(a1, a2, 1, a5, (int)&off_401D68, 9, (int)&v15, a6);
  v12 = PnpHasDerivedKeys(a5, &off_401D34, 3);
  if ( v12 || v11 )
  {
    v14 = PnpGetObjectProperty(a1, a2, 1, a3, 0, (int)DEVPKEY_Device_ContainerId, (int)v24, (int)v25, 16, (int)v23, 0);
    if ( v14 != -1073741275 && v14 != -1073741772 )
    {
      if ( v14 < 0 )
        return sub_7C88C0();
      if ( PnpIsNullGuid(v25) != 1 )
      {
        if ( PnpStringFromGuid((int)v25, (int)v26) < 0 )
          return sub_7C88C0();
        if ( v11 )
        {
          v15 = 0;
          a6(a1, (int)v26, 5, 5, (int)&v15);
        }
        if ( v12 )
        {
          v15 = 0;
          v16 = 0;
          PnpNotifyDerivedKeys(a1, (int)v26, 5, a5, (int)&off_401D34, 3, (int)&v15, a6);
        }
      }
    }
  }
  result = PnpHasDerivedKeys(a5, &off_401D58, 1);
  if ( result || v11 )
  {
    v18 = a6;
    LOBYTE(v22) = v11;
    if ( result )
    {
      v20 = &off_401D58;
      v21 = 1;
      v19 = a5;
    }
    result = CmGetMatchingFilteredDeviceInterfaceList(
               a1,
               0,
               a2,
               0,
               (int)PnpUpdateInterfacesCallback,
               (int)&v18,
               0,
               0,
               (int)v23,
               0);
    if ( result < 0 )
    {
      v15 = 0;
      result = a6(a1, 0, 3, 1, (int)&v15);
    }
  }
  return result;
}
