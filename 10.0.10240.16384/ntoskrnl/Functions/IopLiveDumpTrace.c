// IopLiveDumpTrace 
 
int IopLiveDumpTrace()
{
  int result; // r0
  int v1; // r1

  result = IopLiveDumpIsTracingEnabled();
  if ( result )
    result = EtwWrite(IopLiveDumpEtwRegHandle, SHIDWORD(IopLiveDumpEtwRegHandle), v1, 0);
  return result;
}
