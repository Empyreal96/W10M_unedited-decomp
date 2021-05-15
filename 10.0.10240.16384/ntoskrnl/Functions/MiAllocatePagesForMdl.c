// MiAllocatePagesForMdl 
 
int __fastcall MiAllocatePagesForMdl(__int16 *a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5, int a6, unsigned __int16 a7, int a8)
{
  unsigned int v10; // r7
  int result; // r0
  int v12; // r6
  int v13; // r0
  int v14; // r5
  int v15; // r10
  unsigned int v16; // r4
  int v17; // r9
  unsigned int v18; // r3
  unsigned int v19; // r5
  int v20; // r7
  unsigned int v21; // r0
  unsigned int v22; // r4
  unsigned int *v23; // r2
  unsigned int v24; // r0
  int v25; // [sp+18h] [bp-30h]
  int v26; // [sp+20h] [bp-28h]
  int v27; // [sp+24h] [bp-24h]
  __int16 *varg_r0; // [sp+50h] [bp+8h]

  varg_r0 = a1;
  v26 = a2 >> 12;
  v10 = a3 >> 12;
  if ( v10 > dword_633850 )
    v10 = dword_633850;
  if ( (a4 & 0xFFF) != 0 )
    return sub_511D38();
  v12 = a8;
  v13 = MiObtainMdlCharges((int)a1, a2 >> 12, v10, a4 >> 12, a5, a6, a8);
  v14 = v13;
  v25 = v13;
  if ( !v13 )
    return sub_511D38();
  v15 = *(_DWORD *)(v13 + 20) >> 12;
  v16 = 0;
  v17 = 0;
  *(_DWORD *)(v13 + 20) = 0;
  while ( 1 )
  {
    v27 = *(_DWORD *)(v14 + 20);
    if ( MiFindPagesForMdl(a1, v14, a8, a6, v15, v26, v10, a4 >> 12, a7) == 1 )
      v17 = 1;
    v18 = *(_DWORD *)(v14 + 20);
    v19 = v18 >> 12;
    if ( v18 >> 12 == v15 )
      break;
    if ( (a8 & 0x80) == 0 )
      goto LABEL_18;
    if ( v27 == v18 )
    {
      if ( v16 > 3 || (unsigned int)KeGetCurrentIrql() >= 2 || (a8 & 8) != 0 )
      {
LABEL_18:
        if ( (a8 & 4) != 0 )
          v12 = a8 | 1;
        break;
      }
      KeDelayExecutionThread(0, 0, Mi10Milliseconds);
      ++v16;
    }
    else
    {
      v16 = 0;
    }
    v14 = v25;
  }
  v20 = v15 - v19;
  if ( v15 != v19 )
  {
    if ( a1 == &MiSystemPartition )
    {
      MiReturnResidentAvailable(v15 - v19);
      do
        v21 = __ldrex(&dword_634A2C[31]);
      while ( __strex(v21 + v20, &dword_634A2C[31]) );
    }
    else
    {
      v23 = (unsigned int *)(a1 + 1920);
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 + v20, v23) );
    }
    if ( a1 == &MiSystemPartition )
    {
      do
        v22 = __ldrex((unsigned int *)&dword_634D94);
      while ( __strex(v22 - v20, (unsigned int *)&dword_634D94) );
    }
    MiReturnCommit(a1, v15 - v19);
  }
  if ( (v12 & 1) != 0 )
    v17 = 0;
  result = MiInitializeMdlPages(a1, v25, v15, v12, a6, v17);
  if ( result )
  {
    if ( (v12 & 0x100) != 0 )
      result = MiRemoveMdlPages();
  }
  return result;
}
