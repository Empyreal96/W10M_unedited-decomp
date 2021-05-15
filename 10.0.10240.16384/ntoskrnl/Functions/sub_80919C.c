// sub_80919C 
 
void __fastcall sub_80919C(int a1, int a2, int a3, int a4, int a5, int a6, char a7, int a8, char a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, char *a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, char a36)
{
  int v36; // r4
  int v37; // r5

  PfSnBuildScenarioEventDescriptors(v37 + 16, v37 + 80, &a7, &a9);
  a25 = &a36;
  a26 = 0;
  a27 = 4;
  a28 = 0;
  EtwWrite(*(_DWORD *)(v36 + 152), *(_DWORD *)(v36 + 156), (int)PfSnEvt_GetReadLists_Start, 0);
  JUMPOUT(0x75D280);
}
