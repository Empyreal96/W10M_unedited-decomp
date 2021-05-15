// CmpLogClearAccessBitsEvent 
 
int CmpLogClearAccessBitsEvent(unsigned __int16 *a1, ...)
{
  int result; // r0
  int v3; // r2
  int v4; // r3
  __int16 v5; // [sp+8h] [bp-50h] BYREF
  __int16 *v6; // [sp+10h] [bp-48h]
  int v7; // [sp+14h] [bp-44h]
  int v8; // [sp+18h] [bp-40h]
  int v9; // [sp+1Ch] [bp-3Ch]
  int v10; // [sp+20h] [bp-38h]
  int v11; // [sp+24h] [bp-34h]
  int v12; // [sp+28h] [bp-30h]
  int v13; // [sp+2Ch] [bp-2Ch]
  va_list v14; // [sp+30h] [bp-28h]
  int v15; // [sp+34h] [bp-24h]
  int v16; // [sp+38h] [bp-20h]
  int v17; // [sp+3Ch] [bp-1Ch]
  va_list v18; // [sp+40h] [bp-18h]
  int v19; // [sp+44h] [bp-14h]
  int v20; // [sp+48h] [bp-10h]
  int v21; // [sp+4Ch] [bp-Ch]
  int varg_r1; // [sp+64h] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+64h] [bp+Ch]
  va_list varg_r2; // [sp+68h] [bp+10h] BYREF

  va_start(varg_r2, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r2, _DWORD);
  result = EtwKernelProvRegHandle;
  if ( EtwKernelProvRegHandle )
  {
    v3 = *a1;
    v5 = *a1 >> 1;
    v6 = &v5;
    v7 = 0;
    v8 = 2;
    v9 = 0;
    v4 = *((_DWORD *)a1 + 1);
    v12 = v3;
    v10 = v4;
    v11 = 0;
    v13 = 0;
    va_copy(v14, varg_r1a);
    v15 = 0;
    v16 = 4;
    v17 = 0;
    va_copy(v18, varg_r2);
    v19 = 0;
    v20 = 4;
    v21 = 0;
    result = EtwWrite(EtwKernelProvRegHandle, SHIDWORD(EtwKernelProvRegHandle), (int)REG_EVENT_CLEAR_ACCESS, 0);
  }
  return result;
}
