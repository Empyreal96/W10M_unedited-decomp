// PopPepRegisterDevice 
 
int __fastcall PopPepRegisterDevice(int a1, int a2, _DWORD *a3, int a4, int *a5)
{
  unsigned int v6; // r8
  unsigned int v7; // r5
  unsigned int v8; // r7
  _DWORD *v9; // r6
  int v10; // r4
  unsigned int v11; // r6
  int v12; // r3
  unsigned int v13; // r5
  int v14; // r0
  int v15; // r4
  _DWORD *v16; // r10
  unsigned int v17; // r7
  char *v18; // r0
  int v19; // r2
  int v20; // r1
  int v21; // r2
  unsigned int v22; // r3
  int v23; // lr
  _DWORD *v24; // r9
  int v25; // r5
  _DWORD *v26; // r6
  char *v27; // r0
  int v28; // r1
  int v29; // r2
  int v30; // r3
  unsigned int v31; // r3
  unsigned int v32; // lr
  int v33; // r0
  char *v34; // r1
  _DWORD *v36; // r2
  int v37; // r2
  int v38; // r0
  __int64 v39; // kr08_8
  _DWORD *v40; // [sp+8h] [bp-38h]
  unsigned int v41; // [sp+8h] [bp-38h]
  int v42; // [sp+Ch] [bp-34h]
  int v43; // [sp+10h] [bp-30h]
  unsigned int v44; // [sp+18h] [bp-28h]

  v40 = a3;
  *a5 = 0;
  v6 = a3[2];
  v43 = 0;
  if ( v6 )
  {
    v7 = 0;
    v8 = 0;
    v9 = a3;
    while ( 1 )
    {
      v10 = *(_DWORD *)(v9[3] + 28);
      if ( !v10 || v10 < 0 || v10 + v7 < v7 )
        break;
      ++v8;
      ++v9;
      v7 += v10;
      if ( v8 >= v6 )
      {
        v11 = 0;
        v12 = 168 * v6 + 128;
        if ( v7 )
        {
          v11 = (168 * v6 + 135) & 0xFFFFFFF8;
          v12 = v11 + 24 * v7;
        }
        v13 = (v12 + 3) & 0xFFFFFFFC;
        v14 = ExAllocatePoolWithTag(512, v13 + 60 * (v6 + 1), 1416652112);
        v15 = v14;
        if ( !v14 )
          return v43;
        DbgPrintEx(146, 3, (int)"PopPep: register device (0x%p, %wZ)\n", v14);
        memset((_BYTE *)v15, 0, v13 + 60 * (v6 + 1));
        *(_DWORD *)(v15 + 24) = a2;
        v16 = v40;
        *(_DWORD *)(v15 + 16) = *v40;
        v17 = v15 + v13;
        *(_DWORD *)(v15 + 20) = v40[1];
        KeInitializeEvent(v15 + 28, 0, 0);
        v18 = ActivityAttributes;
        *(_BYTE *)(v15 + 88) = 1;
        *(_DWORD *)(v15 + 120) = v6;
        *(_DWORD *)(v15 + 92) = v6;
        v19 = 0;
        v20 = v15;
        do
        {
          if ( (unsigned int)v19 <= 5 && *v18 == 1 )
          {
            *(_DWORD *)(v20 + 48) = v17;
            v17 += 20;
          }
          ++v19;
          v18 += 124;
          v20 += 4;
        }
        while ( v19 < 6 );
        v21 = *(_DWORD *)(v15 + 12);
        *(_DWORD *)(v15 + 8) |= 1u;
        *(_DWORD *)(v15 + 12) = v21;
        v22 = 0;
        v41 = 0;
        v23 = -128;
        v24 = (_DWORD *)(v15 + v11);
        v42 = -128;
        v44 = v13 + 60 * (v6 + 1) - 24;
        v25 = v15 + 128;
        while ( 1 )
        {
          v26 = (_DWORD *)v16[3];
          *(_DWORD *)(v25 + 8) = v22;
          v27 = ActivityAttributes;
          *(_DWORD *)(v25 + 4) = 3;
          v28 = 0;
          v29 = v25;
          do
          {
            if ( (unsigned int)v28 <= 5 && *v27 == 1 )
            {
              *(_DWORD *)(v29 + 48) = *(_DWORD *)(v23 + v29 + 48);
            }
            else
            {
              *(_DWORD *)(v29 + 48) = v17;
              v17 += 20;
            }
            ++v28;
            v27 += 124;
            v29 += 4;
          }
          while ( v28 < 6 );
          KeInitializeEvent(v25 + 32, 0, 0);
          *(_DWORD *)(v25 + 16) = v26[4];
          *(_DWORD *)(v25 + 20) = v26[5];
          v30 = v26[7];
          *(_DWORD *)(v25 + 156) = v30;
          v31 = v30 - 1;
          if ( v31 >= v26[6] )
            v31 = v26[6];
          v26[6] = v31;
          *(_DWORD *)(v25 + 116) = v31;
          *(_DWORD *)(v25 + 80) = -1;
          *(_DWORD *)(v25 + 84) = -1;
          *(_DWORD *)(v25 + 88) = 0;
          *(_DWORD *)(v25 + 92) = 0;
          *(_DWORD *)(v25 + 96) = 0;
          *(_DWORD *)(v25 + 100) = 0;
          *(_DWORD *)(v25 + 160) = v24;
          **(_DWORD **)(v25 + 60) |= 4u;
          if ( v26[7] > 1u )
          {
            v39 = *(_QWORD *)(v15 + 8);
            *(_DWORD *)(v15 + 8) = v39 & 0xFFFFFFFE;
            *(_DWORD *)(v15 + 12) = HIDWORD(v39);
          }
          v32 = 0;
          if ( v26[7] )
            break;
LABEL_30:
          *(_DWORD *)(v25 + 120) = 0;
          *(_DWORD *)(v25 + 124) = PopPepComponentGetLatencyIdleState(
                                     v25,
                                     0,
                                     *(_DWORD *)(v25 + 80),
                                     *(_DWORD *)(v25 + 84));
          v38 = PopPepComponentGetResidencyIdleState(v25, *(_QWORD *)(v25 + 88));
          *(_DWORD *)(v25 + 128) = v38;
          ++v16;
          *(_DWORD *)(v25 + 132) = *(_DWORD *)(v25 + 156) - 1;
          v23 = v42 - 168;
          v42 -= 168;
          *(_DWORD *)(v25 + 136) = *(_DWORD *)(v25 + 156) - 1;
          *(_DWORD *)(v25 + 140) = *(_DWORD *)(v25 + 156) - 1;
          v25 += 168;
          v22 = v41 + 1;
          v41 = v22;
          if ( v22 >= v6 )
          {
            *a5 = v15;
            v43 = 1;
            if ( a4 == 2 )
              *(_BYTE *)(v15 + 76) = 1;
            *(_DWORD *)(v15 + 108) = 1;
            PopPepInsertDevice(v38, (int *)v15);
            return v43;
          }
        }
        v33 = 0;
        v34 = (char *)v24 - v15;
        while ( (unsigned int)v34 <= v44 )
        {
          ++v32;
          v34 += 24;
          v36 = (_DWORD *)(v33 + v26[8]);
          *v24 = *v36;
          v24[1] = v36[1];
          v37 = v33 + v26[8];
          v33 += 24;
          v24[2] = *(_DWORD *)(v37 + 8);
          v24[3] = *(_DWORD *)(v37 + 12);
          v24 += 6;
          if ( v32 >= v26[7] )
            goto LABEL_30;
        }
        return sub_81296C(v33);
      }
    }
  }
  return v43;
}
