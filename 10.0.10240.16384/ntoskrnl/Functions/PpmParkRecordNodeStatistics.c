// PpmParkRecordNodeStatistics 
 
int __fastcall PpmParkRecordNodeStatistics(int a1)
{
  int result; // r0
  int *v3; // r3
  int v4; // r7
  unsigned int v5; // r2
  int v6; // r5
  __int64 v7; // kr18_8
  unsigned __int64 v8; // r8
  int i; // r6
  __int64 v10; // r0
  int v11; // r6
  unsigned __int64 v12; // kr28_8
  unsigned int v13; // r0
  unsigned int v14; // r7
  int v15; // r1
  __int64 *v16; // r4
  __int64 v17; // t1
  __int64 v18; // r0
  unsigned __int64 v19; // kr38_8
  unsigned int v20; // r1
  unsigned int v21; // r7
  __int64 *v22; // r4
  __int64 v23; // t1
  unsigned __int64 v24; // kr48_8
  int v25; // r3
  unsigned int v26; // r2
  _DWORD *v27; // r4
  unsigned int v28; // r1
  int v29; // r7
  int v30; // r6
  __int64 v31; // kr50_8
  char v32; // [sp+8h] [bp-A8h] BYREF
  char v33; // [sp+Ch] [bp-A4h] BYREF
  int v34; // [sp+10h] [bp-A0h]
  __int16 v35; // [sp+14h] [bp-9Ch] BYREF
  int v36; // [sp+18h] [bp-98h]
  unsigned int v37; // [sp+1Ch] [bp-94h]
  unsigned int v38; // [sp+20h] [bp-90h]
  int v39; // [sp+24h] [bp-8Ch] BYREF
  int v40[34]; // [sp+28h] [bp-88h] BYREF

  result = 176;
  v36 = a1;
  v3 = &PpmCurrentProfile[44 * dword_61EC0C];
  v4 = *((unsigned __int8 *)v3 + 108);
  v38 = *((unsigned __int8 *)v3 + 106);
  v5 = 0;
  v34 = v4;
  if ( PpmParkNumNodes )
  {
    v37 = 0;
    while ( 1 )
    {
      v6 = PpmParkNodes + 88 * v5;
      v7 = *(_QWORD *)(v6 + 48);
      result = HIDWORD(v7);
      v8 = v7 - *(_QWORD *)(v6 + 56);
      if ( a1 )
        break;
      if ( v8 )
      {
        for ( i = 0; i < *(unsigned __int8 *)(v6 + 6) + 1; ++i )
          *(_QWORD *)(*(_DWORD *)(v6 + 40) + 8 * i) = *(_QWORD *)(*(_DWORD *)(v6 + 32) + 8 * i)
                                                    - *(_QWORD *)(*(_DWORD *)(v6 + 36) + 8 * i);
        LODWORD(v10) = _rt_udiv64(100i64, v8 * (unsigned int)v4);
        v11 = *(unsigned __int8 *)(v6 + 6);
        v12 = v8 - v10;
        v13 = 0;
        v14 = 0;
        v15 = v11;
        v16 = (__int64 *)(*(_DWORD *)(v6 + 40) + 8 * v11);
        do
        {
          v17 = *v16--;
          v14 = (__PAIR64__(v14, v13) + v17) >> 32;
          v13 += v17;
          if ( __PAIR64__(v14, v13) >= v12 )
            break;
          --v15;
        }
        while ( v15 >= 0 );
        *(_BYTE *)(v6 + 78) = v15;
        LODWORD(v18) = _rt_udiv64(100i64, v8 * v38);
        v19 = v8 - v18;
        v20 = 0;
        v21 = 0;
        result = v11;
        v22 = (__int64 *)(*(_DWORD *)(v6 + 40) + 8 * v11);
        do
        {
          v23 = *v22--;
          v21 = (__PAIR64__(v21, v20) + v23) >> 32;
          v20 += v23;
          if ( __PAIR64__(v21, v20) >= v19 )
            break;
          --result;
        }
        while ( result >= 0 );
        *(_BYTE *)(v6 + 76) = result;
        if ( result <= 0 )
        {
          *(_BYTE *)(v6 + 77) = 0;
        }
        else
        {
          result = _rt_udiv64(v8, 100i64 * *(_QWORD *)(*(_DWORD *)(v6 + 40) + 8 * result));
          *(_BYTE *)(v6 + 77) = result;
        }
        *(_QWORD *)(v6 + 56) += v8;
        while ( 1 )
        {
          v24 = *(_QWORD *)(*(_DWORD *)(v6 + 40) + 8 * v11);
          if ( v24 > v8 )
            break;
          v25 = *(_DWORD *)(v6 + 36);
          v26 = *(_DWORD *)(v25 + 8 * v11);
          v27 = (_DWORD *)(v25 + 8 * v11);
          v28 = v27[1];
          *v27 = v26 + v24;
          result = v26 + v24;
          v8 -= v24;
          --v11;
          v27[1] = (__PAIR64__(v28, v26) + v24) >> 32;
          if ( v11 < 0 )
            goto LABEL_19;
        }
        *(_QWORD *)(*(_DWORD *)(v6 + 36) + 8 * v11) += v8;
LABEL_19:
        v33 = *(_BYTE *)(v6 + 78);
        v29 = *(_DWORD *)(v6 + 36);
        v30 = *(unsigned __int8 *)(v6 + 6) + 1;
        v39 = v30;
        v32 = *(_BYTE *)(v6 + 76);
        v40[0] = *(_DWORD *)(v6 + 8);
        v35 = *(_WORD *)(v6 + 4);
        if ( PpmEtwRegistered )
        {
          v31 = *(_QWORD *)&PpmEtwHandle;
          result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, PPM_ETW_PARK_NODE_STATS);
          if ( result )
          {
            v40[2] = (int)&v35;
            v40[3] = 0;
            v40[4] = 2;
            v40[5] = 0;
            v40[6] = (int)v40;
            v40[7] = 0;
            v40[8] = 4;
            v40[9] = 0;
            v40[10] = (int)&v32;
            v40[11] = 0;
            v40[12] = 1;
            v40[13] = 0;
            v40[14] = (int)&v39;
            v40[15] = 0;
            v40[16] = 4;
            v40[17] = 0;
            v40[18] = v29;
            v40[19] = 0;
            v40[20] = 8 * v30;
            v40[21] = 0;
            v40[22] = (int)&v33;
            v40[23] = 0;
            v40[24] = 1;
            v40[25] = 0;
            result = EtwWrite(v31, SHIDWORD(v31), (int)PPM_ETW_PARK_NODE_STATS, 0);
          }
        }
        a1 = v36;
        v4 = v34;
      }
      v5 = (unsigned __int16)(v37 + 1);
      v37 = v5;
      if ( v5 >= PpmParkNumNodes )
        return result;
    }
    result = sub_540EA4();
  }
  return result;
}
