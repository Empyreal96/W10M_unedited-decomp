// MiReservePtes 
 
int __fastcall MiReservePtes(int *a1, unsigned int a2)
{
  unsigned int v2; // r8
  int v3; // r10
  int v4; // r0
  unsigned int v5; // r3
  unsigned int *v6; // r9
  unsigned int v7; // r7
  unsigned int *v8; // r1
  unsigned int v9; // r2
  unsigned int *v10; // r0
  unsigned int v11; // r4
  unsigned int v12; // r7
  int v13; // r2
  _BYTE *v14; // r5
  int v15; // r2
  int *v16; // r5
  int v17; // r3
  int v19; // r2
  int v20; // r5
  unsigned int v21; // r4
  unsigned int v22; // r4
  unsigned int v23; // r7
  int v24; // r2
  unsigned int v25; // r3
  unsigned int v26; // t1
  unsigned int v27; // r9
  unsigned int v28; // r8
  unsigned int v29; // r10
  unsigned int v30; // r7
  int v31; // lr
  unsigned int v32; // r5
  unsigned int *v33; // r4
  int v34; // r2
  unsigned int v35; // r7
  unsigned int v36; // r2
  int v37; // r0
  unsigned int *v38; // r2
  unsigned int v39; // r4
  unsigned int v40; // r9
  unsigned int v41; // r8
  unsigned int v42; // r7
  int v43; // r2
  int *v44; // r4
  unsigned int v45; // r3
  unsigned int v46; // r7
  unsigned int v47; // r3
  unsigned int v48; // r4
  unsigned int *v49; // r5
  unsigned int v50; // r2
  unsigned int v51; // r3
  char v52; // r1
  int v53; // r4
  unsigned int v54; // r2
  int v55; // r1
  unsigned int *v56; // lr
  unsigned int v57; // r0
  unsigned int v58; // r0
  unsigned int v59; // r1
  int v60; // r2
  unsigned int v61; // r3
  int v62; // t1
  unsigned int v63; // r7
  unsigned int v64; // r3
  int v65; // r2
  unsigned int v66; // r5
  unsigned int v67; // t1
  unsigned int v68; // r7
  int v69; // r7
  int v70; // r0
  unsigned int v71; // r3
  int v72; // r2
  int v73; // r7
  unsigned int v74; // r3
  unsigned int v75; // r1
  unsigned int *v76; // r2
  unsigned int v77; // r1
  unsigned int v78; // r2
  bool v79; // cf
  unsigned int v80; // r3
  int v81; // r2
  unsigned int v82; // r0
  int v83; // t1
  unsigned int v84; // r1
  int v85; // r0
  int v86; // r0
  int v87; // r7
  unsigned int *v88; // r2
  unsigned int v89; // r5
  unsigned int v90; // r1
  unsigned int v91; // [sp+0h] [bp-80h]
  unsigned int v92; // [sp+4h] [bp-7Ch]
  unsigned int v93; // [sp+4h] [bp-7Ch]
  int *v94; // [sp+8h] [bp-78h]
  unsigned int v95; // [sp+Ch] [bp-74h]
  int v96; // [sp+10h] [bp-70h]
  int v97; // [sp+14h] [bp-6Ch]

  v2 = a2;
  v94 = a1;
  v95 = a2;
  v3 = (int)a1;
  v96 = 0;
  v91 = a2;
  if ( (a1[3] & 4) != 0 )
  {
    a2 >>= 4;
    v91 = v2 >> 4;
    goto LABEL_47;
  }
  if ( a2 <= 0x20 && a1 == &dword_634D58 )
  {
    v4 = KfRaiseIrql(2);
    v97 = v4;
    v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v92 = v5 + 1408;
    if ( *(_DWORD *)(v5 + 5496) != -1 )
      goto LABEL_5;
    KfLowerIrql(v4);
    v40 = dword_634D80;
LABEL_72:
    if ( v40 >= dword_634D58 )
      v41 = 0;
    else
      v41 = v40;
    v42 = dword_634D58 - 1;
    while ( 1 )
    {
      if ( v42 - v41 != -1 )
      {
        v43 = *(_DWORD *)(dword_634D5C + 4 * (v41 >> 5)) | ((1 << (v41 & 0x1F)) - 1);
        v44 = (int *)(dword_634D5C + 4 * (v41 >> 5));
        if ( v43 == -1 )
        {
          while ( (unsigned int)++v44 <= dword_634D5C + 4 * (v42 >> 5) )
          {
            v43 = *v44;
            if ( *v44 != -1 )
              goto LABEL_77;
          }
        }
        else
        {
LABEL_77:
          v45 = __clz(__rbit(~v43)) + 32 * (((int)v44 - dword_634D5C) >> 2);
          if ( v45 <= v42 && v45 != -1 )
          {
            v46 = v45 & 0xFFFFFFE0;
            v47 = (v45 & 0xFFFFFFE0) >> 5;
            v48 = *(_DWORD *)(dword_634D5C + 4 * v47);
            v49 = (unsigned int *)(dword_634D5C + 4 * v47);
            if ( v48 == -1 )
              goto LABEL_217;
            while ( 1 )
            {
              do
                v50 = __ldrex(v49);
              while ( v50 == v48 && __strex(0xFFFFFFFF, v49) );
              if ( v50 == v48 )
                break;
              v48 = v50;
              if ( v50 == -1 )
                goto LABEL_217;
            }
            if ( v48 == -1 )
            {
LABEL_217:
              v40 = v46 + 32;
              goto LABEL_72;
            }
            v97 = KfRaiseIrql(2);
            v51 = (unsigned int)KeGetPcr();
            v92 = (v51 & 0xFFFFF000) + 1408;
            if ( *(_DWORD *)((v51 & 0xFFFFF000) + 0x1578) == -1 )
            {
              v52 = *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)v48);
              *(_DWORD *)((v51 & 0xFFFFF000) + 0x1578) = v48;
              *(_DWORD *)((v51 & 0xFFFFF000) + 0x157C) = v46;
              v53 = -(unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + HIBYTE(v48))
                                     + *((_BYTE *)RtlpBitsClearTotal + BYTE2(v48))
                                     + *((_BYTE *)RtlpBitsClearTotal + BYTE1(v48))
                                     + v52);
              do
                v54 = __ldrex((unsigned int *)&dword_634D88);
              while ( __strex(v54 + v53, (unsigned int *)&dword_634D88) );
              v3 = (int)v94;
              v2 = v95;
              dword_634D80 = v46 + 32;
            }
            else
            {
              __dmb(0xBu);
              do
                v90 = __ldrex(v49);
              while ( __strex(v90 & v48, v49) );
              v3 = (int)v94;
              v2 = v95;
            }
LABEL_5:
            v6 = (unsigned int *)(v92 + 4088);
            if ( !v2 )
            {
              v11 = 0;
              goto LABEL_15;
            }
            if ( v2 > 0x20 )
              goto LABEL_37;
            v7 = 32 - v2;
            v8 = (unsigned int *)(v92 + 4088);
            v9 = *v6;
            v10 = &v6[(32 - v2) >> 5];
            if ( v2 < 0x20 )
            {
              if ( v2 > 1 )
              {
                v20 = 0;
                while ( 1 )
                {
                  if ( v9 == -1 )
                  {
                    while ( 1 )
                    {
                      if ( ++v8 > v10 )
                        goto LABEL_37;
                      v9 = *v8;
                      if ( *v8 != -1 )
                      {
                        v20 = 0;
                        break;
                      }
                    }
                  }
                  v21 = __clz(__rbit(v9));
                  if ( 1 == (unsigned __int8)(v21 >> 5) )
                    v21 = 32;
                  if ( v21 + v20 >= v2 )
                    break;
                  v22 = ~v9;
                  v23 = v2;
                  while ( 1 )
                  {
                    v22 &= v22 >> (v23 >> 1);
                    if ( !v22 )
                      break;
                    v23 -= v23 >> 1;
                    if ( v23 <= 1 )
                    {
                      v24 = __clz(__rbit(v22));
                      goto LABEL_36;
                    }
                  }
                  if ( v8 == (unsigned int *)(v92 + 4088) )
                    goto LABEL_37;
                  v25 = __clz(v9);
                  if ( 1 == (unsigned __int8)(v25 >> 5) )
                    v20 = 32;
                  else
                    v20 = v25;
                  v26 = v8[1];
                  ++v8;
                  v9 = v26;
                }
                v24 = -v20;
LABEL_36:
                v11 = v24 + 32 * (v8 - v6);
                if ( v11 <= 32 - v2 )
                  goto LABEL_11;
                goto LABEL_37;
              }
              if ( v9 == -1 )
              {
                do
                {
                  if ( ++v8 > v10 )
                    goto LABEL_37;
                  v9 = *v8;
                }
                while ( *v8 == -1 );
              }
              v11 = __clz(__rbit(~v9)) + 32 * (v8 - v6);
              if ( v11 > v7 )
                goto LABEL_37;
LABEL_11:
              if ( v11 == -1 )
              {
                v16 = 0;
              }
              else
              {
                v12 = v2;
                v13 = v11 & 7;
                v14 = (_BYTE *)(v92 + 4088 + (v11 >> 3));
                if ( v13 + v2 <= 8 )
                {
                  v15 = *((unsigned __int8 *)dword_409D88 + v2) << v13;
                  goto LABEL_14;
                }
                if ( (v11 & 7) != 0 )
                {
                  v12 = v13 + v2 - 8;
                  *v14++ |= *((_BYTE *)dword_409D94 + v13);
                }
                if ( v12 > 8 )
                {
                  memset(v14, 255, v12 >> 3);
                  v14 += v12 >> 3;
                  v12 &= 7u;
                }
                if ( v12 )
                {
                  LOBYTE(v15) = *((_BYTE *)dword_409D88 + v12);
LABEL_14:
                  *v14 |= v15;
                }
LABEL_15:
                v16 = (int *)(dword_634D60 + 4 * (*(_DWORD *)(v92 + 4092) + v11));
              }
              KfLowerIrql(v97);
              if ( v16 )
                goto LABEL_17;
              a2 = v2;
              break;
            }
            while ( 1 )
            {
              if ( (v9 & 0x80000000) != 0 )
              {
                while ( ++v8 <= v10 )
                {
                  v9 = *v8;
                  if ( (*v8 & 0x80000000) == 0 )
                    goto LABEL_128;
                }
LABEL_37:
                v11 = -1;
                goto LABEL_11;
              }
LABEL_128:
              v64 = __clz(v9);
              if ( 1 == (unsigned __int8)(v64 >> 5) )
                v65 = 32;
              else
                v65 = v64;
              v11 = 32 * (v8 - v6 + 1) - v65;
              if ( v11 > v7 )
                goto LABEL_37;
              v66 = v2 - v65;
              if ( v2 == v65 )
                goto LABEL_11;
              v67 = v8[1];
              ++v8;
              v9 = v67;
              if ( v66 >= 0x20 )
              {
                if ( v9 )
                  continue;
                v66 -= 32;
                if ( !v66 )
                  goto LABEL_11;
                v9 = *++v8;
              }
              v68 = __clz(__rbit(v9));
              if ( 1 == (unsigned __int8)(v68 >> 5) )
                v68 = 32;
              if ( v68 >= v66 )
                goto LABEL_11;
              v7 = 32 - v2;
            }
          }
        }
      }
      if ( !v41 )
      {
        if ( MiEmptyPteBins((int)&dword_634D58, 0) )
          return sub_542294();
        v2 = v95;
        a2 = v91;
        break;
      }
      v73 = v40 + 1;
      if ( v40 + 1 > dword_634D58 )
        v73 = dword_634D58;
      v42 = v73 - 1;
      v41 = 0;
    }
  }
