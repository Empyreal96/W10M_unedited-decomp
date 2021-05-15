// PspComputeReportWakeFilter 
 
_DWORD *__fastcall PspComputeReportWakeFilter(_DWORD *result, _DWORD *a2, _DWORD *a3, int a4)
{
  int v4; // r2

  *a2 = *a3;
  a2[1] = a3[1];
  if ( a4 )
  {
    *a2 &= ~result[122];
    a2[1] &= ~result[123];
  }
  v4 = result[124] & a2[1];
  a2[1] = v4;
  result[124] &= ~v4;
  return result;
}
