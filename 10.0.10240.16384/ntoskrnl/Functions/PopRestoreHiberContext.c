// PopRestoreHiberContext 
 
_DWORD *__fastcall PopRestoreHiberContext(_DWORD *result)
{
  _DWORD *v1; // r9
  unsigned int v2; // r6
  __int64 v3; // r0
  __int64 v4; // r0
  __int64 v5; // r4
  int v6; // r3
  unsigned int *v7; // r2
  unsigned int v8; // r1
  __int64 v9; // r0
  int v10; // r4
  int v11; // r6
  __int64 v12; // r7
  __int64 v13; // r4
  int v14; // r4
  __int64 v15; // r0
  int v16; // r3
  int v17; // r2
  int v18; // r3
  int v19; // r3
  int v20; // r0
  void (__fastcall *v21)(int); // r3
  unsigned int *v22; // r1
  unsigned int v23; // r2
  unsigned int v24; // r2
  unsigned int v25; // lr
  unsigned __int64 v26; // r2
  unsigned __int64 v27; // r4
  unsigned int v28; // r7
  unsigned int v29; // r8
  int v30; // r2
  __int64 v31; // r0
  unsigned int v32; // r6
  __int64 v33; // r2
  bool v34; // cf
  unsigned __int64 v35; // kr30_8
  unsigned __int64 v36; // kr40_8
  unsigned int v37; // r3
  unsigned int v38; // r1
  unsigned int v39; // r0
  unsigned int v40; // kr28_4
  int v41; // r1
  __int64 v42; // r0
  __int64 v43; // r0
  __int64 v44; // kr50_8
  __int64 v45; // r0
  __int64 v46; // r0
  __int64 v47; // r0
  __int64 v48; // r0
  unsigned int v49; // kr58_4
  unsigned int v50; // [sp+8h] [bp-78h]
  int v51; // [sp+8h] [bp-78h]
  int v52; // [sp+Ch] [bp-74h]
  int v53; // [sp+Ch] [bp-74h]
  __int64 v54; // [sp+Ch] [bp-74h]
  unsigned int v55; // [sp+10h] [bp-70h]
  unsigned int v56; // [sp+14h] [bp-6Ch]
  int v57; // [sp+18h] [bp-68h]
  unsigned int v58; // [sp+1Ch] [bp-64h]
  unsigned int v59; // [sp+20h] [bp-60h]
  unsigned int v60; // [sp+24h] [bp-5Ch]
  unsigned int v61; // [sp+30h] [bp-50h]
  unsigned int v62; // [sp+34h] [bp-4Ch]
  __int64 v63; // [sp+3Ch] [bp-44h]
  _DWORD v64[12]; // [sp+50h] [bp-30h] BYREF

  v1 = result;
  v2 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  if ( v2 < result[40] )
  {
    HIDWORD(v3) = result[41] + 112 * v2;
    *(_QWORD *)(HIDWORD(v3) + 64) = 0i64;
    v50 = HIDWORD(v3);
    if ( v2 == result[31] )
    {
      LODWORD(v4) = ReadTimeStampCounter();
      v5 = v4;
      BgkResumeInitialize();
      LODWORD(v3) = ReadTimeStampCounter();
      qword_61F0F0 += v3 - v5;
      HIDWORD(v3) = v50;
    }
    if ( v2 )
    {
      while ( 1 )
      {
        v6 = *((char *)v1 + 5);
        __dmb(0xBu);
        if ( v6 )
          break;
        __dmb(0xAu);
        __yield();
      }
      LODWORD(v3) = v1;
      result = (_DWORD *)PopDecompressHiberBlocks(v3, 0, 1, 0);
      __dmb(0xBu);
      v7 = v1 + 4;
      do
        v8 = __ldrex(v7);
      while ( __strex(v8 + 1, v7) );
      __dmb(0xBu);
    }
    else
    {
      v52 = dword_61EF00;
      v56 = 0;
      v57 = 0;
      LODWORD(v9) = ReadTimeStampCounter();
      v10 = v1[32];
      v63 = v9;
      if ( *(_QWORD *)(v10 + 72) == *(_QWORD *)(v10 + 496) )
      {
        v1[66] = *(_DWORD *)(v10 + 520);
        v1[67] = *(_DWORD *)(v10 + 524);
      }
      else
      {
        v1[66] = 0;
        v1[67] = 0;
      }
      v11 = dword_61EF00;
      v12 = *((_QWORD *)v1 + 33);
      v13 = *((_QWORD *)v1 + 21);
      memset((_BYTE *)dword_61EF00, 0, 56);
      *(_DWORD *)(v11 + 12) = HIDWORD(v12);
      *(_DWORD *)(v11 + 16) = 0;
      *(_QWORD *)v11 = v13;
      *(_DWORD *)(v11 + 8) = v12;
      __dmb(0xBu);
      *((_BYTE *)v1 + 5) = 1;
      IoNotifyDump(2);
      if ( *((_QWORD *)v1 + 33) )
      {
        v1[29] = 9;
        v1[26] = v64;
        v64[0] = dword_61EEB0;
        v64[1] = dword_61EEB0;
        v64[2] = 0;
        v64[3] = 0;
        off_617AD4(0);
        v14 = IoInitializeDumpStack(v1[27]);
        if ( v14 < 0 || PopSimulateHiberBugcheck == 4 )
        {
          if ( (PoDebug & 0x80) != 0 )
            DbgPrint("PopRestoreHiberContext: dump driver initialization failed %08x\n", v14);
          PopInternalAddToDumpFile(v1[27], 256, 0);
          KeBugCheckEx(160, 12, v14, v1[27], 0);
        }
        LODWORD(v15) = ReadTimeStampCounter();
        qword_61F0D0 = v15 - v63;
        v16 = v1[27];
        v1[51] = 0;
        v1[54] = 0;
        v1[55] = 0;
        if ( *(_DWORD *)(v16 + 84) )
          *((_BYTE *)v1 + 260) = 1;
        PopHiberReadChecksums((char *)v1);
        v1[29] = 10;
        v17 = v1[66];
        v18 = *(_DWORD *)(v1[32] + 84);
        v1[63] = 0;
        v1[62] = v18 << 12;
        v19 = v1[67] | v17;
        if ( v19 )
        {
          do
          {
            PopRequestRead(__SPAIR64__(v52, (unsigned int)v1), 1, v19);
            if ( PopDecompressHiberBlocks(__SPAIR64__(v50, (unsigned int)v1), 1, 0, (int)PopDecompressCallback) == -2147483614
              && !v1[51] )
            {
              __dmb(0xAu);
              __yield();
            }
            v19 = v1[67] | v1[66];
          }
          while ( *((_QWORD *)v1 + 33) );
        }
        v20 = PopDecompressHiberBlocks(__SPAIR64__(v50, (unsigned int)v1), 1, 1, 0);
        v21 = *(void (__fastcall **)(int))(v1[27] + 52);
        if ( v21 )
          v21(v20);
      }
      IoNotifyDump(3);
      __dmb(0xBu);
      v22 = v1 + 4;
      do
        v23 = __ldrex(v22);
      while ( __strex(v23 + 1, v22) );
      __dmb(0xBu);
      while ( 1 )
      {
        v24 = *v22;
        __dmb(0xBu);
        if ( v24 == v1[40] )
          break;
        __dmb(0xAu);
        __yield();
      }
      v60 = 0;
      v61 = 0;
      v25 = 0;
      LODWORD(v26) = 0;
      v27 = 0i64;
      v28 = 0;
      v29 = 0;
      v55 = 0;
      v59 = 0;
      v62 = 0;
      if ( v1[40] )
      {
        LODWORD(v27) = HIDWORD(qword_61F0C0);
        v30 = v1[41];
        v31 = qword_61F0E8;
        v58 = qword_61F0C0;
        v32 = 0;
        v53 = dword_61F0B4;
        v51 = dword_61F0B0;
        while ( 1 )
        {
          v33 = *(_QWORD *)(HIDWORD(v27) + v30 + 48);
          v34 = __CFADD__(v51, (_DWORD)v33);
          v51 += v33;
          dword_61F0B0 = v51;
          dword_61F0B4 = HIDWORD(v33) + v34 + v53;
          v53 += HIDWORD(v33) + v34;
          v35 = __PAIR64__(v27, v58) + *(_QWORD *)(v1[41] + HIDWORD(v27) + 56);
          v58 = v35;
          qword_61F0C0 = v35;
          qword_61F0E8 = v31 + *(_QWORD *)(v1[41] + HIDWORD(v27) + 64);
          LODWORD(v27) = HIDWORD(v27) + v1[41];
          if ( *(_QWORD *)(v27 + 48) + *(_QWORD *)(v27 + 56) > __PAIR64__(v56, v57) )
          {
            v56 = (*(_QWORD *)(v27 + 48) + *(_QWORD *)(v27 + 56)) >> 32;
            v57 = *(_DWORD *)(v27 + 48) + *(_DWORD *)(v27 + 56);
          }
          v36 = __PAIR64__(v29, v25) + *(_QWORD *)(v27 + 72);
          v29 = HIDWORD(v36);
          v25 = v36;
          v37 = (__PAIR64__(v55, v32) + *(_QWORD *)(v27 + 80)) >> 32;
          v32 += *(_DWORD *)(v27 + 80);
          v55 = v37;
          v38 = *(_DWORD *)(v27 + 96);
          v26 = __PAIR64__(v62, v59) + *(_QWORD *)(v27 + 88);
          v39 = *(_DWORD *)(v27 + 100);
          v62 = HIDWORD(v26);
          v59 = v26;
          v40 = v60;
          v60 += v38;
          LODWORD(v27) = HIDWORD(v35);
          v61 = (__PAIR64__(v61, v40) + __PAIR64__(v39, v38)) >> 32;
          ++v28;
          HIDWORD(v27) += 112;
          v31 = qword_61F0E8;
          if ( v28 >= v1[40] )
            break;
          v30 = v1[41];
        }
        v27 = __PAIR64__(v55, v32);
      }
      else
      {
        HIDWORD(v26) = 0;
      }
      if ( v26 == -1i64 )
        __brkdiv0();
      LODWORD(v54) = _rt_sdiv64(v26 + 1, __SPAIR64__(v29, v25));
      HIDWORD(v54) = v41;
      v42 = __PAIR64__(v61, v60) + 1;
      if ( v60 == -1 && !HIDWORD(v42) )
        __brkdiv0();
      LODWORD(v43) = _rt_sdiv64(v42, v27);
      v44 = v43;
      if ( v43 <= v54 )
        goto LABEL_55;
      v45 = __PAIR64__(v62, v59) + __PAIR64__(v61, v60) + 1;
      if ( v59 + v60 == -1 && !HIDWORD(v45) )
        __brkdiv0();
      LODWORD(v46) = _rt_sdiv64(v45, qword_61F0B8 * (unsigned int)v1[40]);
      if ( v44 == v54 )
        __brkdiv0();
      LODWORD(v47) = _rt_sdiv64(v44 - v54, 100 * (v46 - v54));
      if ( v47 > 99 )
        LODWORD(v47) = 99;
      dword_61EED4 = v47;
      if ( (int)v47 < 1 )
LABEL_55:
        dword_61EED4 = 1;
      LODWORD(v48) = ReadTimeStampCounter();
      v49 = v48 - v63;
      result = (_DWORD *)((unsigned __int64)(v48 - v63) >> 32);
      LODWORD(qword_61F0D8) = v49;
      HIDWORD(qword_61F0D8) = result;
      qword_61F0A8 = __PAIR64__((unsigned int)result, v49) - qword_61F0D0 - __PAIR64__(v56, v57);
    }
  }
  return result;
}
