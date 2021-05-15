// PpmCheckComputeHeteroResponse 
 
int PpmCheckComputeHeteroResponse()
{
  int v0; // r10
  unsigned int v1; // r1
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r4
  unsigned int v5; // r5
  unsigned int v6; // r0
  unsigned int v7; // r1
  unsigned int v8; // r7
  unsigned int v9; // lr
  unsigned int v10; // r8
  unsigned int v11; // r1
  int v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // r0
  unsigned int v15; // r9
  int v16; // lr
  unsigned int v17; // r7
  unsigned int v18; // r10
  unsigned int v19; // r6
  unsigned __int64 v20; // kr10_8
  unsigned __int64 v21; // kr18_8
  unsigned int v22; // r9
  unsigned int v23; // r5
  int *v24; // r4
  _DWORD *v25; // r8
  int v26; // t1
  int v27; // r2
  _DWORD *v28; // r9
  _QWORD *v29; // r8
  int v30; // r2
  int v31; // t1
  int v32; // t1
  unsigned __int8 v33; // r3
  unsigned int v34; // r1
  char v35; // r2
  int v36; // r3
  int v38; // [sp+10h] [bp-1D0h]
  int v39; // [sp+14h] [bp-1CCh]
  int *v40; // [sp+18h] [bp-1C8h]
  int v41; // [sp+1Ch] [bp-1C4h]
  int v42; // [sp+24h] [bp-1BCh]
  unsigned int v43; // [sp+28h] [bp-1B8h]
  unsigned int v44; // [sp+30h] [bp-1B0h]
  int v45; // [sp+38h] [bp-1A8h]
  _DWORD v46[32]; // [sp+40h] [bp-1A0h] BYREF
  _QWORD v47[36]; // [sp+C0h] [bp-120h] BYREF

  v40 = &PpmCurrentProfile[44 * dword_61EC0C + 8];
  if ( PpmHeteroPolicy != 4 )
  {
LABEL_44:
    PpmParkCalculateUnparkCount();
    return 1;
  }
  v0 = 0;
  v1 = 0;
  v2 = PpmParkNumNodes;
  v41 = 0;
  v43 = 0;
  if ( PpmParkNumNodes )
  {
    v3 = 0;
    v42 = 0;
    while ( 1 )
    {
      v4 = v3 + PpmParkNodes;
      v45 = v3 + PpmParkNodes;
      if ( *(_BYTE *)(v3 + PpmParkNodes + 65) )
        break;
      v0 = 1;
      v41 = 1;
LABEL_42:
      ++v1;
      v3 += 88;
      v42 = v3;
      v43 = v1;
      if ( v1 >= v2 )
      {
        if ( v0 )
          goto LABEL_44;
        return 1;
      }
    }
    v5 = 0;
    v6 = *(_DWORD *)(v4 + 8);
    v7 = 0;
    v8 = *(unsigned __int8 *)(v4 + 75);
    v9 = KeNumberProcessors_0;
    v10 = 0;
    v44 = v8;
    while ( v6 )
    {
      v11 = __clz(__rbit(v6));
      v6 &= ~(1 << v11);
      if ( v11 >= v9 )
        v12 = 0;
      else
        v12 = (int)*(&KiProcessorBlock + v11);
      v13 = (unsigned int)(*(_DWORD *)(v12 + 3240) * *(_DWORD *)(v12 + 3236)) >> 16;
      v10 = (__PAIR64__(v10, v5) + v13) >> 32;
      v5 += v13;
      v46[v11] = v13;
      v7 = v11 + 1;
    }
    qsort((unsigned int)v46, v7, 4u, (int (__fastcall *)(unsigned int, _BYTE *))PpmUtilityComparer);
    v14 = *(unsigned __int8 *)(v4 + 6);
    v38 = 0;
    v39 = 0;
    v15 = 0;
    if ( *(_BYTE *)(v4 + 6) )
    {
      v16 = *(_DWORD *)(v4 + 40);
      v17 = 0;
      v18 = 0;
      v19 = 0;
      do
      {
        v20 = __PAIR64__(v17, v15) + *(_QWORD *)(v16 + 8 * v14) * __PAIR64__(v10, v5);
        v17 = HIDWORD(v20);
        v15 = v20;
        v47[v14 - 1] = v20;
        v16 = *(_DWORD *)(v4 + 40);
        v21 = __PAIR64__(v19, v18) + *(_QWORD *)(v16 + 8 * v14) * v14;
        v19 = HIDWORD(v21);
        v18 = v21;
        --v14;
      }
      while ( v14 );
      v8 = v44;
      v38 = HIDWORD(v21);
      v39 = v21;
      v0 = v41;
    }
    v22 = *(unsigned __int8 *)(v4 + 65);
    v23 = v8;
    if ( v8 >= v22 )
      goto LABEL_22;
    v24 = &v46[v8];
    v25 = &v47[v8];
    do
    {
      v26 = *v24++;
      if ( !PpmHeteroUtilityGreaterThanOrEqualThreshold(
              v39,
              v38,
              v26,
              0,
              *v25,
              v25[1],
              *((unsigned __int8 *)v40 + v23 + 136)) )
        break;
      ++v23;
      v25 += 2;
    }
    while ( v23 < v22 );
    v8 = v44;
    v4 = v45;
    v0 = v41;
    if ( v23 <= v44 )
    {
LABEL_22:
      if ( v23 )
      {
        v28 = &v46[v23];
        v29 = &v47[v23];
        while ( 1 )
        {
          --v23;
          v31 = *--v28;
          v30 = v31;
          v32 = *((_DWORD *)v29-- - 2);
          if ( PpmHeteroUtilityGreaterThanOrEqualThreshold(
                 v39,
                 v38,
                 v30,
                 0,
                 v32,
                 *((_DWORD *)v29 + 1),
                 *((unsigned __int8 *)v40 + v23 + 104)) )
          {
            break;
          }
          if ( !v23 )
            goto LABEL_28;
        }
        ++v23;
      }
LABEL_28:
      v27 = v23 < v8;
    }
    else
    {
      v27 = 2;
    }
    if ( *(char *)(v4 + 84) == v27 )
    {
      v33 = *(_BYTE *)(v4 + 83) + 1;
      v34 = v33;
      *(_BYTE *)(v4 + 83) = v33;
    }
    else
    {
      v34 = 1;
      *(_BYTE *)(v4 + 83) = 1;
      *(_BYTE *)(v4 + 84) = v27;
    }
    if ( PpmCheckCurrentPipelineId != 5 )
    {
      if ( v27 == 2 )
      {
        if ( v34 < *((unsigned __int8 *)v40 + 103) )
        {
LABEL_39:
          v35 = *(_BYTE *)(v4 + 82) | 6;
          v36 = *(unsigned __int8 *)(v4 + 75);
          *(_BYTE *)(v4 + 82) = v35;
          if ( !v36 )
          {
            v0 = 1;
            *(_BYTE *)(v4 + 82) = v35 & 0xFD;
            v41 = 1;
          }
          PpmEventTraceHeteroResponse(v4, v46, v47);
          v3 = v42;
          v1 = v43;
          v2 = PpmParkNumNodes;
          goto LABEL_42;
        }
      }
      else if ( v27 != 1 || v34 < *((unsigned __int8 *)v40 + 102) )
      {
        goto LABEL_39;
      }
    }
    *(_BYTE *)(v4 + 75) = v23;
    goto LABEL_39;
  }
  return 1;
}
