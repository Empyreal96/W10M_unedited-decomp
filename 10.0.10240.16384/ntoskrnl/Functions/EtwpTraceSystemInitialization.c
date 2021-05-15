// EtwpTraceSystemInitialization 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpTraceSystemInitialization(int a1, int a2, int a3)
{
  int result; // r0
  int v4; // r5 OVERLAPPED
  int v5; // r6 OVERLAPPED
  __int16 v6; // [sp+8h] [bp-278h] BYREF
  int v7; // [sp+Ch] [bp-274h] BYREF
  int v8; // [sp+10h] [bp-270h] BYREF
  int v9; // [sp+14h] [bp-26Ch] BYREF
  int v10; // [sp+18h] [bp-268h] BYREF
  int v11; // [sp+1Ch] [bp-264h] BYREF
  int v12; // [sp+20h] [bp-260h] BYREF
  int v13; // [sp+24h] [bp-25Ch] BYREF
  int v14; // [sp+28h] [bp-258h] BYREF
  _DWORD v15[2]; // [sp+30h] [bp-250h] BYREF
  __int64 v16; // [sp+38h] [bp-248h] BYREF
  int v17; // [sp+40h] [bp-240h] BYREF
  int v18; // [sp+44h] [bp-23Ch] BYREF
  int v19; // [sp+48h] [bp-238h] BYREF
  int v20; // [sp+4Ch] [bp-234h] BYREF
  __int16 v21; // [sp+154h] [bp-12Ch] BYREF
  int *v22; // [sp+160h] [bp-120h]
  int v23; // [sp+164h] [bp-11Ch]
  int v24; // [sp+168h] [bp-118h]
  int v25; // [sp+16Ch] [bp-114h]
  int *v26; // [sp+170h] [bp-110h]
  int v27; // [sp+174h] [bp-10Ch]
  int v28; // [sp+178h] [bp-108h]
  int v29; // [sp+17Ch] [bp-104h]
  int *v30; // [sp+180h] [bp-100h]
  int v31; // [sp+184h] [bp-FCh]
  int v32; // [sp+188h] [bp-F8h]
  int v33; // [sp+18Ch] [bp-F4h]
  int *v34; // [sp+190h] [bp-F0h]
  int v35; // [sp+194h] [bp-ECh]
  int v36; // [sp+198h] [bp-E8h]
  int v37; // [sp+19Ch] [bp-E4h]
  __int16 *v38; // [sp+1A0h] [bp-E0h]
  int v39; // [sp+1A4h] [bp-DCh]
  int v40; // [sp+1A8h] [bp-D8h]
  int v41; // [sp+1ACh] [bp-D4h]
  int *v42; // [sp+1B0h] [bp-D0h]
  int v43; // [sp+1B4h] [bp-CCh]
  int v44; // [sp+1B8h] [bp-C8h]
  int v45; // [sp+1BCh] [bp-C4h]
  __int64 *v46; // [sp+1C0h] [bp-C0h]
  int v47; // [sp+1C4h] [bp-BCh]
  int v48; // [sp+1C8h] [bp-B8h]
  int v49; // [sp+1CCh] [bp-B4h]
  _DWORD v50[44]; // [sp+1D0h] [bp-B0h] BYREF

  v7 = 0x4000;
  v8 = InitSafeBootMode;
  v17 = 284;
  result = RtlGetVersion(&v17, a2, a3, 284);
  if ( result >= 0 )
  {
    *(_QWORD *)&v4 = KeBootTime;
    v16 = KeBootTime;
    if ( (unsigned int)dword_617748 > 5 && TlgKeywordOn((int)&dword_617748, 0x200000000000i64) )
    {
      v15[0] = v4;
      v15[1] = v5;
      v11 = v18;
      v14 = v19;
      v13 = v20;
      v9 = 1;
      v12 = v7;
      v6 = v21;
      v10 = v8;
      v50[8] = &v11;
      v50[9] = 0;
      v50[10] = 4;
      v50[11] = 0;
      v50[12] = &v14;
      v50[13] = 0;
      v50[14] = 4;
      v50[15] = 0;
      v50[16] = &v13;
      v50[17] = 0;
      v50[18] = 4;
      v50[19] = 0;
      v50[20] = &v9;
      v50[21] = 0;
      v50[22] = 4;
      v50[23] = 0;
      v50[24] = &v12;
      v50[25] = 0;
      v50[26] = 4;
      v50[27] = 0;
      v50[28] = &v6;
      v50[29] = 0;
      v50[30] = 2;
      v50[31] = 0;
      v50[32] = &v10;
      v50[33] = 0;
      v50[34] = 4;
      v50[35] = 0;
      v50[36] = v15;
      v50[37] = 0;
      v50[38] = 8;
      v50[39] = 0;
      TlgWrite(&dword_617748, (unsigned __int8 *)dword_4149EC + 1, 0, 0, 10, v50);
    }
    result = EtwKernelProvRegHandle;
    if ( EtwKernelProvRegHandle )
    {
      v22 = &v18;
      v23 = 0;
      v24 = 4;
      v25 = 0;
      v26 = &v19;
      v27 = 0;
      v28 = 4;
      v29 = 0;
      v30 = &v20;
      v31 = 0;
      v32 = 4;
      v33 = 0;
      v34 = &v7;
      v35 = 0;
      v36 = 4;
      v37 = 0;
      v38 = &v21;
      v39 = 0;
      v40 = 2;
      v41 = 0;
      v42 = &v8;
      v43 = 0;
      v44 = 4;
      v45 = 0;
      v46 = &v16;
      v47 = 0;
      v48 = 8;
      v49 = 0;
      result = EtwWrite(EtwKernelProvRegHandle, SHIDWORD(EtwKernelProvRegHandle), (int)KernelSystemStart, 0);
    }
  }
  return result;
}
