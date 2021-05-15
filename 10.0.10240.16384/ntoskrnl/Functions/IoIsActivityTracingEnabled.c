// IoIsActivityTracingEnabled 
 
int IoIsActivityTracingEnabled()
{
  int result; // r0

  if ( (IopFunctionPointerMask & 4) != 0 )
    result = sub_521814();
  else
    result = 0;
  return result;
}
