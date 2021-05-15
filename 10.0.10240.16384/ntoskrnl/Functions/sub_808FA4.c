// sub_808FA4 
 
void __fastcall sub_808FA4(int a1, int a2, int a3, int a4, int a5, int a6, char a7, int a8, char a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28)
{
  int v28; // r4
  int v29; // r5
  int *v30; // r6

  PfSnBuildScenarioEventDescriptors(v28 + 16, v28 + 80, &a7, &a9);
  if ( v30 == PfSnEvt_AsyncWorker_Start )
  {
    a25 = v28 + 124;
    a26 = 0;
    a27 = 4;
    a28 = 0;
  }
  EtwWrite(*(_DWORD *)(v29 + 152), *(_DWORD *)(v29 + 156), (int)v30, 0);
  JUMPOUT(0x75CE18);
}
