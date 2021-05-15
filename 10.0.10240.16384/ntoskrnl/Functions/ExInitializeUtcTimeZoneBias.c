// ExInitializeUtcTimeZoneBias 
 
int ExInitializeUtcTimeZoneBias()
{
  int result; // r0

  if ( ExpRealTimeIsUniversal )
    result = sub_970AFC();
  else
    result = -1073741637;
  return result;
}
