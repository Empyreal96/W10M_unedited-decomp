// WheapSqmCollectPshedPluginTelemetry 
 
int WheapSqmCollectPshedPluginTelemetry()
{
  int v0; // r5
  int v1; // r6
  int v2; // r4
  int result; // r0
  int v4; // [sp+Ch] [bp-3Ch]
  char v5[8]; // [sp+10h] [bp-38h] BYREF
  char v6[8]; // [sp+18h] [bp-30h] BYREF
  int v7; // [sp+20h] [bp-28h]
  int v8; // [sp+24h] [bp-24h]
  char *v9; // [sp+28h] [bp-20h]
  int v10; // [sp+2Ch] [bp-1Ch]
  int v11; // [sp+30h] [bp-18h]
  int v12; // [sp+34h] [bp-14h]

  v0 = 0;
  v1 = 0;
  RtlInitUnicodeString((unsigned int)v5, L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\WHEA\\Information");
  v7 = 24;
  v8 = 0;
  v10 = 576;
  v9 = v5;
  v11 = 0;
  v12 = 0;
  if ( ZwOpenKey() >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v6, L"PshedPluginFAMask");
    v2 = ExAllocatePoolWithTag(1, 16, 1634035799);
    if ( v2 )
    {
      if ( ZwQueryValueKey() >= 0 && v4 == 16 )
      {
        v1 = *(_DWORD *)(v2 + 12);
        v0 = 1;
      }
      ExFreePoolWithTag(v2);
    }
    ZwClose();
  }
  result = WheapSqmDwordCommon(5, (int)WHEA_SQM_EVENT_SETDWORD, 7205, v0);
  if ( v0 )
    result = WheapSqmDwordCommon(5, (int)WHEA_SQM_EVENT_SETDWORD, 7202, v1);
  return result;
}
