// _wctomb_s_l 
 
int wctomb_s_l(int *a1, int a2, unsigned int a3, ...)
{
  int v4; // r3
  int result; // r0
  int v6[4]; // [sp+8h] [bp-10h] BYREF
  int varg_r3; // [sp+2Ch] [bp+14h] BYREF
  va_list varg_r3a; // [sp+2Ch] [bp+14h]
  va_list va1; // [sp+30h] [bp+18h] BYREF

  va_start(va1, a3);
  va_start(varg_r3a, a3);
  varg_r3 = va_arg(va1, _DWORD);
  v6[0] = varg_r3;
  if ( a2 || !a3 )
  {
    if ( a1 )
      *a1 = -1;
    if ( a3 > 0x7FFFFFFF )
    {
      PopPoCoalescinCallback();
      return 22;
    }
    if ( a2 )
    {
      if ( RtlUnicodeToMultiByteN(a2, a3, v6, (int *)varg_r3a) < 0 )
      {
        result = 42;
        gbl_errno = 42;
        return result;
      }
      if ( a1 )
      {
        v4 = v6[0];
        goto LABEL_16;
      }
    }
    else if ( a1 )
    {
      v4 = _mb_cur_max;
      goto LABEL_16;
    }
  }
  else if ( a1 )
  {
    v4 = 0;
LABEL_16:
    *a1 = v4;
    return 0;
  }
  return 0;
}
