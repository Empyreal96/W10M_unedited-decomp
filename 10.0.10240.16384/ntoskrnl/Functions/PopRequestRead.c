// PopRequestRead 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopRequestRead(__int64 a1, int a2, int a3)
{
  __int64 v3; // r2
  _DWORD *v4; // r5
  int v5; // r9
  int v6; // r8
  int v7; // r3
  __int64 v8; // r0
  __int64 v9; // r6
  __int64 v10; // r0
  __int64 v11; // kr08_8
  __int64 v12; // kr10_8
  __int64 v13; // kr18_8
  int v14; // r0
  unsigned int v15; // r1
  unsigned int v16; // r6
  int v17; // r7
  int v18; // r4
  int v19; // r3
  int v20; // r4
  unsigned __int64 v21; // r2
  __int64 v22; // r2
  unsigned int v23; // r4 OVERLAPPED
  unsigned int v24; // r6
  unsigned __int64 v25; // r2
  int v26; // r5
  int v27; // r2
  int v28; // r3
  int v29; // r3
  unsigned int v30; // r10
  int *v31; // r7
  BOOL v32; // r7
  __int64 v33; // r0
  int v34; // r3
  int v35; // r5
  __int64 v36; // r0
  int v37; // r3
  int v38; // r2
  unsigned int v39; // r3
  bool v40; // cf
  int v41; // r3
  unsigned int v42; // r2
  int v43; // r3
  unsigned __int64 v44; // kr40_8
  int v45; // r3
  _DWORD *v47; // [sp+8h] [bp-48h]
  int v48[2]; // [sp+18h] [bp-38h] BYREF
  unsigned __int64 v49; // [sp+20h] [bp-30h] BYREF
  __int64 var28[7]; // [sp+28h] [bp-28h] BYREF
  int varg_r2; // [sp+60h] [bp+10h]
  int varg_r3; // [sp+64h] [bp+14h]

  var28[6] = a1;
  varg_r2 = a2;
  varg_r3 = a3;
  v3 = *(_QWORD *)(a1 + 264);
  v4 = (_DWORD *)HIDWORD(a1);
  v5 = *(_DWORD *)(a1 + 200);
  v47 = (_DWORD *)HIDWORD(a1);
  v6 = a1;
  if ( v3 )
  {
    while ( 1 )
    {
      v7 = *(_DWORD *)(v6 + 204);
      if ( v7 )
        break;
      PopHiberCheckForDebugBreak(a1, SHIDWORD(a1), v3, 0);
      PopGetIoLocation(v48, *(_DWORD **)(v6 + 104), *(_QWORD *)(v6 + 248), &v49);
      v20 = *(_DWORD *)(v6 + 272);
      LODWORD(v21) = *(_DWORD *)(v6 + 216);
      *(_DWORD *)(v6 + 240) = v48[0];
      *(_DWORD *)(v6 + 244) = v48[1];
      if ( !(v20 << 12) )
        __brkdiv0();
      HIDWORD(v21) = *(_DWORD *)(v6 + 220);
      _rt_udiv64((unsigned int)(v20 << 12), v21);
      v24 = ((unsigned __int64)(unsigned int)(v20 << 12) - v22) >> 32;
      v23 = (v20 << 12) - v22;
      if ( __PAIR64__(v24, v23) >= v49 )
      {
        v24 = HIDWORD(v49);
        v23 = v49;
      }
      v25 = *(_QWORD *)(v6 + 264);
      if ( __PAIR64__(v24, v23) < v25 )
        LODWORD(v25) = v23;
      LODWORD(a1) = ProducerGetBuffer(v4, v23, v25, varg_r2);
      v26 = a1;
      if ( !(_DWORD)a1 )
        return a1;
      v27 = a1 & 0xFFF;
      *(_DWORD *)(v6 + 256) = a1;
      *(_DWORD *)v5 = 0;
      *(_WORD *)(v5 + 4) = 4 * (((v27 + v23 + 4095) >> 12) + 7);
      v28 = a1 & 0xFFFFF000;
      *(_QWORD *)(v5 + 16) = *(_QWORD *)(&v23 - 1);
      v29 = 1;
      *(_WORD *)(v5 + 6) = 1;
      *(_DWORD *)(v5 + 24) = v27;
      *(_DWORD *)(v5 + 12) = a1;
      if ( (v27 + v23 + 4095) >> 12 )
      {
        v30 = (v27 + v23 + 4095) >> 12;
        v31 = (int *)(v5 + 28);
        do
        {
          MmGetPhysicalAddress((int)var28, v26, v27, v29);
          v27 = var28[0];
          v26 += 4096;
          v29 = var28[0] >> 12;
          *v31++ = v29;
          --v30;
        }
        while ( v30 );
      }
      v32 = *(_BYTE *)(v6 + 260) != 0;
      LODWORD(v33) = ReadTimeStampCounter();
      v34 = *(_DWORD *)(v6 + 108);
      *(_QWORD *)(v6 + 208) = v33;
      v35 = (*(int (__fastcall **)(BOOL, int, int))(v34 + 108))(v32, v6 + 240, v5);
      if ( v35 == -1073741637 )
      {
        if ( !v32 )
          goto LABEL_36;
        *(_BYTE *)(v6 + 260) = 0;
        LODWORD(v36) = ReadTimeStampCounter();
        v37 = *(_DWORD *)(v6 + 108);
        *(_QWORD *)(v6 + 208) = v36;
        v35 = (*(int (__fastcall **)(_DWORD, int, int))(v37 + 108))(0, v6 + 240, v5);
      }
      if ( v35 < 0 || PopSimulateHiberBugcheck == 8 )
      {
LABEL_36:
        PopInternalAddToDumpFile(*(_DWORD *)(v6 + 108), 256, 0);
        KeBugCheckEx(160, 266, 10, v6, v35);
      }
      LODWORD(a1) = ReadTimeStampCounter();
      v38 = *(_DWORD *)(v6 + 212);
      v39 = *(_DWORD *)(v6 + 208);
      v40 = (unsigned int)a1 >= v39;
      LODWORD(a1) = a1 - v39;
      v41 = qword_61F0E0;
      LODWORD(qword_61F0E0) = qword_61F0E0 + a1;
      HIDWORD(qword_61F0E0) += HIDWORD(a1) - (v38 + !v40) + __CFADD__(v41, (_DWORD)a1);
      v44 = *(_QWORD *)(v6 + 264);
      v42 = HIDWORD(v44);
      v43 = v44;
      if ( __PAIR64__(v24, v23) < v44 )
      {
        v43 = v23;
        v42 = v24;
      }
      *(_DWORD *)(v6 + 232) = v43;
      *(_DWORD *)(v6 + 236) = v42;
      *(_DWORD *)(v6 + 224) = v23;
      *(_DWORD *)(v6 + 228) = v24;
      if ( !v32 || !v35 )
      {
        v4 = v47;
LABEL_31:
        v45 = 2;
        goto LABEL_32;
      }
      v4 = v47;
      v45 = 1;
LABEL_32:
      *(_DWORD *)(v6 + 204) = v45;
LABEL_33:
      v3 = *(_QWORD *)(v6 + 264);
      if ( !v3 )
        return a1;
    }
    if ( v7 != 1 )
    {
      PopHiberChecksumHiberFileData(
        v6,
        0,
        *(_DWORD *)(v6 + 248),
        *(_DWORD *)(v6 + 252),
        *(_DWORD *)(v6 + 256),
        *(_DWORD *)(v6 + 232));
      LODWORD(v8) = ReadTimeStampCounter();
      v9 = v8;
      qword_61F0B8 = qword_61F0B8 - *(_QWORD *)(v6 + 208) + v8;
      v4 = v47;
      ProducerConsumerBufferComplete(v47, v47 + 6, *(_DWORD *)(v6 + 256), *(_DWORD *)(v6 + 232));
      LODWORD(v10) = ReadTimeStampCounter();
      qword_61F0E8 += v10 - v9;
      v11 = *(_QWORD *)(v6 + 264) - *(_QWORD *)(v6 + 232);
      *(_QWORD *)(v6 + 264) = v11;
      if ( !(*(_DWORD *)(v6 + 268) | (unsigned int)v11) )
      {
        v47[6] = v47[8];
        v47[7] = v47[9];
      }
      v12 = *(_QWORD *)(v6 + 224);
      a1 = HIDWORD(v12);
      *(_QWORD *)(v6 + 248) += v12;
      v13 = *(_QWORD *)(v6 + 216) + v12;
      *(_DWORD *)(v6 + 224) = 0;
      *(_DWORD *)(v6 + 228) = 0;
      *(_DWORD *)(v6 + 204) = 0;
      *(_QWORD *)(v6 + 216) = v13;
      goto LABEL_33;
    }
    ++qword_61F0C8;
    v14 = ReadTimeStampCounter();
    v16 = v15;
    v17 = v14;
    v18 = (*(int (__fastcall **)(int, int, int))(*(_DWORD *)(v6 + 108) + 108))(2, v6 + 240, v5);
    if ( v18 < 0 )
    {
      PopInternalAddToDumpFile(v6, 312, 0);
      PopInternalAddToDumpFile(*(_DWORD *)(v6 + 108), 256, 0);
      KeBugCheckEx(160, 266, 10, v6, v18);
    }
    LODWORD(a1) = ReadTimeStampCounter();
    v19 = qword_61F0E0;
    HIDWORD(a1) = (a1 - __PAIR64__(v16, v17)) >> 32;
    LODWORD(qword_61F0E0) = qword_61F0E0 + a1 - v17;
    HIDWORD(qword_61F0E0) += HIDWORD(a1) + __CFADD__(v19, a1 - v17);
    if ( v18 == 259 )
      return a1;
    goto LABEL_31;
  }
  return a1;
}
