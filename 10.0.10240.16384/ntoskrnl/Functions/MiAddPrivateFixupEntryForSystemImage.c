// MiAddPrivateFixupEntryForSystemImage 
 
int __fastcall MiAddPrivateFixupEntryForSystemImage(int a1, unsigned int a2)
{
  unsigned int v4; // r0
  int v6; // r7
  int *v7; // r6
  int v8; // r0
  int v9; // r3
  int v10; // r9
  unsigned int v11; // r1
  unsigned int v12; // r5
  int v13; // r7
  int **v14; // r1
  unsigned int v15; // r0

  v4 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  if ( (v4 & 0x1F) == 0 )
    return sub_5549EC();
  v6 = ExAllocatePoolWithTag(512, 4 * ((v4 >> 5) + 3));
  if ( !v6 )
    return 0;
  v7 = (int *)ExAllocatePoolWithTag(512, 28);
  v8 = v6;
  if ( !v7 )
  {
LABEL_17:
    ExFreePoolWithTag(v8, 0);
    return 0;
  }
  MiInitializePrivateFixupBitmap(v6, a1);
  v7[5] = v6;
  v7[6] = a1;
  v7[2] = a2;
  v7[3] = a2 + (*(_DWORD *)(*(_DWORD *)a1 + 4) << 12) - 1;
  v7[4] = *(_DWORD *)(*(_DWORD *)a1 + 24);
  if ( a2 >= dword_63389C )
  {
    v9 = *((unsigned __int8 *)&MiState[2423]
         + ((int)(((a2 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
    if ( (v9 == 1 || v9 == 11) && (*(_BYTE *)(*(_DWORD *)a1 + 10) & 1) == 0 && !MiCreateSessionDriverProtos(a1, a2, v7) )
    {
      ExFreePoolWithTag(v7, 0);
      v8 = v6;
      goto LABEL_17;
    }
  }
  v10 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    v12 = 288;
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_632F00);
  }
  else
  {
    do
      v11 = __ldrex((unsigned __int8 *)&dword_632F00 + 3);
    while ( __strex(v11 | 0x80, (unsigned __int8 *)&dword_632F00 + 3) );
    __dmb(0xBu);
    v12 = 0x120u;
    if ( v11 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632F00);
    while ( 1 )
    {
      v13 = dword_632F00;
      if ( (dword_632F00 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632F00 & 0x40000000) == 0 )
      {
        do
          v15 = __ldrex((unsigned int *)&dword_632F00);
        while ( v15 == v13 && __strex(v13 | 0x40000000, (unsigned int *)&dword_632F00) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v14 = (int **)dword_632F08;
  *v7 = (int)&dword_632F04;
  v7[1] = (int)v14;
  if ( *v14 != &dword_632F04 )
    __fastfail(3u);
  *v14 = v7;
  dword_632F08 = (int)v7;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiState[v12]);
  }
  else
  {
    __dmb(0xBu);
    MiState[v12] = 0;
  }
  KfLowerIrql(v10);
  return 1;
}
