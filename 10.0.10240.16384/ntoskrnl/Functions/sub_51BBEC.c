// sub_51BBEC 
 
void __fastcall sub_51BBEC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, char a14)
{
  int v14; // r5
  int v15; // r8
  _DWORD *v16; // r9
  int v17; // r6
  unsigned int v18; // r5
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r4

  if ( a14 || v14 != -1073741769 && v14 < 0 )
  {
    v17 = KdEnterDebugger(a1, a2);
    v18 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    KdpCopyContext(*(_DWORD *)(v18 + 2712), *v16, v16);
    KiSaveProcessorControlState((_DWORD *)(v18 + 1440), v19, v20, v21);
    v22 = **(_DWORD **)(v18 + 2712);
    KdpReportExceptionStateChange(v15);
    KdpCopyContext(v16, v22, *(_DWORD *)(v18 + 2712));
    KiRestoreProcessorControlState((unsigned int *)(v18 + 1440));
    KdExitDebugger(v17);
    KdpControlCPressed = 0;
    JUMPOUT(0x444C52);
  }
  JUMPOUT(0x444C50);
}
