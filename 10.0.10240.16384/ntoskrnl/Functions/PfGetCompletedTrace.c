// PfGetCompletedTrace 
 
int __fastcall PfGetCompletedTrace(unsigned int a1, unsigned int a2, int a3, unsigned int *a4)
{
  int *v4; // r8
  int v5; // r9
  int v6; // r0
  unsigned int v7; // r5
  unsigned int v8; // r1
  int v9; // r4
  int v10; // r5
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r5
  BOOL v14; // lr
  int v15; // r1
  int *v16; // r9
  int *v17; // r2
  unsigned int v18; // r3
  int v19; // r8
  int v20; // r3
  int v21; // r1
  unsigned __int8 v22; // r4
  unsigned int v23; // r1
  unsigned __int8 v24; // r4
  unsigned int v25; // r1
  int v27; // [sp+0h] [bp-58h]
  int v30; // [sp+10h] [bp-48h]
  unsigned int v31; // [sp+14h] [bp-44h]
  unsigned int *v32; // [sp+18h] [bp-40h]
  int v33; // [sp+30h] [bp-28h]
  unsigned int varg_r0; // [sp+60h] [bp+8h]
  unsigned int varg_r1; // [sp+64h] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  v32 = a4;
  v33 = (char)a3;
  v4 = 0;
  v30 = 0;
  v31 = 0;
  v5 = KeAbPreAcquire((unsigned int)&dword_643A80, 0, 0);
  v6 = KfRaiseIrql(1);
  v27 = v6;
  do
    v7 = __ldrex((unsigned __int8 *)&dword_643A80);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)&dword_643A80) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
  {
    ExpAcquireFastMutexContended((int)&dword_643A80, v5);
    v6 = v27;
  }
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  dword_643A84 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_643A9C = v6;
  while ( dword_643A7C )
  {
    dword_643A7C = 0;
    dword_643A84 = 0;
    __dmb(0xBu);
    do
      v8 = __ldrex(&dword_643A80);
    while ( !v8 && __strex(1u, &dword_643A80) );
    if ( v8 )
    {
      ExpReleaseFastMutexContended(&dword_643A80, v8);
      LOBYTE(v6) = v27;
    }
    KfLowerIrql((unsigned __int8)v6);
    KeAbPostRelease((unsigned int)&dword_643A80);
    PfFbBufferListFlushStandby(qword_6439A0);
    v9 = KeAbPreAcquire((unsigned int)&dword_643A80, 0, 0);
    v10 = KfRaiseIrql(1);
    do
      v11 = __ldrex((unsigned __int8 *)&dword_643A80);
    while ( __strex(v11 & 0xFE, (unsigned __int8 *)&dword_643A80) );
    __dmb(0xBu);
    if ( (v11 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&dword_643A80, v9);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    dword_643A84 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    LOBYTE(v6) = v10;
    LOBYTE(v27) = v10;
    dword_643A9C = v10;
  }
  v12 = dword_643A6C;
  v13 = dword_643A70;
  v14 = dword_643A6C >= (unsigned int)dword_643A70;
  v15 = 0;
  while ( 1 )
  {
    if ( v15 )
    {
      v16 = &dword_643A5C;
      v17 = &dword_643A6C;
    }
    else
    {
      v16 = &dword_643A64;
      v17 = &dword_643A74;
    }
    if ( (int *)*v16 != v16 )
      break;
    if ( (unsigned int)++v15 >= 2 )
    {
      v22 = v27;
      goto LABEL_33;
    }
  }
  v30 = *v16;
  v4 = (int *)*v16;
  v18 = *(_DWORD *)(*v16 + 16) + 16;
  v31 = v18;
  if ( v18 > a2 )
  {
    *v32 = v18;
    v19 = -1073741789;
    v20 = 1;
    goto LABEL_46;
  }
  v21 = *v4;
  if ( (int *)v4[1] != v16 || *(int **)(v21 + 4) != v4 )
    __fastfail(3u);
  *v16 = v21;
  *(_DWORD *)(v21 + 4) = v16;
  --*v17;
  v22 = dword_643A9C;
  v13 = dword_643A70;
  v12 = dword_643A6C;
LABEL_33:
  if ( v14 && v12 < v13 )
  {
    PfTAccessTracingStart((int)&PfTGlobals, (int)&PfKernelGlobals, 2);
    KeSetEvent((int)algn_643B4C, 0, 0);
    v22 = dword_643A9C;
  }
  dword_643A84 = 0;
  __dmb(0xBu);
  do
    v23 = __ldrex(&dword_643A80);
  while ( !v23 && __strex(1u, &dword_643A80) );
  if ( v23 )
    ExpReleaseFastMutexContended(&dword_643A80, v23);
  KfLowerIrql(v22);
  KeAbPostRelease((unsigned int)&dword_643A80);
  v20 = 0;
  if ( v4 )
  {
    if ( v33 )
      ProbeForWrite(a1, a2, 8);
    *(_DWORD *)a1 = 0;
    *(_DWORD *)(a1 + 4) = 0;
    *(_DWORD *)(a1 + 8) = 0;
    *(_DWORD *)(a1 + 12) = 0;
    *(_WORD *)a1 = 1;
    *(_WORD *)(a1 + 2) = 16;
    *(_QWORD *)(a1 + 8) = (((unsigned int)dword_637338 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                        + (((unsigned int)dword_63733C * (unsigned __int64)MEMORY[0xFFFF9004]) << 8);
    memmove(a1 + 16, v30 + 8, *(_DWORD *)(v30 + 16));
    *v32 = v31;
    PfTFreeTraceDump(v30);
    v19 = 0;
    v20 = 0;
  }
  else
  {
    v19 = -2147483622;
  }
LABEL_46:
  if ( v20 )
  {
    dword_643A84 = 0;
    v24 = dword_643A9C;
    __dmb(0xBu);
    do
      v25 = __ldrex(&dword_643A80);
    while ( !v25 && __strex(1u, &dword_643A80) );
    if ( v25 )
      ExpReleaseFastMutexContended(&dword_643A80, v25);
    KfLowerIrql(v24);
    KeAbPostRelease((unsigned int)&dword_643A80);
  }
  return v19;
}
