// PpmPerfSelectProcessorState 
 
int __fastcall PpmPerfSelectProcessorState(int a1)
{
  unsigned int v1; // r10
  int v2; // r9
  int v3; // r8
  unsigned __int8 *v5; // r4
  int result; // r0
  int *v7; // r1
  int v8; // r7
  int v9; // r2
  int v10; // r0
  unsigned int v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r5
  _DWORD *v14; // r2
  int v15; // r3
  unsigned int v16; // r0
  unsigned int v17; // r7
  int v18; // r1
  unsigned int v19; // r3
  bool v20; // cf
  int v21; // r7
  int v22; // r1
  unsigned int v24; // r0
  unsigned int v25; // r0
  int v26; // r3
  int v27; // r1
  int v28; // [sp+10h] [bp-C8h] BYREF
  unsigned int v29; // [sp+14h] [bp-C4h]
  _DWORD *v30; // [sp+18h] [bp-C0h]
  unsigned int v31; // [sp+1Ch] [bp-BCh]
  int v32; // [sp+20h] [bp-B8h]
  int v33; // [sp+24h] [bp-B4h]
  unsigned int v34; // [sp+28h] [bp-B0h] BYREF
  unsigned int v35; // [sp+2Ch] [bp-ACh]
  unsigned int v36; // [sp+30h] [bp-A8h] BYREF
  unsigned int v37; // [sp+34h] [bp-A4h] BYREF
  unsigned int v38; // [sp+38h] [bp-A0h] BYREF
  unsigned int v39; // [sp+3Ch] [bp-9Ch]
  unsigned int v40; // [sp+40h] [bp-98h]
  int v41; // [sp+44h] [bp-94h]
  char v42[8]; // [sp+48h] [bp-90h] BYREF
  char v43[8]; // [sp+50h] [bp-88h] BYREF
  int *v44; // [sp+58h] [bp-80h]
  int v45; // [sp+5Ch] [bp-7Ch]
  int v46; // [sp+60h] [bp-78h]
  int v47; // [sp+64h] [bp-74h]
  int v48; // [sp+68h] [bp-70h]
  int v49; // [sp+6Ch] [bp-6Ch]
  int v50; // [sp+70h] [bp-68h]
  int v51; // [sp+74h] [bp-64h]
  int *v52; // [sp+78h] [bp-60h]
  int v53; // [sp+7Ch] [bp-5Ch]
  int v54; // [sp+80h] [bp-58h]
  int v55; // [sp+84h] [bp-54h]
  int *v56; // [sp+88h] [bp-50h]
  int v57; // [sp+8Ch] [bp-4Ch]
  int v58; // [sp+90h] [bp-48h]
  int v59; // [sp+94h] [bp-44h]
  int *v60; // [sp+98h] [bp-40h]
  int v61; // [sp+9Ch] [bp-3Ch]
  int v62; // [sp+A0h] [bp-38h]
  int v63; // [sp+A4h] [bp-34h]
  int *v64; // [sp+A8h] [bp-30h]
  int v65; // [sp+ACh] [bp-2Ch]
  int v66; // [sp+B0h] [bp-28h]
  int v67; // [sp+B4h] [bp-24h]

  v28 = 0;
  v1 = 0;
  v2 = *(unsigned __int8 *)(a1 + 2986);
  v30 = *(_DWORD **)(a1 + 3204);
  v3 = *(_DWORD *)(a1 + 3200);
  v37 = v30[1];
  v5 = *(unsigned __int8 **)(a1 + 3196);
  v41 = 1;
  if ( (unsigned int)PpmMfBufferingThreshold > 0x64 )
    return sub_54078C();
  v7 = &PpmCurrentProfile[44 * dword_61EC0C + 8];
  if ( v5
    && PpmCurrentProfile == (int *)PpmLowPowerProfile
    && byte_61EC4C
    && v5[185] < (unsigned int)(unsigned __int8)PpmMfBufferingThreshold )
  {
    v7 = &dword_61DBC0[44 * dword_61EC0C];
    v8 = 4096;
    v28 = 4096;
  }
  else
  {
    v8 = 0;
  }
  v9 = v7[12];
  v10 = *((unsigned __int8 *)v7 + v2 + 70);
  v38 = *((unsigned __int8 *)v7 + v2 + 30);
  v36 = *((unsigned __int8 *)v7 + v2 + 32);
  v32 = *((unsigned __int8 *)v7 + v2 + 34);
  v33 = *((unsigned __int8 *)v7 + v2 + 36);
  v11 = *((unsigned __int8 *)v7 + v2 + 40);
  v39 = *((unsigned __int8 *)v7 + v2 + 38);
  v34 = v11;
  v12 = (unsigned __int8)((int)(v11 + v39) >> 1);
  v35 = v12;
  if ( v9 == 3 || v9 == 1 )
  {
    v13 = *(_DWORD *)(v3 + 84);
    v14 = v30;
  }
  else
  {
    v14 = v30;
    if ( PpmPerfBoostAtGuaranteed )
      v13 = v30[4];
    else
      v13 = 100;
  }
  v15 = *(unsigned __int8 *)(a1 + 3222);
  v29 = v13;
  if ( !v15 || !v10 )
  {
    v40 = (unsigned __int8)PpmPerfIdealAggressiveIncreaseThreshold;
    if ( (unsigned __int8)PpmPerfIdealAggressiveIncreaseThreshold > 0x64u )
      v40 = 100;
    if ( !v12 )
    {
      if ( !v33 )
        v33 = 2;
      if ( !v32 )
        v32 = 2;
    }
    v13 = v14[10];
    v31 = *(_DWORD *)(a1 + 3240);
    if ( PpmPerfCalculateActualUtilization )
    {
      v16 = *(_DWORD *)(a1 + 3228);
      if ( !v16 )
        __brkdiv0();
      v1 = v31 / v16;
      if ( PpmPerfCalculateActualUtilization == 2 )
        v13 = v30[11];
    }
    else
    {
      if ( !v13 )
        __brkdiv0();
      v1 = v31 / v13;
    }
    v17 = v13;
    if ( v1 <= v34 )
    {
      if ( v1 < v39 && v13 > 1 )
      {
        v41 = 3;
        if ( !v32 )
        {
          if ( !v35 )
            __brkdiv0();
          v13 = v31 / v35;
          v18 = v28 | 0x100;
          v28 |= 0x100u;
LABEL_26:
          if ( PpmCheckCurrentPipelineId == 5 )
          {
LABEL_30:
            if ( v5 )
            {
              if ( v5[186] )
              {
                if ( v13 <= v5[186] )
                  v13 = v5[186];
                v5[186] = 0;
                v18 |= 0x10000u;
                v28 = v18;
                if ( (PoDebug & 0x40000) != 0 )
                {
                  DbgPrint("PPM: Class0 Floor Processor %d set to %d%%\n", *(_DWORD *)(a1 + 20), v13);
                  v18 = v28;
                }
              }
              if ( v5[187] )
              {
                if ( v13 <= v5[187] )
                  v13 = v5[187];
                v5[187] = 0;
                v28 = v18 | 0x20000;
                if ( (PoDebug & 0x40000) != 0 )
                  DbgPrint("PPM: Class1 MinPerf Processor %d set to %d%%\n", *(_DWORD *)(a1 + 20), v13);
              }
            }
            v21 = v28;
            goto LABEL_34;
          }
          v19 = *(_DWORD *)(v3 + 176);
          v20 = v13 >= v17;
          if ( v13 > v17 )
          {
            if ( v19 < v36 )
            {
LABEL_46:
              v18 |= 0x800u;
              v28 = v18;
              v13 = v17;
              goto LABEL_30;
            }
            v20 = v13 >= v17;
          }
          if ( v20 || v19 >= v38 )
            goto LABEL_30;
          goto LABEL_46;
        }
        v18 = v28;
        if ( v32 == 1 )
        {
          v18 = v28 | 0x200;
          v28 |= 0x200u;
          if ( v13 > PpmPerfSingleStepSize )
          {
            v13 -= PpmPerfSingleStepSize;
            goto LABEL_26;
          }
        }
        else if ( v32 != 2 )
        {
          goto LABEL_26;
        }
        v18 |= 0x400u;
        v28 = v18;
        v13 = 1;
        goto LABEL_26;
      }
LABEL_25:
      v18 = v28;
      goto LABEL_26;
    }
    if ( v13 >= v29 )
      goto LABEL_25;
    if ( v33 == 3 )
    {
      if ( v1 < v40 )
        v24 = v35;
      else
        v24 = v39;
      if ( !v24 )
        __brkdiv0();
      v25 = v31 / v24;
      v26 = v28 | 0x80;
    }
    else
    {
      if ( v33 )
      {
        if ( v33 != 1 )
        {
          if ( v33 == 2 )
          {
            v28 |= 0x40u;
            goto LABEL_58;
          }
LABEL_57:
          if ( v13 < v29 )
            goto LABEL_25;
LABEL_58:
          v13 = v29;
          goto LABEL_25;
        }
        v13 += PpmPerfSingleStepSize;
        v26 = v28 | 0x20;
LABEL_56:
        v28 = v26;
        goto LABEL_57;
      }
      if ( !v35 )
        __brkdiv0();
      v25 = v31 / v35;
      v26 = v28 | 0x10;
    }
    v13 = v25;
    goto LABEL_56;
  }
  v21 = v8 | 1;
  if ( v10 == 1 )
    v13 = 1;
  if ( (PoDebug & 0x40000) != 0 )
    DbgPrint("PPM: Parked Processor %d set to %d%%\n", *(_DWORD *)(a1 + 20), v13);
LABEL_34:
  result = (*(int (__fastcall **)(unsigned int, unsigned int, _DWORD, unsigned int, int, char *, char *))(v3 + 68))(
             v37,
             v13,
             *(_DWORD *)(v3 + 92),
             v29,
             v41,
             v42,
             v43);
  v34 = v21;
  v36 = result;
  v37 = v1;
  v30[10] = result;
  v38 = v13;
  if ( PpmEtwRegistered )
  {
    result = PpmEtwHandle;
    if ( PpmEtwHandle )
    {
      v22 = *(_DWORD *)(PpmEtwHandle + 16);
      if ( *(_DWORD *)(v22 + 56)
        && (*(unsigned __int8 *)(v22 + 60) >= 4u || !*(_BYTE *)(v22 + 60))
        && (*(_DWORD *)(v22 + 72) & 0x20) != 0
        && *(_QWORD *)(v22 + 80) == (*(_DWORD *)(v22 + 80) & 0x20)
        || *(_BYTE *)(PpmEtwHandle + 52)
        && (v27 = *(_DWORD *)(PpmEtwHandle + 20), *(_DWORD *)(v27 + 56))
        && (*(unsigned __int8 *)(v27 + 60) >= 4u || !*(_BYTE *)(v27 + 60))
        && (*(_DWORD *)(v27 + 72) & 0x20) != 0
        && *(_QWORD *)(v27 + 80) == (*(_DWORD *)(v27 + 80) & 0x20) )
      {
        LOWORD(v28) = *(unsigned __int8 *)(a1 + 1052);
        v44 = &v28;
        v45 = 0;
        v46 = 2;
        v47 = 0;
        v48 = a1 + 1053;
        v49 = 0;
        v50 = 1;
        v51 = 0;
        v52 = (int *)&v37;
        v53 = 0;
        v54 = 4;
        v55 = 0;
        v56 = (int *)&v38;
        v57 = 0;
        v58 = 4;
        v59 = 0;
        v60 = (int *)&v36;
        v61 = 0;
        v62 = 4;
        v63 = 0;
        v64 = (int *)&v34;
        v65 = 0;
        v66 = 4;
        v67 = 0;
        result = EtwWrite(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_PERF_SELECT_PROCESSOR_STATE, 0);
      }
    }
  }
  return result;
}
