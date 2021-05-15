// EtwpCheckLoggerAccessAndDoRundown 
 
int __fastcall EtwpCheckLoggerAccessAndDoRundown(unsigned int a1, int a2, int a3)
{
  int v5; // r0
  int v6; // r4
  int v7; // r5

  v5 = EtwpAcquireLoggerContextByLoggerId(a1, 1);
  v6 = v5;
  if ( !v5 )
    return -1073741162;
  v7 = EtwpCheckLoggerControlAccess(128, v5);
  if ( v7 >= 0 )
  {
    if ( (*(_DWORD *)(v6 + 12) & 0x2000000) != 0 )
      EtwpLogKernelTraceRundown(a2, &EtwpGroupMasks[8 * *(unsigned __int8 *)(v6 + 610)], a3);
    if ( (*(_DWORD *)(v6 + 608) & 0x800) != 0 )
      EtwpLogPmcCounterRundown(v6, a2);
    if ( (*(_DWORD *)(v6 + 608) & 0x1000000) != 0 )
      EtwpStackRundown(*(_DWORD *)(v6 + 624), a2);
  }
  EtwpReleaseLoggerContext((_DWORD *)v6, 1);
  return v7;
}
