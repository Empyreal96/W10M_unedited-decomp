// ExpWnfInitServerSilo 
 
int ExpWnfInitServerSilo()
{
  int result; // r0
  int v1[8]; // [sp+0h] [bp-20h] BYREF

  memset(v1, 0, 24);
  LOWORD(v1[0]) = 1;
  HIWORD(v1[0]) |= 1u;
  v1[1] = (int)ExpWnfCreateServerSiloCallback;
  v1[2] = (int)ExpWnfTerminateServerSiloCallback;
  if ( ((int (__fastcall *)(_DWORD, const __int16 *, int *, int *))PsRegisterMonitorServerSilo)(
         0,
         L"NTOS_EX_WNF",
         v1,
         &ExpWnfSiloMonitor) < 0 )
    JUMPOUT(0x81087A);
  if ( PsStartMonitorServerSilo(ExpWnfSiloMonitor) >= 0 )
    result = 1;
  else
    result = sub_810874();
  return result;
}
