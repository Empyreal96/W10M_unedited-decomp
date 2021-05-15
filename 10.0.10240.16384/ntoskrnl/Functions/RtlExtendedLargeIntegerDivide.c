// RtlExtendedLargeIntegerDivide 
 
_QWORD *__fastcall RtlExtendedLargeIntegerDivide(_QWORD *a1, unsigned __int64 a2, unsigned int a3, _DWORD *a4)
{
  int v6; // r2
  _QWORD *varg_r0; // [sp+18h] [bp+8h]

  varg_r0 = a1;
  if ( !a3 )
    __brkdiv0();
  *a1 = (unsigned int)_rt_udiv64(a3, a2);
  if ( a4 )
    *a4 = v6;
  return a1;
}
