// NtDebugContinue 
 
int __fastcall NtDebugContinue(int a1, int *a2, int a3, int a4)
{
  int v5; // r4
  int *v6; // r6
  unsigned int v7; // r8
  int v8; // r9
  int v9; // r1
  unsigned int v10; // r2
  int *v11; // r2
  int v12; // lr
  int v13; // r9
  int v14; // r1
  int v15; // r0
  int **v16; // r1
  int v17; // r9
  unsigned int v18; // r1
  char v20; // [sp+8h] [bp-40h]
  int v21; // [sp+Ch] [bp-3Ch] BYREF
  int v22; // [sp+10h] [bp-38h]
  int *v23; // [sp+14h] [bp-34h]
  int v24; // [sp+18h] [bp-30h]
  int *v25; // [sp+20h] [bp-28h]
  int v26; // [sp+24h] [bp-24h]
  int varg_r0; // [sp+50h] [bp+8h]
  int *varg_r1; // [sp+54h] [bp+Ch]
  int varg_r2; // [sp+58h] [bp+10h]
  int varg_r3; // [sp+5Ch] [bp+14h]

  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  varg_r0 = a1;
  v20 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v23 = (int *)*a2;
  v25 = v23;
  v24 = a2[1];
  v26 = v24;
  if ( a3 != -2147418111 && (a3 <= 0x10000 || a3 > 65538 && a3 != 1073807361 && (a3 <= 1073807362 || a3 > 1073807364)) )
    return -1073741811;
  v5 = ObReferenceObjectByHandle(a1, 1, DbgkDebugObjectType, v20, (int)&v21, 0);
  if ( v5 < 0 )
    return v5;
  v22 = 0;
  v6 = 0;
  v7 = v21 + 16;
  v8 = KeAbPreAcquire(v21 + 16, 0, 0);
  v9 = KfRaiseIrql(1);
  v25 = (int *)v9;
  do
    v10 = __ldrex((unsigned __int8 *)v7);
  while ( __strex(v10 & 0xFE, (unsigned __int8 *)v7) );
  __dmb(0xBu);
  if ( (v10 & 1) == 0 )
  {
    ExpAcquireFastMutexContended(v7, v8);
    v9 = (int)v25;
  }
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  *(_DWORD *)(v7 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v7 + 28) = v9;
  v11 = *(int **)(v21 + 48);
  v25 = (int *)(v21 + 48);
  if ( v11 != (int *)(v21 + 48) )
  {
    v12 = (int)v23;
    v13 = v24;
    v14 = 0;
    do
    {
      if ( v11[6] == v12 )
      {
        if ( v14 )
        {
          v11[11] &= 0xFFFFFFFB;
          KeSetEvent(v21, 0, 0);
          break;
        }
        if ( v11[7] == v13 && (v11[11] & 1) != 0 )
        {
          v15 = *v11;
          v16 = (int **)v11[1];
          if ( *(int **)(*v11 + 4) != v11 || *v16 != v11 )
            __fastfail(3u);
          *v16 = (int *)v15;
          *(_DWORD *)(v15 + 4) = v16;
          v6 = v11;
          v22 = 1;
          v14 = 1;
        }
      }
      v11 = (int *)*v11;
    }
    while ( v11 != v25 );
  }
  *(_DWORD *)(v7 + 4) = 0;
  v17 = *(_DWORD *)(v7 + 28);
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)v7);
  while ( !v18 && __strex(1u, (unsigned int *)v7) );
  if ( v18 )
    ExpReleaseFastMutexContended((unsigned int *)v7, v18);
  KfLowerIrql((unsigned __int8)v17);
  KeAbPostRelease(v7);
  ObfDereferenceObject(v21);
  if ( !v22 )
    return -1073741811;
  if ( (PerfGlobalGroupMask[0] & 0x400000) != 0 )
    EtwTraceDebuggerEvent(v6[8], v6[9], 2);
  v6[21] = a3;
  v6[10] = 0;
  DbgkpWakeTarget(v6);
  return v5;
}
