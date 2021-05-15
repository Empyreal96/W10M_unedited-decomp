// ExGetCurrentProcessorCpuUsage 
 
int __fastcall ExGetCurrentProcessorCpuUsage(_DWORD *a1)
{
  _DWORD *v2; // r1
  int v3; // r3
  __int64 v4; // r0
  unsigned __int64 v5; // r2
  int result; // r0

  v2 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
  LODWORD(v4) = v2[930] + v2[929];
  v3 = v2[355];
  HIDWORD(v4) = 0;
  v5 = 100i64 * *(unsigned int *)(v3 + 404);
  if ( !(_DWORD)v4 )
    __brkdiv0();
  result = _rt_udiv64(v4, v5);
  *a1 = 100 - result;
  return result;
}
