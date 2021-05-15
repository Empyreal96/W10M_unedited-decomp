// _snscanf_s 
 
int snscanf_s(int a1, int a2, int a3, ...)
{
  va_list varg_r3; // [sp+1Ch] [bp+14h] BYREF

  va_start(varg_r3, a3);
  if ( a3 )
    return sinput_s(a1, a2, a3, (int *)varg_r3);
  PopPoCoalescinCallback();
  return -1;
}
