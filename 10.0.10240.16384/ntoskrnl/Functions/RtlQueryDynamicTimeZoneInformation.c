// RtlQueryDynamicTimeZoneInformation 
 
int __fastcall RtlQueryDynamicTimeZoneInformation(int a1)
{
  return RtlpQueryTimeZoneInformationWorker(a1, 0x1B0u);
}
