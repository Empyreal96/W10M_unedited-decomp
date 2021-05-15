// RtlCompareMemoryUlong 
 
char *RtlCompareMemoryUlong(int *a1, char *a2, ...)
{
  char *v2; // r6
  int *v3; // r5
  unsigned int v4; // r4
  int v5; // t1
  char *v7; // r1
  char *v8; // r0
  int varg_r2; // [sp+20h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+20h] [bp+10h]
  va_list varg_r3; // [sp+24h] [bp+14h] BYREF

  va_start(varg_r3, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3, _DWORD);
  v2 = a2;
  v3 = a1;
  if ( ((unsigned __int8)a1 & 3) != 0 || ((unsigned __int8)a2 & 3) != 0 )
    return 0;
  v4 = (unsigned int)a2 >> 2;
  if ( (unsigned int)a2 >> 2 )
  {
    while ( 1 )
    {
      v5 = *v3++;
      --v4;
      if ( v5 != varg_r2 )
        break;
      if ( !v4 )
        return a2;
    }
    v7 = (char *)(v3 - 1);
    v2 = (char *)((char *)(v3 - 1) - (char *)a1);
    if ( *((char *)v3 - 4) == (char)varg_r2 )
    {
      v8 = (char *)((char *)varg_r2a - v7);
      do
      {
        ++v7;
        ++v2;
      }
      while ( *v7 == v7[(_DWORD)v8] );
    }
  }
  return v2;
}
