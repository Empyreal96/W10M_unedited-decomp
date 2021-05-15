// RtlQueryTimeZoneInformation 
 
int __fastcall RtlQueryTimeZoneInformation(int a1)
{
  return RtlpQueryTimeZoneInformationWorker(a1, 0xACu);
}
