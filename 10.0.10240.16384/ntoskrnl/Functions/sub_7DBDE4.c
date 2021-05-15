// sub_7DBDE4 
 
void __fastcall sub_7DBDE4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, __int64 a13, int a14, int a15, int a16, int a17, __int64 a18, int a19, int a20, int a21, int a22, void *a23, int a24, int a25, int a26, void *a27, int a28, int a29, int a30, void *a31, int a32, int a33, int a34, __int64 *a35, int a36, int a37, int a38, __int64 *a39, int a40, int a41, int a42, int *a43, int a44, int a45, int a46, int *a47, int a48, int a49, int a50, int *a51, int a52, int a53, int a54, int *a55, int a56, int a57, int a58, int *a59, int a60, int a61, int a62, int a63)
{
  _DWORD *v66; // r6
  _DWORD *v67; // r7
  _DWORD *v68; // r8
  int *v69; // r9
  unsigned int v70; // r4
  __int64 v71; // r0
  int v72; // r3
  void *v73; // r1
  int v74; // r2
  void *v75; // r3
  int v76; // r2
  void *v77; // r3
  int v78; // r2
  int v79; // r3
  int v80; // r3
  int v81; // r2
  int v82; // r4
  unsigned int v83; // r8
  int v84; // r3
  int *v85; // r2
  int v86; // r4
  int v87; // r1
  int *v88; // r2
  int v89; // r4
  unsigned int v90; // r5
  int v91; // r0
  int *v92; // r2
  int v93; // r3

  v70 = STACK[0x168];
  if ( v68 )
  {
    a13 = RtlConvertLuidToUlonglong((int)(v68 + 4));
    v71 = RtlConvertLuidToUlonglong((int)(v68 + 6));
    v72 = v68[42];
    a18 = v71;
    a12 = v72;
    a10 = v68[43];
    a11 = v68[44];
    if ( (a11 & 0x20) == 0 )
      v70 = v68[48];
  }
  else
  {
    a13 = 0i64;
    a18 = 0i64;
    a11 = 0;
    a12 = 0;
    a10 = 0;
  }
  a19 = SepGetSidManagementActionName(a3, &a7);
  a20 = 0;
  a21 = a7;
  a22 = 0;
  v73 = &unk_6534E4;
  v74 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 380);
  if ( v74 && *(_WORD *)v74 )
  {
    v75 = *(void **)(v74 + 4);
    v76 = *(unsigned __int16 *)(v74 + 2);
  }
  else
  {
    v75 = &unk_6534E4;
    v76 = 2;
  }
  a23 = v75;
  a24 = 0;
  a25 = v76;
  a26 = 0;
  if ( v70 && *(_WORD *)(v70 + 36) )
  {
    v77 = *(void **)(v70 + 40);
    v78 = *(unsigned __int16 *)(v70 + 38);
  }
  else
  {
    v77 = &unk_6534E4;
    v78 = 2;
  }
  a27 = v77;
  a28 = 0;
  a29 = v78;
  a30 = 0;
  if ( v70 && *(_WORD *)(v70 + 44) )
  {
    v73 = *(void **)(v70 + 48);
    v79 = *(unsigned __int16 *)(v70 + 46);
  }
  else
  {
    v79 = 2;
  }
  a33 = v79;
  a34 = 0;
  a35 = &a13;
  a36 = 0;
  a37 = 8;
  a38 = 0;
  a39 = &a18;
  a40 = 0;
  a41 = 8;
  a42 = 0;
  a43 = &a12;
  a44 = 0;
  a45 = 4;
  a46 = 0;
  a47 = &a10;
  a48 = 0;
  a49 = 4;
  a50 = 0;
  a51 = &a11;
  a52 = 0;
  a53 = 4;
  a54 = 0;
  a31 = v73;
  a32 = 0;
  if ( v67 )
  {
    a14 = v67[1];
    v80 = a14 >> 31;
  }
  else
  {
    v80 = 0;
    a14 = 0;
  }
  a15 = v80;
  a55 = &a14;
  a56 = 0;
  a57 = 8;
  a58 = 0;
  if ( v67 )
    v81 = v67[2];
  else
    v81 = 0;
  a59 = &a9;
  a60 = 0;
  a61 = 4;
  v82 = 11;
  a62 = 0;
  v83 = 0;
  a9 = v81;
  if ( v67 && v81 )
  {
    a63 = SepGetSidValuesDump(v67, &a8);
    a64 = 0;
    v83 = a63;
    a65 = a8;
    a66 = 0;
    v82 = 12;
  }
  if ( v66 )
  {
    a16 = v66[1];
    v84 = a16 >> 31;
  }
  else
  {
    v84 = 0;
    a16 = 0;
  }
  a17 = v84;
  v85 = &a19 + 4 * v82;
  *v85 = (int)&a16;
  v86 = v82 + 1;
  v85[1] = 0;
  v85[2] = 8;
  v85[3] = 0;
  if ( !v66 || v67 == v66 )
    v87 = 0;
  else
    v87 = v66[2];
  v88 = &a19 + 4 * v86;
  *v88 = (int)&a7;
  v88[1] = 0;
  v89 = v86 + 1;
  v90 = 0;
  v88[2] = 4;
  v88[3] = 0;
  a7 = v87;
  if ( v66 && v87 )
  {
    v91 = SepGetSidValuesDump(v66, &a8);
    v92 = &a19 + 4 * v89;
    v93 = a8;
    v90 = v91;
    *v92 = v91;
    v92[1] = 0;
    v92[2] = v93;
    v92[3] = 0;
  }
  EtwWrite(*v69, v69[1], (int)TokenSidManagementLog, 0);
  if ( v83 )
    ExFreePoolWithTag(v83);
  if ( v90 )
    ExFreePoolWithTag(v90);
  JUMPOUT(0x6E6E1C);
}
