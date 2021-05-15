// sub_80901C 
 
void __fastcall sub_80901C(int a1, int a2, int a3, int a4, int a5, int a6, char a7, int a8, char a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, char a18, char a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, int a47, int a48, int a49, int a50, int a51, int a52, int a53, int a54, int a55, int a56, int a57, int a58, int a59, int a60, int a61, int a62, int a63)
{
  int v67; // r6
  int v68; // r9

  PfSnBuildScenarioEventDescriptors(v68 + 16, v68 + 80, &a19, &a67);
  STACK[0x138] = (unsigned int)&a18;
  STACK[0x13C] = 0;
  STACK[0x140] = 4;
  STACK[0x144] = 0;
  STACK[0x148] = (unsigned int)&a9;
  STACK[0x14C] = 0;
  STACK[0x150] = 4;
  STACK[0x154] = 0;
  STACK[0x158] = (unsigned int)&a7;
  STACK[0x15C] = 0;
  STACK[0x160] = 1;
  STACK[0x164] = 0;
  EtwWrite(*(_DWORD *)(v67 + 152), *(_DWORD *)(v67 + 156), (int)PfSnEvt_PrefetchSections_Start, 0);
  JUMPOUT(0x75D0AE);
}
