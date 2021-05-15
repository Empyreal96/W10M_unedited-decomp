// PopDecompressHiberBlocks 
 
int __fastcall PopDecompressHiberBlocks(__int64 a1, int a2, int a3, int a4)
{
  int v4; // r9
  int v5; // r6
  _DWORD *v6; // r7
  int v7; // r0
  unsigned int v8; // r1
  unsigned int v9; // r4
  int v10; // r5
  __int64 v11; // r0
  int v12; // r0
  int v13; // r5
  _BYTE *v14; // r4
  unsigned int *v15; // r0
  char *v16; // lr
  unsigned int v17; // r1
  int v18; // r5
  unsigned int v19; // t1
  unsigned int v20; // r2
  unsigned int v21; // r4
  int v22; // r9
  unsigned int v23; // r0
  __int64 v24; // r4
  int v25; // r1
  __int64 v26; // r0
  __int64 v27; // r0
  __int64 v28; // r4
  __int64 v29; // r0
  __int64 v30; // r0
  __int64 v31; // r4
  __int64 v32; // r0
  __int64 v33; // kr18_8
  __int64 v34; // r0
  void (__fastcall *v35)(_DWORD *); // r4
  int v36; // r0
  _DWORD *v37; // r5
  int v38; // r3
  unsigned int v39; // r1
  int v40; // r3
  int v41; // r2
  int v42; // r4
  unsigned int v43; // lr
  __int64 v44; // kr28_8
  unsigned __int64 v45; // r2
  bool v46; // cf
  int v47; // r1
  unsigned int v48; // r4
  unsigned int v49; // r2
  unsigned int v50; // kr08_4
  unsigned int v51; // r3
  int v53; // [sp+8h] [bp-110h]
  int v54; // [sp+18h] [bp-100h]
  unsigned int v55; // [sp+1Ch] [bp-FCh] BYREF
  __int64 v56; // [sp+20h] [bp-F8h]
  unsigned int v57; // [sp+28h] [bp-F0h]
  _DWORD *v58; // [sp+2Ch] [bp-ECh]
  void (__fastcall *v59)(_DWORD *); // [sp+30h] [bp-E8h]
  int v60; // [sp+34h] [bp-E4h]
  int v61; // [sp+38h] [bp-E0h] BYREF
  int v62; // [sp+3Ch] [bp-DCh]
  int v63; // [sp+40h] [bp-D8h]
  int v64[2]; // [sp+48h] [bp-D0h] BYREF
  char v65[8]; // [sp+50h] [bp-C8h] BYREF
  int v66; // [sp+58h] [bp-C0h] BYREF
  __int16 v67; // [sp+5Ch] [bp-BCh]
  __int16 v68; // [sp+5Eh] [bp-BAh]
  int v69; // [sp+64h] [bp-B4h]
  int v70; // [sp+68h] [bp-B0h]
  unsigned int v71; // [sp+6Ch] [bp-ACh]
  int v72; // [sp+70h] [bp-A8h]
  char v73; // [sp+74h] [bp-A4h] BYREF
  char v74[96]; // [sp+B8h] [bp-60h] BYREF
  __int64 varg_r0; // [sp+120h] [bp+8h]
  int varg_r2; // [sp+128h] [bp+10h]
  int varg_r3; // [sp+12Ch] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a2;
  varg_r3 = a3;
  v63 = a3;
  v4 = dword_61EF00;
  v54 = dword_61EF00;
  v5 = HIDWORD(a1);
  v6 = (_DWORD *)a1;
  v59 = (void (__fastcall *)(_DWORD *))a4;
  v60 = 0;
  v61 = 0;
  v62 = 0;
  while ( 1 )
  {
    PopHiberCheckForDebugBreak(a1);
    if ( !*(_QWORD *)&dword_61F108
      && v6[31] == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)
      && byte_61EED0 )
    {
      KeQueryPerformanceCounter(v64, 0);
      dword_61F108 = v64[0];
      dword_61F10C = v64[1];
    }
    if ( v6[31] == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)
      && !byte_61EED1
      && (!byte_61EED0 || (unsigned int)dword_61EEB8 > 0x640) )
    {
      v7 = ReadTimeStampCounter();
      v9 = v8;
      v10 = v7;
      if ( byte_64A430 )
      {
        BgDisplayProgressIndicator(1);
        byte_63760A = 1;
      }
      LODWORD(v11) = ReadTimeStampCounter();
      qword_61F0F0 += v11 - __PAIR64__(v9, v10);
    }
    v55 = 4;
    v12 = ConsumerPeekAndConsumeBuffer(v4, &v55, varg_r2, 4, v5);
    v13 = v12;
    v57 = v12;
    if ( !v12 )
      break;
    v14 = (_BYTE *)PopReadProducerConsumerBuffer(v12, 4, v65, v4, v5, 1);
    LODWORD(v56) = (unsigned __int8)*v14;
    HIDWORD(v56) = v13 + 4;
    v58 = v14;
    v15 = (unsigned int *)PopReadProducerConsumerBuffer(v13 + 4, 4 * v56, v74, v4, v5, 1);
    v16 = &v73;
    v17 = 0;
    v18 = (unsigned __int8)*v14;
    if ( *v14 )
    {
      do
      {
        v19 = *v15++;
        v20 = v19 >> 4;
        v21 = (v19 & 0xF) + (v19 >> 4) + 1;
        v17 += v21 - (v19 >> 4);
        while ( v20 < v21 )
        {
          *(_DWORD *)v16 = v20;
          v16 += 4;
          ++v20;
        }
        --v18;
      }
      while ( v18 );
      v14 = v58;
    }
    if ( v17 > v6[44] )
    {
      PopInternalAddToDumpFile((int)v6, 312, 0);
      KeBugCheckEx(160, 263, 10, (int)v6, 0);
    }
    v22 = v17 << 12;
    v66 = 0;
    v67 = 4 * ((((v17 << 12) + 4095) >> 12) + 7);
    v23 = *(_DWORD *)(v5 + 4);
    v68 = 0;
    v70 = 0;
    v71 = v17 << 12;
    v72 = 0;
    MmMapMemoryDumpMdlEx(v23, v17, (int)&v66, 1);
    v68 |= 1u;
    if ( ((*(_DWORD *)v14 >> 8) & 0x3FFFFF) == v22 )
    {
      LODWORD(v24) = ReadTimeStampCounter();
      HIDWORD(v24) = v25;
      ProducerConsumerCopyFromContextBuffer(v69, v22, v54, HIDWORD(v56) + 4 * v56);
      LODWORD(v26) = ReadTimeStampCounter();
      *(_QWORD *)(v5 + 56) += v26 - v24;
      LODWORD(v27) = ReadTimeStampCounter();
      v4 = v54;
      v28 = v27;
      ProducerConsumerBufferComplete(v54, v54 + 40, v57, v55);
      LODWORD(v29) = ReadTimeStampCounter();
      a1 = v29 - v28;
      *(_QWORD *)(v5 + 64) += a1;
    }
    else
    {
      LODWORD(v30) = ReadTimeStampCounter();
      v31 = v30;
      ProducerConsumerCopyFromContextBuffer(*(_DWORD *)(v5 + 12), (*v58 >> 8) & 0x3FFFFF, v54, HIDWORD(v56) + 4 * v56);
      LODWORD(v32) = ReadTimeStampCounter();
      v33 = *(_QWORD *)(v5 + 56);
      v56 = v32;
      *(_QWORD *)(v5 + 56) = v33 - v31 + v32;
      ProducerConsumerBufferComplete(v54, v54 + 40, v57, v55);
      LODWORD(v34) = ReadTimeStampCounter();
      v35 = v59;
      *(_QWORD *)(v5 + 64) += v34 - v56;
      if ( v35 )
      {
        v35(v6);
        v62 = HIDWORD(qword_61F0E0);
        v60 = qword_61F0E0;
      }
      v36 = ReadTimeStampCounter();
      v37 = v58;
      v38 = *(_DWORD *)(v5 + 8);
      v55 = v39;
      v53 = v38;
      v40 = (*v58 >> 8) & 0x3FFFFF;
      v41 = *v58 >> 30;
      v57 = v36;
      v42 = RtlDecompressBufferProgress(
              *((_WORD *)PopCompressMethodMap + v41),
              v69,
              v22,
              *(_DWORD *)(v5 + 12),
              v40,
              (int)&v61,
              v53,
              (int)v35,
              (int)v6);
      LODWORD(a1) = ReadTimeStampCounter();
      v43 = HIDWORD(a1);
      if ( v42 < 0 || v61 != v22 )
      {
        v6[30] = -1073741246;
        PopInternalAddToDumpFile((int)v6, 312, 0);
        KeBugCheckEx(160, 263, 10, (int)v6, 0);
      }
      v44 = *(_QWORD *)(v5 + 48) - __PAIR64__(v55, v57) + a1;
      *(_QWORD *)(v5 + 48) = v44;
      if ( v59 )
      {
        v45 = __PAIR64__(*(_DWORD *)(v5 + 52), v44) - qword_61F0E0;
        v46 = __CFADD__(v44 - qword_61F0E0, v60);
        v47 = v62;
        *(_DWORD *)(v5 + 48) = v44 - qword_61F0E0 + v60;
        *(_DWORD *)(v5 + 52) = v47 + v46 + HIDWORD(v45);
      }
      v48 = v56;
      HIDWORD(a1) = v5 + 8 * ((*v37 & 0xC0000000) >= 0x80000000);
      v49 = *(_DWORD *)(HIDWORD(a1) + 92);
      v50 = *(_DWORD *)(HIDWORD(a1) + 88);
      *(_DWORD *)(HIDWORD(a1) + 88) = v50 + v22;
      v51 = *(_DWORD *)(HIDWORD(a1) + 72);
      *(_DWORD *)(HIDWORD(a1) + 92) = (__PAIR64__(v49, v50) + (unsigned int)v22) >> 32;
      v4 = v54;
      *(_QWORD *)(HIDWORD(a1) + 72) = __PAIR64__(*(_DWORD *)(HIDWORD(a1) + 76), v51)
                                    - __PAIR64__(HIDWORD(v56), v48)
                                    + __PAIR64__(v43, a1);
    }
    if ( !v63 )
      return 0;
  }
  return -2147483614;
}
