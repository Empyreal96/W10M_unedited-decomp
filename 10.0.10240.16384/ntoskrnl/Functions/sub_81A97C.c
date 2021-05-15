// sub_81A97C 
 
void __fastcall sub_81A97C(int a1, int a2, int a3, int a4, int a5, int a6, char a7, int a8, int a9, int a10, BOOL a11, unsigned __int16 *a12, int a13, int a14, int a15, int a16, char *a17, int a18, int a19, int a20, BOOL *a21, int a22, int a23, int a24, int *a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int *a33, int a34, int a35, int a36, int *a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, int a47, int a48, unsigned __int16 *a49, int a50, unsigned int a51, int a52, unsigned __int16 *a53, int a54, int a55, int a56, int a57, int a58, int a59, int a60)
{
  _DWORD *v60; // r4
  int v61; // r6
  __int64 *v62; // r8
  int v63; // r9
  int v64; // r0
  unsigned int v65; // r3
  int v66; // r5
  int v67; // r7
  unsigned int v68; // r3
  int v69; // r2
  unsigned __int16 *v70; // r10
  unsigned __int16 v71; // r0
  char v72; // r3
  int v73; // r3
  int v74; // r2
  __int64 v75; // r0

  v64 = IoGetDeviceAttachmentBaseRef(*(_DWORD *)(*(_DWORD *)(v61 + 16) + 24));
  v66 = v64;
  if ( v64 )
  {
    v65 = *(_DWORD *)(v64 + 176);
    v67 = *(_DWORD *)(v65 + 20);
  }
  else
  {
    v67 = 0;
  }
  if ( v67 )
  {
    PoStoreDiagnosticContext(*(_DWORD **)(v61 + 12), 0, (unsigned int *)&a8, v65);
    v60 = (_DWORD *)ExAllocatePoolWithTag(1, a8, 1346721364);
    if ( v60 )
    {
      if ( PoStoreDiagnosticContext(*(_DWORD **)(v61 + 12), (int)v60, (unsigned int *)&a8, v68) >= 0 )
      {
        v69 = v60[5];
        v70 = (unsigned __int16 *)((char *)v60 + v60[2]);
        a12 = (unsigned __int16 *)((char *)v60 + v60[3]);
        a13 = (int)v60 + v69;
        a14 = (unsigned __int16)(a8 - v69);
        HIWORD(a9) = a8 - v69;
        v71 = wcslen(v70);
        a8 = v71;
        LOWORD(a10) = v71;
        LOWORD(a9) = wcslen(a12);
        HIWORD(a10) = *(_WORD *)(v67 + 160) >> 1;
        a11 = *(_BYTE *)(v61 + 9) != 0;
        v72 = *(_BYTE *)(v61 + 8);
        a15 = v61;
        a7 = v72;
        a17 = &a7;
        a18 = 0;
        a19 = 1;
        a20 = 0;
        a21 = &a11;
        a22 = 0;
        a23 = 4;
        a24 = 0;
        a25 = &a15;
        a26 = 0;
        a27 = 4;
        a28 = 0;
        a29 = (int)&a10 + 2;
        a30 = 0;
        a31 = 2;
        a32 = 0;
        a33 = &a10;
        a34 = 0;
        a35 = 2;
        a36 = 0;
        a37 = &a9;
        a38 = 0;
        a39 = 2;
        a40 = 0;
        a41 = (int)&a9 + 2;
        a42 = 0;
        a43 = 2;
        a44 = 0;
        v73 = *(_DWORD *)(v67 + 164);
        v74 = *(unsigned __int16 *)(v67 + 160);
        a49 = v70;
        a45 = v73;
        a46 = 0;
        a47 = v74;
        a48 = 0;
        a50 = 0;
        a51 = 2 * a8;
        a52 = 0;
        a53 = a12;
        a54 = 0;
        a55 = 2 * (unsigned __int16)a9;
        a56 = 0;
        v75 = *v62;
        a57 = a13;
        a58 = 0;
        a59 = a14;
        a60 = 0;
        EtwWrite(v75, SHIDWORD(v75), v63, 0);
      }
    }
  }
  if ( v66 )
    ObfDereferenceObject(v66);
  if ( v60 )
    ExFreePoolWithTag((unsigned int)v60);
  JUMPOUT(0x7B7EF2);
}
