// PfTTraceListAdd 
 
int __fastcall PfTTraceListAdd(int **a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r7
  unsigned int v7; // r1
  unsigned int v8; // r1
  BOOL v9; // r7
  int *v10; // r5
  int *v11; // r0
  int **v12; // r2
  unsigned int v13; // r3
  unsigned __int8 v14; // r5
  unsigned int v15; // r1
  int v17[8]; // [sp+0h] [bp-20h] BYREF

  v17[2] = a4;
  v17[1] = (int)v17;
  v17[0] = (int)v17;
  v5 = KeAbPreAcquire((unsigned int)&dword_643A80, 0, 0);
  v6 = KfRaiseIrql(1);
  do
    v7 = __ldrex((unsigned __int8 *)&dword_643A80);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)&dword_643A80) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&dword_643A80, v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  dword_643A84 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_643A9C = v6;
  v8 = dword_643A70;
  v9 = dword_643A6C < (unsigned int)dword_643A70;
  if ( a1[5] == (int *)1 )
  {
    v8 = dword_643A78;
    v10 = &dword_643A64;
    v11 = &dword_643A74;
    if ( dword_643A74 + 1 == dword_643A78 )
      ++dword_643B14;
  }
  else
  {
    v10 = &dword_643A5C;
    v11 = &dword_643A6C;
    if ( dword_643A6C + 1 == dword_643A70 )
      ++dword_643B10;
    dword_643A7C = 1;
  }
  v12 = (int **)v10[1];
  *a1 = v10;
  a1[1] = (int *)v12;
  if ( *v12 != v10 )
    __fastfail(3u);
  *v12 = (int *)a1;
  v10[1] = (int)a1;
  v13 = *v11 + 1;
  *v11 = v13;
  if ( v13 > v8 )
    PfTTraceListTrim(a1[5], v8, v17);
  if ( v10 == &dword_643A5C && (int *)*v10 == v10 )
    dword_643A7C = 0;
  if ( v9 && dword_643A6C >= (unsigned int)dword_643A70 )
    PfTAccessTracingCleanup((int)&PfTGlobals, v8, 2);
  KeSetEvent(dword_643AA0, 0, 0);
  dword_643A84 = 0;
  v14 = dword_643A9C;
  __dmb(0xBu);
  do
    v15 = __ldrex(&dword_643A80);
  while ( !v15 && __strex(1u, &dword_643A80) );
  if ( v15 )
    ExpReleaseFastMutexContended(&dword_643A80, v15);
  KfLowerIrql(v14);
  KeAbPostRelease((unsigned int)&dword_643A80);
  return PfTTraceListFree(v17);
}
