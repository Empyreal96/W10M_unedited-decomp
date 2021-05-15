// PerfLogExecutiveResourceRelease 
 
_DWORD *__fastcall PerfLogExecutiveResourceRelease(int a1, int a2, int a3, unsigned int a4)
{
  _DWORD *result; // r0
  unsigned int v8; // r1
  unsigned int v9; // r4
  _DWORD *v10; // r6
  int v11; // r8
  int v12; // r9
  int *v13; // r4
  unsigned __int64 v14; // kr00_8
  __int64 v15; // r8
  unsigned int v16; // r3
  unsigned int v17; // r1
  int v18; // r3
  unsigned int v20; // [sp+Ch] [bp-6Ch]
  _DWORD *v21; // [sp+10h] [bp-68h]
  int v22[2]; // [sp+18h] [bp-60h] BYREF
  __int64 v23; // [sp+20h] [bp-58h]
  int v24; // [sp+28h] [bp-50h]
  int v25; // [sp+2Ch] [bp-4Ch]
  int v26; // [sp+30h] [bp-48h]
  int v27; // [sp+34h] [bp-44h]
  int v28; // [sp+38h] [bp-40h]
  int v29; // [sp+3Ch] [bp-3Ch]
  unsigned int v30; // [sp+40h] [bp-38h]
  int v31[12]; // [sp+48h] [bp-30h] BYREF

  result = (_DWORD *)ReadTimeStampCounter();
  v20 = v8;
  v21 = result;
  v9 = (unsigned int)KeGetPcr();
  v10 = (_DWORD *)((v9 & 0xFFFFF000) + 1408);
  v11 = *(unsigned __int8 *)((v9 & 0xFFFFF000) + 0x99C);
  v12 = *(unsigned __int8 *)((v9 & 0xFFFFF000) + 0x99D);
  ++*(_DWORD *)((v9 & 0xFFFFF000) + 0x14B0);
  if ( !*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x404) )
    return result;
  result = EtwpGetTrackingLockSlotForThread(a2, a1 & 0xFFFF0000);
  v13 = result;
  if ( !result )
    return result;
  if ( !result[7] )
  {
LABEL_28:
    v13[6] = 0;
    return result;
  }
  ++v10[973];
  if ( result[8] < (unsigned int)(a3 + 1) )
    result[8] = a3 + 1;
  if ( a1 == 65570 || a1 == 65602 )
  {
    v14 = *((_QWORD *)result + 1);
    if ( v14 > 2 && *((unsigned __int16 *)result + 10) == v11 && *((unsigned __int8 *)result + 22) == v12 )
      v15 = __PAIR64__(v20, (unsigned int)v21) - v14;
    else
      v15 = 0i64;
    if ( *(_QWORD *)result > 1ui64 )
    {
      if ( !EtwpExecutiveResourceContentionSampleRate )
        __brkdiv0();
      if ( !((v10[940] + v10[939]) % (unsigned int)EtwpExecutiveResourceContentionSampleRate) )
        goto LABEL_27;
    }
    v16 = result[10];
    if ( a4 > v16 )
    {
      if ( !EtwpExecutiveResourceContentionSampleRate )
        __brkdiv0();
      if ( !((a4 - v16) % EtwpExecutiveResourceContentionSampleRate) )
        goto LABEL_27;
    }
    v17 = v10[940] + v10[939];
    if ( !EtwpExecutiveResourceReleaseSampleRate )
      __brkdiv0();
    result = (_DWORD *)(v17 / EtwpExecutiveResourceReleaseSampleRate);
    if ( !(v17 % EtwpExecutiveResourceReleaseSampleRate) )
    {
LABEL_27:
      v28 = a2;
      v29 = a1;
      v22[0] = v13[2];
      v22[1] = v13[3];
      v18 = v13[8];
      v23 = v15;
      v26 = v18;
      v24 = *v13;
      v25 = v13[1];
      v30 = a4 - v13[10];
      v27 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x370);
      v31[0] = (int)v22;
      v31[1] = 0;
      v31[2] = 48;
      v31[3] = 0;
      result = EtwTraceKernelEvent(v31, 1, 0x20020000u, 1323, 22026242);
    }
    goto LABEL_28;
  }
  if ( a1 == 65586 || a1 == 65618 )
    result[7] = 2;
  return result;
}
