// EtwpTraceLostEvent 
 
int EtwpTraceLostEvent(unsigned int a1, __int16 *a2, unsigned __int16 *a3, ...)
{
  int result; // r0
  __int16 v7; // [sp+20h] [bp-70h] BYREF
  _DWORD _28[27]; // [sp+28h] [bp-68h] BYREF
  va_list varg_r3; // [sp+A4h] [bp+14h] BYREF

  va_start(varg_r3, a3);
  result = memcmp(a1, (unsigned int)EventTracingProvGuid, 16);
  if ( result )
  {
    v7 = *a2;
    _28[0] = a1;
    _28[1] = 0;
    _28[2] = 16;
    _28[3] = 0;
    va_copy((va_list)&_28[4], varg_r3);
    _28[5] = 0;
    _28[6] = 4;
    _28[7] = 0;
    _28[8] = &v7;
    _28[9] = 0;
    _28[10] = 2;
    _28[11] = 0;
    _28[12] = *((_DWORD *)a3 + 1);
    _28[13] = 0;
    _28[14] = *a3;
    _28[15] = 0;
    _28[16] = &EtwpNull;
    _28[17] = 0;
    _28[18] = 2;
    _28[19] = 0;
    result = EtwWriteEx(
               EtwpEventTracingProvRegHandle,
               dword_61ADA4,
               (int)ETW_EVENT_LOST_EVENT,
               (int)&EtwpEventTracingProvRegHandle,
               0,
               0,
               1,
               0,
               0,
               5,
               (int)_28);
  }
  return result;
}
