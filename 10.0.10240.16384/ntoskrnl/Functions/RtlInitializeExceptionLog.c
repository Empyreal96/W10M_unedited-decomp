// RtlInitializeExceptionLog 
 
_BYTE *RtlInitializeExceptionLog()
{
  _BYTE *result; // r0

  result = (_BYTE *)ExAllocatePoolWithTag(512, 26000, 1734501445);
  RtlpExceptionLog2 = (int)result;
  if ( result )
  {
    result = memset(result, 0, 26000);
    RtlpExceptionLogSize = 50;
  }
  RtlpExceptionLog = 0;
  return result;
}
