// KdpSymbol 
 
int __fastcall KdpSymbol(int result, int a2, __int64 a3, _BYTE *a4, int a5, int a6)
{
  int v6; // r9
  int v8; // r8
  unsigned int v9; // r7
  int v10; // r1
  int v11; // r2
  int v12; // r3
  _DWORD *v13; // r4
  int v14; // r5
  _BYTE *v15; // r1
  int v16; // r4
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // [sp+0h] [bp-20h]

  v6 = a3;
  v20 = result;
  if ( !BYTE4(a3) )
  {
    HIDWORD(a3) = (unsigned __int8)KdDebuggerNotPresent;
    if ( !KdDebuggerNotPresent )
    {
      v8 = KdEnterDebugger(a5, a6, a3);
      v9 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      KiSaveProcessorControlState((_DWORD *)(v9 + 1440), v10, v11, v12);
      v13 = *(_DWORD **)(v9 + 2712);
      v14 = *(_DWORD *)a4;
      KdpQuickMoveMemory((int)v13, a4, 416);
      *v13 = v14;
      KdpReportLoadSymbolsStateChange(v20, a2, v6, *(_DWORD *)(v9 + 2712));
      v15 = *(_BYTE **)(v9 + 2712);
      v16 = *(_DWORD *)v15;
      KdpQuickMoveMemory((int)a4, v15, 416);
      *(_DWORD *)a4 = v16;
      KiRestoreProcessorControlState((unsigned int *)(v9 + 1440));
      result = KdExitDebugger(v8, v17, v18, v19);
    }
  }
  return result;
}
