// RtlSetTimeZoneInformation 
 
int __fastcall RtlSetTimeZoneInformation(int a1)
{
  return RtlpSetTimeZoneInformationWorker(a1, 172);
}
