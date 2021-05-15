// PpmEventTraceProcessorIdleAccounting 
 
int __fastcall PpmEventTraceProcessorIdleAccounting(int a1)
{
  int v1; // r4
  _BYTE *v3; // r3
  int *v4; // r6
  int v5; // r5
  int v6; // r7
  _BYTE *v7; // r0
  _DWORD *v8; // r2
  int v9; // r1
  int v10; // r3
  _BYTE *v11; // r0
  _DWORD *v12; // r6
  __int16 v14; // [sp+8h] [bp-90h] BYREF
  int v15; // [sp+Ch] [bp-8Ch] BYREF
  __int64 v16; // [sp+10h] [bp-88h] BYREF
  _DWORD *v17; // [sp+18h] [bp-80h]
  int v18; // [sp+1Ch] [bp-7Ch]
  int v19; // [sp+20h] [bp-78h]
  int v20; // [sp+24h] [bp-74h]
  __int16 *v21; // [sp+28h] [bp-70h]
  int v22; // [sp+2Ch] [bp-6Ch]
  int v23; // [sp+30h] [bp-68h]
  int v24; // [sp+34h] [bp-64h]
  int v25; // [sp+38h] [bp-60h]
  int v26; // [sp+3Ch] [bp-5Ch]
  int v27; // [sp+40h] [bp-58h]
  int v28; // [sp+44h] [bp-54h]
  __int64 *v29; // [sp+48h] [bp-50h]
  int v30; // [sp+4Ch] [bp-4Ch]
  int v31; // [sp+50h] [bp-48h]
  int v32; // [sp+54h] [bp-44h]
  int *v33; // [sp+58h] [bp-40h]
  int v34; // [sp+5Ch] [bp-3Ch]
  int v35; // [sp+60h] [bp-38h]
  int v36; // [sp+64h] [bp-34h]
  int v37; // [sp+68h] [bp-30h]
  int v38; // [sp+6Ch] [bp-2Ch]
  int v39; // [sp+70h] [bp-28h]
  int v40; // [sp+74h] [bp-24h]

  v1 = 0;
  if ( PpmEtwRegistered )
  {
    if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_IDLE_ACCOUNTING_RUNDOWN) )
    {
      v3 = *(_BYTE **)(a1 + 2944);
      v4 = *(int **)(a1 + 2948);
      if ( v3 )
      {
        if ( v4 )
        {
          v5 = *v4;
          v6 = 0;
          if ( *v3 == 1 )
          {
            v6 = 80 * v5;
            v7 = (_BYTE *)ExAllocatePoolWithTag(512, 80 * v5);
            v1 = (int)v7;
            if ( !v7 )
              return 0;
            memset(v7, 0, 80 * v5);
            if ( v5 )
            {
              v8 = (_DWORD *)v1;
              v9 = v5;
              do
              {
                *v8 = v4[36];
                v8[1] = v4[37];
                v8[4] = v4[38];
                v8[5] = v4[39];
                v8[6] = v4[28];
                v8[7] = v4[29];
                v8[8] = v4[30];
                v8[9] = v4[31];
                v8[14] = v4[24];
                v8[15] = v4[25];
                v8[16] = v4[22];
                v8[17] = v4[23];
                v8[18] = v4[20];
                v8[19] = v4[21];
                v8[2] = v4[40];
                v8[3] = v4[41];
                v8[10] = v4[44];
                v8[11] = v4[45];
                v8[12] = v4[42];
                v10 = v4[43];
                v4 += 246;
                v8[13] = v10;
                v8 += 20;
                --v9;
              }
              while ( v9 );
            }
          }
          v11 = (_BYTE *)ExAllocatePoolWithTag(512, 416 * v5 + 24);
          v12 = v11;
          if ( v11 )
          {
            memset(v11, 0, 416 * v5 + 24);
            PpmTranslateIdleAccounting(a1 + 2944, v12, &v16);
            v17 = v12;
            v18 = 0;
            v19 = 416 * v5 + 24;
            v20 = 0;
            v14 = *(unsigned __int8 *)(a1 + 1052);
            v21 = &v14;
            v22 = 0;
            v23 = 2;
            v24 = 0;
            v25 = a1 + 1053;
            v26 = 0;
            v27 = 1;
            v28 = 0;
            v29 = &v16;
            v30 = 0;
            v31 = 8;
            v32 = 0;
            if ( v1 )
            {
              v37 = v1;
              v38 = 0;
              v39 = v6;
              v40 = 0;
              v15 = v5;
            }
            else
            {
              v15 = 0;
            }
            v33 = &v15;
            v34 = 0;
            v35 = 4;
            v36 = 0;
            EtwWrite(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_IDLE_ACCOUNTING_RUNDOWN, 0);
            ExFreePoolWithTag(v12);
          }
          if ( v1 )
            ExFreePoolWithTag(v1);
        }
      }
    }
  }
  return 0;
}
