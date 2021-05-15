// PopRequestWrite 
 
BOOL __fastcall PopRequestWrite(int a1, int a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r10
  int v7; // r5
  int v8; // r3
  __int64 v9; // r0
  unsigned int v10; // r9
  __int64 v11; // r0
  __int64 v12; // kr10_8
  __int64 v13; // kr18_8
  int v14; // r0
  unsigned int v15; // r1
  unsigned int v16; // r5
  int v17; // r4
  __int64 v18; // r0
  int v19; // r3
  int v20; // r4
  unsigned __int64 v21; // r2
  __int64 v22; // r2
  unsigned int v23; // r4
  unsigned int v24; // r9
  unsigned int v25; // kr28_4
  int v26; // r0
  int v27; // r5
  int v28; // r3
  unsigned int v29; // r0
  __int64 v30; // r2
  int v31; // r1
  __int64 v32; // kr30_8
  int v33; // r2
  int v34; // r3
  unsigned int v35; // r8
  int *v36; // r4
  int v37; // r0
  unsigned int v38; // r1
  unsigned int v39; // r9
  int v40; // r4
  __int64 v41; // r0
  int v42; // r0
  unsigned int v43; // r1
  int v44; // r4
  __int64 v45; // r0
  int v46; // r1
  unsigned int v48; // [sp+8h] [bp-58h]
  unsigned int v50; // [sp+10h] [bp-50h]
  int v51; // [sp+14h] [bp-4Ch]
  int v52; // [sp+1Ch] [bp-44h] BYREF
  unsigned __int64 v53; // [sp+20h] [bp-40h] BYREF
  int v54[2]; // [sp+28h] [bp-38h] BYREF
  unsigned __int64 v55; // [sp+30h] [bp-30h] BYREF
  __int64 v56; // [sp+38h] [bp-28h] BYREF
  int varg_r0; // [sp+68h] [bp+8h]
  int varg_r1; // [sp+6Ch] [bp+Ch]
  int varg_r2; // [sp+70h] [bp+10h]
  int varg_r3; // [sp+74h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = *(_DWORD *)(a1 + 200);
  v48 = 0;
  v51 = 0;
  HIDWORD(v56) = 0;
  v6 = 0;
LABEL_2:
  while ( 2 )
  {
    v7 = a2;
    while ( 1 )
    {
      v8 = *(_DWORD *)(a1 + 204);
      if ( !v8 )
        break;
      if ( v8 == 1 )
      {
        v14 = ReadTimeStampCounter();
        v16 = v15;
        v6 = v14;
        v48 = v15;
        v17 = (*(int (__fastcall **)(int, int, int, _DWORD))(*(_DWORD *)(a1 + 108) + 84))(2, a1 + 240, v4, 0);
        LODWORD(v18) = ReadTimeStampCounter();
        qword_61EFA8 += v18 - __PAIR64__(v16, v6);
        if ( v17 < 0 )
        {
          PopInternalAddToDumpFile(a1, 312, 0);
          PopInternalAddToDumpFile(*(_DWORD *)(a1 + 108), 256, 0);
          KeBugCheckEx(160, 266, 10, a1, v17);
        }
        if ( v17 != 259 )
        {
          *(_DWORD *)(a1 + 204) = 2;
          goto LABEL_2;
        }
        return 0;
      }
      LODWORD(v9) = ReadTimeStampCounter();
      v10 = HIDWORD(v9);
      v48 = HIDWORD(v9);
      v6 = v9;
      qword_61EFA0 = qword_61EFA0 - *(_QWORD *)(a1 + 208) + v9;
      v7 = a2;
      ProducerConsumerBufferComplete(a2, a2 + 40, *(_DWORD *)(a1 + 256), *(_DWORD *)(a1 + 232));
      LODWORD(v11) = ReadTimeStampCounter();
      qword_61EFC8 += v11 - __PAIR64__(v10, v6);
      qword_61F158 += *(_QWORD *)(a1 + 232);
      dword_61F160 += (unsigned int)(*(_DWORD *)(a1 + 224) + 4095) >> 12;
      v12 = *(_QWORD *)(a1 + 224);
      *(_QWORD *)(a1 + 248) += v12;
      v13 = *(_QWORD *)(a1 + 216) + v12;
      *(_DWORD *)(a1 + 224) = 0;
      *(_DWORD *)(a1 + 228) = 0;
      *(_DWORD *)(a1 + 204) = 0;
      *(_QWORD *)(a1 + 216) = v13;
    }
    v19 = PopWatchdogTimerCount;
    if ( (PopWatchdogTimerCount & 0x1F) == 0 )
    {
      ((void (__cdecl *)())off_617B08)();
      v19 = PopWatchdogTimerCount;
    }
    PopWatchdogTimerCount = v19 + 1;
    PopGetIoLocation(v54, *(_DWORD **)(a1 + 104), *(_QWORD *)(a1 + 248), &v55);
    v20 = *(_DWORD *)(a1 + 272);
    LODWORD(v21) = *(_DWORD *)(a1 + 216);
    *(_DWORD *)(a1 + 240) = v54[0];
    *(_DWORD *)(a1 + 244) = v54[1];
    if ( !(v20 << 12) )
      __brkdiv0();
    HIDWORD(v21) = *(_DWORD *)(a1 + 220);
    _rt_udiv64((unsigned int)(v20 << 12), v21);
    v25 = (v20 << 12) - v22;
    v23 = ((unsigned __int64)(unsigned int)(v20 << 12) - v22) >> 32;
    v24 = v25;
    v53 = __PAIR64__(v23, v25);
    v50 = v23;
    if ( __PAIR64__(v23, v25) >= v55 )
    {
      v23 = HIDWORD(v55);
      v50 = HIDWORD(v55);
      v24 = v55;
      v53 = v55;
    }
    v26 = ConsumerGetBuffer(v7, (unsigned int *)&v53, varg_r2, v55);
    v27 = v26;
    v28 = HIDWORD(v53);
    if ( v26 )
    {
      *(_DWORD *)(a1 + 256) = v26;
      v29 = v53;
      LODWORD(v30) = *(_DWORD *)(a1 + 248);
      *(_DWORD *)(a1 + 232) = v53;
      *(_DWORD *)(a1 + 236) = v28;
      HIDWORD(v30) = *(_DWORD *)(a1 + 252);
      v31 = dword_61EEAC;
      v32 = v30 + __PAIR64__(v23, v24);
      if ( (v30 + __PAIR64__(v23, v24)) >> 32 > (unsigned int)dword_61EEAC
        || HIDWORD(v32) >= dword_61EEAC && (v31 = dword_61EEA8, (unsigned int)v32 > dword_61EEA8) )
      {
        HIDWORD(v30) = *(_DWORD *)(a1 + 116);
        if ( HIDWORD(v30) == 4 || HIDWORD(v30) == 5 )
        {
          v51 = PopGetRemainingHibernateRangeDataSize((_DWORD *)a1, v31, v30, SHIDWORD(v30));
          HIDWORD(v56) = v46;
        }
        v52 = MmGetNumberOfPhysicalPages(0);
        IoAddTriageDumpDataBlock((int)&v52, 4);
        KeBugCheckEx(160, 11, dword_61EEA8, *(_DWORD *)(a1 + 116), v51);
      }
      PopHiberChecksumHiberFileData(a1, 1, v30, HIDWORD(v30), v27, v29);
      v33 = v27 & 0xFFF;
      *(_DWORD *)v4 = 0;
      *(_WORD *)(v4 + 4) = 4 * (((v33 + v24 + 4095) >> 12) + 7);
      *(_DWORD *)(v4 + 16) = v27 & 0xFFFFF000;
      *(_DWORD *)(v4 + 20) = v24;
      v34 = 1;
      *(_WORD *)(v4 + 6) = 1;
      *(_DWORD *)(v4 + 24) = v33;
      *(_DWORD *)(v4 + 12) = v27;
      if ( (v24 + v33 + 4095) >> 12 )
      {
        v35 = (v24 + v33 + 4095) >> 12;
        v36 = (int *)(v4 + 28);
        do
        {
          MmGetPhysicalAddress((int)&v56, v27, v33, v34);
          v33 = v56;
          v27 += 4096;
          v34 = v56 >> 12;
          *v36++ = v34;
          --v35;
        }
        while ( v35 );
      }
      *(_DWORD *)(a1 + 224) = v24;
      *(_DWORD *)(a1 + 228) = v50;
      if ( *(_BYTE *)(a1 + 260) )
      {
        v37 = ReadTimeStampCounter();
        v39 = v38;
        v48 = v38;
        v6 = v37;
        v40 = (*(int (__fastcall **)(int, int, int, _DWORD))(*(_DWORD *)(a1 + 108) + 84))(1, a1 + 240, v4, 0);
        LODWORD(v41) = ReadTimeStampCounter();
        qword_61EFA8 += v41 - __PAIR64__(v39, v6);
        if ( v40 == -1073741637 )
        {
          *(_BYTE *)(a1 + 260) = 0;
        }
        else
        {
          if ( v40 < 0 || PopSimulateHiberBugcheck == 2 )
          {
            PopInternalAddToDumpFile(a1, 312, 0);
            PopInternalAddToDumpFile(*(_DWORD *)(a1 + 108), 256, 0);
            KeBugCheckEx(160, 266, 10, a1, v40);
          }
          if ( v40 == 259 )
            *(_DWORD *)(a1 + 204) = 1;
          else
            *(_DWORD *)(a1 + 204) = 2;
        }
      }
      else
      {
        v39 = v48;
      }
      if ( !*(_BYTE *)(a1 + 260) )
      {
        v42 = ReadTimeStampCounter();
        v39 = v43;
        v48 = v43;
        v6 = v42;
        v44 = (*(int (__fastcall **)(int, int))(*(_DWORD *)(a1 + 108) + 48))(a1 + 240, v4);
        LODWORD(v45) = ReadTimeStampCounter();
        qword_61EFA8 += v45 - __PAIR64__(v39, v6);
        if ( v44 < 0 )
        {
          PopInternalAddToDumpFile(a1, 312, 0);
          PopInternalAddToDumpFile(*(_DWORD *)(a1 + 108), 256, 0);
          KeBugCheckEx(160, 266, 10, a1, v44);
        }
        *(_DWORD *)(a1 + 204) = 2;
      }
      *(_DWORD *)(a1 + 208) = v6;
      *(_DWORD *)(a1 + 212) = v39;
      continue;
    }
    break;
  }
  return !v53;
}
