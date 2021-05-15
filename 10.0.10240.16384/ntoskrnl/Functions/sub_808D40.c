// sub_808D40 
 
void __fastcall sub_808D40(int a1, int a2, int a3, int a4, int a5, int a6, char a7, int a8, char a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28)
{
  int v28; // r4
  int v29; // r5

  PfSnBuildScenarioEventDescriptors(v29 + 12, v29 + 76, &a7, &a9);
  a25 = v29 + 288;
  a26 = 0;
  a27 = 4;
  a28 = 0;
  EtwWrite(*(_DWORD *)(v28 + 152), *(_DWORD *)(v28 + 156), (int)PfSnEvt_EndTrace_Info, 0);
  JUMPOUT(0x75C688);
}
