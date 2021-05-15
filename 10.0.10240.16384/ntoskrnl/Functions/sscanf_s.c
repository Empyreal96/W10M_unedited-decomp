// sscanf_s 
 
int sscanf_s(unsigned int a1, int a2, ...)
{
  int result; // r0
  char *v5; // r0
  va_list varg_r2; // [sp+20h] [bp+10h] BYREF

  va_start(varg_r2, a2);
  if ( a2 )
  {
    v5 = strlen(a1);
    result = sinput_s(a1, v5, a2, (int *)varg_r2);
  }
  else
  {
    PopPoCoalescinCallback();
    result = -1;
  }
  return result;
}
