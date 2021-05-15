// EtwRegisterCounters 
 
int EtwRegisterCounters()
{
  __int16 v1; // [sp+0h] [bp-28h] BYREF
  __int16 v2; // [sp+2h] [bp-26h]
  const __int16 *v3; // [sp+4h] [bp-24h]
  int v4; // [sp+8h] [bp-20h] BYREF
  __int16 *v5; // [sp+Ch] [bp-1Ch]
  int v6; // [sp+10h] [bp-18h]
  int *v7; // [sp+14h] [bp-14h]
  int (*v8)(); // [sp+18h] [bp-10h]
  int v9; // [sp+1Ch] [bp-Ch]

  v1 = 50;
  v2 = 52;
  v3 = L"Event Tracing for Windows";
  v4 = 256;
  v7 = &`PcwpRegisterEventTracingCounterSet'::`2'::Descriptors;
  v6 = 6;
  v8 = EtwpEventTracingCounterSetCallback;
  v9 = 1;
  v5 = &v1;
  PcwRegister(&PcwpEventTracingCounterSet, &v4);
  v1 = 66;
  v2 = 68;
  v3 = L"Event Tracing for Windows Session";
  v4 = 256;
  v7 = &`PcwpRegisterEventTracingSessionCounterSet'::`2'::Descriptors;
  v6 = 5;
  v8 = EtwpEventTracingCounterSetCallback;
  v9 = 2;
  v5 = &v1;
  return PcwRegister(&PcwpEventTracingSessionCounterSet, &v4);
}
