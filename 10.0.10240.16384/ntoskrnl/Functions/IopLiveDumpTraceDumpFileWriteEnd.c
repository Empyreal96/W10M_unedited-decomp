// IopLiveDumpTraceDumpFileWriteEnd 
 
int IopLiveDumpTraceDumpFileWriteEnd(int a1, int a2, ...)
{
  int result; // r0
  int v4; // r1
  int *v5; // r7
  int v6; // r2
  int v7; // r1
  int v8; // r2
  int v9; // kr08_4
  int v10; // r2
  int v11; // r3
  int v12; // [sp+8h] [bp-88h] BYREF
  int v13; // [sp+Ch] [bp-84h]
  __int64 v14; // [sp+10h] [bp-80h] BYREF
  int v15[2]; // [sp+18h] [bp-78h] BYREF
  __int64 v16; // [sp+20h] [bp-70h] BYREF
  va_list v17; // [sp+28h] [bp-68h]
  int v18; // [sp+2Ch] [bp-64h]
  int v19; // [sp+30h] [bp-60h]
  int v20; // [sp+34h] [bp-5Ch]
  __int64 *v21; // [sp+38h] [bp-58h]
  int v22; // [sp+3Ch] [bp-54h]
  int v23; // [sp+40h] [bp-50h]
  int v24; // [sp+44h] [bp-4Ch]
  __int64 *v25; // [sp+48h] [bp-48h]
  int v26; // [sp+4Ch] [bp-44h]
  int v27; // [sp+50h] [bp-40h]
  int v28; // [sp+54h] [bp-3Ch]
  int *v29; // [sp+58h] [bp-38h]
  int v30; // [sp+5Ch] [bp-34h]
  int v31; // [sp+60h] [bp-30h]
  int v32; // [sp+64h] [bp-2Ch]
  int *v33; // [sp+68h] [bp-28h]
  int v34; // [sp+6Ch] [bp-24h]
  int v35; // [sp+70h] [bp-20h]
  int v36; // [sp+74h] [bp-1Ch]
  int varg_r2; // [sp+A0h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+A0h] [bp+10h]
  va_list varg_r3; // [sp+A4h] [bp+14h] BYREF

  va_start(varg_r3, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3, _DWORD);
  result = IopLiveDumpIsTracingEnabled();
  if ( result )
  {
    if ( v4 )
      v5 = LIVEDUMP_EVENT_WRITE_DEFERRED_DUMPDATA_TO_FILE_END;
    else
      v5 = LIVEDUMP_EVENT_WRITE_DUMPDATA_TO_FILE_END;
    v6 = *(_DWORD *)(a1 + 228);
    if ( varg_r2 < 0 )
    {
      v11 = 0;
      v14 = 0i64;
      v16 = 0i64;
      v12 = 0;
      v13 = 0;
      v15[0] = 0;
    }
    else
    {
      v14 = *(_QWORD *)(v6 + 4000);
      v16 = *(_QWORD *)(v6 + 4128);
      v7 = *(_DWORD *)(v6 + 4140);
      v9 = *(_DWORD *)(v6 + 4136) << 12;
      v8 = (unsigned __int64)*(unsigned int *)(v6 + 4136) >> 20;
      v12 = v9;
      v10 = v8 | (v7 << 12);
      v13 = v10;
      v11 = (v14 - __PAIR64__(v10, v9) - v16) >> 32;
      v15[0] = v14 - v9 - v16;
    }
    v15[1] = v11;
    va_copy(v17, varg_r2a);
    v18 = 0;
    v19 = 4;
    v20 = 0;
    v21 = &v14;
    v22 = 0;
    v23 = 8;
    v24 = 0;
    v25 = &v16;
    v26 = 0;
    v27 = 8;
    v28 = 0;
    v29 = &v12;
    v30 = 0;
    v31 = 8;
    v32 = 0;
    v33 = v15;
    v34 = 0;
    v35 = 8;
    v36 = 0;
    result = EtwWrite(IopLiveDumpEtwRegHandle, SHIDWORD(IopLiveDumpEtwRegHandle), (int)v5, 0);
  }
  return result;
}
