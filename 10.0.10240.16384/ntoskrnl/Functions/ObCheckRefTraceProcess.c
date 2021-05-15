// ObCheckRefTraceProcess 
 
int ObCheckRefTraceProcess()
{
  int result; // r0

  if ( (ObpTraceFlags & 0x20) != 0 )
    result = sub_7F4A44();
  else
    result = 0;
  return result;
}
