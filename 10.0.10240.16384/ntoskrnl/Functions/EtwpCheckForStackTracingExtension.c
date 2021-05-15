// EtwpCheckForStackTracingExtension 
 
int EtwpCheckForStackTracingExtension()
{
  int result; // r0

  if ( EtwpGetFlagExtension() )
    result = sub_7EAD68();
  else
    result = 0;
  return result;
}
