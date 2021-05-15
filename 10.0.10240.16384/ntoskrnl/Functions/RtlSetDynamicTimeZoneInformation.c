// RtlSetDynamicTimeZoneInformation 
 
int __fastcall RtlSetDynamicTimeZoneInformation(int a1)
{
  return RtlpSetTimeZoneInformationWorker(a1, 432);
}
