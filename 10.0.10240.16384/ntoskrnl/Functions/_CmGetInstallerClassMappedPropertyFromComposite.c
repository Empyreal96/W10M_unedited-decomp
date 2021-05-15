// _CmGetInstallerClassMappedPropertyFromComposite 
 
int __fastcall CmGetInstallerClassMappedPropertyFromComposite(int a1, int a2, int a3, unsigned int a4, _DWORD *a5, char *a6, unsigned int a7, unsigned int *a8)
{
  char *v8; // r9
  int v10; // r4
  unsigned int v12; // r5
  int v13; // r0
  char v14; // r3
  int v15; // r7
  int v16; // r0
  int v17; // r0
  unsigned int v18; // [sp+20h] [bp-30h] BYREF
  int v19; // [sp+24h] [bp-2Ch]
  int v20; // [sp+28h] [bp-28h]
  int v21; // [sp+2Ch] [bp-24h]

  v20 = a1;
  v21 = a3;
  v19 = a2;
  v8 = a6;
  v10 = 0;
  *a5 = 0;
  *a8 = 0;
  v18 = 0;
  if ( !a6 )
    return sub_7E41F4();
  if ( !a7 )
    v8 = 0;
  v12 = *(_DWORD *)(a4 + 16);
  if ( v12 < 2 )
    return -1073741264;
  if ( v12 == 10 && !memcmp(a4, (unsigned int)DEVPKEY_NAME, 16) )
  {
    v15 = v21;
    v16 = PnpGetObjectProperty(v20, v19, 2, v21, 0, (int)DEVPKEY_DeviceClass_Name, (int)a5, (int)v8, a7, (int)&v18, 0);
    v10 = v16;
    if ( v16 )
    {
      if ( v16 != -1073741789 )
      {
        if ( v16 != -1073741275 )
          return v10;
        v17 = PnpGetObjectProperty(
                v20,
                v19,
                2,
                v15,
                0,
                (int)DEVPKEY_DeviceClass_ClassName,
                (int)a5,
                (int)v8,
                a7,
                (int)&v18,
                0);
        v10 = v17;
        if ( v17 )
        {
          if ( v17 != -1073741789 )
            return v10;
        }
      }
    }
  }
  else
  {
    if ( v12 != 4 || memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_Configurable, 16) )
      return v10;
    v13 = PnpGetObjectProperty(
            v20,
            v19,
            2,
            v21,
            0,
            (int)DEVPKEY_DeviceClass_ConfigurableOverride,
            (int)a5,
            (int)v8,
            a7,
            (int)&v18,
            0);
    v10 = v13;
    if ( v13 && v13 != -1073741789 )
    {
      if ( v13 == -1073741275 )
      {
        v10 = PnpGetObjectProperty(
                v20,
                v19,
                2,
                v21,
                0,
                (int)DEVPKEY_DeviceClass_ClassInstaller,
                (int)a5,
                0,
                0,
                (int)&v18,
                0);
        if ( v10 == -1073741275 )
          v10 = PnpGetObjectProperty(
                  v20,
                  v19,
                  2,
                  v21,
                  0,
                  (int)DEVPKEY_DeviceClass_ClassCoInstallers,
                  (int)a5,
                  0,
                  0,
                  (int)&v18,
                  0);
        if ( v10 == -1073741275 || v10 >= 0 || v10 == -1073741789 )
        {
          *a8 = 1;
          *a5 = 17;
          if ( a7 < *a8 )
          {
            v10 = -1073741789;
          }
          else
          {
            if ( v10 == -1073741275 )
              v14 = -1;
            else
              v14 = 0;
            *v8 = v14;
            v10 = 0;
          }
        }
      }
      return v10;
    }
  }
  *a8 = v18;
  return v10;
}
