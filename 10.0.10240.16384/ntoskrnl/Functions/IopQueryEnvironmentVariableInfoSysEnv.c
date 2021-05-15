// IopQueryEnvironmentVariableInfoSysEnv 
 
int IopQueryEnvironmentVariableInfoSysEnv(int a1, int a2, ...)
{
  _DWORD *v2; // r6
  int result; // r0
  int var28[11]; // [sp+18h] [bp-28h] BYREF
  int varg_r2; // [sp+50h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+50h] [bp+10h]
  _DWORD *varg_r3; // [sp+54h] [bp+14h]
  _DWORD *v8; // [sp+58h] [bp+18h]
  _DWORD *v9; // [sp+5Ch] [bp+1Ch]
  va_list va1; // [sp+60h] [bp+20h] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD *);
  v8 = va_arg(va1, _DWORD *);
  v9 = va_arg(va1, _DWORD *);
  v2 = varg_r3;
  result = IopIssueSystemEnvironmentRequest(5373968, 1, a1, a2, (int)varg_r2a, 4, (int)var28, 24, 0);
  if ( result >= 0 )
  {
    if ( v2 )
    {
      *v2 = var28[0];
      v2[1] = var28[1];
    }
    if ( v8 )
    {
      *v8 = var28[2];
      v8[1] = var28[3];
    }
    if ( v9 )
    {
      *v9 = var28[4];
      v9[1] = var28[5];
    }
  }
  return result;
}
