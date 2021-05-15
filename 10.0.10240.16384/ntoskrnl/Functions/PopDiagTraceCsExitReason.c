// PopDiagTraceCsExitReason 
 
int __fastcall PopDiagTraceCsExitReason(int result, int a2, int a3, int a4, char a5, int a6, char a7, int a8, char a9, int a10, int a11, char a12, int a13, int a14)
{
  unsigned int v14; // r2
  __int64 v15; // r6
  __int64 v16; // r4
  int v17; // r3
  unsigned int v18; // r2
  __int64 v19; // kr00_8
  int v20; // r1
  int v21; // r2
  char v22; // [sp+8h] [bp-198h] BYREF
  BOOL v23; // [sp+Ch] [bp-194h] BYREF
  int v24[2]; // [sp+10h] [bp-190h] BYREF
  int v25[2]; // [sp+18h] [bp-188h] BYREF
  int v26[2]; // [sp+20h] [bp-180h] BYREF
  __int64 v27; // [sp+28h] [bp-178h] BYREF
  _DWORD v28[2]; // [sp+30h] [bp-170h] BYREF
  int v29; // [sp+38h] [bp-168h] BYREF
  unsigned int v30; // [sp+3Ch] [bp-164h] BYREF
  int v31; // [sp+40h] [bp-160h] BYREF
  unsigned int v32; // [sp+44h] [bp-15Ch] BYREF
  unsigned int v33; // [sp+48h] [bp-158h] BYREF
  int v34; // [sp+4Ch] [bp-154h] BYREF
  __int64 v35; // [sp+50h] [bp-150h] BYREF
  int v36[2]; // [sp+58h] [bp-148h] BYREF
  int v37[2]; // [sp+60h] [bp-140h] BYREF
  int v38[78]; // [sp+68h] [bp-138h] BYREF

  v14 = *(unsigned __int8 *)(result + 92);
  v15 = *(_QWORD *)(result + 16);
  v34 = *(_DWORD *)result;
  v35 = v15;
  v16 = *(_QWORD *)(result + 64);
  v28[0] = *(_DWORD *)(result + 24);
  v17 = *(_DWORD *)(result + 28);
  v27 = v16;
  v28[1] = v17;
  v24[0] = *(_DWORD *)(result + 32);
  v24[1] = *(_DWORD *)(result + 36);
  v29 = *(_DWORD *)(result + 40);
  v25[0] = *(_DWORD *)(result + 48);
  v25[1] = *(_DWORD *)(result + 52);
  v26[0] = *(_DWORD *)(result + 56);
  v26[1] = *(_DWORD *)(result + 60);
  v38[0] = *(_DWORD *)(result + 72);
  v38[1] = *(_DWORD *)(result + 76);
  v36[0] = *(_DWORD *)(result + 96);
  v36[1] = *(_DWORD *)(result + 100);
  v22 = v14 >> 1;
  v31 = *(_DWORD *)(result + 84);
  v33 = v14 & 1;
  v18 = *(unsigned __int8 *)(result + 93);
  v37[0] = *(_DWORD *)(result + 120);
  v37[1] = *(_DWORD *)(result + 124);
  v30 = v18 & 1;
  v32 = (v18 >> 1) & 1;
  if ( PopDiagHandleRegistered )
  {
    v19 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_CS_EXIT_REASON);
    if ( result )
    {
      if ( v15 )
      {
        v23 = v16 != 0;
        v38[2] = (int)&v34;
        v38[3] = 0;
        v38[4] = 4;
        v38[5] = 0;
        v38[6] = (int)v24;
        v38[7] = 0;
        v38[8] = 8;
        v38[9] = 0;
        v38[10] = (int)v26;
        v38[11] = 0;
        v38[12] = 8;
        v38[13] = 0;
        v38[14] = (int)v25;
        v38[15] = 0;
        v38[16] = 8;
        v38[17] = 0;
        v38[18] = (int)v28;
        v38[19] = 0;
        v38[20] = 8;
        v38[21] = 0;
        v38[22] = (int)&v35;
        v38[23] = 0;
        v38[24] = 8;
        v38[25] = 0;
        v38[26] = (int)&v29;
        v38[27] = 0;
        v38[28] = 4;
        v38[29] = 0;
        v38[30] = (int)&v22;
        v38[31] = 0;
        v38[32] = 1;
        v38[33] = 0;
        v38[34] = (int)&v23;
        v38[35] = 0;
        v38[36] = 4;
        v38[37] = 0;
        v38[38] = (int)&v31;
        v38[39] = 0;
        v38[40] = 4;
        v38[41] = 0;
        v38[42] = (int)&v27;
        v38[43] = 0;
        v38[44] = 8;
        v38[45] = 0;
        v38[46] = (int)v38;
        v38[47] = 0;
        v38[48] = 8;
        v38[49] = 0;
        v38[50] = (int)&v33;
        v38[51] = 0;
        v38[52] = 4;
        v38[53] = 0;
        v38[54] = (int)v36;
        v38[55] = 0;
        v38[56] = 8;
        v38[57] = 0;
        v38[58] = (int)v37;
        v38[59] = 0;
        v38[60] = 8;
        v38[61] = 0;
        v38[62] = (int)&v32;
        v38[63] = 0;
        v38[64] = 4;
        v38[65] = 0;
        v38[66] = (int)&v30;
        v38[67] = 0;
        v38[68] = 4;
        v38[69] = 0;
        result = EtwWrite(v19, SHIDWORD(v19), (int)POP_ETW_EVENT_CS_EXIT_REASON, 0);
      }
      else
      {
        result = sub_7BF280(result, v20, v21, 0, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
      }
    }
  }
  return result;
}
