// sub_7F517C 
 
void __fastcall sub_7F517C(int a1, int a2, int a3, int a4, unsigned __int16 *a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, __int16 *a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, unsigned __int16 *a47, int a48, int a49, int a50, int a51, int a52, int a53, int a54, int a55, int a56, unsigned int *a57, int a58, int a59, int a60, int a61, unsigned int *a62)
{
  _DWORD *v63; // r5
  char *v64; // r6
  unsigned int *v65; // r7
  unsigned int *v66; // r8
  unsigned int v67; // r10
  int v68; // r0
  unsigned int v69; // r9
  __int16 v70; // r3
  int v71; // r0
  unsigned __int16 *v72; // r5
  int v73; // r3
  unsigned int *v74; // r0
  int v75; // lr
  unsigned int v76; // r3
  unsigned int v77; // r4
  unsigned int *v78; // r0
  int v79; // r6
  unsigned int v80; // r2
  unsigned int v81; // r3
  int v82; // r3
  int v83; // r3
  int v84; // r3
  int v85; // [sp+4h] [bp+4h]
  int v86; // [sp+8h] [bp+8h]
  int v87; // [sp+Ch] [bp+Ch]
  int v88; // [sp+10h] [bp+10h]
  int v89; // [sp+14h] [bp+14h]
  int v90; // [sp+18h] [bp+18h]

  v68 = SepAdtAuditablePrivilege(v63, v67);
  v69 = STACK[0x2F0];
  if ( !v68 && !SepAdtAuditablePrivilege(v64, STACK[0x2F0]) )
    goto LABEL_38;
  memset(&a17, 0, 664);
  a17 = 6;
  LOWORD(a21) = 140;
  a18 = 4703;
  a19 = 0;
  v70 = LOBYTE(STACK[0x2F4]) ? 8 : 16;
  HIWORD(a21) = v70;
  v71 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( !*(_DWORD *)(v71 + 380) )
    goto LABEL_38;
  v89 = *(_DWORD *)(v71 + 176);
  v72 = a5;
  if ( SeLocateProcessImageName(v71) >= 0 )
  {
    if ( a15 )
      v73 = a15;
    else
      v73 = a15;
    v88 = **(_DWORD **)(v73 + 148);
    v86 = *(_DWORD *)(a15 + 24);
    v90 = *(_DWORD *)(a15 + 28);
    v87 = *(_DWORD *)(a6 + 28);
    v85 = *(_DWORD *)(a6 + 24);
    if ( v69 )
    {
      v74 = (unsigned int *)ExAllocatePoolWithTag(1, 12 * v69 + 20, 1883333971);
      v66 = v74;
      if ( !v74 )
        goto LABEL_32;
      *v74 = v69;
      v74[1] = 1;
      v75 = v64 - (char *)v74;
      do
      {
        v76 = *(unsigned int *)((char *)v74 + v75 + 4);
        v77 = *(unsigned int *)((char *)v74 + v75 + 8);
        v74[2] = *(unsigned int *)((char *)v74 + v75);
        v74[3] = v76;
        v74[4] = v77;
        v74 += 3;
        --v69;
      }
      while ( v69 );
      v72 = a5;
    }
    if ( !v67 )
    {
LABEL_21:
      a23 = 4;
      v82 = *(unsigned __int8 *)(v88 + 1);
      a27 = v88;
      a47 = v72;
      a24 = 4 * (v82 + 2);
      a28 = 1;
      a29 = 24;
      a32 = &SeSubsystemName;
      a33 = 5;
      a34 = 8;
      a35 = v86;
      a36 = v90;
      a38 = 35;
      a39 = 8;
      a40 = v85;
      a41 = v87;
      a43 = 2;
      a44 = *v72 + 8;
      a48 = 11;
      a49 = 4;
      a50 = v89;
      if ( v66 )
      {
        a53 = 8;
        if ( *v66 )
          v83 = 12 * (*v66 - 1) + 20;
        else
          v83 = 8;
        a54 = v83;
        a57 = v66;
      }
      if ( v65 )
      {
        a58 = 8;
        if ( *v65 )
          v84 = 12 * (*v65 - 1) + 20;
        else
          v84 = 8;
        a59 = v84;
        a62 = v65;
      }
      a19 = 8;
      SepAdtLogAuditRecord((int)&a17);
      goto LABEL_32;
    }
    v78 = (unsigned int *)ExAllocatePoolWithTag(1, 12 * v67 + 20, 1883333971);
    v65 = v78;
    if ( v78 )
    {
      v78[1] = 1;
      *v78 = v67;
      v79 = a12 - (_DWORD)v78;
      do
      {
        v80 = *(unsigned int *)((char *)v78 + v79 + 4);
        v81 = *(unsigned int *)((char *)v78 + v79 + 8);
        v78[2] = *(unsigned int *)((char *)v78 + v79);
        v78[3] = v80;
        v78[4] = v81;
        v78 += 3;
        --v67;
      }
      while ( v67 );
      v72 = a5;
      goto LABEL_21;
    }
  }
LABEL_32:
  if ( v72 )
    ExFreePoolWithTag((unsigned int)v72);
  if ( v66 )
    ExFreePoolWithTag((unsigned int)v66);
  if ( v65 )
    ExFreePoolWithTag((unsigned int)v65);
LABEL_38:
  JUMPOUT(0x715D62);
}
