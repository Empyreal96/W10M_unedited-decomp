// EtwpInitializeSecurity 
 
int EtwpInitializeSecurity()
{
  int v0; // r4
  int v1; // r0
  int result; // r0
  _BYTE v3[8]; // [sp+0h] [bp-30h] BYREF
  char v4[8]; // [sp+8h] [bp-28h] BYREF
  int v5; // [sp+10h] [bp-20h]
  int v6; // [sp+14h] [bp-1Ch]
  _BYTE *v7; // [sp+18h] [bp-18h]
  int v8; // [sp+1Ch] [bp-14h]
  int v9; // [sp+20h] [bp-10h]
  int v10; // [sp+24h] [bp-Ch]

  RtlInitUnicodeString((unsigned int)v3, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI\\Security");
  v5 = 24;
  v6 = 0;
  v8 = 576;
  v7 = v3;
  v9 = 0;
  v10 = 0;
  v0 = ZwOpenKey();
  if ( v0 < 0
    || (RtlInitUnicodeString((unsigned int)v4, L"0811c1af-7a07-4a06-82ed-869455cdf713"),
        v1 = EtwpGetGuidSecurityDescriptor((int)v4, &EtwpDefaultTraceSecurityDescriptor),
        EtwpDefaultTraceSecurityDescriptor) )
  {
    result = v0;
  }
  else
  {
    result = sub_9705AC(v1);
  }
  return result;
}
