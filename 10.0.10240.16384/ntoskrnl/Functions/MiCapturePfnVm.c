// MiCapturePfnVm 
 
int __fastcall MiCapturePfnVm(int *a1, int a2, int *a3, unsigned int *a4, int *a5)
{
  int v5; // r10
  int *v7; // r6
  unsigned __int8 *v10; // r1
  unsigned int v11; // r5
  int v13; // r0
  int v14; // r2
  int *v15; // r0
  int *v16; // r5
  int v17; // r4
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r4
  int v22; // r0
  int v23; // r3
  int v25; // [sp+4h] [bp-24h]

  v5 = *a1;
  v7 = 0;
  *a3 = 0;
  v25 = KfRaiseIrql(2);
  v10 = (unsigned __int8 *)(a2 + 15);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 0x80, v10) );
  __dmb(0xBu);
  if ( v11 >> 7 )
    return sub_54EB3C();
  v13 = MiCombineCandidate(a1, a2);
  if ( v13 )
  {
    *a4 = *(_DWORD *)(a2 + 4) | 0x80000000;
    v14 = (*(_DWORD *)(a2 + 8) >> 5) & 0x1F;
    *a5 = v14;
    if ( v13 == 1 )
    {
      v15 = (int *)MiGetTopLevelPfn(a2, 0, v14, (int)a5);
      v16 = v15;
      v17 = *v15;
      v7 = (int *)(*v15 + 492);
      if ( *v15 == PsInitialSystemProcess && *(_DWORD *)(v5 + 672) )
        v7 = 0;
      if ( ObReferenceObjectSafeWithTag(*v15) )
        *a3 = v17;
      else
        v7 = 0;
      if ( v16 != (int *)a2 )
      {
        __dmb(0xBu);
        v18 = (unsigned int *)(v16 + 3);
        do
          v19 = __ldrex(v18);
        while ( __strex(v19 & 0x7FFFFFFF, v18) );
      }
    }
    else if ( v13 == 2 )
    {
      v7 = &dword_634E80;
    }
    else
    {
      v22 = MiAttachToOwningSession(a2, 17, 0);
      if ( v22 )
      {
        v23 = *(_DWORD *)(v22 + 324);
        *a3 = v22;
        v7 = (int *)(v23 + 3248);
      }
      else
      {
        v7 = 0;
      }
    }
  }
  __dmb(0xBu);
  v20 = (unsigned int *)(a2 + 12);
  do
    v21 = __ldrex(v20);
  while ( __strex(v21 & 0x7FFFFFFF, v20) );
  KfLowerIrql(v25);
  return (int)v7;
}
