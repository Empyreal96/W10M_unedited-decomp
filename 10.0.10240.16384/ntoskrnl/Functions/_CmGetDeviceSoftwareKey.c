// _CmGetDeviceSoftwareKey 
 
int __fastcall CmGetDeviceSoftwareKey(int *a1, int a2, unsigned __int16 *a3, int a4, char a5)
{
  int v8; // r4
  int v10; // r0
  int v11; // [sp+10h] [bp-98h] BYREF
  int v12; // [sp+14h] [bp-94h] BYREF
  int v13; // [sp+18h] [bp-90h] BYREF
  int v14; // [sp+1Ch] [bp-8Ch]
  char v15[2]; // [sp+20h] [bp-88h] BYREF
  unsigned __int16 v16; // [sp+22h] [bp-86h]
  int v17; // [sp+24h] [bp-84h]
  char v18[16]; // [sp+28h] [bp-80h] BYREF
  unsigned __int16 v19[56]; // [sp+38h] [bp-70h] BYREF

  v11 = 0;
  v13 = 0;
  v14 = 0;
  v12 = 88;
  v8 = CmGetDeviceRegProp((int)a1, a2, 0, 10, (int)&v13, (int)a3, (int)&v12);
  if ( v8 == -1073741275 )
  {
    if ( a5 != 1
      || (v12 = 78,
          v13 = 0,
          v10 = CmGetDeviceRegProp((int)a1, a2, 0, 9, (int)&v13, (int)v19, (int)&v12),
          v8 = v10,
          v10 == -1073741275) )
    {
      v8 = -1073741772;
    }
    else if ( v10 >= 0 )
    {
      v19[38] = 0;
      v8 = CmOpenInstallerClassRegKey(a1, v19, 32, 0, 131103, 0, (int)&v11, 0);
      if ( v8 >= 0 )
      {
        v8 = CmCreateOrdinalInstanceKey(a1, v11, v18);
        if ( v8 >= 0 )
        {
          v8 = RtlStringCchPrintfExW((int)a3, 44, 0, 0, 2048, L"%s\\%s");
          if ( v8 >= 0 )
          {
            v8 = RtlInitUnicodeStringEx((int)v15, a3);
            if ( v8 >= 0 )
            {
              v8 = CmSetDeviceRegProp((int)a1, a2, 0, 10, 1, v17, v16, 0);
              if ( v8 < 0 )
                return sub_7EF1D4();
            }
          }
        }
        if ( v14 )
          ZwClose();
      }
    }
  }
  if ( v11 )
    ZwClose();
  return v8;
}
