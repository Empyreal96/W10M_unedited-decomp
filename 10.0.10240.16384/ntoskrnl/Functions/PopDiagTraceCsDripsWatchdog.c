// PopDiagTraceCsDripsWatchdog 
 
int __fastcall PopDiagTraceCsDripsWatchdog(int result, int a2, int a3, int a4, char a5, unsigned __int8 a6, char a7, unsigned __int16 *a8, unsigned __int16 *a9)
{
  __int64 v10; // kr00_8
  int v11; // r2
  int v12; // r3
  int v13; // r2
  int v14; // r3
  __int16 v15; // [sp+8h] [bp-D0h] BYREF
  __int16 v16; // [sp+Ah] [bp-CEh] BYREF
  int v17; // [sp+Ch] [bp-CCh] BYREF
  _DWORD v18[30]; // [sp+10h] [bp-C8h] BYREF
  __int16 *v19; // [sp+88h] [bp-50h]
  int v20; // [sp+8Ch] [bp-4Ch]
  int v21; // [sp+90h] [bp-48h]
  int v22; // [sp+94h] [bp-44h]
  int v23; // [sp+98h] [bp-40h]
  int v24; // [sp+9Ch] [bp-3Ch]
  int v25; // [sp+A0h] [bp-38h]
  int v26; // [sp+A4h] [bp-34h]
  __int16 *v27; // [sp+A8h] [bp-30h]
  int v28; // [sp+ACh] [bp-2Ch]
  int v29; // [sp+B0h] [bp-28h]
  int v30; // [sp+B4h] [bp-24h]
  int v31; // [sp+B8h] [bp-20h]
  int v32; // [sp+BCh] [bp-1Ch]
  int v33; // [sp+C0h] [bp-18h]
  int v34; // [sp+C4h] [bp-14h]
  int varg_r0; // [sp+E0h] [bp+8h] BYREF
  int varg_r1; // [sp+E4h] [bp+Ch] BYREF
  int varg_r2[2]; // [sp+E8h] [bp+10h] BYREF

  varg_r0 = result;
  varg_r1 = a2;
  varg_r2[0] = a3;
  varg_r2[1] = a4;
  if ( PopDiagHandleRegistered )
  {
    v10 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_CS_DRIPS_WATCHDOG);
    if ( result )
    {
      v18[2] = &varg_r0;
      v18[3] = 0;
      v18[4] = 4;
      v18[5] = 0;
      v18[6] = &varg_r1;
      v18[7] = 0;
      v18[8] = 4;
      v18[9] = 0;
      v18[10] = varg_r2;
      v18[11] = 0;
      v18[12] = 4;
      v18[13] = 0;
      v18[14] = &v17;
      v18[15] = 0;
      v18[16] = 4;
      v18[17] = 0;
      v18[18] = &a5;
      v18[19] = 0;
      v18[20] = 4;
      v18[21] = 0;
      v18[22] = v18;
      v18[23] = 0;
      v18[24] = 4;
      v18[25] = 0;
      v18[26] = &a7;
      v18[27] = 0;
      v18[28] = 1;
      v18[29] = 0;
      v17 = a4;
      v18[0] = a6;
      if ( a8 )
      {
        v11 = *a8;
        v15 = *a8 >> 1;
        v19 = &v15;
        v20 = 0;
        v21 = 2;
        v22 = 0;
        v12 = *((_DWORD *)a8 + 1);
        v25 = v11;
        v23 = v12;
        v24 = 0;
      }
      else
      {
        v15 = 0;
        v19 = &v15;
        v20 = 0;
        v21 = 2;
        v22 = 0;
        v23 = 0;
        v24 = 0;
        v25 = 0;
      }
      v26 = 0;
      if ( a9 )
      {
        v13 = *a9;
        v16 = *a9 >> 1;
        v27 = &v16;
        v28 = 0;
        v29 = 2;
        v30 = 0;
        v14 = *((_DWORD *)a9 + 1);
        v33 = v13;
        v31 = v14;
        v32 = 0;
      }
      else
      {
        v16 = 0;
        v27 = &v16;
        v28 = 0;
        v29 = 2;
        v30 = 0;
        v31 = 0;
        v32 = 0;
        v33 = 0;
      }
      v34 = 0;
      result = EtwWrite(v10, SHIDWORD(v10), (int)POP_ETW_EVENT_CS_DRIPS_WATCHDOG, 0);
    }
  }
  return result;
}
