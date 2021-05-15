// KdpSysWriteMsr 
 
int __fastcall KdpSysWriteMsr(int a1, _DWORD *a2)
{
  int (__fastcall *v3)(_DWORD); // r0

  if ( !KdpCpuBuffer )
    return -1073741661;
  v3 = (int (__fastcall *)(_DWORD))KdpEncodeMsrAccess(KdpCpuBuffer, a1, 0);
  if ( !v3(*a2) )
    return -1073741810;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}
