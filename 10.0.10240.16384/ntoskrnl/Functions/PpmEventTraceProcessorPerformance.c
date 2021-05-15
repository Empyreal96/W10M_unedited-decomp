// PpmEventTraceProcessorPerformance 
 
int __fastcall PpmEventTraceProcessorPerformance(int result)
{
  int v1; // r4
  __int64 v2; // kr00_8
  _DWORD *v3; // r1
  _DWORD *v4; // r2
  int v5; // r3
  __int16 v6; // [sp+8h] [bp-E8h] BYREF
  int v7; // [sp+Ch] [bp-E4h] BYREF
  int v8; // [sp+10h] [bp-E0h] BYREF
  int v9; // [sp+14h] [bp-DCh] BYREF
  int v10; // [sp+18h] [bp-D8h] BYREF
  int v11; // [sp+1Ch] [bp-D4h] BYREF
  int v12; // [sp+20h] [bp-D0h] BYREF
  int v13; // [sp+24h] [bp-CCh] BYREF
  int v14; // [sp+28h] [bp-C8h] BYREF
  int v15[49]; // [sp+2Ch] [bp-C4h] BYREF

  v1 = result;
  if ( PpmEtwRegistered )
  {
    v2 = *(_QWORD *)&PpmEtwHandle;
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_CURRENT_PERF_RUNDOWN);
    if ( result )
    {
      v3 = *(_DWORD **)(v1 + 3204);
      v4 = *(_DWORD **)(v1 + 3200);
      v15[0] = *(unsigned __int8 *)(v1 + 3222);
      if ( v3 )
      {
        v14 = v3[4];
        v9 = v3[5];
        v5 = v3[11];
      }
      else
      {
        v5 = 100;
        v14 = 100;
        v9 = 100;
      }
      v13 = v5;
      if ( v4 )
      {
        v7 = v4[36];
        v8 = v4[35];
        v10 = v4[38];
        v11 = v4[20];
        v12 = *(_DWORD *)(v1 + 3224);
      }
      else
      {
        v7 = 100;
        v8 = 100;
        v10 = 100;
        v12 = 100;
        v11 = *(_DWORD *)(v1 + 964);
      }
      v6 = *(unsigned __int8 *)(v1 + 1052);
      v15[1] = (int)&v6;
      v15[2] = 0;
      v15[3] = 2;
      v15[4] = 0;
      v15[5] = v1 + 1053;
      v15[6] = 0;
      v15[7] = 1;
      v15[8] = 0;
      v15[9] = (int)v15;
      v15[10] = 0;
      v15[11] = 4;
      v15[12] = 0;
      v15[13] = (int)&v14;
      v15[14] = 0;
      v15[15] = 4;
      v15[16] = 0;
      v15[17] = (int)&v9;
      v15[18] = 0;
      v15[19] = 4;
      v15[20] = 0;
      v15[21] = (int)&v13;
      v15[22] = 0;
      v15[23] = 4;
      v15[24] = 0;
      v15[25] = (int)&v11;
      v15[26] = 0;
      v15[27] = 4;
      v15[28] = 0;
      v15[29] = (int)&v7;
      v15[30] = 0;
      v15[31] = 4;
      v15[32] = 0;
      v15[33] = (int)&v8;
      v15[34] = 0;
      v15[35] = 4;
      v15[36] = 0;
      v15[37] = (int)&v10;
      v15[38] = 0;
      v15[39] = 4;
      v15[40] = 0;
      v15[41] = (int)&v12;
      v15[42] = 0;
      v15[43] = 4;
      v15[44] = 0;
      result = EtwWrite(v2, SHIDWORD(v2), (int)PPM_ETW_CURRENT_PERF_RUNDOWN, 0);
    }
  }
  return result;
}
