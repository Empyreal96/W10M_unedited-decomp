// KeSwitchFrozenProcessor 
 
int __fastcall KeSwitchFrozenProcessor(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r0
  int v5; // r3
  int v6; // r4
  unsigned int v8; // [sp+0h] [bp-18h] BYREF
  int v9; // [sp+4h] [bp-14h]
  unsigned int v10; // [sp+8h] [bp-10h]
  int v11; // [sp+Ch] [bp-Ch]

  v8 = a1;
  v9 = a2;
  v10 = a3;
  v11 = a4;
  if ( a1 < KeNumberProcessors_0 && !PoAllProcIntrDisabled )
  {
    v4 = (unsigned int)*(&KiProcessorBlock + a1);
    v5 = *(_DWORD *)(v4 + 1672);
    if ( v5 == 2 || v5 == 4 )
    {
      v6 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
      KiSetDebuggerOwner(v4);
      if ( (*(_DWORD *)(v6 + 1672) & 0xF) == 2 )
        return 3;
      if ( (*(_DWORD *)(v6 + 1672) & 0xF) != 4 )
        return 0;
      KeQueryPerformanceCounter(&v8, 0);
      v10 = v8;
      v11 = v9;
      while ( v6 != KiDebuggerOwner )
      {
        KiCheckStall(v6, 1);
        KiTurnOffProcessorWhileFrozen();
      }
    }
  }
  return 2;
}
