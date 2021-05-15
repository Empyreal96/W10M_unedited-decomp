// EtwpValidateLoggerInfo 
 
int __fastcall EtwpValidateLoggerInfo(_DWORD *a1)
{
  if ( !a1 )
    return -1073741811;
  if ( *a1 < 0xB0u )
    return -1073741306;
  if ( (a1[11] & 0x20000) == 0 )
    return -1073741811;
  return 0;
}
