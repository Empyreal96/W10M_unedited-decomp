// IopLiveDumpTraceInterfaceEnd 
 
int IopLiveDumpTraceInterfaceEnd()
{
  int result; // r0
  int v1; // r1
  int *v2; // r2

  result = IopLiveDumpIsTracingEnabled();
  if ( result )
  {
    if ( v1 )
    {
      if ( v1 == 1 )
        v2 = LIVEDUMP_EVENT_WRITE_DEFERRED_DATA_API_END;
      else
        v2 = LIVEDUMP_EVENT_DISCARD_DEFERRED_DATA_API_END;
    }
    else
    {
      v2 = LIVEDUMP_EVENT_CAPTURE_API_END;
    }
    result = EtwWrite(IopLiveDumpEtwRegHandle, SHIDWORD(IopLiveDumpEtwRegHandle), (int)v2, 0);
  }
  return result;
}
