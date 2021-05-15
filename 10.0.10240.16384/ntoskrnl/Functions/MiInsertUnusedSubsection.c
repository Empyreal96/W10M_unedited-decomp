// MiInsertUnusedSubsection 
 
int __fastcall MiInsertUnusedSubsection(int a1, int a2)
{
  int v2; // r7
  unsigned int v3; // r2
  int v5; // r9
  unsigned int v6; // r3
  unsigned int v7; // r4
  unsigned int v8; // r1
  unsigned int v9; // r6
  int v10; // r7
  int *v11; // r1
  int **v12; // r0
  void **v14; // r0
  unsigned int v15; // r0
  int v16; // r0
  int v18; // [sp+4h] [bp-24h]

  v2 = a2;
  v3 = 4 * (*(_DWORD *)(a1 + 28) + *(_DWORD *)(a1 + 36));
  v5 = 0;
  v18 = *(_DWORD *)(a1 + 28) + *(_DWORD *)(a1 + 36);
  if ( v3 > 0xFF0 )
  {
    if ( (v3 & 0xFFF) > 0xFE0 || v3 >= 0x10000 )
      return sub_54A8A4();
    v6 = v3 + 7;
  }
  else
  {
    v6 = v3 + 15;
  }
  v7 = v6 & 0xFFFFFFF8;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    v9 = 192;
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_632D80);
  }
  else
  {
    do
      v8 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
    while ( __strex(v8 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
    __dmb(0xBu);
    v9 = 0xC0u;
    if ( v8 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
    while ( 1 )
    {
      v10 = dword_632D80;
      if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632D80 & 0x40000000) == 0 )
      {
        do
          v15 = __ldrex((unsigned int *)&dword_632D80);
        while ( v15 == v10 && __strex(v10 | 0x40000000, (unsigned int *)&dword_632D80) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    v2 = a2;
  }
  v11 = (int *)(a1 + 52);
  *(_WORD *)(a1 + 18) |= 8u;
  dword_632E14 += v7;
  if ( *(_DWORD *)(a1 + 64) )
  {
    if ( v2 == 1 )
    {
      v12 = (int **)dword_63FA74;
      *v11 = (int)&dword_63FA70;
      *(_DWORD *)(a1 + 56) = v12;
      if ( *v12 != &dword_63FA70 )
        __fastfail(3u);
      *v12 = v11;
      dword_63FA74 = a1 + 52;
    }
    else
    {
      v16 = dword_63FA70;
      *v11 = dword_63FA70;
      *(_DWORD *)(a1 + 56) = &dword_63FA70;
      if ( *(int **)(v16 + 4) != &dword_63FA70 )
        __fastfail(3u);
      *(_DWORD *)(v16 + 4) = v11;
      dword_63FA70 = a1 + 52;
    }
  }
  else
  {
    v14 = (void **)dword_63FA7C;
    *v11 = (int)&unk_63FA78;
    *(_DWORD *)(a1 + 56) = v14;
    if ( *v14 != &unk_63FA78 )
      __fastfail(3u);
    *v14 = v11;
    dword_63FA7C = a1 + 52;
    dword_63FA08 += v18;
    if ( (unsigned int)dword_63FA08 >= 0x40000 )
      v5 = 1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiState[v9]);
  }
  else
  {
    __dmb(0xBu);
    MiState[v9] = 0;
  }
  if ( v5 == 1 )
    KeSetEvent((int)&unk_63F9E8, 0, 0);
  return 0;
}
