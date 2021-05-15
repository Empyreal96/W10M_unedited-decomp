// sub_7F2D84 
 
void __fastcall sub_7F2D84(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, unsigned __int16 a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int *a25, int a26, int a27, int a28, int *a29, int a30, int a31, int a32, int *a33, int a34, int a35, int a36, int *a37, int a38, int a39, int a40, int *a41, int a42, int a43, int a44, int *a45, int a46, int a47, int a48, int *a49, int a50, int a51, int a52, int *a53, int a54, int a55, int a56, int a57, int a58, int a59, int a60, int a61, int a62, int a63)
{
  int v68; // r4
  int *v69; // r5
  _DWORD *v70; // r0
  char *v71; // r0
  _DWORD *v72; // r4
  int v73; // r1
  int v74; // r6
  __int64 v75; // kr00_8
  unsigned int v76; // r10
  unsigned int v77; // r8
  int v78; // r7
  unsigned int v79; // r9
  int v80; // r1
  int v81; // r3
  char *v82; // r7
  unsigned __int16 *v83; // r1
  int v84; // r6
  int v85; // r0
  int *v86; // r2
  int *v87; // r2
  int v88; // r0
  int *v89; // r2
  int *v90; // r3
  int *v91; // r2
  int *v92; // r2
  int *v93; // r3
  int *v94; // r2

  a19 = **(_DWORD **)(v68 + 60);
  a12 = 0;
  a13 = 0;
  a14 = 0;
  a15 = 0;
  a10 = 0;
  a11 = 0;
  a20 = 0;
  a21 = 0;
  a22 = 0;
  v70 = *(_DWORD **)(v68 + 60);
  a7 = 0;
  PoStoreRequester(v70, 0, (unsigned int *)&a7, 0);
  v71 = (char *)ExAllocatePoolWithTag(1, a7, 1346721364);
  v72 = v71;
  if ( v71 )
  {
    if ( PoStoreRequester(*(_DWORD **)(a8 + 60), v71, (unsigned int *)&a7, 0) >= 0 )
    {
      v74 = a19;
      if ( a19 )
      {
        a12 = v72[3];
        a15 = MmGetSessionIdEx(*(_DWORD *)(*(_DWORD *)(a8 + 60) + 4));
        v81 = v72[2];
        v76 = 0;
        v77 = 0;
        v82 = (char *)v72 + v81;
        if ( (_DWORD *)((char *)v72 + v81) && sub_455E68((unsigned __int16 *)((char *)v72 + v81), v80, &a7) >= 0 )
        {
          v77 = (unsigned int)v82;
          v76 = (unsigned __int16)(2 * a7);
        }
        if ( v74 == 2 )
        {
          RtlStringCbPrintfW(&STACK[0x1A0], 0x2Cu, (int)L"%d", v72[4]);
          v83 = (unsigned __int16 *)&STACK[0x1A0];
        }
        else
        {
          v83 = 0;
        }
        RtlInitUnicodeString((unsigned int)&a17, v83);
        v79 = a17;
        v78 = a18;
      }
      else
      {
        v75 = *((_QWORD *)v72 + 1);
        v76 = 0;
        v77 = 0;
        if ( (_DWORD *)((char *)v72 + v75) && sub_455E68((unsigned __int16 *)((char *)v72 + v75), v73, &a7) >= 0 )
        {
          v77 = (unsigned int)v72 + v75;
          v76 = (unsigned __int16)(2 * a7);
        }
        v78 = 0;
        v79 = 0;
        if ( (_DWORD *)((char *)v72 + HIDWORD(v75))
          && sub_455E68((unsigned __int16 *)((char *)v72 + HIDWORD(v75)), v73, &a7) >= 0 )
        {
          v79 = (unsigned __int16)(2 * a7);
          v78 = (int)v72 + HIDWORD(v75);
        }
      }
      v84 = a8;
      if ( !*(_DWORD *)(a8 + 60) )
        a14 = 1;
      if ( (*(_DWORD *)(a8 + 12) & 2) != 0 )
        a10 = 1;
      if ( (*(_DWORD *)(a8 + 12) & 1) != 0 )
        a21 = 1;
      if ( (*(_DWORD *)(a8 + 12) & 4) != 0 )
        a20 = 1;
      if ( (*(_DWORD *)(a8 + 12) & 8) != 0 )
        a11 = 1;
      if ( (*(_DWORD *)(a8 + 12) & 0x10) != 0 )
        a13 = 1;
      a25 = &a8;
      a26 = 0;
      a27 = 4;
      a28 = 0;
      a29 = &a19;
      a30 = 0;
      a31 = 4;
      a32 = 0;
      a33 = &a12;
      a34 = 0;
      a35 = 4;
      a36 = 0;
      a37 = &a15;
      a38 = 0;
      a39 = 4;
      a40 = 0;
      a41 = &a14;
      a42 = 0;
      a43 = 4;
      a44 = 0;
      a45 = &a10;
      a46 = 0;
      a47 = 4;
      a48 = 0;
      a49 = &a21;
      a50 = 0;
      a51 = 4;
      a52 = 0;
      a53 = &a20;
      a54 = 0;
      a55 = 4;
      a56 = 0;
      a57 = a8 + 28;
      a58 = 0;
      a59 = 4;
      a60 = 0;
      a61 = a8 + 24;
      a62 = 0;
      HIWORD(a9) = v76 >> 1;
      LOWORD(a9) = v79 >> 1;
      a63 = 4;
      a64 = 0;
      a65 = a8 + 32;
      a66 = 0;
      a67 = 4;
      a68 = 0;
      STACK[0x100] = (unsigned int)&a9 + 2;
      STACK[0x104] = 0;
      STACK[0x108] = 2;
      STACK[0x10C] = 0;
      STACK[0x110] = (unsigned int)&a9;
      STACK[0x114] = 0;
      STACK[0x118] = 2;
      v85 = 13;
      STACK[0x11C] = 0;
      if ( v76 >> 1 )
      {
        STACK[0x120] = v77;
        STACK[0x124] = 0;
        STACK[0x128] = 2 * (v76 >> 1);
        STACK[0x12C] = 0;
        v85 = 14;
      }
      if ( (unsigned __int16)(v79 >> 1) )
      {
        v86 = (int *)&(&a25)[4 * v85];
        v86[1] = 0;
        v86[2] = 2 * (unsigned __int16)(v79 >> 1);
        *v86 = v78;
        v86[3] = 0;
        ++v85;
      }
      v87 = (int *)&(&a25)[4 * v85];
      *v87 = (int)&a11;
      v87[1] = 0;
      v88 = v85 + 1;
      v87[2] = 4;
      v87[3] = 0;
      v89 = (int *)&(&a25)[4 * v88];
      *v89 = (int)&a13;
      v89[1] = 0;
      ++v88;
      v90 = (int *)&(&a25)[4 * v88];
      v89[2] = 4;
      v89[3] = 0;
      *v90 = (int)&a22;
      v90[1] = 0;
      v90[2] = 4;
      v90[3] = 0;
      ++v88;
      v91 = (int *)&(&a25)[4 * v88];
      *v91 = v84 + 36;
      v91[1] = 0;
      ++v88;
      v91[2] = 4;
      v91[3] = 0;
      v92 = (int *)&(&a25)[4 * v88];
      *v92 = v84 + 40;
      v92[1] = 0;
      v93 = (int *)&(&a25)[4 * v88 + 4];
      v92[2] = 4;
      v92[3] = 0;
      *v93 = (int)&a22;
      v93[1] = 0;
      v93[2] = 4;
      v93[3] = 0;
      if ( a23 )
        v94 = POP_ETW_EVENT_POWER_REQUEST_RUNDOWN;
      else
        v94 = POP_ETW_EVENT_CREATE_POWER_REQUEST;
      EtwWrite(*v69, v69[1], (int)v94, 0);
    }
    ExFreePoolWithTag((unsigned int)v72);
  }
  JUMPOUT(0x70B914);
}
