// KeRaiseUserException 
 
int __fastcall KeRaiseUserException(int a1, int a2)
{
  int v2; // r5
  unsigned int v3; // r6
  int v4; // r4
  int v5; // r1
  int v6; // r1
  int v7; // r0

  v2 = a1;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = KeGetCurrentIrql(a1);
  if ( !v4 )
    v4 = KfRaiseIrql(1);
  v5 = *(_DWORD *)(v3 + 96);
  if ( v5 && KiGetTrapFrameMode(v5) )
  {
    *(_DWORD *)(*(_DWORD *)(v3 + 156) + 420) = v2;
    __disable_irq();
    *(_DWORD *)(v6 + 128) = KeRaiseUserExceptionDispatcher;
    *(_DWORD *)(v6 + 132) = *(_DWORD *)(v6 + 132) & 0xF9FF03FF | 0x20;
    if ( *(_BYTE *)(v6 + 16) != 2 )
    {
      v7 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 160);
      if ( v7 )
      {
        if ( (*(_DWORD *)(v6 + 132) & 0x1F) == 16 && (*(_DWORD *)(v6 + 132) & 0x600FC00) == 0 )
        {
          *(_DWORD *)(v6 + 112) = *(_DWORD *)(v6 + 128);
          *(_DWORD *)(v6 + 128) = v7;
        }
      }
    }
    __enable_irq();
  }
  if ( !v4 )
    KfLowerIrql(0);
  return v2;
}
