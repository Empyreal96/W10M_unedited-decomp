// PspSetJobRateControl 
 
int __fastcall PspSetJobRateControl(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r6
  int v9; // r5
  _DWORD *v10; // r4
  int v11; // r0
  int v12; // r1
  int v13; // r10
  int v14; // r2
  int v15; // r3
  int *v16; // r9
  int v17; // r0
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r4
  int v23; // [sp+8h] [bp-40h]
  int v24; // [sp+10h] [bp-38h] BYREF
  int v25; // [sp+14h] [bp-34h]
  int v26; // [sp+18h] [bp-30h]
  int v27; // [sp+1Ch] [bp-2Ch]
  int v28; // [sp+20h] [bp-28h]
  char v29; // [sp+24h] [bp-24h]

  v9 = 0;
  v10 = 0;
  v23 = PspGetRateControlJobFlag(a2, 1);
  v11 = PspGetRateControlJobFlag(a2, 0);
  v12 = *(_DWORD *)(a1 + 744);
  v13 = v11;
  if ( (v12 & v11) != 0 )
    v6 = 1;
  if ( (v12 & v11) == 0 )
    v6 = 0;
  v16 = (int *)PspGetRateControlHeaderPtr(a1, a2);
  if ( (v14 & 1) != 0 )
  {
    if ( !v15 )
    {
      if ( v6 )
      {
        v9 = -1073741637;
        goto LABEL_21;
      }
      v17 = PspAllocateRateControl(a2);
      v10 = (_DWORD *)v17;
      if ( !v17 )
      {
        v9 = -1073741801;
        goto LABEL_21;
      }
      *v16 = v17;
      __dmb(0xBu);
      v18 = (unsigned int *)(a1 + 744);
      do
        v19 = __ldrex(v18);
      while ( __strex(v19 | v23, v18) );
      __dmb(0xBu);
      PspModifyAncestorBits(a1, v13, 1);
    }
    v24 = 0;
    v25 = a5;
    v26 = a6;
    v27 = a1;
    v29 = 1;
    v28 = a2;
    v9 = PspEnumJobsAndProcessesInJobHierarchy(
           a1,
           (int)PspSetRateControlJobPreCallback,
           0,
           (int)PspSetRateControlProcessCallback,
           (int)&v24,
           5u);
  }
  else
  {
    if ( !v15 )
    {
      v9 = -1073741811;
      goto LABEL_21;
    }
    PspRemoveRateControl(a1, a2, v14, a5, a6);
  }
  if ( v9 >= 0 )
    return v9;
  if ( v10 )
    PspFreeRateControl(v10, a2);
LABEL_21:
  *v16 = 0;
  __dmb(0xBu);
  v20 = (unsigned int *)(a1 + 744);
  do
    v21 = __ldrex(v20);
  while ( __strex(v21 & ~v23, v20) );
  __dmb(0xBu);
  if ( !v6 )
  {
    PspModifyAncestorBits(a1, v13, 0);
    v29 = 0;
    v24 = 0;
    v25 = 0;
    v26 = 0;
    v27 = 0;
    v28 = a2;
    PspEnumJobsAndProcessesInJobHierarchy(
      a1,
      (int)PspSetRateControlJobPreCallback,
      0,
      (int)PspSetRateControlProcessCallback,
      (int)&v24,
      5u);
  }
  return v9;
}
