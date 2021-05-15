// MiSystemImageHasPrivateFixups 
 
int __fastcall MiSystemImageHasPrivateFixups(unsigned int a1, _DWORD *a2, unsigned int *a3)
{
  bool v3; // zf
  int v5; // r10
  int v7; // r4
  unsigned int v8; // r1
  unsigned int v9; // r0
  int *v10; // r1
  unsigned int v11; // r4
  unsigned int v12; // r1
  int v13; // r3
  int v14; // r4
  unsigned int v15; // r0
  int v18; // [sp+8h] [bp-20h]

  *a3 = 0;
  v3 = dword_632F04 == (_DWORD)&dword_632F04;
  *a2 = 0;
  if ( v3 )
    return 0;
  if ( (a1 < dword_63389C
     || *((_BYTE *)&MiState[2423] + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) != 12)
    && (!PsNtosImageBase
     || (a1 < PsNtosImageBase || a1 >= PsNtosImageEnd) && (a1 < PsHalImageBase || a1 >= PsHalImageEnd)) )
  {
    if ( a1 < dword_63389C )
      return 0;
    v13 = *((unsigned __int8 *)&MiState[2423]
          + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
    if ( v13 != 11 && v13 != 1 )
      return 0;
  }
  v5 = 0;
  v18 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51F5AC();
  v7 = dword_632F00 & 0x7FFFFFFF;
  v8 = (dword_632F00 & 0x7FFFFFFF) + 1;
  do
    v9 = __ldrex((unsigned int *)&dword_632F00);
  while ( v9 == v7 && __strex(v8, (unsigned int *)&dword_632F00) );
  __dmb(0xBu);
  if ( v9 != v7 )
    ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&dword_632F00);
  v10 = (int *)dword_632F04;
  if ( (int *)dword_632F04 != &dword_632F04 )
  {
    while ( a1 < v10[2] || a1 > v10[3] )
    {
      v10 = (int *)*v10;
      if ( v10 == &dword_632F04 )
        goto LABEL_15;
    }
    v14 = v10[2];
    v15 = (a1 - v14) >> 12;
    if ( ((*(char *)(((a1 - v14) >> 15) + *(_DWORD *)(v10[5] + 4)) >> (v15 & 7)) & 1) != 0 )
    {
      v5 = v14 - v10[4];
      *a3 = v15;
      *a2 = v10[6];
    }
    else
    {
      v5 = 0;
    }
  }
LABEL_15:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_632F00);
  }
  else
  {
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&dword_632F00);
    while ( __strex(v11 & 0xBFFFFFFF, (unsigned int *)&dword_632F00) );
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)&dword_632F00);
    while ( __strex(v12 - 1, (unsigned int *)&dword_632F00) );
  }
  KfLowerIrql(v18);
  return v5;
}
