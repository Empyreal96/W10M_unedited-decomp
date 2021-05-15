// IopLiveDumpIsTracingEnabled 
 
BOOL IopLiveDumpIsTracingEnabled()
{
  BOOL result; // r0
  int v1; // r3

  result = 0;
  if ( IopLiveDumpEtwRegHandle )
  {
    v1 = IopLiveDumpEtwEnabled;
    __dmb(0xBu);
    if ( v1 )
      result = 1;
  }
  return result;
}
