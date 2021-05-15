// WdipSemLoadGroupPolicy 
 
int WdipSemLoadGroupPolicy()
{
  int v0; // r4
  int v2; // [sp+8h] [bp-10h] BYREF
  int v3; // [sp+Ch] [bp-Ch] BYREF
  int v4; // [sp+10h] [bp-8h] BYREF

  v2 = 0;
  v4 = 4;
  v3 = 0;
  if ( WdipSemOpenRegistryKey(L"\\REGISTRY\\MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\WDI", 0, &v2) < 0 )
    goto LABEL_2;
  v0 = WdipSemQueryValueFromRegistry(v2, L"ScenarioExecutionEnabled", 4, 4, &v3, &v4);
  if ( v0 >= 0 )
  {
    if ( !v3 )
      v0 = -1073741823;
  }
  else
  {
    v0 = WdipSemLoadLocalGroupPolicy(v2);
    if ( v0 < 0 )
    {
      WdipSemCleanupGroupPolicy();
LABEL_2:
      v0 = 0;
      goto LABEL_8;
    }
  }
LABEL_8:
  if ( v2 )
    ZwClose();
  return v0;
}
