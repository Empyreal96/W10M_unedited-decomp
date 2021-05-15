// MiFindContiguousPages 
 
int __fastcall MiFindContiguousPages(__int16 *a1, int a2, int a3, int a4, unsigned int a5, int a6, unsigned int a7, int a8, int a9, unsigned int *a10)
{
  unsigned int v11; // r8
  unsigned int v12; // r7
  unsigned int v13; // r5
  unsigned int v14; // r4
  int result; // r0
  __int16 *v16; // r0
  int v17; // r6
  int *v18; // r1
  int v19; // r3
  int v20; // r4
  unsigned __int8 *v21; // r2
  int v22; // r3
  int v23; // r1
  unsigned __int8 *v24; // r4
  int v25; // r2
  unsigned int v26; // r6
  unsigned int v27; // r4
  unsigned int v28; // r7
  int v29; // r8
  unsigned int v30; // r5
  unsigned int v31; // r3
  int v32; // r1
  int v33; // r4
  unsigned int v34; // r5
  bool v35; // zf
  unsigned int v36; // r0
  int v37; // r5
  unsigned int v38; // r5
  unsigned int *v39; // r6
  int v40; // r2
  int v41; // r2
  unsigned int v42; // r0
  int v43; // lr
  unsigned __int8 *v44; // r3
  unsigned int v45; // r1
  unsigned __int8 *v46; // r1
  int v47; // r3
  unsigned int v48; // r2
  unsigned int *v49; // r2
  unsigned int v50; // r0
  unsigned int *v51; // r2
  unsigned int v52; // r0
  unsigned __int16 *v53; // r3
  int v54; // r4
  int v55; // r2
  unsigned int v56; // r0
  unsigned int v57; // r3
  unsigned int v58; // r0
  unsigned int v59; // r0
  unsigned int *v60; // r2
  unsigned int v61; // r4
  unsigned int v63; // [sp+14h] [bp-ACh]
  char v64[4]; // [sp+18h] [bp-A8h] BYREF
  int *v65; // [sp+1Ch] [bp-A4h]
  unsigned __int8 *v66; // [sp+20h] [bp-A0h]
  int v67; // [sp+24h] [bp-9Ch]
  int v68; // [sp+28h] [bp-98h]
  unsigned __int8 *v69; // [sp+2Ch] [bp-94h]
  int v70; // [sp+30h] [bp-90h]
  unsigned int v71; // [sp+34h] [bp-8Ch] BYREF
  int v72; // [sp+38h] [bp-88h]
  int v73; // [sp+3Ch] [bp-84h]
  int v74; // [sp+40h] [bp-80h]
  int v75; // [sp+44h] [bp-7Ch] BYREF
  int v76; // [sp+48h] [bp-78h]
  unsigned int *v77; // [sp+4Ch] [bp-74h]
  int v78; // [sp+50h] [bp-70h]
  int v79; // [sp+58h] [bp-68h] BYREF
  int v80; // [sp+5Ch] [bp-64h]
  int v81; // [sp+60h] [bp-60h]
  int v82; // [sp+64h] [bp-5Ch]
  int v83; // [sp+68h] [bp-58h]
  int v84; // [sp+6Ch] [bp-54h]
  int v85; // [sp+70h] [bp-50h]
  int v86; // [sp+74h] [bp-4Ch]
  unsigned int v87; // [sp+78h] [bp-48h]
  int v88; // [sp+80h] [bp-40h] BYREF
  int v89; // [sp+84h] [bp-3Ch]
  unsigned __int64 v90; // [sp+88h] [bp-38h]
  int v91[12]; // [sp+90h] [bp-30h] BYREF

  v11 = a7;
  v63 = a7;
  v77 = a10;
  v12 = a3;
  v13 = a2;
  v80 = 0;
  v81 = 0;
  v82 = 0;
  v74 = a3;
  v72 = a2;
  v79 = 0;
  v14 = KeGetCurrentIrql();
  if ( v14 > 2 )
    return sub_513764();
  v16 = a1;
  v85 = (unsigned __int16)*a1;
  if ( v14 == 2 )
    v17 = a9 | 8;
  else
    v17 = a9;
  v84 = v17 & 0x20000000;
  v67 = v17;
  if ( (v17 & 0x20000000) == 0 )
  {
    if ( !MiChargeCommit(a1, a5, 1) )
      return -1073741523;
    v35 = MiChargeResident(a1, a5, 0) == 0;
    v16 = a1;
    if ( v35 )
    {
      MiReturnCommit(a1, a5);
      return -1073741670;
    }
    if ( a1 == MiSystemPartition )
    {
      do
        v36 = __ldrex(&dword_634A2C[37]);
      while ( __strex(v36 + a5, &dword_634A2C[37]) );
      v16 = a1;
    }
  }
  if ( (v17 & 0x40) != 0 )
  {
    if ( a6 == 1 )
    {
      if ( MiFindLargeNodePages(v16, a7, v17, &v71) >= 0 )
      {
        result = 0;
        *v77 = v71;
        return result;
      }
      v37 = -1073741801;
    }
    else
    {
      v37 = -1073741811;
    }
  }
  else
  {
    if ( (int)a5 > *((_DWORD *)v16 + 928) - 128 )
    {
      v37 = -1073741670;
    }
    else
    {
      v86 = v17 & 0x10000000;
      if ( (v17 & 0x10000000) != 0 || (MiCreatePteCopyList(a5, 64, &v79), v80) )
      {
        v68 = 0;
        if ( (v17 & 0x8000000) != 0 && (v17 & 0x2000008) == 0 && InitializationPhase && v14 != 2 )
          v68 = 1;
        if ( a7 >= (unsigned __int16)KeNumberNodes )
        {
          v11 = a7 | 0x80000000;
          v63 = a7 | 0x80000000;
        }
        v71 = 0;
        v18 = (int *)MiReferencePageRuns();
        v19 = *v18;
        v65 = v18;
        v73 = -1;
        v20 = (int)&v18[2 * v19 + 2];
        v78 = 0;
        v76 = v20;
LABEL_14:
        while ( 2 )
        {
          v21 = 0;
          v66 = 0;
          while ( 1 )
          {
            v22 = *v18;
            if ( *v18 )
            {
              v23 = (int)&v18[2 * v22];
              v24 = (unsigned __int8 *)(v20 + 2 * v22);
              do
              {
                v24 -= 2;
                v23 -= 8;
                v25 = v24[1];
                v83 = v22 - 1;
                v69 = v24;
                v70 = v23;
                if ( ((v11 & 0x80000000) != 0 || *v24 == v11) && (!v66 || v25 == *v66) )
                {
                  v26 = *(_DWORD *)(v23 + 8);
                  v27 = *(_DWORD *)(v23 + 12) + v26;
LABEL_20:
                  if ( v27 - 1 > v12 )
                    v27 = v12 + 1;
                  if ( v26 < v13 )
                    v26 = v13;
                  if ( v26 < v27 )
                  {
                    while ( 1 )
                    {
                      if ( a5 > v27 - v26 )
                        goto LABEL_61;
                      if ( !a4 )
                        break;
                      v32 = ~(a4 - 1);
                      if ( (((v27 - 1) ^ (v27 - a5)) & v32) == 0 )
                        break;
                      if ( (v32 & v27) == v27 )
                        v27 -= a4;
                      else
                        v27 &= v32;
                      if ( v26 >= v27 )
                        goto LABEL_61;
                    }
                    v71 = 1;
                    v75 = 0;
                    v28 = v27 - a5;
                    v29 = MmPfnDatabase + 24 * (v27 - a5);
                    v87 = v27 - a5;
                    v30 = MiPfnsWorthTrying(v85, v29, a5, v67, &v75, v64);
                    if ( !v30 )
                    {
                      if ( v75 == 1 )
                        MiEmptyKernelStackCache();
                      v30 = MiClaimPhysicalRun(a1, v27 - a5, a5, &v79, v67, -1, 0);
                      if ( !v30 )
                      {
                        MiDereferencePageRuns(v65);
                        MiReleasePteCopyList(&v79);
                        if ( (((unsigned __int16)a5 | (unsigned __int16)v28) & 0x3FF) == 0 )
                        {
                          v38 = a5 >> 10;
                          v39 = (unsigned int *)(dword_634C94 + 4 * (v28 >> 15));
                          v40 = (v28 >> 10) & 0x1F;
                          if ( v40 + (a5 >> 10) > 0x20 )
                          {
                            if ( v40 )
                            {
                              v54 = 32 - v40;
                              __dmb(0xBu);
                              v55 = ((1 << (32 - v40)) - 1) << v40;
                              do
                                v56 = __ldrex(v39);
                              while ( __strex(v56 | v55, v39) );
                              __dmb(0xBu);
                              v38 -= v54;
                              ++v39;
                            }
                            if ( v38 >= 0x20 )
                            {
                              v57 = v38 >> 5;
                              do
                              {
                                v38 -= 32;
                                --v57;
                                *v39++ = -1;
                              }
                              while ( v57 );
                            }
                            if ( !v38 )
                              goto LABEL_39;
                            __dmb(0xBu);
                            do
                              v58 = __ldrex(v39);
                            while ( __strex(v58 | ((1 << v38) - 1), v39) );
                          }
                          else
                          {
                            if ( v38 == 32 )
                            {
                              *v39 = -1;
                              goto LABEL_39;
                            }
                            __dmb(0xBu);
                            v41 = ((1 << v38) - 1) << v40;
                            do
                              v42 = __ldrex(v39);
                            while ( __strex(v42 | v41, v39) );
                          }
                          __dmb(0xBu);
                        }
LABEL_39:
                        MiConvertContiguousPages(v29, a5, a6);
                        if ( (v67 & 0x40000000) == 0 )
                        {
                          if ( (v67 & 0x200000) != 0 )
                            v33 = 2;
                          else
                            v33 = 1;
                          v34 = v29 + 24 * a5;
                          do
                          {
                            *(_DWORD *)v29 = 0;
                            v29 += 24;
                            *(_DWORD *)(v29 - 4) &= 0xF7FFFFFF;
                            MiSetPfnOwnedAndActive(v29 - 24, -4, a6, v33);
                          }
                          while ( v29 != v34 );
                          v28 = v87;
                        }
                        result = 0;
                        *v77 = v28;
                        return result;
                      }
                      if ( v86 )
                      {
                        v43 = KfRaiseIrql(2);
                        v44 = (unsigned __int8 *)(v29 + 15);
                        do
                          v45 = __ldrex(v44);
                        while ( __strex(v45 | 0x80, v44) );
                        __dmb(0xBu);
                        if ( v45 >> 7 )
                        {
                          v46 = (unsigned __int8 *)(v29 + 15);
                          do
                          {
                            do
                            {
                              __dmb(0xAu);
                              __yield();
                              v47 = *(_DWORD *)(v29 + 12);
                              __dmb(0xBu);
                            }
                            while ( (v47 & 0x80000000) != 0 );
                            do
                              v48 = __ldrex(v46);
                            while ( __strex(v48 | 0x80, v46) );
                            __dmb(0xBu);
                          }
                          while ( v48 >> 7 );
                        }
                        if ( (*(_DWORD *)(v29 + 4) | 0x80000000) == -4 && (*(_BYTE *)(v29 + 18) & 7) == 5 )
                        {
                          __dmb(0xBu);
                          v49 = (unsigned int *)(v29 + 12);
                          do
                            v50 = __ldrex(v49);
                          while ( __strex(v50 & 0x7FFFFFFF, v49) );
                          KfLowerIrql(v43);
                          v13 = v72;
                          v12 = v74;
                          v11 = v63;
                          v68 = 0;
                          break;
                        }
                        __dmb(0xBu);
                        v51 = (unsigned int *)(v29 + 12);
                        do
                          v52 = __ldrex(v51);
                        while ( __strex(v52 & 0x7FFFFFFF, v51) );
                        KfLowerIrql(v43);
                      }
                    }
                    v31 = v28 - v26;
                    v12 = v74;
                    if ( v30 <= v31 )
                    {
                      v27 -= v30;
                      v13 = v72;
                      goto LABEL_20;
                    }
                    v13 = v72;
                  }
LABEL_61:
                  v24 = v69;
                  v23 = v70;
                  v11 = v63;
                }
                v22 = v83;
              }
              while ( v83 );
              v20 = v76;
              v18 = v65;
              v21 = v66;
            }
            if ( !v21 )
              break;
            v66 = ++v21;
            if ( v21 )
            {
              if ( v73 != -1 )
              {
                v53 = (unsigned __int16 *)(v78 + 2);
                v78 += 2;
                if ( v78 )
                {
                  v73 = *v53;
                  goto LABEL_14;
                }
              }
              break;
            }
          }
          if ( v71 == 1 && v68 )
          {
            if ( (dword_682604 & 0x100000) != 0 )
            {
              v88 = 0;
              v89 = 0;
              v90 = 0i64;
              v88 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x370);
              v89 = 0;
              v90 = (unsigned __int64)a5 << 12;
              v91[0] = (int)&v88;
              v91[1] = 0;
              v91[2] = 16;
              v91[3] = 0;
              EtwTraceKernelEvent(v91, 1, 537919488, 625, 4200962);
              v18 = v65;
            }
            if ( byte_634C8C )
            {
              MiQueueWorkingSetRequest(a1, 32);
              v18 = v65;
            }
            v68 = 0;
            v73 = -1;
            continue;
          }
          break;
        }
        v37 = -1073741801;
        MiDereferencePageRuns(v18);
      }
      else
      {
        v37 = -1073741670;
      }
    }
    MiReleasePteCopyList(&v79);
  }
  if ( !v84 )
  {
    if ( a1 == MiSystemPartition )
    {
      MiReturnResidentAvailable(a5);
      do
        v59 = __ldrex(&dword_634A2C[39]);
      while ( __strex(v59 + a5, &dword_634A2C[39]) );
    }
    else
    {
      v60 = (unsigned int *)(a1 + 1920);
      do
        v61 = __ldrex(v60);
      while ( __strex(v61 + a5, v60) );
    }
    MiReturnCommit(a1, a5);
  }
  return v37;
}
