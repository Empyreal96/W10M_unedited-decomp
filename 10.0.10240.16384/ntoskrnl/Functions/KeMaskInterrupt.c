// KeMaskInterrupt 
 
int __fastcall KeMaskInterrupt(int a1, unsigned int a2, int a3)
{
  BOOL v6; // r7
  int v7; // r4
  unsigned int v8; // r6
  int v9; // r3
  unsigned int *v10; // r2
  unsigned int v11; // r0
  int v12; // r8
  int v13; // r6
  int v14; // r7
  int v15; // r0
  unsigned int v16; // r2
  int v17; // r1
  int v18; // r0

  v6 = KiIsInterruptTypeSecondary(a3) != 0;
  v7 = 0;
  v8 = 0;
  if ( a2 )
  {
    while ( 1 )
    {
      v9 = *(_DWORD *)(a1 + 4 * v8);
      __dmb(0xBu);
      v10 = (unsigned int *)(v9 + 60);
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 | 1, v10) );
      __dmb(0xBu);
      if ( (v11 & 1) != 0 )
        break;
      v8 = (unsigned __int8)(v8 + 1);
      if ( v8 >= a2 )
        goto LABEL_6;
    }
    v7 = -2147483611;
  }
  else
  {
LABEL_6:
    if ( *(_DWORD *)(a3 + 8) )
      goto LABEL_17;
    v12 = *(_DWORD *)(a3 + 56);
    if ( v6 )
    {
      v7 = KiMaskSecondaryInterruptInternal(*(_DWORD *)(*(_DWORD *)a1 + 44), v12);
    }
    else
    {
      v13 = 0;
      v14 = KfRaiseIrql(15);
      v15 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
      v16 = 0;
      if ( a2 )
      {
        while ( 1 )
        {
          v17 = *(_DWORD *)(a1 + 4 * v16);
          if ( *(_DWORD *)(v17 + 52) == v15 )
            break;
          v16 = (unsigned __int8)(v16 + 1);
          if ( v16 >= a2 )
            goto LABEL_13;
        }
        v7 = KiMaskInterruptInternal(*(_DWORD *)(v17 + 44), v12);
        v13 = 1;
      }
LABEL_13:
      v18 = KfLowerIrql(v14);
      if ( !v13 )
        return sub_51FBF8(v18);
    }
    if ( v7 == 296 )
LABEL_17:
      v7 = 0;
  }
  return v7;
}
