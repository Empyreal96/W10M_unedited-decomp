// PopDiagTraceDirtyTransition 
 
int PopDiagTraceDirtyTransition(int result, int a2, ...)
{
  int v3; // r4
  __int64 v4; // kr00_8
  int v5; // r3
  _DWORD *v6; // r2
  char *v7; // r3
  int *v8; // r2
  int v9; // r1
  int v10; // [sp+8h] [bp-B0h] BYREF
  int v11; // [sp+Ch] [bp-ACh] BYREF
  int v12; // [sp+10h] [bp-A8h] BYREF
  int v13; // [sp+14h] [bp-A4h]
  int v14; // [sp+18h] [bp-A0h]
  int v15; // [sp+1Ch] [bp-9Ch]
  int *v16; // [sp+20h] [bp-98h]
  int v17; // [sp+24h] [bp-94h]
  int v18; // [sp+28h] [bp-90h]
  int v19; // [sp+2Ch] [bp-8Ch]
  char v20; // [sp+30h] [bp-88h] BYREF
  int *v21; // [sp+70h] [bp-48h]
  int v22; // [sp+74h] [bp-44h]
  int v23; // [sp+78h] [bp-40h]
  int v24; // [sp+7Ch] [bp-3Ch]
  va_list v25; // [sp+80h] [bp-38h]
  int v26; // [sp+84h] [bp-34h]
  int v27; // [sp+88h] [bp-30h]
  int v28; // [sp+8Ch] [bp-2Ch]
  va_list v29; // [sp+90h] [bp-28h]
  int v30; // [sp+94h] [bp-24h]
  int v31; // [sp+98h] [bp-20h]
  int v32; // [sp+9Ch] [bp-1Ch]
  int varg_r2; // [sp+C8h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+C8h] [bp+10h]
  int varg_r3; // [sp+CCh] [bp+14h]
  va_list va1; // [sp+D0h] [bp+18h] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v3 = result;
  if ( PopDiagHandleRegistered )
  {
    v4 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DIRTY_TRANSITION);
    if ( result )
    {
      v10 = 0;
      v12 = 0;
      v13 = 0;
      v14 = 0;
      v15 = 0;
      v5 = *(_DWORD *)(v3 + 132);
      if ( v5 )
      {
        v6 = *(_DWORD **)(v5 + 108);
        if ( v6 )
        {
          v10 = v6[10];
          v12 = v6[11];
          v13 = v6[12];
          v14 = v6[13];
          v15 = v6[14];
        }
      }
      v16 = &v10;
      v17 = 0;
      v18 = 4;
      v19 = 0;
      v7 = &v20;
      v8 = &v12;
      v9 = 4;
      v11 = a2;
      do
      {
        *((_DWORD *)v7 + 1) = 0;
        *((_DWORD *)v7 + 2) = 4;
        *(_DWORD *)v7 = v8;
        *((_DWORD *)v7 + 3) = 0;
        v7 += 16;
        ++v8;
        --v9;
      }
      while ( v9 );
      v21 = &v11;
      v22 = 0;
      v23 = 4;
      v24 = 0;
      va_copy(v25, varg_r2a);
      v26 = 0;
      v27 = 8;
      v28 = 0;
      va_copy(v29, va1);
      v30 = 0;
      v31 = 4;
      v32 = 0;
      result = EtwWrite(v4, SHIDWORD(v4), (int)POP_ETW_EVENT_DIRTY_TRANSITION, 0);
    }
  }
  return result;
}
