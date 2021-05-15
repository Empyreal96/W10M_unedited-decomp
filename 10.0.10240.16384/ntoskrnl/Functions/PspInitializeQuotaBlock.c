// PspInitializeQuotaBlock 
 
int __fastcall PspInitializeQuotaBlock(int a1, int a2, int a3)
{
  _BYTE *v6; // r0
  int v8; // r5
  char v9; // r2
  int v10; // r1
  int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r6
  unsigned int v14; // r1
  void **v15; // lr
  int v16; // r7
  int v17; // r0
  int v18; // t1
  unsigned int v19; // r2
  int v20; // [sp+0h] [bp-48h] BYREF
  char v21[28]; // [sp+8h] [bp-40h] BYREF
  int v22; // [sp+24h] [bp-24h]

  v6 = memset((_BYTE *)a3, 0, 1152);
  *(_DWORD *)(a3 + 1028) = 1;
  *(_DWORD *)(a3 + 1024) = 1;
  if ( a1 )
    return sub_81A89C(v6);
  v8 = 0;
  while ( 1 )
  {
    v9 = PspResourceFlags[8 * v8];
    if ( (v9 & 2) != 0 )
      goto LABEL_10;
    v10 = a3 + (v8 << 8);
    v11 = a2 ? *(_DWORD *)(a2 + 4 * v8) : *(_DWORD *)PspQuotaLimitOffsets[v8];
    *(_DWORD *)(v10 + 128) = v11;
    if ( (v9 & 1) == 0 )
      goto LABEL_10;
    if ( v11 != -1 )
      break;
    *(_DWORD *)(v10 + 128) = 0;
    PspInsertExpansionEntry(&PspQuotaExpansionDescriptors[7 * v8], v10, -1, 7 * v8);
LABEL_10:
    if ( ++v8 >= 4 )
      return 0;
  }
  if ( !v11 )
    goto LABEL_10;
  v20 = 0;
  if ( PspExpandLimit(v8, v10, v11, (int)&v20) )
  {
    if ( !v8 && IopIrpCreditsEnabled < 1 )
    {
      __dmb(0xBu);
      do
        v12 = __ldrex((unsigned int *)&IopIrpCreditsEnabled);
      while ( !v12 && __strex(1u, (unsigned int *)&IopIrpCreditsEnabled) );
      __dmb(0xBu);
      if ( !v12 )
      {
        IopQueryProcessorInitValues(v21, 1);
        KeSynchronizeWithDynamicProcessors();
        v13 = KeNumberProcessors_0;
        v14 = 0;
        if ( KeNumberProcessors_0 )
        {
          v15 = &KiProcessorBlock;
          v16 = v22;
          do
          {
            v18 = (int)*v15++;
            v17 = v18;
            if ( *(_DWORD *)(v18 + 1616) != 0x7FFFFFFF )
              break;
            ++v14;
            *(_DWORD *)(v17 + 1616) = v16;
          }
          while ( v14 < v13 );
        }
        __dmb(0xBu);
        do
          v19 = __ldrex((unsigned int *)&IopIrpCreditsEnabled);
        while ( __strex(v19 + 1, (unsigned int *)&IopIrpCreditsEnabled) );
        __dmb(0xBu);
      }
    }
    goto LABEL_10;
  }
  return -1073741670;
}