LABEL_47:
  v3 = (int)v94;
  if ( v2 >= 0x400 )
  {
    v86 = MiExpandPtes(v94, v2);
    v87 = v86;
    if ( v86 )
    {
      if ( v94 == &dword_634D58 && (dword_681258 & 2) != 0 )
        MiCheckPteReserve(v86, v2);
      v88 = (unsigned int *)(v94 + 12);
      do
        v89 = __ldrex(v88);
      while ( __strex(v89 - v91, v88) );
      return v87;
    }
    if ( v94 == &dword_634D58 )
    {
LABEL_215:
      ++**(_DWORD **)(v3 + 20);
      return 0;
    }
    a2 = v91;
  }
  v27 = v94[10];
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !*(_DWORD *)v3 )
        goto LABEL_147;
      v28 = *(_DWORD *)v3;
      if ( v27 >= *(_DWORD *)v3 )
        v29 = 0;
      else
        v29 = v27;
      v30 = v28 - 1;
      v31 = v94[1];
      if ( !a2 )
      {
        v35 = v29 & 0xFFFFFFF8;
        goto LABEL_60;
      }
LABEL_53:
      if ( v30 - v29 + 1 < a2 )
        goto LABEL_154;
      v93 = v30 - a2 + 1;
      v32 = v31 + 4 * (v93 >> 5);
      v33 = (unsigned int *)(v31 + 4 * (v29 >> 5));
      v34 = ((1 << (v29 & 0x1F)) - 1) | *v33;
      a2 = v91;
      if ( v91 <= 0x3F )
      {
        if ( v91 < 0x20 )
        {
          if ( v91 > 1 )
          {
            v55 = 0;
            v56 = (unsigned int *)(v31 + 4 * (v30 >> 5));
            while ( 1 )
            {
              if ( v34 == -1 )
              {
                while ( (unsigned int)++v33 <= v32 )
                {
                  v34 = *v33;
                  if ( *v33 != -1 )
                  {
                    v55 = 0;
                    goto LABEL_96;
                  }
                }
LABEL_118:
                a2 = v91;
                v35 = -1;
                goto LABEL_119;
              }
LABEL_96:
              v57 = __clz(__rbit(v34));
              if ( 1 == (unsigned __int8)(v57 >> 5) )
                v57 = 32;
              if ( v57 + v55 >= v91 )
                break;
              v58 = ~v34;
              v59 = v91;
              while ( 1 )
              {
                v58 &= v58 >> (v59 >> 1);
                if ( !v58 )
                  break;
                v59 -= v59 >> 1;
                if ( v59 <= 1 )
                {
                  v60 = __clz(__rbit(v58));
                  goto LABEL_103;
                }
              }
              if ( v33 == v56 )
                goto LABEL_118;
              v61 = __clz(v34);
              if ( 1 == (unsigned __int8)(v61 >> 5) )
                v55 = 32;
              else
                v55 = v61;
              v62 = v33[1];
              ++v33;
              v34 = v62;
            }
            v60 = -v55;
LABEL_103:
            a2 = v91;
            v35 = v60 + 32 * (((int)v33 - v94[1]) >> 2);
            if ( v35 > v93 )
            {
              v35 = -1;
              goto LABEL_119;
            }
          }
          else
          {
            if ( v34 == -1 )
            {
              do
              {
                if ( (unsigned int)++v33 > v32 )
                  goto LABEL_154;
                v34 = *v33;
              }
              while ( *v33 == -1 );
            }
            v35 = __clz(__rbit(~v34)) + 32 * (((int)v33 - v31) >> 2);
            if ( v35 > v93 )
            {
              v35 = -1;
              goto LABEL_119;
            }
          }
          goto LABEL_59;
        }
        while ( 1 )
        {
          if ( v34 < 0 )
          {
            while ( (unsigned int)++v33 <= v32 )
            {
              v34 = *v33;
              if ( (*v33 & 0x80000000) == 0 )
                goto LABEL_182;
            }
LABEL_154:
            v35 = -1;
LABEL_119:
            if ( !v29 )
              goto LABEL_60;
            v63 = v27 + a2;
            if ( v27 + a2 > v28 )
              v63 = v28;
            v31 = v94[1];
            v30 = v63 - 1;
            v29 = 0;
            goto LABEL_53;
          }
LABEL_182:
          v80 = __clz(v34);
          if ( 1 == (unsigned __int8)(v80 >> 5) )
            v81 = 32;
          else
            v81 = v80;
          v35 = 32 * ((((int)v33 - v31) >> 2) + 1) - v81;
          if ( v35 > v93 )
            goto LABEL_154;
          v82 = a2 - v81;
          if ( a2 == v81 )
            goto LABEL_59;
          v83 = v33[1];
          ++v33;
          v34 = v83;
          if ( v82 >= 0x20 )
          {
            if ( v34 )
              continue;
            v82 -= 32;
            if ( !v82 )
              goto LABEL_59;
            v34 = *++v33;
          }
          v84 = __clz(__rbit(v34));
          if ( 1 == (unsigned __int8)(v84 >> 5) )
            v84 = 32;
          v79 = v84 >= v82;
          a2 = v91;
          if ( v79 )
            goto LABEL_59;
        }
      }
      if ( (v93 & 0x1F) != 0 )
        v32 += 4;
      if ( !v34 )
      {
        v72 = 0;
        goto LABEL_172;
      }
      if ( !*++v33 )
      {
        v71 = __clz(v34);
        if ( 1 == (unsigned __int8)(v71 >> 5) )
          v72 = 32;
        else
          v72 = v71;
        goto LABEL_172;
      }
      while ( 1 )
      {
        while ( 1 )
        {
          do
          {
            if ( (unsigned int)v33 > v32 )
              goto LABEL_154;
            ++v33;
          }
          while ( *v33 );
          v74 = __clz(*(v33 - 1));
          v72 = 1 == (unsigned __int8)(v74 >> 5) ? 32 : v74;
LABEL_172:
          v35 = 32 * (((int)v33 - v31) >> 2) - v72;
          if ( v35 > v93 )
            goto LABEL_154;
          v75 = a2 - v72;
          v76 = &v33[v75 >> 5];
          if ( ++v33 == v76 )
            break;
          while ( !*v33 )
          {
            if ( ++v33 == v76 )
              goto LABEL_176;
          }
          a2 = v91;
        }
LABEL_176:
        v77 = v75 & 0x1F;
        if ( !v77 )
          break;
        v78 = __clz(__rbit(*v33));
        if ( 1 == (unsigned __int8)(v78 >> 5) )
          v78 = 32;
        v79 = v78 >= v77;
        a2 = v91;
        if ( v79 )
          goto LABEL_59;
      }
      a2 = v91;
