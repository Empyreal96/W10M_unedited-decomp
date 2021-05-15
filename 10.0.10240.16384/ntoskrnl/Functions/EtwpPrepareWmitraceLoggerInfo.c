// EtwpPrepareWmitraceLoggerInfo 
 
_BYTE *__fastcall EtwpPrepareWmitraceLoggerInfo(int a1)
{
  _BYTE *result; // r0
  __int16 v3; // r2

  result = memset((_BYTE *)a1, 0, 176);
  *(_DWORD *)a1 = 176;
  *(_DWORD *)(a1 + 44) = 0x20000;
  v3 = -1;
  if ( EtwpWmitraceParams )
    v3 = EtwpWmitraceParams;
  *(_WORD *)(a1 + 8) = v3;
  return result;
}
