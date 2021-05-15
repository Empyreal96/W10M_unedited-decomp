// PopReadShutdownPolicy 
 
int PopReadShutdownPolicy()
{
  int result; // r0
  char v1[8]; // [sp+10h] [bp-48h] BYREF
  int v2; // [sp+18h] [bp-40h]
  int v3; // [sp+1Ch] [bp-3Ch]
  char *v4; // [sp+20h] [bp-38h]
  int v5; // [sp+24h] [bp-34h]
  int v6; // [sp+28h] [bp-30h]
  int v7; // [sp+2Ch] [bp-2Ch]
  int v8; // [sp+3Ch] [bp-1Ch]
  char v9; // [sp+44h] [bp-14h]

  RtlInitUnicodeString((unsigned int)v1, L"\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows NT");
  v2 = 24;
  v3 = 0;
  v5 = 576;
  v4 = v1;
  v6 = 0;
  v7 = 0;
  result = ZwOpenKey();
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v1, L"DontPowerOffAfterShutdown");
    if ( ZwQueryValueKey() >= 0 && v8 == 4 )
      PopShutdownPowerOffPolicy = v9 == 1;
    result = ZwClose();
  }
  return result;
}
