// sub_7DC260 
 
void __fastcall sub_7DC260(int a1, int a2, int a3, int a4, int a5, int a6, unsigned __int16 *a7, __int16 a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, __int16 *a26, int a27, int a28, unsigned __int64 a29, int a30, int a31, int a32, int a33, int a34, __int16 *a35, int a36, int a37, int a38, int a39, unsigned __int16 *a40, int a41, int a42, int a43, int a44, _DWORD *a45, int a46, int a47, int a48, int a49, int a50, int a51, int a52, int a53, int a54, unsigned __int16 *a55)
{
  int v55; // r5
  _DWORD *v56; // r6
  unsigned __int16 *v57; // r7
  __int16 *v58; // r9
  int v59; // r0
  int v61; // r8
  _DWORD *v62; // r2
  int *v63; // r3
  int v64; // r10
  __int16 v65; // r3
  int v66; // r3
  int v67; // r1
  unsigned __int64 v68; // kr00_8
  int v69; // r3
  int v70; // r3
  unsigned int v71; // [sp+8h] [bp+8h]
  unsigned int v72; // [sp+10h] [bp+10h]
  int v73; // [sp+14h] [bp+14h]

  v59 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v73 = *(_DWORD *)(v59 + 176);
  v61 = SeLocateProcessImageName(v59);
  if ( v61 >= 0 )
  {
    v62 = (_DWORD *)STACK[0x2D8];
    if ( v55 )
      v63 = *(int **)(v55 + 148);
    else
      v63 = (int *)v62[37];
    v64 = *v63;
    v71 = v62[6];
    v72 = v62[7];
    if ( !v58 )
      v58 = &SeSubsystemName;
    memset(&a11, 0, 664);
    a11 = 4;
    LOWORD(a15) = a8;
    a12 = 4673;
    if ( LOBYTE(STACK[0x2E0]) )
      v65 = 8;
    else
      v65 = 16;
    HIWORD(a15) = v65;
    a17 = 4;
    v66 = *(unsigned __int8 *)(v64 + 1);
    a21 = v64;
    a26 = v58;
    a18 = 4 * (v66 + 2);
    a22 = 1;
    v67 = (unsigned __int16)*v58 + 8;
    a23 = v67;
    if ( v55 )
    {
      v68 = *(_QWORD *)(v55 + 24);
      a27 = 5;
      a28 = 8;
      a29 = v68;
    }
    else
    {
      a27 = 5;
      a28 = 8;
      a29 = __PAIR64__(v72, v71);
    }
    a31 = 1;
    a32 = v67;
    a35 = v58;
    if ( v57 )
    {
      a36 = 1;
      v69 = *v57;
      a40 = v57;
      a37 = v69 + 8;
    }
    if ( v56 && *v56 )
    {
      v70 = 12 * (*v56 - 1) + 20;
      a41 = 8;
      a42 = v70;
      a45 = v56;
    }
    a46 = 11;
    a47 = 4;
    a55 = a7;
    a48 = v73;
    a51 = 2;
    a52 = *a7 + 8;
    a13 = 8;
    SepAdtLogAuditRecord((int)&a11);
  }
  if ( a7 )
    ExFreePoolWithTag((unsigned int)a7);
  if ( v61 < 0 )
    SepAuditFailed();
  JUMPOUT(0x6E8B5A);
}
