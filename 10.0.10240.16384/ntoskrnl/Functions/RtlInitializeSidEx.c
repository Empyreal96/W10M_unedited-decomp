// RtlInitializeSidEx 
 
int RtlInitializeSidEx(int a1, int a2, int a3, ...)
{
  int v3; // r4
  int result; // r0
  va_list v6; // r2
  char varg_r2; // [sp+18h] [bp+10h]
  va_list varg_r3; // [sp+1Ch] [bp+14h] BYREF

  va_start(varg_r3, a3);
  v3 = a3;
  varg_r2 = a3;
  result = RtlInitializeSid();
  if ( result >= 0 )
  {
    va_copy(v6, varg_r3);
    for ( ; v3; --v3 )
    {
      v6 = (va_list)((char *)v6 + (-(int)v6 & 3) + 4);
      *(_DWORD *)(a1 + 8) = *(v6 - 1);
      a1 += 4;
    }
    result = 0;
  }
  return result;
}
