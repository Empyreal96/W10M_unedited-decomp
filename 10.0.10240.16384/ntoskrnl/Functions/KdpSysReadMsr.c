// KdpSysReadMsr 
 
int __fastcall KdpSysReadMsr(int a1, _DWORD *a2)
{
  int (__fastcall *v3)(_DWORD *); // r0
  int result; // r0

  if ( KdpCpuBuffer )
  {
    v3 = (int (__fastcall *)(_DWORD *))KdpEncodeMsrAccess(KdpCpuBuffer, a1, 1);
    *a2 = 0;
    a2[1] = 0;
    if ( v3(a2) )
      result = 0;
    else
      result = -1073741810;
  }
  else
  {
    result = -1073741661;
    *a2 = 0;
    a2[1] = 0;
  }
  return result;
}
