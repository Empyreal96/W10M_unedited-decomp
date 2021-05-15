// IoGetDumpStackTransferSizes 
 
_DWORD *__fastcall IoGetDumpStackTransferSizes(_DWORD *result, _DWORD *a2)
{
  if ( CrashdmpImageEntry && dword_637670 )
    return (_DWORD *)dword_637670();
  if ( result )
    *result = 4096;
  if ( a2 )
    *a2 = 0x10000;
  return result;
}