LABEL_59:
      if ( v35 == -1 )
        goto LABEL_119;
LABEL_60:
      v3 = (int)v94;
      if ( v35 != -1 )
        break;
      v2 = v95;
LABEL_147:
      v69 = v96;
      if ( (*(_DWORD *)(v3 + 12) & 1) != 0 )
      {
        if ( (v96 & 1) == 0 )
        {
          v69 = v96 | 1;
          v96 |= 1u;
          v70 = MiEmptyPteBins(v3, 0);
          a2 = v91;
          if ( v70 == 1 )
            continue;
        }
        if ( (v69 & 2) == 0 )
        {
          v69 |= 2u;
          v96 = v69;
          if ( MiPteBinsNeedTrimming(v3) )
          {
            v85 = MiEmptyPteBins(v3, 1);
            a2 = v91;
            if ( v85 == 1 )
              continue;
          }
        }
      }
      v16 = (int *)MiExpandPtes((int *)v3, v2);
      if ( v16 )
      {
        v36 = v91;
        goto LABEL_65;
      }
      if ( (*(_DWORD *)(v3 + 12) & 1) == 0 || (v69 & 4) != 0 )
        goto LABEL_215;
      v96 = v69 | 4;
      MiEmptyPteBins(v3, 1);
      a2 = v91;
    }
    if ( RtlInterlockedSetClearRun(v94, v35, a2) )
      break;
    v2 = v95;
    a2 = v91;
  }
  v36 = v91;
  v94[10] = v35 + v91;
  if ( (v94[3] & 4) != 0 )
    v35 *= 16;
  v2 = v95;
  v16 = (int *)(v94[2] + 4 * v35);
LABEL_65:
  v37 = -v36;
  v38 = (unsigned int *)(v3 + 48);
  do
    v39 = __ldrex(v38);
  while ( __strex(v39 + v37, v38) );
LABEL_17:
  if ( (*(_DWORD *)(v3 + 12) & 2) == 0 )
  {
    v19 = 2;
    goto LABEL_26;
  }
  if ( (int *)v3 == &dword_634D58 && (dword_681258 & 2) != 0 )
    MiCheckPteReserve(v16, v2);
  v17 = *v16;
  if ( v2 == 1 )
  {
    if ( (v17 & 0xFFFFF000) == 0 )
      return (int)v16;
LABEL_25:
    v19 = 0;
LABEL_26:
    MiFlushTbAsNeeded(v16, v2, v19);
  }
  else if ( v2 != 2 || (v17 & 0xFFFFF000) != 0 || (v16[1] & 0xFFFFF000) != 0 )
  {
    goto LABEL_25;
  }
  return (int)v16;
}
