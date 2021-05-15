// PfSnGetCompletedTrace 
 
int __fastcall PfSnGetCompletedTrace(int a1, unsigned int a2, unsigned int *a3, int a4)
{
  unsigned int *v4; // r10
  int v5; // r9
  int v6; // r8
  int v7; // r1
  unsigned int v8; // r5
  unsigned int v9; // r4
  int v10; // r5
  unsigned int v11; // r3
  int v12; // r1
  unsigned __int8 v13; // r5
  unsigned int v14; // r1
  unsigned __int8 v15; // r4
  unsigned int v16; // r1
  int v19; // [sp+8h] [bp-28h]
  int varg_r0; // [sp+38h] [bp+8h]
  unsigned int varg_r1; // [sp+3Ch] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  v4 = a3;
  v5 = 1;
  v6 = KeAbPreAcquire((unsigned int)&dword_637384, 0, 0);
  v7 = KfRaiseIrql(1);
  v19 = v7;
  do
    v8 = __ldrex((unsigned __int8 *)&dword_637384);
  while ( __strex(v8 & 0xFE, (unsigned __int8 *)&dword_637384) );
  __dmb(0xBu);
  if ( (v8 & 1) == 0 )
  {
    ExpAcquireFastMutexContended((int)&dword_637384, v6);
    v7 = v19;
  }
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  dword_637388 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_6373A0 = v7;
  dword_6373A8 = 2;
  v9 = dword_63737C;
  if ( (int *)dword_63737C == &dword_63737C )
  {
    v10 = -2147483622;
  }
  else
  {
    v11 = *(_DWORD *)(dword_63737C + 16);
    if ( v11 <= a2 )
    {
      v12 = *(_DWORD *)dword_63737C;
      if ( *(int **)(dword_63737C + 4) != &dword_63737C || *(_DWORD *)(v12 + 4) != dword_63737C )
        __fastfail(3u);
      dword_63737C = *(_DWORD *)dword_63737C;
      *(_DWORD *)(v12 + 4) = &dword_63737C;
      --dword_6373A4;
      dword_637388 = 0;
      v13 = dword_6373A0;
      __dmb(0xBu);
      do
        v14 = __ldrex((unsigned int *)&dword_637384);
      while ( !v14 && __strex(1u, (unsigned int *)&dword_637384) );
      if ( v14 )
        ExpReleaseFastMutexContended((unsigned int *)&dword_637384, v14);
      KfLowerIrql(v13);
      KeAbPostRelease((unsigned int)&dword_637384);
      v5 = 0;
      if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
        ProbeForWrite(a1, a2, 8);
      memmove(a1, v9 + 8, *(_DWORD *)(v9 + 16));
      *v4 = *(_DWORD *)(v9 + 16);
      ExFreePoolWithTag(v9);
      v10 = 0;
    }
    else
    {
      *v4 = v11;
      v10 = -1073741789;
    }
  }
  if ( v5 )
  {
    dword_637388 = 0;
    v15 = dword_6373A0;
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)&dword_637384);
    while ( !v16 && __strex(1u, (unsigned int *)&dword_637384) );
    if ( v16 )
      ExpReleaseFastMutexContended((unsigned int *)&dword_637384, v16);
    KfLowerIrql(v15);
    KeAbPostRelease((unsigned int)&dword_637384);
  }
  return v10;
}
