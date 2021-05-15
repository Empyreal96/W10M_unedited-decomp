// EtwWriteErrorLogEntry 
 
int EtwWriteErrorLogEntry(int a1, int a2, int a3, unsigned int a4, int a5, unsigned __int16 *a6, unsigned __int16 *a7, ...)
{
  unsigned int v7; // r8
  _DWORD *v9; // r0
  int v11; // r10
  int v12; // r3
  int v13; // r3
  char v14; // r3
  __int16 v15; // r0
  int v16; // r7
  unsigned int v17; // r5
  unsigned int v18; // r9
  int *v19; // r2
  int v20; // r7
  __int16 v21; // r0
  int *v22; // r2
  int v23; // r7
  unsigned int v24; // r1
  int *v25; // r2
  int v26; // r3
  int *v27; // r2
  int v28; // r7
  int *v29; // r3
  int result; // r0
  __int16 v31; // [sp+38h] [bp-268h] BYREF
  __int16 v32; // [sp+3Ah] [bp-266h] BYREF
  unsigned int v33; // [sp+3Ch] [bp-264h] BYREF
  int v34; // [sp+40h] [bp-260h]
  unsigned int v35; // [sp+44h] [bp-25Ch]
  unsigned __int16 v36; // [sp+48h] [bp-258h] BYREF
  char v37; // [sp+4Ah] [bp-256h]
  char v38; // [sp+4Bh] [bp-255h]
  char v39; // [sp+4Ch] [bp-254h]
  char v40; // [sp+4Dh] [bp-253h]
  __int16 v41; // [sp+4Eh] [bp-252h]
  int v42; // [sp+50h] [bp-250h]
  int v43; // [sp+54h] [bp-24Ch]
  unsigned int v44; // [sp+58h] [bp-248h]
  _DWORD v45[88]; // [sp+60h] [bp-240h] BYREF
  int varE0[57]; // [sp+1C0h] [bp-E0h] BYREF
  int varg_r0; // [sp+2A8h] [bp+8h]
  int v48; // [sp+2C4h] [bp+24h] BYREF
  va_list va; // [sp+2C4h] [bp+24h]
  int v50; // [sp+2C8h] [bp+28h]
  va_list va1; // [sp+2CCh] [bp+2Ch] BYREF

  va_start(va1, a7);
  va_start(va, a7);
  v48 = va_arg(va1, _DWORD);
  v50 = va_arg(va1, _DWORD);
  varg_r0 = a1;
  v7 = (unsigned __int16)a1;
  v44 = a4;
  v9 = (_DWORD *)EtwpLoggerRundown[(unsigned __int16)a1];
  v34 = 0;
  v11 = 0;
  ExAcquireRundownProtectionCacheAwareEx(v9, 1);
  if ( v7 >= 0x40 )
    v12 = 1;
  else
    v12 = WmipLoggerContext[v7];
  if ( (v12 & 1) != 0 || !PsEqualCurrentServerSilo(*(_DWORD *)(v12 + 652)) )
  {
    ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v7], 1);
    result = -1073741727;
  }
  else
  {
    ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v7], 1);
    v13 = *(_DWORD *)(a3 + 12) >> 30;
    if ( v13 == 1 )
    {
      v14 = 4;
    }
    else if ( v13 == 2 )
    {
      v14 = 3;
    }
    else
    {
      v14 = 2;
    }
    v39 = v14;
    v41 = *(_WORD *)(a3 + 8);
    v40 = 0;
    v42 = 0;
    v43 = 0;
    v36 = 0;
    varE0[0] = a5;
    varE0[1] = 0;
    varE0[2] = 8;
    varE0[3] = 0;
    varE0[4] = a3 + 12;
    varE0[5] = 0;
    varE0[6] = 4;
    varE0[7] = 0;
    v37 = 0;
    v38 = 0;
    v15 = wcslen(a6);
    varE0[8] = (int)&v32;
    varE0[9] = 0;
    varE0[10] = 2;
    varE0[11] = 0;
    varE0[12] = (int)a6;
    varE0[13] = 0;
    varE0[14] = 2 * (unsigned __int16)(v15 + 1);
    varE0[15] = 0;
    va_copy((va_list)&varE0[16], va);
    varE0[17] = 0;
    v32 = v15 + 1;
    varE0[18] = 2;
    v16 = 5;
    varE0[19] = 0;
    if ( (_WORD)v48 )
    {
      varE0[22] = (unsigned __int16)v48;
      varE0[20] = v50;
      varE0[21] = 0;
      varE0[23] = 0;
      v16 = 6;
    }
    v17 = *(unsigned __int16 *)(a3 + 2) + 40;
    v33 = v17;
    if ( v17 > a4 )
    {
      v17 = a4;
      v33 = a4;
    }
    v18 = *(unsigned __int16 *)(a3 + 4);
    if ( *(_WORD *)(a3 + 4) && *(unsigned __int16 *)(a3 + 6) < v17 )
      *(_WORD *)(a3 + 6) = v17;
    *(_WORD *)(a3 + 4) = v18 + 1;
    v35 = 0;
    v31 = 0;
    v19 = &varE0[4 * v16];
    *v19 = (int)&v31;
    v19[1] = 0;
    v19[2] = 2;
    v19[3] = 0;
    v20 = v16 + 1;
    v21 = wcslen(a7);
    v22 = &varE0[4 * v20];
    v23 = v20 + 1;
    v22[1] = 0;
    v22[2] = 2 * (unsigned __int16)(v21 + 1);
    *v22 = (int)a7;
    v22[3] = 0;
    if ( v18 )
    {
      v24 = (*(unsigned __int16 *)(a3 + 6) + a3 + 1) & 0xFFFFFFFE;
      v7 = 0;
      do
      {
        if ( v24 + 2 * v11 >= a3 + v44 )
          break;
        if ( !*(_WORD *)(v24 + 2 * v11) )
        {
          v7 = (unsigned __int16)(v7 + 1);
          v34 = (unsigned __int16)(v11 + 1);
          v31 = v7;
        }
        v11 = (unsigned __int16)(v11 + 1);
      }
      while ( v7 < v18 );
      v35 = v7;
      LOWORD(v7) = varg_r0;
      v25 = &varE0[4 * v23];
      v26 = v34;
      *v25 = v24;
      v25[1] = 0;
      v25[2] = 2 * v26;
      v25[3] = 0;
      ++v23;
    }
    v31 = v35 + 1;
    v27 = &varE0[4 * v23];
    *v27 = (int)&v33;
    v27[1] = 0;
    v28 = v23 + 1;
    v29 = &varE0[4 * v28];
    *((_QWORD *)v27 + 1) = 4i64;
    *v29 = a3;
    v29[1] = 0;
    v29[2] = v17;
    v29[3] = 0;
    memset(v45, 0, sizeof(v45));
    v45[3] = 765409858;
    v45[4] = 1194525140;
    v45[5] = 503642007;
    v45[6] = -2065948288;
    v45[22] = 1;
    LOBYTE(v45[23]) = -1;
    v45[26] = -1;
    v45[27] = -1;
    v45[28] = 0;
    v45[29] = 0;
    v45[24] = 64;
    HIWORD(v45[23]) = v7;
    result = EtwpEventWriteFull(v45, 1, 0, 0, 0, &v36, 0, 4u, 0, 0, v28 + 1, (int)varE0, 0, 0, 0, 0, 0, 0);
    if ( result < 0 )
      --*(_WORD *)(a3 + 4);
  }
  return result;
}
