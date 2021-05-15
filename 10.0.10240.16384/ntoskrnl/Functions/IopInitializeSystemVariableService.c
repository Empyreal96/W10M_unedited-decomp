// IopInitializeSystemVariableService 
 
int IopInitializeSystemVariableService()
{
  char v1[8]; // [sp+10h] [bp-48h] BYREF
  int v2; // [sp+18h] [bp-40h]
  int v3; // [sp+1Ch] [bp-3Ch]
  char *v4; // [sp+20h] [bp-38h]
  int v5; // [sp+24h] [bp-34h]
  int v6; // [sp+28h] [bp-30h]
  int v7; // [sp+2Ch] [bp-2Ch]
  int v8; // [sp+3Ch] [bp-1Ch]
  int v9; // [sp+40h] [bp-18h]
  int v10; // [sp+44h] [bp-14h]

  RtlInitUnicodeString(
    (unsigned int)v1,
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\WindowsTrustedRT\\Parameters");
  v2 = 24;
  v3 = 0;
  v5 = 576;
  v4 = v1;
  v6 = 0;
  v7 = 0;
  if ( ZwOpenKey() >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v1, L"Flags");
    if ( ZwQueryValueKey() >= 0 && v8 == 4 && v9 == 4 )
      IopSysEnvOverrideFlags = v10;
  }
  return 0;
}
