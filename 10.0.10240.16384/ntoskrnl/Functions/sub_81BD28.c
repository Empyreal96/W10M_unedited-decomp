// sub_81BD28 
 
int __fastcall sub_81BD28(int a1, int a2, int a3, int a4, unsigned __int16 *a5, unsigned __int16 *a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, __int16 *a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, int a47, unsigned __int16 *a48, int a49, int a50, int a51, int a52, int a53, int a54, int a55, int a56, int a57, unsigned __int16 *a58)
{
  int v58; // r4
  int v59; // r6
  int v60; // r8
  int v61; // r5
  int v62; // r10
  int v63; // r4
  int v64; // r9
  int v65; // r3
  int v66; // r3
  int v67; // r0
  int (__fastcall *v69)(int); // [sp-4h] [bp-4h]

  v60 = *(_DWORD *)(v58 + 176);
  SeCaptureSubjectContext(&a9, a2, a3, a4);
  v61 = a9;
  if ( !a9 )
  {
    v61 = a11;
    if ( !a11 )
      goto LABEL_11;
  }
  v62 = **(_DWORD **)(v61 + 148);
  v63 = SeLocateProcessImageName(v58);
  if ( v63 >= 0 )
  {
    v64 = *(_DWORD *)(v59 + 176);
    v63 = SeLocateProcessImageName(v59);
    if ( v63 >= 0 )
    {
      a13 = 5;
      a17 = 524421;
      a14 = 4696;
      a19 = 4;
      v65 = *(unsigned __int8 *)(v62 + 1);
      a23 = v62;
      a20 = 4 * (v65 + 2);
      a24 = 1;
      a25 = 24;
      a41 = v64;
      a48 = a6;
      a28 = &SeSubsystemName;
      a29 = 5;
      a30 = 8;
      v66 = *(_DWORD *)(v61 + 24);
      a51 = v60;
      a58 = a5;
      a31 = v66;
      a32 = *(_DWORD *)(v61 + 28);
      a34 = 35;
      a35 = 8;
      a36 = *(_DWORD *)(a7 + 24);
      a37 = *(_DWORD *)(a7 + 28);
      a39 = 11;
      a40 = 4;
      a44 = 2;
      a45 = *a6 + 8;
      a49 = 11;
      a50 = 4;
      a54 = 2;
      a55 = *a5 + 8;
      a15 = 8;
      SepAdtLogAuditRecord((int)&a13);
    }
    if ( a6 )
      ExFreePoolWithTag((unsigned int)a6);
  }
  if ( a5 )
    ExFreePoolWithTag((unsigned int)a5);
  if ( v63 < 0 )
LABEL_11:
    SepAuditFailed();
  v67 = SeReleaseSubjectContext((int)&a9);
  return v69(v67);
}
