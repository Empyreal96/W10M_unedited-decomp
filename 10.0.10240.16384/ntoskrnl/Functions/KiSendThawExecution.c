// KiSendThawExecution 
 
int KiSendThawExecution()
{
  int result; // r0
  unsigned int v1; // r4
  unsigned int v2; // r2
  int v3; // r2
  unsigned int v4; // r2
  unsigned int v5; // r2
  int v6; // r2
  unsigned int v7; // [sp+0h] [bp-20h]

  *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC08) = 0;
  result = KiSetDebuggerOwner(0);
  if ( (KiBugCheckActive & 3) != 0 )
    return sub_51C098(result);
  if ( (unsigned int)KeNumberProcessors_0 >= 2 && !PoAllProcIntrDisabled )
  {
    v1 = 0;
    result = KiTurnOnFrozenProcessors(result);
    v2 = 0;
    v7 = 0;
    if ( KeNumberProcessors_0 )
    {
      while ( 1 )
      {
        v3 = (int)*(&KiProcessorBlock + v2);
        if ( v3 == ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408 )
          goto LABEL_16;
        if ( (*(_DWORD *)(v3 + 1672) & 0xF) != 2 )
          break;
        *(_DWORD *)(v3 + 1672) = 3;
        v4 = v7;
        v1 |= 1 << v7;
LABEL_9:
        v2 = v4 + 1;
        v7 = v2;
        if ( v2 >= KeNumberProcessors_0 )
          goto LABEL_10;
      }
      *(_DWORD *)(v3 + 1672) = 0;
LABEL_16:
      v4 = v7;
      goto LABEL_9;
    }
LABEL_10:
    __dsb(0xFu);
    __sev();
    while ( v1 )
    {
      v5 = __clz(__rbit(v1));
      v1 &= ~(1 << v5);
      v6 = (int)*(&KiProcessorBlock + v5);
      while ( *(_DWORD *)(v6 + 1672) == 3 )
      {
        __dmb(0xAu);
        __yield();
      }
    }
  }
  return result;
}
