// sub_54AE9C 
 
void __fastcall sub_54AE9C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, char *a9, int a10, int a11, int a12, int *a13, int a14, int a15, int a16, unsigned __int16 *a17, int a18, unsigned int a19, int a20, char a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, int a47, int a48, int a49, int a50, int a51, int a52, int a53, int a54, int a55, int a56, char a57)
{
  int v57; // r4
  int *v58; // r5
  unsigned __int16 *v59; // r6
  int v60; // r2
  int v61; // r0
  unsigned int v62; // r0

  v59 = (unsigned __int16 *)&word_5CB8A8;
  v60 = *(_DWORD *)(v57 + 40 * *(char *)(v57 + 34) + 108);
  a7 = *(_DWORD *)(v57 + 24);
  if ( a7 < 0 && !*(_DWORD *)(v60 + 116) )
  {
    v61 = IoFindDeviceThatFailedIrp(v57);
    if ( PopDiagGetDriverName(v61, &a21, 120) >= 0 )
      v59 = (unsigned __int16 *)&a21;
  }
  a9 = &a57;
  a10 = 0;
  a11 = 4;
  a12 = 0;
  a13 = &a7;
  a14 = 0;
  a15 = 4;
  a16 = 0;
  v62 = wcslen(v59);
  a17 = v59;
  a18 = 0;
  a19 = 2 * (v62 + 1);
  a20 = 0;
  EtwWrite(*v58, v58[1], (int)POP_ETW_EVENT_IRPFINISH, 0);
  JUMPOUT(0x4D1DD0);
}
