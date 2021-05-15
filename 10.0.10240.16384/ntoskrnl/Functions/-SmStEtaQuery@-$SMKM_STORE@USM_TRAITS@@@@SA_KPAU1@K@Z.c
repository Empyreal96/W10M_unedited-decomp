// -SmStEtaQuery@-$SMKM_STORE@USM_TRAITS@@@@SA_KPAU1@K@Z 
 
unsigned __int64 __fastcall SMKM_STORE<SM_TRAITS>::SmStEtaQuery(int a1, int a2, int a3, int a4)
{
  int v7; // r2
  unsigned int v8; // r1
  int v9; // r7
  int v10; // r8
  int v11; // r5
  unsigned int v12; // r9
  unsigned int v13; // r10
  int i; // r4
  __int64 v15; // r0
  int v16; // [sp+0h] [bp-28h] BYREF
  int v17; // [sp+4h] [bp-24h]
  int v18; // [sp+8h] [bp-20h]

  v16 = a2;
  v17 = a3;
  v18 = a4;
  if ( !*(_BYTE *)(a1 + 3516) )
    return 0i64;
  v7 = *(_DWORD *)(a1 + 1592);
  if ( *(int *)(v7 + 8) <= 0 )
  {
    KeQueryPerformanceCounter(&v16, 0);
    v9 = v16;
    v10 = v17;
  }
  else
  {
    v8 = *(_DWORD *)(v7 + 12);
    __dmb(0xBu);
    v10 = (*(_QWORD *)v7 + (unsigned __int64)v8) >> 32;
    v9 = *(_DWORD *)v7 + v8;
  }
  v11 = *(_DWORD *)(a1 + 1592);
  v12 = *(_DWORD *)(a1 + 3592);
  v13 = *(_DWORD *)(a1 + 3596);
  for ( i = *(_DWORD *)(v11 + 16); *(_DWORD *)i < (unsigned int)(a2 << 12); i += 32 )
    ;
  ++*(_WORD *)(i + 4);
  LODWORD(v15) = KeQueryInterruptTime();
  *(_QWORD *)(v11 + 32) = v15;
  return *(_QWORD *)(i + 8) + __PAIR64__(v10, v9) + __PAIR64__(v13, v12);
}
