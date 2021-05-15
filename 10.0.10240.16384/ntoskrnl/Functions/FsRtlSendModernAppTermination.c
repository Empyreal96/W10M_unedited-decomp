// FsRtlSendModernAppTermination 
 
int __fastcall FsRtlSendModernAppTermination(int a1, unsigned int a2, int a3)
{
  if ( !a1 || !a2 )
    return sub_555AE0();
  if ( a2 > 0x1000 )
    return -2147483643;
  if ( a3 == 1 || !a3 )
    return ZwUpdateWnfStateData();
  return -1073741811;
}
