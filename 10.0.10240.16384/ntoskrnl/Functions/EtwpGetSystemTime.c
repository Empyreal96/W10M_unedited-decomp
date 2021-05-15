// EtwpGetSystemTime 
 
int EtwpGetSystemTime()
{
  return RtlGetSystemTimePrecise();
}
