// CmpLogTxrInitEvent 
 
const __int16 *CmpLogTxrInitEvent(int a1, _DWORD *a2, ...)
{
  const __int16 *result; // r0
  unsigned int v3; // r2
  int v4; // r2
  __int16 v5; // [sp+8h] [bp-80h] BYREF
  int v6; // [sp+Ch] [bp-7Ch] BYREF
  int v7; // [sp+10h] [bp-78h]
  __int16 *v8; // [sp+18h] [bp-70h]
  int v9; // [sp+1Ch] [bp-6Ch]
  int v10; // [sp+20h] [bp-68h]
  int v11; // [sp+24h] [bp-64h]
  const __int16 *v12; // [sp+28h] [bp-60h]
  int v13; // [sp+2Ch] [bp-5Ch]
  unsigned int v14; // [sp+30h] [bp-58h]
  int v15; // [sp+34h] [bp-54h]
  int v16; // [sp+38h] [bp-50h]
  int v17; // [sp+3Ch] [bp-4Ch]
  int v18; // [sp+40h] [bp-48h]
  int v19; // [sp+44h] [bp-44h]
  int v20; // [sp+48h] [bp-40h]
  int v21; // [sp+4Ch] [bp-3Ch]
  int v22; // [sp+50h] [bp-38h]
  int v23; // [sp+54h] [bp-34h]
  va_list v24; // [sp+58h] [bp-30h]
  int v25; // [sp+5Ch] [bp-2Ch]
  int v26; // [sp+60h] [bp-28h]
  int v27; // [sp+64h] [bp-24h]
  int *v28; // [sp+68h] [bp-20h]
  int v29; // [sp+6Ch] [bp-1Ch]
  int v30; // [sp+70h] [bp-18h]
  int v31; // [sp+74h] [bp-14h]
  va_list varg_r2; // [sp+98h] [bp+10h] BYREF

  va_start(varg_r2, a2);
  result = L"\\SystemRoot\\System32\\Config\\SYSTEM";
  v3 = 68;
  v6 = a2[815];
  if ( EtwKernelProvRegHandle )
  {
    if ( off_60E8A4 != a2 )
    {
      result = (const __int16 *)a2[495];
      v7 = a2[494];
      v3 = (unsigned __int16)v7;
    }
    v5 = v3 >> 1;
    v8 = &v5;
    v9 = 0;
    v14 = v3;
    v4 = a2[8];
    v10 = 2;
    v11 = 0;
    v12 = result;
    v13 = 0;
    v15 = 0;
    v16 = v4 + 148;
    v17 = 0;
    v18 = 16;
    v19 = 0;
    v20 = v4 + 112;
    v21 = 0;
    v22 = 16;
    v23 = 0;
    va_copy(v24, varg_r2);
    v25 = 0;
    v26 = 4;
    v27 = 0;
    v28 = &v6;
    v29 = 0;
    v30 = 4;
    v31 = 0;
    result = (const __int16 *)EtwWrite(
                                EtwKernelProvRegHandle,
                                SHIDWORD(EtwKernelProvRegHandle),
                                (int)REG_EVENT_TXR_INIT,
                                0);
  }
  return result;
}
