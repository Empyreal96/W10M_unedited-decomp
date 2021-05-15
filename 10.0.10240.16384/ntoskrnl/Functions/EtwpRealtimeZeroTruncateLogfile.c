// EtwpRealtimeZeroTruncateLogfile 
 
int __fastcall EtwpRealtimeZeroTruncateLogfile(_DWORD *a1)
{
  int result; // r0

  if ( ZwSetInformationFile() < 0 )
    return sub_81BEF0();
  result = ZwSetInformationFile();
  if ( result < 0 )
    return sub_81BEF0();
  a1[76] = 72;
  a1[74] = 72;
  a1[72] = 72;
  a1[73] = 0;
  a1[75] = 0;
  a1[77] = 0;
  return result;
}
