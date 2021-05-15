// PpmEventTraceHeteroResponse 
 
int PpmEventTraceHeteroResponse(int result, int a2, int a3, int a4, ...)
{
  int v4; // r8
  int v5; // r4
  int v6; // r7
  int v7; // r6
  int v8; // r3
  __int64 v9; // kr08_8
  unsigned __int64 *v10; // r4
  int v11; // r7
  unsigned __int64 v12; // r0
  char v13; // [sp+8h] [bp-E0h] BYREF
  char v14; // [sp+9h] [bp-DFh] BYREF
  unsigned __int64 *v15; // [sp+Ch] [bp-DCh]
  int v16; // [sp+10h] [bp-D8h]
  int v17; // [sp+18h] [bp-D0h]
  int v18; // [sp+1Ch] [bp-CCh]
  int v19; // [sp+20h] [bp-C8h]
  int v20; // [sp+24h] [bp-C4h]
  int v21; // [sp+28h] [bp-C0h]
  int v22; // [sp+2Ch] [bp-BCh]
  int v23; // [sp+30h] [bp-B8h]
  int v24; // [sp+34h] [bp-B4h]
  char *v25; // [sp+38h] [bp-B0h]
  int v26; // [sp+3Ch] [bp-ACh]
  int v27; // [sp+40h] [bp-A8h]
  int v28; // [sp+44h] [bp-A4h]
  int v29; // [sp+48h] [bp-A0h]
  int v30; // [sp+4Ch] [bp-9Ch]
  int v31; // [sp+50h] [bp-98h]
  int v32; // [sp+54h] [bp-94h]
  unsigned __int64 *v33; // [sp+58h] [bp-90h]
  int v34; // [sp+5Ch] [bp-8Ch]
  int v35; // [sp+60h] [bp-88h]
  int v36; // [sp+64h] [bp-84h]
  va_list v37; // [sp+68h] [bp-80h]
  int v38; // [sp+6Ch] [bp-7Ch]
  int v39; // [sp+70h] [bp-78h]
  int v40; // [sp+74h] [bp-74h]
  int v41; // [sp+78h] [bp-70h]
  int v42; // [sp+7Ch] [bp-6Ch]
  int v43; // [sp+80h] [bp-68h]
  int v44; // [sp+84h] [bp-64h]
  char *v45; // [sp+88h] [bp-60h]
  int v46; // [sp+8Ch] [bp-5Ch]
  int v47; // [sp+90h] [bp-58h]
  int v48; // [sp+94h] [bp-54h]
  va_list v49; // [sp+98h] [bp-50h]
  int v50; // [sp+9Ch] [bp-4Ch]
  int v51; // [sp+A0h] [bp-48h]
  int v52; // [sp+A4h] [bp-44h]
  int v53; // [sp+A8h] [bp-40h]
  int v54; // [sp+ACh] [bp-3Ch]
  int v55; // [sp+B0h] [bp-38h]
  int v56; // [sp+B4h] [bp-34h]
  va_list v57; // [sp+B8h] [bp-30h]
  int v58; // [sp+BCh] [bp-2Ch]
  int v59; // [sp+C0h] [bp-28h]
  int v60; // [sp+C4h] [bp-24h]
  unsigned __int64 v61; // [sp+100h] [bp+18h] BYREF
  va_list va; // [sp+100h] [bp+18h]
  void *v63; // [sp+108h] [bp+20h] BYREF
  va_list va1; // [sp+108h] [bp+20h]
  va_list va2; // [sp+10Ch] [bp+24h] BYREF

  va_start(va2, a4);
  va_start(va1, a4);
  va_start(va, a4);
  v61 = va_arg(va1, __int64);
  va_copy(va2, va1);
  v63 = va_arg(va2, void *);
  v15 = (unsigned __int64 *)a3;
  v16 = a2;
  v4 = result;
  if ( PpmEtwRegistered )
  {
    v5 = dword_61DEC4;
    v6 = PpmEtwHandle;
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_HETERO_RESPONSE);
    if ( result )
    {
      v7 = *(unsigned __int8 *)(v4 + 6);
      v8 = *(_DWORD *)(v4 + 84);
      v9 = v61;
      v13 = *(_BYTE *)(v4 + 6);
      v14 = v8;
      if ( v61 > 1 && v7 )
      {
        v10 = v15;
        v11 = v7;
        do
        {
          if ( !v9 )
            __brkdiv0();
          LODWORD(v12) = _rt_udiv64(v9, *v10);
          *v10++ = v12;
          --v11;
        }
        while ( v11 );
        v5 = dword_61DEC4;
        v6 = PpmEtwHandle;
      }
      v17 = v4 + 4;
      v18 = 0;
      v19 = 2;
      v20 = 0;
      v21 = v4 + 8;
      v22 = 0;
      v23 = 4;
      v24 = 0;
      v25 = &v13;
      v26 = 0;
      v27 = 1;
      v28 = 0;
      v29 = v16;
      v30 = 0;
      v31 = 4 * v7;
      v32 = 0;
      v33 = v15;
      v34 = 0;
      v35 = 8 * v7;
      v36 = 0;
      va_copy(v37, va);
      v38 = 0;
      v39 = 8;
      v40 = 0;
      v41 = v4 + 83;
      v42 = 0;
      v43 = 1;
      v44 = 0;
      v45 = &v14;
      v46 = 0;
      v47 = 1;
      v48 = 0;
      va_copy(v49, va1);
      v50 = 0;
      v51 = 1;
      v52 = 0;
      v53 = v4 + 75;
      v54 = 0;
      v55 = 1;
      v56 = 0;
      va_copy(v57, va2);
      v58 = 0;
      v59 = 4;
      v60 = 0;
      result = EtwWrite(v6, v5, (int)PPM_ETW_HETERO_RESPONSE, 0);
    }
  }
  return result;
}
