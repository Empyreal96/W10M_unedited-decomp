// EtwShutdown 
 
_DWORD *__fastcall EtwShutdown(int a1)
{
  int v2; // r0
  signed int v3; // r4
  int v4; // r9
  BOOL v5; // r10
  _DWORD *result; // r0
  __int16 v7; // r3
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // [sp+0h] [bp-D8h] BYREF
  int v12[52]; // [sp+8h] [bp-D0h] BYREF

  if ( !a1 )
  {
    EtwpTraceSystemShutdown();
    PsGetMonitorContextServerSilo(EtwSiloMonitor, -1, &v11);
    v2 = v11;
    *(_BYTE *)(v11 + 393) = 1;
    PsDereferenceMonitorContextServerSilo(v2);
  }
  memset(v12, 0, 176);
  v12[0] = 176;
  v12[11] = 0x20000;
  v3 = 63;
  v4 = 63;
  v5 = PsIsCurrentThreadInServerSilo();
  do
  {
    result = (_DWORD *)EtwpAcquireLoggerContextByLoggerId(v3, 0);
    if ( !result )
      goto LABEL_12;
    if ( a1 )
    {
      if ( !v5 && (result[3] & 0x400000) == 0 )
      {
LABEL_18:
        result = (_DWORD *)EtwpReleaseLoggerContext(result, 0);
        goto LABEL_12;
      }
    }
    else if ( (result[3] & 0x400) != 0 )
    {
      goto LABEL_18;
    }
    v7 = -1;
    if ( v4 )
      v7 = v3;
    LOWORD(v12[2]) = v7;
    v8 = result[51];
    v9 = result[52];
    v10 = result[53];
    v12[6] = result[50];
    v12[7] = v8;
    v12[8] = v9;
    v12[9] = v10;
    EtwpReleaseLoggerContext(result, 0);
    if ( !a1 )
      ++EtwpStopTraceCount;
    result = (_DWORD *)EtwpStopTrace(v12, 1);
LABEL_12:
    v3 = (__int16)(v4 - 1);
    v4 = v3;
  }
  while ( v3 >= 0 );
  if ( !a1 )
    EtwpStopTraceCount = 0;
  return result;
}
