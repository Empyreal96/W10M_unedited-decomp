// sub_7DC388 
 
void __fastcall sub_7DC388(int a1, int a2, int a3, int a4, int a5, int a6, __int16 a7, unsigned __int16 *a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, unsigned __int16 *a21, int a22, int a23, int a24, int a25, __int16 *a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, __int16 *a36, int a37, int a38, int a39, int a40, unsigned __int16 *a41, int a42, int a43, int a44, int a45, unsigned __int16 *a46, int a47, int a48, int a49, int a50, int a51, int a52, int a53, unsigned int a54, int a55, int a56, int a57, int a58, int a59, int a60, _DWORD *a61, int a62, int a63)
{
  unsigned __int16 *v68; // r6
  _DWORD *v69; // r7
  unsigned __int16 *v70; // r8
  __int16 *v71; // r9
  _DWORD *v72; // r4
  unsigned int v73; // r5
  unsigned __int16 **v74; // r3
  unsigned __int16 *v75; // r10
  __int64 v76; // kr00_8
  __int16 v77; // r3
  int v78; // r3
  int v79; // r1
  int v80; // r2
  int v81; // r3
  int v82; // r3
  int v83; // r3
  int v84; // r3
  int v85; // r3
  int v86; // [sp+10h] [bp+10h]

  v72 = (_DWORD *)STACK[0x2D8];
  v73 = STACK[0x2DC];
  if ( STACK[0x2D8] )
    v74 = (unsigned __int16 **)v72[37];
  else
    v74 = *(unsigned __int16 ***)(v73 + 148);
  v75 = *v74;
  if ( !RtlEqualSid((unsigned __int16 *)SeLocalSystemSid, *v74) )
  {
    if ( SeLocateProcessImageName(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74)) >= 0 )
    {
      v76 = *(_QWORD *)(v73 + 24);
      v86 = *(_DWORD *)(v73 + 24);
      if ( !v71 )
        v71 = &SeSubsystemName;
      memset(&a11, 0, 664);
      a11 = 4;
      LOWORD(a15) = a7;
      a12 = 4674;
      if ( LOBYTE(STACK[0x2EC]) )
        v77 = 8;
      else
        v77 = 16;
      HIWORD(a15) = v77;
      a17 = 4;
      v78 = *((unsigned __int8 *)v75 + 1);
      a21 = v75;
      a26 = v71;
      a18 = 4 * (v78 + 2);
      a22 = 1;
      v79 = (unsigned __int16)*v71 + 8;
      a23 = v79;
      if ( v72 )
      {
        v80 = v72[7];
        v81 = v72[6];
        a27 = 5;
        a28 = 8;
        a30 = v80;
      }
      else
      {
        a27 = 5;
        a28 = 8;
        v81 = v86;
        a30 = HIDWORD(v76);
      }
      a29 = v81;
      a32 = 1;
      a33 = v79;
      a36 = v71;
      if ( v68 )
      {
        a37 = 1;
        v82 = *v68;
        a41 = v68;
        a38 = v82 + 8;
      }
      if ( v70 )
      {
        a42 = 2;
        v83 = *v70;
        a46 = v70;
        a43 = v83 + 8;
      }
      a47 = 11;
      a48 = 4;
      a49 = ObNormalizeHandleValue(a10);
      if ( v68 )
      {
        a52 = 7;
        a53 = 4;
        a54 = STACK[0x2E4];
        a55 = 4;
      }
      else
      {
        a52 = 3;
        a53 = 4;
        a54 = STACK[0x2E4];
      }
      if ( v69 && *v69 )
      {
        v84 = 12 * (*v69 - 1) + 20;
        a57 = 8;
        a58 = v84;
        a61 = v69;
      }
      a62 = 11;
      a63 = 4;
      a64 = STACK[0x2E0];
      a67 = 2;
      v85 = *a8;
      STACK[0x108] = (unsigned int)a8;
      a68 = v85 + 8;
      a13 = 11;
      SepAdtLogAuditRecord((int)&a11);
      ExFreePoolWithTag((unsigned int)a8);
      JUMPOUT(0x6E8BE6);
    }
    SepAuditFailed();
  }
  JUMPOUT(0x6E8BE4);
}
