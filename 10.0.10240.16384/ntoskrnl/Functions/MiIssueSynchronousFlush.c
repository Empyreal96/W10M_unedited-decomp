// MiIssueSynchronousFlush 
 
int MiIssueSynchronousFlush(int a1, int a2, ...)
{
  int result; // r0
  char v5[4]; // [sp+8h] [bp-20h] BYREF
  int v6; // [sp+Ch] [bp-1Ch]
  int var18[7]; // [sp+10h] [bp-18h] BYREF
  int varg_r2; // [sp+38h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+38h] [bp+10h]
  int varg_r3; // [sp+3Ch] [bp+14h]
  int v11; // [sp+40h] [bp+18h]
  int *v12; // [sp+44h] [bp+1Ch]
  va_list va1; // [sp+48h] [bp+20h] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v11 = va_arg(va1, _DWORD);
  v12 = va_arg(va1, int *);
  v5[0] = 0;
  v5[1] = 0;
  v5[2] = 4;
  v6 = 0;
  var18[1] = (int)var18;
  var18[0] = (int)var18;
  KeResetEvent(v5);
  result = IoSynchronousPageWriteEx(a1, a2, (int *)varg_r2a, v5, (unsigned __int8)v11, v12);
  if ( result >= 0 )
    return KeWaitForSingleObject(v5, 19, 0);
  *v12 = result;
  return result;
}
