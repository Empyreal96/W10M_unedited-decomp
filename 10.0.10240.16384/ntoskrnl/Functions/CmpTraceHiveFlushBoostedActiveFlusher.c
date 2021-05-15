// CmpTraceHiveFlushBoostedActiveFlusher 
 
int CmpTraceHiveFlushBoostedActiveFlusher()
{
  __int64 v0; // kr00_8
  int result; // r0
  _DWORD v2[8]; // [sp+8h] [bp-20h] BYREF

  v2[0] = 285212700;
  v2[1] = 200452;
  v2[2] = 0;
  v2[3] = 0x40000000;
  v0 = *(_QWORD *)&EtwpRegTraceHandle;
  result = EtwEventEnabled(EtwpRegTraceHandle, dword_92026C, (int)v2);
  if ( result )
    result = EtwWrite(v0, SHIDWORD(v0), (int)v2, 0);
  return result;
}
