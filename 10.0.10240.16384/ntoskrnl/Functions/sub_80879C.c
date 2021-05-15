// sub_80879C 
 
void __fastcall sub_80879C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, char a9, int a10, char a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int *a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, char *a39, int a40, int a41, int a42, int *a43, int a44, int a45, int a46, int a47, int a48, int a49, int a50, int a51, int a52, int a53, char a54, __int16 a55, int a56, char a57, char a58, __int64 a59)
{
  int v59; // r4
  char v60; // r5
  int v61; // r6

  PfSnBuildScenarioEventDescriptors(v61, &a54, &a9, &a11);
  LOBYTE(a7) = v60;
  HIWORD(a7) = a55;
  a27 = (int)&a7 + 2;
  a28 = 0;
  a29 = 2;
  a30 = 0;
  a31 = &a7;
  a32 = 0;
  a33 = 1;
  a34 = 0;
  BYTE1(a7) = a57;
  a35 = (int)&a7 + 1;
  a36 = 0;
  a37 = 1;
  a38 = 0;
  a39 = &a58;
  a40 = 0;
  a41 = 4;
  a42 = 0;
  if ( a59 < 0 )
  {
    if ( (HIDWORD(a59) & (unsigned int)a59) == -1 )
      a8 = -1;
    else
      a8 = -2;
  }
  else
  {
    a8 = _rt_sdiv64((unsigned int)dword_989680, a59);
  }
  a43 = &a8;
  a44 = 0;
  a45 = 4;
  a46 = 0;
  EtwWrite(*(_DWORD *)(v59 + 152), *(_DWORD *)(v59 + 156), (int)PfSnEvt_ScenarioDecision_Info, 0);
  JUMPOUT(0x75B944);
}
