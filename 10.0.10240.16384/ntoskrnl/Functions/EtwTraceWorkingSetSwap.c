// EtwTraceWorkingSetSwap 
 
int EtwTraceWorkingSetSwap()
{
  int result; // r0

  result = EtwProviderEnabled(EtwpMemoryProvRegHandle, unk_61A944, 0, (int)&EtwpMemoryProvRegHandle, 128i64);
  if ( result )
    result = sub_7DB6C4();
  return result;
}
