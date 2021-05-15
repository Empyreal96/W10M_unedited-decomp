// RtlOsDeploymentState 
 
int RtlOsDeploymentState()
{
  int v1; // [sp+Ch] [bp-54h]
  int v2; // [sp+28h] [bp-38h] BYREF
  _DWORD v3[10]; // [sp+38h] [bp-28h] BYREF

  v1 = 1;
  RtlInitUnicodeString((unsigned int)&v2, L"\\Registry\\Machine\\System\\Setup");
  if ( ZwOpenKey() >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v3, L"Compact");
    if ( ZwQueryValueKey() >= 0 && v3[3] == 4 && v3[4] == 4 && v3[5] )
      v1 = 2;
  }
  return v1;
}
