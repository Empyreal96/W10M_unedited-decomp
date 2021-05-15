// sub_7EE26C 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_7EE26C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, _QWORD *a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, __int64 a25)
{
  int v25; // r2
  int v26; // r1
  int v27; // r0
  unsigned int v28; // r4 OVERLAPPED
  int v29; // r0
  int v30; // r3
  int v31; // r2
  int v32; // r3
  int v33; // r4
  int v34; // r2
  int v35; // r3
  int v36; // r4
  int v37; // r1
  __int64 v38; // r2
  int v39; // r8
  int v40; // r9
  int v41; // r10
  int v42; // lr
  int v43; // r2
  int v44; // r4
  int v45; // r2
  __int64 v46; // kr00_8
  _DWORD *v47; // r5
  unsigned int v48; // r7
  _DWORD *v49; // r9
  int v50; // r10
  _BYTE *v51; // r3

  LODWORD(a25) = a1;
  a23 = v42;
  v43 = a20;
  v44 = a22;
  *(_DWORD *)(v39 + 56) = a19;
  *(_DWORD *)(v39 + 60) = v43;
  *(_DWORD *)(v39 + 64) = v41;
  *(_DWORD *)(v39 + 68) = v44;
  v45 = a24;
  v46 = a25;
  *(_DWORD *)(v39 + 72) = a23;
  *(_DWORD *)(v39 + 76) = v45;
  *(_QWORD *)(v39 + 80) = v46;
  EtwpUpdateFilterData(v39, v40, 0, 1);
  v47 = (_DWORD *)(v39 + 28);
  v48 = 0;
  if ( *(_DWORD *)(v39 + 28) != v39 + 28 )
  {
    v49 = *(_DWORD **)(v39 + 28);
    if ( v49 != v47 )
    {
      do
      {
        if ( a17 )
        {
          v50 = (int)(v49 - 2);
          v51 = v49 + 11;
        }
        else
        {
          v50 = (int)v49;
          v51 = (char *)v49 + 51;
        }
        v25 = (unsigned __int8)*v51;
        v49 = (_DWORD *)*v49;
        v26 = v25 & ~a10;
        *v51 = v26;
        if ( ((*(_BYTE *)(v50 + 50) & 8) == 0 || a11 == a13) && v26 != v25 )
        {
          EtwpComputeRegEntryEnableInfo(v50, (int)&a19);
          v27 = EtwpGetSchematizedFilterSize(v39);
          v28 = 120;
          a12 = v27;
          if ( v27 )
            v28 = v27 + 136;
          if ( v48 )
          {
            if ( *(_DWORD *)(v48 + 4) != v28 || RtlCompareMemory((unsigned __int8 *)(v48 + 72), (int)&a19, 32) != 32 )
            {
              EtwpUnreferenceDataBlock(v48);
              v48 = 0;
              a9 = 0;
            }
            if ( v48 )
              goto LABEL_25;
          }
          v29 = EtwpAllocDataBlock(v28, 0, &a9);
          v48 = (unsigned int)a9;
          if ( v29 >= 0 )
          {
            v30 = 3;
            *a9 = *(_QWORD *)(&v28 - 1);
            v31 = *(_DWORD *)(*(_DWORD *)(v50 + 16) + 16);
            v32 = *(_DWORD *)(*(_DWORD *)(v50 + 16) + 20);
            v33 = *(_DWORD *)(*(_DWORD *)(v50 + 16) + 24);
            *(_DWORD *)(v48 + 40) = *(_DWORD *)(*(_DWORD *)(v50 + 16) + 12);
            *(_DWORD *)(v48 + 44) = v31;
            *(_DWORD *)(v48 + 48) = v32;
            *(_DWORD *)(v48 + 52) = v33;
            v34 = a20;
            v35 = a21;
            v36 = a22;
            *(_DWORD *)(v48 + 72) = a19;
            *(_DWORD *)(v48 + 76) = v34;
            *(_DWORD *)(v48 + 80) = v35;
            *(_DWORD *)(v48 + 84) = v36;
            v37 = a24;
            v38 = a25;
            *(_DWORD *)(v48 + 88) = a23;
            *(_DWORD *)(v48 + 92) = v37;
            *(_QWORD *)(v48 + 96) = v38;
            *(_DWORD *)(v48 + 112) = *(_BYTE *)(v39 + 51) & 1;
            LODWORD(v38) = *(_DWORD *)(v39 + 40);
            LOWORD(a15) = *(_WORD *)(v39 + 48);
            HIWORD(a15) = *(unsigned __int8 *)(v39 + 50);
            *(_DWORD *)(v48 + 104) = a15;
            *(_DWORD *)(v48 + 108) = v38;
            LODWORD(v38) = a12;
            if ( a12 )
            {
              HIDWORD(v38) = 0x80000000;
              *(_QWORD *)(v48 + 128) = v38;
              *(_DWORD *)(v48 + 120) = 136;
              *(_DWORD *)(v48 + 124) = 0;
              EtwpCopySchematizedFilters(v48 + 136, v39, *(unsigned __int8 *)(v50 + 51));
              *(_DWORD *)(v48 + 116) = 1;
            }
            else
            {
              *(_DWORD *)(v48 + 116) = 0;
            }
            v47 = (_DWORD *)(v39 + 28);
          }
          if ( v48 )
LABEL_25:
            EtwpSendDataBlock(v50, v48);
        }
      }
      while ( v49 != v47 );
      if ( v48 )
        EtwpUnreferenceDataBlock(v48);
    }
  }
  JUMPOUT(0x77F04C);
}
