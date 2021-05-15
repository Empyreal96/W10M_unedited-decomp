// swscanf_s 
 
int swscanf_s(unsigned __int16 *a1, int a2, ...)
{
  int result; // r0
  unsigned int v5; // r0
  va_list varg_r2; // [sp+20h] [bp+10h] BYREF

  va_start(varg_r2, a2);
  if ( a2 )
  {
    v5 = wcslen(a1);
    result = swinput_s(a1, v5, a2, (int *)varg_r2);
  }
  else
  {
    PopPoCoalescinCallback();
    result = -1;
  }
  return result;
}
