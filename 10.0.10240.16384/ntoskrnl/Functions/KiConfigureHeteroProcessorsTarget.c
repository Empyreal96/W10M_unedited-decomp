// KiConfigureHeteroProcessorsTarget 
 
int __fastcall KiConfigureHeteroProcessorsTarget(int a1, int a2, unsigned int *a3, unsigned int *a4)
{
  unsigned int *v5; // r10
  unsigned int v7; // r5
  void **v8; // r0
  int v9; // t1
  int v10; // r3
  unsigned int v11; // r0
  void **v12; // lr
  int v13; // r5
  int v14; // t1
  int *v15; // r1
  int v16; // r3
  int v17; // r3
  int v18; // r2
  _DWORD *v19; // r6
  int v20; // r3
  int v21; // r2
  int v22; // r5
  unsigned int i; // r1
  char *v24; // r0
  int result; // r0
  unsigned int v26; // r2

  v5 = a3;
  KeSignalCallDpcSynchronize(a4);
  if ( !*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) )
  {
    if ( *(_DWORD *)(a2 + 8) )
    {
      v11 = 0;
      if ( KeNumberProcessors_0 )
      {
        v12 = &KiProcessorBlock;
        do
        {
          v14 = (int)*v12++;
          v13 = v14;
          v15 = &KiGroupBlock[2 * *(unsigned __int8 *)(v14 + 1052)];
          if ( ((*(_DWORD *)(a2 + 8) >> v11) & 1) != 0 )
          {
            v16 = *(_DWORD *)(v13 + 1048);
            *(_BYTE *)(v13 + 2986) = 0;
            v17 = v16 | v15[1];
          }
          else
          {
            v18 = *(_DWORD *)(v13 + 1048);
            *(_BYTE *)(v13 + 2986) = 1;
            v17 = v15[1] & ~v18;
          }
          v15[1] = v17;
          ++v11;
        }
        while ( v11 < KeNumberProcessors_0 );
        v5 = a3;
      }
    }
    else
    {
      v7 = 0;
      if ( KeNumberProcessors_0 )
      {
        v8 = &KiProcessorBlock;
        do
        {
          v9 = (int)*v8++;
          ++v7;
          v10 = *(unsigned __int8 *)(v9 + 1052);
          *(_BYTE *)(v9 + 2986) = 0;
          KiGroupBlock[2 * v10 + 1] &= ~*(_DWORD *)(v9 + 1048);
        }
        while ( v7 < KeNumberProcessors_0 );
      }
    }
    KiHeteroSystem = 0;
    if ( KeNumberNodes == 1 )
    {
      v19 = KeNodeBlock;
      if ( *((_WORD *)KeNodeBlock + 132) )
        v20 = 0;
      else
        v20 = *(_DWORD *)(a2 + 8);
      v21 = *((_DWORD *)KeNodeBlock + 65);
      v22 = v21 & v20;
      if ( (v21 & v20) == 0 || v22 == v21 )
      {
        v22 = *((_DWORD *)KeNodeBlock + 65);
      }
      else
      {
        v21 &= ~v22;
        KiHeteroSystem = 1;
      }
      for ( i = 1; i < 5; ++i )
      {
        v24 = (char *)&v19[2 * i];
        *((_DWORD *)v24 + 73) = v19[65];
        *((_DWORD *)v24 + 74) = v19[65];
        if ( i == 1 )
        {
          *((_DWORD *)v24 + 74) = v21;
        }
        else if ( i != 2 )
        {
          if ( i == 3 )
          {
            *((_DWORD *)v24 + 73) = v22;
            *((_DWORD *)v24 + 74) = v22;
          }
          else if ( i == 4 )
          {
            *((_DWORD *)v24 + 73) = v22;
          }
          continue;
        }
        *((_DWORD *)v24 + 73) = v21;
      }
    }
  }
  result = KeSignalCallDpcSynchronize(a4);
  __dmb(0xBu);
  do
    v26 = __ldrex(v5);
  while ( __strex(v26 - 1, v5) );
  __dmb(0xBu);
  return result;
}
