// MiCreateImageFileMap 
 
int __fastcall MiCreateImageFileMap(int a1, int a2, int a3, _DWORD *a4, int *a5, _DWORD *a6, _DWORD *a7)
{
  char v10; // r5
  unsigned int v11; // r8
  int *v12; // r4
  int v13; // r1
  int v14; // r2
  int v15; // r0
  unsigned __int16 *v16; // r10
  int v17; // r2
  int v18; // r3
  int v19; // r0
  int v20; // r5
  int v21; // r7
  unsigned int v22; // r6
  unsigned int v23; // r3
  int v24; // r0
  int v25; // r4
  unsigned int v26; // r0
  int v27; // r2
  unsigned int v28; // r8
  unsigned int v29; // r2
  _DWORD *v30; // r9
  unsigned int v31; // r3
  int v32; // lr
  int v33; // r1
  int v34; // r2
  int v35; // r3
  int v36; // r10
  __int16 v37; // r2
  int v38; // r4
  unsigned int v39; // r3
  int v40; // r6
  int v41; // r8
  int v42; // r5
  _DWORD *v43; // r10
  char v44; // r2
  _BYTE *v45; // r1
  unsigned int v46; // r3
  int v47; // r7
  __int16 v48; // r8
  int v49; // r9
  int v50; // r2
  BOOL v51; // r6
  int v52; // r5
  _DWORD *v53; // r4
  int v54; // r3
  int v55; // r5
  int *v56; // r7
  int v57; // r6
  int v58; // r5
  int v59; // t1
  int v60; // r7
  int v61; // r2
  unsigned int v62; // r5
  unsigned int v63; // r0
  int v64; // r0
  unsigned int v65; // r4
  unsigned int v66; // r4
  int v67; // r0
  int v68; // r3
  bool v69; // r0
  __int16 v70; // r1
  int v71; // [sp+10h] [bp-E0h] BYREF
  unsigned int v72; // [sp+14h] [bp-DCh]
  _BYTE *v73; // [sp+18h] [bp-D8h] BYREF
  _DWORD *v74; // [sp+1Ch] [bp-D4h]
  unsigned int v75; // [sp+20h] [bp-D0h]
  int v76; // [sp+24h] [bp-CCh]
  int v77; // [sp+28h] [bp-C8h]
  int *v78; // [sp+2Ch] [bp-C4h]
  unsigned int v79; // [sp+30h] [bp-C0h] BYREF
  int v80; // [sp+34h] [bp-BCh]
  int v81; // [sp+38h] [bp-B8h]
  int v82; // [sp+3Ch] [bp-B4h]
  int v83; // [sp+40h] [bp-B0h]
  char v84[16]; // [sp+48h] [bp-A8h] BYREF
  int v85; // [sp+58h] [bp-98h]
  _DWORD *v86; // [sp+5Ch] [bp-94h]
  _DWORD *v87; // [sp+60h] [bp-90h]
  int *v88; // [sp+64h] [bp-8Ch]
  int v89[2]; // [sp+68h] [bp-88h] BYREF
  __int16 v90; // [sp+70h] [bp-80h]
  __int16 v91; // [sp+72h] [bp-7Eh]
  _DWORD v92[4]; // [sp+78h] [bp-78h] BYREF
  int v93; // [sp+88h] [bp-68h]
  int *v94; // [sp+90h] [bp-60h] BYREF
  int v95; // [sp+94h] [bp-5Ch]
  int v96; // [sp+98h] [bp-58h]
  int v97; // [sp+9Ch] [bp-54h]
  int v98; // [sp+A0h] [bp-50h] BYREF
  __int16 v99; // [sp+A4h] [bp-4Ch]
  __int16 v100; // [sp+A6h] [bp-4Ah]
  int v101; // [sp+B0h] [bp-40h]
  int v102; // [sp+B4h] [bp-3Ch]
  int v103; // [sp+B8h] [bp-38h]
  int v104; // [sp+BCh] [bp-34h]
  int *v105; // [sp+C0h] [bp-30h] BYREF
  int v106; // [sp+C4h] [bp-2Ch]
  int v107; // [sp+C8h] [bp-28h]
  int varg_r0; // [sp+F8h] [bp+8h]
  int varg_r1; // [sp+FCh] [bp+Ch]
  int varg_r2; // [sp+100h] [bp+10h]
  _DWORD *varg_r3; // [sp+104h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v87 = a4;
  v76 = a1;
  v88 = a5;
  v85 = a2;
  v74 = a6;
  v86 = a7;
  v105 = 0;
  v106 = 0;
  v107 = 0;
  if ( FsRtlGetFileSize(a1, &v94) < 0 )
    return sub_7D4318();
  if ( v95 )
    JUMPOUT(0x7D4328);
  v75 = 1;
  v10 = 0;
  v73 = 0;
  v11 = 0;
  v77 = 0;
  KeInitializeEvent((int)v84, 0, 0);
  v98 = 0;
  v99 = 32;
  v101 = 0;
  v103 = 0;
  v100 = 16386;
  v12 = &v98;
  v102 = 4096;
  v15 = MiGetPageForHeader(a2, v13, v14, 16386);
  v83 = v15;
  if ( v15 != -1 )
  {
    v104 = v15;
    v16 = 0;
    v81 = MmPfnDatabase + 24 * v15;
    CcZeroEndOfLastPage(a1);
    if ( MiFlushDataSection(a1) )
    {
      v10 = 1;
      v77 = 1;
    }
    v17 = 128;
    if ( (v10 & 1) != 0 || (v18 = varg_r2, (varg_r2 & 0x80) != 0) )
    {
      if ( PsIsCurrentThreadPrefetching() )
      {
        v27 = 64;
        v25 = -1073740749;
        dword_632EE4 = 64;
LABEL_108:
        v43 = 0;
        goto LABEL_68;
      }
    }
    v19 = MiCopyHeaderIfResident(a1, v83, v17, v18);
    v20 = (int)v94;
    if ( v19 == 1 )
    {
      v22 = 4096;
      v72 = 4096;
      v21 = varg_r2;
    }
    else
    {
      v21 = varg_r2;
      v22 = 0;
      v72 = 0;
      if ( ((varg_r2 & 0x20) != 0 || (varg_r2 & 0x400) != 0 && (unsigned int)v94 <= 0x20000) && !**(_DWORD **)(v76 + 20) )
      {
        v23 = ((unsigned int)v94 + 4095) >> 12;
        v75 = v23;
        if ( v23 > 1 )
        {
          v24 = MiCreateMdl(v23 << 12);
          v21 = varg_r2;
          v22 = v72;
          v78 = (int *)v24;
          v105 = (int *)v24;
          if ( v24 )
          {
            v16 = *(unsigned __int16 **)(v24 + 16);
            v12 = (int *)v24;
          }
          else
          {
            v75 = 1;
          }
LABEL_17:
          if ( (*((_WORD *)v12 + 3) & 2) != 0 )
          {
            v16 = (unsigned __int16 *)MmMapLockedPagesSpecifyCache((int)v12, 0, 1, 0, 0, 1073741856);
            if ( !v16 )
            {
              v27 = 37;
              v25 = -1073741670;
              dword_632EE4 = 37;
              goto LABEL_108;
            }
            v21 = varg_r2;
            v22 = v72;
            v78 = v12;
            v105 = v12;
          }
          if ( !v22 )
          {
            v79 = 0;
            v80 = 0;
            v25 = IoPageRead(v76, (int)v12, &v79, (int)v84, (int)&v71);
            if ( v25 == 259 )
            {
              KeWaitForSingleObject((unsigned int)v84, 9, 0, 0, 0);
              v25 = v71;
            }
            if ( v25 < 0 )
            {
              v27 = 2;
              dword_632EE4 = 2;
              if ( v25 == -1073741740 )
                goto LABEL_108;
              goto LABEL_98;
            }
            v22 = v72;
            v26 = v75;
            if ( v72 == v75 << 12 )
            {
              v21 = varg_r2;
              goto LABEL_24;
            }
            if ( v72 < 0x40 )
            {
              v25 = -1073741521;
              v27 = 38;
              dword_632EE4 = 38;
              goto LABEL_108;
            }
            memset((_BYTE *)v16 + v72, 0, (v75 << 12) - v72);
            v21 = varg_r2;
            v22 = v72;
          }
          v26 = v75;
LABEL_24:
          v27 = *v16;
          if ( v27 != 23117 )
          {
            v25 = -1073741521;
            goto LABEL_108;
          }
          v28 = *((_DWORD *)v16 + 15);
          v29 = v28 + 248;
          if ( v28 + 248 <= v28 )
          {
            v27 = 6;
          }
          else if ( (unsigned __int64)v28 + 248 > (unsigned int)v20 )
          {
            v27 = 5;
          }
          else if ( v29 > v26 << 12 )
          {
            v60 = MiCreateMdl(0x2000);
            v82 = v60;
            v106 = v60;
            if ( !v60 )
            {
              v25 = -1073741670;
              v27 = 7;
              goto LABEL_106;
            }
            v79 = v28 & 0xFFFFF000;
            v80 = 0;
            KeResetEvent((int)v84);
            v72 = 0;
            v25 = IoPageRead(v76, v60, &v79, (int)v84, (int)&v71);
            if ( v25 == 259 )
            {
              KeWaitForSingleObject((unsigned int)v84, 9, 0, 0, 0);
              v25 = v71;
            }
            if ( v25 < 0 )
            {
              v27 = 8;
LABEL_117:
              dword_632EE4 = v27;
              if ( v25 == -1073741740 )
                goto LABEL_107;
              v11 = 0;
LABEL_98:
              v43 = 0;
              if ( v25 != -1073741209 )
                v25 = -1073741792;
              goto LABEL_68;
            }
            if ( v72 == 0x2000 || v72 >= (v28 & 0xFFF) + 248 )
            {
              v61 = v28 & 0xFFF;
              v30 = (_DWORD *)(v61 + *(_DWORD *)(v60 + 16));
              v31 = v72 - v61;
              v22 = (v28 & 0xFFFFF000) + v72;
              v21 = varg_r2;
              v72 = v22;
LABEL_30:
              v25 = MiVerifyImageHeader(v74, v30, v16, v31);
              if ( v25 )
              {
                v27 = 9;
                goto LABEL_106;
              }
              v32 = (int)v74;
              if ( v74[5] >= v74[3] )
              {
                v25 = -1073741701;
                v27 = 16;
                goto LABEL_106;
              }
              *v86 = v28 + 52;
              if ( !(((*(_DWORD *)(v32 + 12) & 0xFFF) != 0) + (*(_DWORD *)(v32 + 12) >> 12)) )
              {
                v25 = -1073741701;
                v27 = 10;
                goto LABEL_106;
              }
              v33 = v30[2];
              v34 = v30[3];
              v35 = v30[4];
              v92[0] = v30[1];
              v92[1] = v33;
              v92[2] = v34;
              v92[3] = v35;
              v93 = v30[5];
              if ( (v93 & 3) != 0 )
              {
                v25 = -1073741701;
                v27 = 14;
                goto LABEL_106;
              }
              if ( *(_WORD *)v32 )
              {
                v25 = -1073741701;
                v27 = 15;
                goto LABEL_106;
              }
              v36 = LOWORD(v92[0]);
              if ( LOWORD(v92[0]) == 332 || LOWORD(v92[0]) == 34404 )
              {
                v37 = HIWORD(v93);
                if ( (v93 & 0x10000) == 0 || (*(_WORD *)(v32 + 48) & 0x1000) == 0 )
                {
LABEL_40:
                  if ( (v37 & 0x4000) != 0 )
                  {
                    v25 = -1073741701;
                    v27 = 28;
                    goto LABEL_106;
                  }
                  v38 = (unsigned __int16)v93 + 24;
                  v39 = v38 + 40 * HIWORD(v92[0]) + v28;
                  if ( v39 <= v28 )
                  {
                    v25 = -1073741701;
                    v27 = 52;
                    goto LABEL_106;
                  }
                  if ( v39 <= v22 )
                  {
                    v40 = v107;
                    v41 = (int)v30 + v38;
LABEL_44:
                    if ( *(_DWORD *)(v32 + 8) >= 0x1000u )
                    {
                      v42 = v77;
                      goto LABEL_46;
                    }
                    if ( (v21 & 0x20000) == 0 && (v36 == 332 || v36 == 34404) )
                    {
                      v42 = v77 | 8;
                      v77 |= 8u;
LABEL_46:
                      v25 = MiBuildImageControlArea(v42, v85, v41, v32, v92, v21, &v94, &v73);
                      v43 = v73;
                      if ( v25 < 0 )
                      {
                        v11 = 0;
                      }
                      else
                      {
                        v44 = varg_r2;
                        if ( (varg_r2 & 0x200) != 0 )
                        {
                          *(_BYTE *)(*(_DWORD *)(*(_DWORD *)v73 + 36) + 35) |= 0x10u;
                          v44 = varg_r2;
                        }
                        v45 = (_BYTE *)*v43;
                        v73 = (_BYTE *)*v43;
                        if ( v82 || v40 || (v42 & 8) != 0 || (v46 = v74[5], v46 >= 0x1000) )
                        {
                          v47 = 0;
                        }
                        else
                        {
                          if ( (v46 & 0x1FF) != 0 )
                          {
                            ++*((_DWORD *)v45 + 3);
                            v44 = varg_r2;
                          }
                          v47 = 1;
                        }
                        v48 = HIWORD(v93);
                        v49 = v42 & 1;
                        v51 = (v42 & 1) != 0
                           || (v44 & 0x80) != 0
                           || IoIsDeviceEjectable(*(_DWORD *)(v76 + 4))
                           || (v48 & 0x400) != 0 && (*(_DWORD *)(v50 + 32) & 1) != 0
                           || (v48 & 0x800) != 0 && (*(_DWORD *)(v50 + 32) & 0x10) != 0;
                        v52 = *((_DWORD *)v45 + 3);
                        if ( !v52 )
                          goto LABEL_61;
                        if ( MiChargeCommit((int)MiSystemPartition, *((_DWORD *)v45 + 3), 0) )
                        {
                          do
                            v65 = __ldrex((unsigned int *)&dword_634DAC);
                          while ( __strex(v65 + v52, (unsigned int *)&dword_634DAC) );
LABEL_61:
                          v27 = v43[7];
                          v53 = v74;
                          if ( (v27 & 0x20000) != 0 && (v77 & 8) == 0 && (v74[4] & 0x1000000) == 0 )
                            v43[7] = v27 | 0x4000000;
                          v54 = v75;
                          v55 = v81;
                          if ( v75 > 1 )
                            MiInitializeImageProtos((int)v43, (int)v78, v81);
                          if ( v47 == 1 )
                            MiInitializeImageHeaderPage(v83, v53[5], v27, v54);
                          if ( v51 )
                          {
                            v27 = (int)v73;
                            v73[10] |= 1u;
                            if ( v49 || (v66 = varg_r2, (varg_r2 & 0x80) != 0) )
                            {
                              v43[7] |= 0x40000u;
                              v66 = varg_r2;
                            }
                            if ( (PerfGlobalGroupMask & 4) != 0 )
                            {
                              v90 = v48;
                              v67 = *(_DWORD *)(v76 + 4);
                              v89[0] = *(_DWORD *)(v76 + 12);
                              v68 = *(_DWORD *)(v67 + 32);
                              v91 = v49;
                              v89[1] = v68;
                              v69 = IoIsDeviceEjectable(v67);
                              v91 = v70 & 0xFFF9 | (2 * (v69 | (unsigned __int16)(2 * ((v66 >> 7) & 1))));
                              v94 = v89;
                              v95 = 0;
                              v96 = 12;
                              v97 = 0;
                              EtwTraceKernelEvent((int *)&v94, 1, 4u, 617, 4200450);
                            }
                          }
                          v11 = (unsigned int)v73;
                          v25 = 0;
                          *v87 = v73;
                          *v88 = v55;
                          goto LABEL_68;
                        }
                        v27 = 35;
                        v25 = -1073741523;
                        v11 = (unsigned int)v73;
                        dword_632EE4 = 35;
                      }
LABEL_68:
                      v56 = (int *)&v105;
                      v57 = 3;
                      do
                      {
                        v59 = *v56++;
                        v58 = v59;
                        if ( v59 )
                        {
                          if ( (*(_WORD *)(v58 + 6) & 1) != 0 )
                          {
                            MmUnmapLockedPages(*(_DWORD *)(v58 + 12), v58, v27);
                          }
                          else
                          {
                            ExFreePoolWithTag(*(_DWORD *)(v58 + 16));
                            IoFreeMdl(v58);
                          }
                        }
                        --v57;
                      }
                      while ( v57 );
                      if ( v25 < 0 )
                      {
                        MiReturnPfnReferenceCount(v81);
                        if ( v11 )
                          ExFreePoolWithTag(v11);
                        if ( v43 )
                          ExFreePoolWithTag((unsigned int)v43);
                      }
                      return v25;
                    }
                    v25 = -1073741701;
                    v27 = 22;
                    goto LABEL_106;
                  }
                  v62 = (((_WORD)v38 + (_WORD)v30) & 0xFFF) + 40 * HIWORD(v92[0]);
                  if ( !v62 || (v63 = (v62 + 4095) & 0xFFFFF000, v62 > v63) )
                  {
                    v25 = -1073741701;
                    v27 = 53;
                    goto LABEL_106;
                  }
                  v64 = MiCreateMdl(v63);
                  v40 = v64;
                  v107 = v64;
                  if ( !v64 )
                  {
                    v25 = -1073741670;
                    v27 = 18;
                    goto LABEL_106;
                  }
                  v79 = (v38 + v28) & 0xFFFFF000;
                  v80 = 0;
                  v41 = (((_WORD)v38 + (_WORD)v28) & 0xFFF) + *(_DWORD *)(v64 + 16);
                  KeResetEvent((int)v84);
                  v72 = 0;
                  v25 = IoPageRead(v76, v40, &v79, (int)v84, (int)&v71);
                  if ( v25 == 259 )
                  {
                    KeWaitForSingleObject((unsigned int)v84, 9, 0, 0, 0);
                    v25 = v71;
                  }
                  if ( v25 >= 0 )
                  {
                    if ( v72 >= v62 )
                    {
                      v21 = varg_r2;
                      v32 = (int)v74;
                      goto LABEL_44;
                    }
                    v25 = -1073741701;
                    v27 = 40;
LABEL_106:
                    dword_632EE4 = v27;
LABEL_107:
                    v11 = 0;
                    goto LABEL_108;
                  }
                  v27 = 19;
                  goto LABEL_117;
                }
              }
              else
              {
                v37 = HIWORD(v93);
                if ( (v93 & 0x10000) == 0 )
                {
                  if ( (*(_WORD *)(v32 + 48) & 0x40) == 0 || (*(_WORD *)(v32 + 48) & 0x100) == 0 )
                  {
                    v25 = -1073741701;
                    v27 = 44;
                    goto LABEL_106;
                  }
                  goto LABEL_40;
                }
              }
              v25 = -1073741701;
              v27 = 23;
              goto LABEL_106;
            }
            v27 = 24;
          }
          else
          {
            if ( v29 <= v22 )
            {
              v30 = (_DWORD *)((char *)v16 + v28);
              v31 = v22 - v28;
              v82 = v106;
              goto LABEL_30;
            }
            v27 = 39;
          }
          v25 = -1073741520;
          goto LABEL_106;
        }
      }
    }
    v78 = v105;
    goto LABEL_17;
  }
  return -1073741670;
}
