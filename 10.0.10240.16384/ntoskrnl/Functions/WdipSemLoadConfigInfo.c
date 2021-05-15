// WdipSemLoadConfigInfo 
 
int WdipSemLoadConfigInfo()
{
  int v0; // r4
  int v1; // r3
  char v2; // r2
  int v4; // [sp+8h] [bp-18h] BYREF
  int v5; // [sp+Ch] [bp-14h] BYREF
  int v6; // [sp+10h] [bp-10h] BYREF
  int v7[3]; // [sp+14h] [bp-Ch] BYREF

  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7[0] = 0;
  v0 = WdipSemOpenRegistryKey(L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\Control\\WDI\\Config", 0, &v4);
  if ( v0 >= 0 )
  {
    if ( WdipSemQueryValueFromRegistry(v4, L"SEMEnabled", 4, 4, &v5, &v6) >= 0 && !v5 )
    {
      v0 = -1073741823;
      goto LABEL_12;
    }
    v0 = WdipSemQueryValueFromRegistry(v4, L"SEMTimeOutValue", 4, 4, v7, &v6);
    if ( v0 >= 0 )
    {
      if ( !v7[0] )
      {
        WdipSemTimeoutValue = 600;
        v2 = 0;
LABEL_11:
        WdipSemTimeoutEnabled = v2;
        WdipSemDeleteValueFromRegistry(v4);
        goto LABEL_12;
      }
      v1 = 60 * v7[0];
    }
    else
    {
      v0 = 0;
      v1 = 600;
    }
    WdipSemTimeoutValue = v1;
    v2 = 1;
    goto LABEL_11;
  }
LABEL_12:
  if ( v4 )
    ZwClose();
  return v0;
}
