// PerfDiagpIsTracingAllowed 
 
int PerfDiagpIsTracingAllowed()
{
  int v0; // r4
  char v2[8]; // [sp+30h] [bp-30h] BYREF
  char v3[8]; // [sp+38h] [bp-28h] BYREF
  int v4; // [sp+44h] [bp-1Ch]
  int v5; // [sp+48h] [bp-18h]
  int v6; // [sp+4Ch] [bp-14h]

  v0 = 1;
  RtlInitUnicodeString(
    (unsigned int)v2,
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Diagnostics\\Performance");
  RtlInitUnicodeString((unsigned int)v3, L"DisableDiagnosticTracing");
  if ( ZwOpenKey() >= 0 && ZwQueryValueKey() >= 0 && v4 == 4 && v5 == 4 && v6 )
    v0 = 0;
  return v0;
}
