// WheapSqmCollectWheaOscTelemetry 
 
int WheapSqmCollectWheaOscTelemetry()
{
  int v0; // r6
  int v1; // r5
  int v2; // r4
  int v4; // [sp+8h] [bp-40h]
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
  RtlInitUnicodeString((unsigned int)v6, L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\ACPI\\Parameters");
  v7 = 24;
  v8 = 0;
  v10 = 576;
  v9 = v6;
  v11 = 0;
  v12 = 0;
  if ( ZwOpenKey() >= 0 )
  {
    v2 = ExAllocatePoolWithTag(1, 16);
    if ( v2 )
    {
      RtlInitUnicodeString((unsigned int)v5, L"WHEAOSCImplemented");
      if ( ZwQueryValueKey() >= 0 && v4 == 16 && *(_DWORD *)(v2 + 12) )
        v0 = 1;
      RtlInitUnicodeString((unsigned int)v5, L"APEIOSCGranted");
      if ( ZwQueryValueKey() >= 0 && v4 == 16 && *(_DWORD *)(v2 + 12) )
        v1 = 1;
      ExFreePoolWithTag(v2);
    }
    ZwClose();
  }
  WheapSqmSetDword(7208, v0);
  return WheapSqmSetDword(7207, v1);
}
