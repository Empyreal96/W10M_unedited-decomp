// FsRtlNotifyFilterReportChange 
 
int __fastcall FsRtlNotifyFilterReportChange(int result, int a2, int a3, int a4, unsigned __int16 *a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r5
  int v11; // lr
  int *v12; // r2
  int v13; // r4
  unsigned int v14; // r6
  unsigned int v15; // r8
  int v16; // r0
  int v17; // r5
  unsigned int v18; // r2
  int v19; // r10
  int v20; // r8
  unsigned __int16 *v21; // r6
  int v22; // r4
  int v23; // r8
  __int16 v24; // r3
  int v25; // r2
  unsigned __int16 *v26; // r0
  unsigned int v27; // r2
  unsigned int v28; // r3
  __int16 v29; // r3
  int v30; // r3
  int v31; // r3
  int (__fastcall *v32)(_DWORD, int, _DWORD); // r3
  int (__fastcall *v33)(_DWORD, int); // r3
  __int16 v34; // r1
  unsigned int v35; // r10
  int v36; // r0
  int v37; // r1
  int v38; // r2
  unsigned __int16 v39; // r3
  int v40; // lr
  __int16 v41; // r2
  int v42; // r3
  int v43; // r0
  int v44; // r2
  int v45; // r5
  unsigned int v46; // r1
  unsigned __int16 *v47; // r6
  unsigned __int16 *v48; // r6
  int v49; // r2
  int v50; // r5
  unsigned int v51; // r5
  int v52; // r6
  int v53; // r0
  int v54; // r3
  int v55; // r3
  int v56; // r8
  int v57; // r0
  int v58; // r0
  unsigned int v59; // r8
  _DWORD *v60; // r0
  int v61; // r2
  int v62; // r3
  int v63; // r3
  int v64; // r6
  int v65; // r0
  unsigned int *v66; // r4
  int v67; // r3
  unsigned int v68; // r1
  int v71; // [sp+20h] [bp-A0h]
  unsigned __int16 v72; // [sp+28h] [bp-98h] BYREF
  unsigned __int16 v73; // [sp+2Ah] [bp-96h]
  int v74; // [sp+2Ch] [bp-94h]
  _DWORD *v75; // [sp+30h] [bp-90h]
  int v76; // [sp+34h] [bp-8Ch]
  unsigned __int16 *v77; // [sp+38h] [bp-88h]
  __int16 v78; // [sp+40h] [bp-80h] BYREF
  __int16 v79; // [sp+42h] [bp-7Eh]
  int v80; // [sp+44h] [bp-7Ch]
  int v81; // [sp+48h] [bp-78h]
  __int16 v82; // [sp+50h] [bp-70h]
  __int16 v83; // [sp+52h] [bp-6Eh]
  int v84; // [sp+54h] [bp-6Ch]
  int v85; // [sp+58h] [bp-68h]
  int v86; // [sp+5Ch] [bp-64h]
  int v87; // [sp+60h] [bp-60h]
  int v88; // [sp+64h] [bp-5Ch]
  int v89; // [sp+68h] [bp-58h]
  int v90; // [sp+6Ch] [bp-54h]
  unsigned int v91; // [sp+70h] [bp-50h]
  int v92; // [sp+74h] [bp-4Ch]
  _DWORD *v93; // [sp+78h] [bp-48h]
  int v94; // [sp+7Ch] [bp-44h]
  int v95; // [sp+80h] [bp-40h]
  _WORD v96[2]; // [sp+88h] [bp-38h] BYREF
  int v97; // [sp+8Ch] [bp-34h]
  _DWORD *v98; // [sp+90h] [bp-30h]
  _DWORD *v99; // [sp+94h] [bp-2Ch]
  unsigned int v100; // [sp+98h] [bp-28h]
  int v101; // [sp+A0h] [bp-20h]
  unsigned int *varg_r0; // [sp+C8h] [bp+8h]
  int varg_r1; // [sp+CCh] [bp+Ch]
  int varg_r2; // [sp+D0h] [bp+10h]
  int varg_r3; // [sp+D4h] [bp+14h]

  v10 = a4;
  v81 = a4;
  varg_r3 = a4;
  v11 = a3;
  varg_r2 = a3;
  v12 = (int *)a2;
  varg_r1 = a2;
  v13 = result;
  varg_r0 = (unsigned int *)result;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  v84 = 0;
  v90 = 0;
  v78 = 0;
  v79 = 0;
  v80 = 0;
  v76 = 0;
  v72 = 0;
  v73 = 0;
  v74 = 0;
  v86 = 0;
  v95 = 0;
  if ( !a4 && v11 )
    return result;
  v88 = 0;
  v84 = 0;
  v89 = 0;
  v80 = 0;
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( v14 != *(_DWORD *)(result + 32) )
  {
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = KeAbPreAcquire(result, 0, 0);
    v17 = v16;
    do
      v18 = __ldrex((unsigned __int8 *)v13);
    while ( __strex(v18 & 0xFE, (unsigned __int8 *)v13) );
    __dmb(0xBu);
    if ( (v18 & 1) == 0 )
      ExpAcquireFastMutexContended(v13, v16);
    if ( v17 )
      *(_BYTE *)(v17 + 14) |= 1u;
    *(_DWORD *)(v13 + 4) = v15;
    *(_DWORD *)(v13 + 32) = v14;
    v10 = v81;
    v11 = a3;
    v12 = (int *)a2;
  }
  ++*(_DWORD *)(v13 + 36);
  v19 = *v12;
  result = 16;
  v20 = a9;
  v21 = (unsigned __int16 *)a6;
  v77 = (unsigned __int16 *)a6;
  while ( 1 )
  {
    v92 = v19;
    v71 = v19;
    if ( (int *)v19 == v12 )
      break;
    v22 = v19 - 16;
    v94 = v19 - 16;
    if ( v11 )
    {
      if ( **(_WORD **)(v19 + 64) && (*(_DWORD *)(v19 + 24) & a7) != 0 )
      {
        if ( !v21 )
        {
          v97 = *(_DWORD *)(v11 + 4);
          v24 = v10;
          v96[0] = v10;
          v25 = *(unsigned __int8 *)(v19 + 68);
          if ( v10 != v25 )
          {
            v24 = v10 - v25;
            v96[0] = v10 - v25;
          }
          v96[1] = v24;
          v21 = v96;
          v77 = v96;
        }
        v26 = *(unsigned __int16 **)(v19 + 64);
        v27 = *v26;
        v28 = *v21;
        if ( v28 < v27 )
          goto LABEL_140;
        if ( v28 == v27 )
        {
          v23 = 1;
          goto LABEL_34;
        }
        v29 = *(_WORD *)(v19 + 20);
        if ( (v29 & 1) != 0 )
        {
          if ( (v29 & 0x10) != 0
            || ((v30 = *((_DWORD *)v21 + 1), *(_BYTE *)(v19 + 68) == 1) ? (v31 = *(char *)(v27 + v30)) : (v31 = *(unsigned __int16 *)(v27 + v30)),
                v31 == 92) )
          {
            v23 = 0;
LABEL_34:
            if ( !memcmp(*((_DWORD *)v26 + 1), *((_DWORD *)v21 + 1), v27)
              && (v23
               || (v32 = *(int (__fastcall **)(_DWORD, int, _DWORD))(v19 - 8)) == 0
               || v32(*(_DWORD *)(v19 - 12), a9, *(_DWORD *)(v19 - 4))) )
            {
              v33 = *(int (__fastcall **)(_DWORD, int))(v19 + 16);
              if ( !v33 || !a10 || v33(*(_DWORD *)(v19 - 12), a10) )
              {
                v11 = a3;
LABEL_43:
                v34 = *(_WORD *)(v19 + 20);
                if ( (v34 & 2) == 0 )
                {
                  v35 = *(_DWORD *)(v19 + 36);
                  if ( v35 )
                  {
                    v93 = 0;
                    v98 = 0;
                    if ( *(_DWORD *)(v22 + 56) )
                    {
                      v35 = *(_DWORD *)(v22 + 56);
                      v91 = v35;
                    }
                    else
                    {
                      if ( *(_DWORD *)(v22 + 24) != v22 + 24 )
                      {
                        v93 = (_DWORD *)(*(_DWORD *)(v22 + 24) - 88);
                        v98 = v93;
                        v101 = v93[24];
                        v35 = *(_DWORD *)(v101 + 8);
                      }
                      v91 = v35;
                    }
                    if ( v23 )
                    {
                      v49 = 0;
                      v76 = 0;
                      v72 = 0;
                    }
                    else if ( v86 )
                    {
                      v49 = v76;
                    }
                    else
                    {
                      if ( (v34 & 0x10) != 0 || (v36 = *((_DWORD *)v21 + 1), v36 != *(_DWORD *)(v11 + 4)) )
                      {
                        if ( v88 )
                        {
                          v40 = v88;
                        }
                        else
                        {
                          v40 = *(_DWORD *)(v11 + 4);
                          v88 = v40;
                          v84 = v40;
                          v41 = v10;
                          v85 = v10;
                          v82 = v10;
                          v42 = *(unsigned __int8 *)(v22 + 84);
                          if ( v10 != v42 )
                          {
                            v41 = v10 - v42;
                            v85 = (unsigned __int16)(v10 - v42);
                            v82 = v10 - v42;
                          }
                          v83 = v41;
                        }
                        LOBYTE(v43) = 0;
                        v44 = 0;
                        v87 = 0;
                        if ( (v34 & 0x10) == 0 )
                        {
                          v45 = 1;
                          v46 = 0;
                          if ( *(_BYTE *)(v22 + 84) == 1 )
                          {
                            while ( 1 )
                            {
                              v47 = *(unsigned __int16 **)(v22 + 80);
                              if ( v46 >= *v47 )
                                break;
                              if ( *(_BYTE *)(*((_DWORD *)v47 + 1) + v46) == 92 )
                                ++v45;
                              ++v46;
                            }
                            while ( 1 )
                            {
                              if ( *(_BYTE *)(v44 + v40) == 92 )
                              {
                                v43 = (unsigned __int8)(v43 + 1);
                                if ( v43 == v45 )
                                  break;
                              }
                              v87 = ++v44;
                            }
                          }
                          else
                          {
                            while ( 1 )
                            {
                              v48 = *(unsigned __int16 **)(v22 + 80);
                              if ( v46 >= *v48 >> 1 )
                                break;
                              if ( *(_WORD *)(*((_DWORD *)v48 + 1) + 2 * v46) == 92 )
                                ++v45;
                              ++v46;
                            }
                            while ( 1 )
                            {
                              if ( *(_WORD *)(v40 + 2 * v44) == 92 )
                              {
                                v43 = (unsigned __int8)(v43 + 1);
                                if ( v43 == v45 )
                                  break;
                              }
                              v87 = ++v44;
                            }
                            v44 *= *(unsigned __int8 *)(v22 + 84);
                            v87 = v44;
                          }
                        }
                        v87 = v44 + *(unsigned __int8 *)(v22 + 84);
                        v74 = v87 + v40;
                        v39 = v85 - v87;
                      }
                      else
                      {
                        v37 = **(unsigned __int16 **)(v22 + 80);
                        v38 = *(unsigned __int8 *)(v22 + 84);
                        v74 = v38 + v37 + v36;
                        v39 = *v21 - v38 - v37;
                      }
                      v49 = v39;
                      v76 = v39;
                      v72 = v39;
                      v73 = v39;
                    }
                    v50 = 12;
                    if ( v86 )
                    {
                      v51 = *a5 + 12;
                    }
                    else
                    {
                      if ( v23 )
                      {
                        v52 = (unsigned __int8)NlsMbOemCodePageTag;
                      }
                      else
                      {
                        if ( *(_BYTE *)(v22 + 84) == 1 )
                        {
                          v52 = (unsigned __int8)NlsMbOemCodePageTag;
                          if ( NlsMbOemCodePageTag )
                            v53 = RtlxOemStringToUnicodeSize(&v72);
                          else
                            v53 = 2 * (v49 + 1);
                          v54 = v53 + 10;
                        }
                        else
                        {
                          v54 = v49 + 12;
                          v52 = (unsigned __int8)NlsMbOemCodePageTag;
                        }
                        v50 = v54 + 2;
                      }
                      if ( v89 )
                      {
                        v55 = v90;
                      }
                      else
                      {
                        v89 = *(_DWORD *)(a3 + 4) + v81;
                        v80 = v89;
                        v55 = (unsigned __int16)(*(_WORD *)a3 - v81);
                        v90 = (unsigned __int16)v55;
                        v78 = v55;
                        v79 = v55;
                      }
                      v56 = *(unsigned __int8 *)(v22 + 84);
                      if ( v56 == 1 )
                      {
                        if ( v52 )
                          v57 = RtlxOemStringToUnicodeSize(&v78);
                        else
                          v57 = 2 * (v55 + 1);
                        v51 = v57 + v50 - 2;
                      }
                      else
                      {
                        v51 = v50 + v55;
                      }
                      if ( a5 )
                      {
                        if ( v56 == 2 )
                        {
                          v51 += *a5 + 2;
                        }
                        else
                        {
                          if ( v52 )
                            v58 = RtlxOemStringToUnicodeSize(a5);
                          else
                            v58 = 2 * (*a5 + 1);
                          v51 = v58 + v51 - 1;
                        }
                      }
                    }
                    v59 = (*(_DWORD *)(v22 + 60) + 3) & 0xFFFFFFFC;
                    v100 = v59;
                    if ( v51 > v35 || v59 + v51 > v35 )
                      goto LABEL_126;
                    v60 = 0;
                    v75 = 0;
                    v61 = *(_DWORD *)(v22 + 48);
                    if ( v61 )
                    {
                      v62 = *(_DWORD *)(v22 + 64);
                      v75 = (_DWORD *)(v61 + v62);
                      *v75 = v59 - v62;
                      *(_DWORD *)(v22 + 64) = v59;
                      v60 = (_DWORD *)(v59 + *(_DWORD *)(v22 + 48));
                      v75 = v60;
                      goto LABEL_121;
                    }
                    if ( v93 )
                    {
                      v63 = v93[3];
                      if ( v63 )
                      {
                        v60 = (_DWORD *)v93[3];
                        v75 = v60;
                        *(_DWORD *)(v22 + 48) = v63;
                        goto LABEL_120;
                      }
                      v64 = v93[1];
                      if ( v64 )
                      {
                        if ( (*(_WORD *)(v64 + 6) & 5) != 0 )
                          v60 = *(_DWORD **)(v64 + 12);
                        else
                          v60 = (_DWORD *)MmMapLockedPagesSpecifyCache(v64, 0, 1, 0, 0, 1073741840);
                        v99 = v60;
                        v75 = v60;
                        *(_DWORD *)(v22 + 48) = v60;
LABEL_120:
                        *(_DWORD *)(v22 + 56) = v35;
                      }
                    }
LABEL_121:
                    if ( !*(_DWORD *)(v22 + 48) )
                    {
                      PsChargePoolQuota();
                      v65 = ExAllocatePoolWithTag(17, v35, 1316115270);
                      *(_DWORD *)(v22 + 48) = v65;
                      *(_DWORD *)(v22 + 44) = v65;
                      *(_DWORD *)(v22 + 56) = v35;
                      v60 = *(_DWORD **)(v22 + 48);
                      v75 = v60;
                    }
                    if ( v60 )
                    {
                      if ( FsRtlNotifyUpdateBuffer(v60, a8, &v72) )
                      {
                        *(_DWORD *)(v22 + 60) = v59 + v51;
                        goto LABEL_127;
                      }
LABEL_126:
                      *(_WORD *)(v22 + 36) |= 2u;
                    }
LABEL_127:
                    if ( (*(_WORD *)(v22 + 36) & 2) != 0 && *(_DWORD *)(v22 + 48) )
                    {
                      if ( *(_DWORD *)(v22 + 44) )
                      {
                        PsReturnProcessPagedPoolQuota(*(_DWORD *)(v22 + 72), *(_DWORD *)(v22 + 56));
                        ExFreePoolWithTag(*(_DWORD *)(v22 + 44));
                      }
                      *(_DWORD *)(v22 + 48) = 0;
                      *(_DWORD *)(v22 + 44) = 0;
                      *(_DWORD *)(v22 + 64) = 0;
                      *(_DWORD *)(v22 + 60) = 0;
                      *(_DWORD *)(v22 + 56) = 0;
                    }
                    v21 = v77;
                  }
                  v19 = v71;
                }
                if ( a8 == 4 )
                {
                  *(_WORD *)(v22 + 36) |= 8u;
                }
                else
                {
                  *(_WORD *)(v22 + 36) &= 0xFFF7u;
                  if ( *(_DWORD *)(v22 + 24) != v22 + 24 )
                    FsRtlNotifyCompleteIrpList(v22, 0);
                }
              }
            }
            v11 = a3;
          }
          v20 = a9;
        }
LABEL_140:
        v12 = (int *)a2;
        result = 16;
        goto LABEL_141;
      }
    }
    else if ( v20 == *(_DWORD *)(v19 - 4) )
    {
      v74 = 0;
      v76 = 0;
      v72 = 0;
      v86 = 1;
      v23 = 0;
      goto LABEL_43;
    }
LABEL_141:
    v19 = *(_DWORD *)v19;
    v10 = v81;
  }
  v66 = varg_r0;
  v67 = varg_r0[9] - 1;
  varg_r0[9] = v67;
  if ( !v67 )
  {
    v66[8] = 0;
    v66[1] = 0;
    __dmb(0xBu);
    do
      v68 = __ldrex(v66);
    while ( !v68 && __strex(1u, v66) );
    if ( v68 )
      ExpReleaseFastMutexContended(v66, v68);
    result = KeAbPostRelease((unsigned int)v66);
  }
  return result;
}
