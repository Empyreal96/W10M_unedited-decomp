// KdpSysCheckMsrFault 
 
int __fastcall KdpSysCheckMsrFault(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 64) == KdpCpuBuffer + 1 )
    result = sub_51BBDC();
  else
    result = 0;
  return result;
}
