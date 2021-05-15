// KeUnmaskInterrupt 
 
int __fastcall KeUnmaskInterrupt(int a1, unsigned int a2, int a3)
{
  BOOL v6; // r5
  unsigned int v7; // r4
  int v8; // r3
  unsigned int *v9; // r2
  unsigned int v10; // r0
  int result; // r0

  v6 = KiIsInterruptTypeSecondary(a3) != 0;
  v7 = 0;
  if ( a2 )
  {
    while ( 1 )
    {
      v8 = *(_DWORD *)(a1 + 4 * v7);
      __dmb(0xBu);
      v9 = (unsigned int *)(v8 + 60);
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 & 0xFFFFFFFE, v9) );
      __dmb(0xBu);
      if ( (v10 & 1) == 0 )
        break;
      v7 = (unsigned __int8)(v7 + 1);
      if ( v7 >= a2 )
        goto LABEL_6;
    }
    result = 295;
  }
  else
  {
LABEL_6:
    if ( *(_DWORD *)(a3 + 8)
      || (v6 ? (result = KiUnmaskSecondaryInterruptInternal(*(_DWORD *)(*(_DWORD *)a1 + 44), *(_DWORD *)(a3 + 56))) : (result = off_617A64(*(_DWORD *)(a3 + 56), 0)),
          result == 296) )
    {
      result = 0;
    }
  }
  return result;
}
