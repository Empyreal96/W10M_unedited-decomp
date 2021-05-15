// FsRtlNotifyCleanup 
 
unsigned int __fastcall FsRtlNotifyCleanup(int a1, int a2, int a3, int a4)
{
  int v5; // r2
  unsigned int v7; // r8
  unsigned int v8; // r9
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r4
  unsigned int result; // r0
  unsigned int *v13; // r4
  int v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r4
  unsigned int v17; // [sp+0h] [bp-28h] BYREF
  int v18; // [sp+4h] [bp-24h]
  int v19; // [sp+8h] [bp-20h]
  unsigned int *varg_r0; // [sp+30h] [bp+8h]
  int varg_r1; // [sp+34h] [bp+Ch]
  int varg_r2; // [sp+38h] [bp+10h]
  int varg_r3; // [sp+3Ch] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v19 = a4;
  v5 = a2;
  v18 = a2;
  varg_r0 = (unsigned int *)a1;
  v17 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( v7 != *(_DWORD *)(a1 + 32) )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v9 = KeAbPreAcquire(a1, 0, 0);
    v10 = v9;
    do
      v11 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v11 & 0xFE, (unsigned __int8 *)a1) );
    __dmb(0xBu);
    if ( (v11 & 1) == 0 )
      ExpAcquireFastMutexContended(a1, v9);
    if ( v10 )
      *(_BYTE *)(v10 + 14) |= 1u;
    *(_DWORD *)(a1 + 4) = v8;
    *(_DWORD *)(a1 + 32) = v7;
    v5 = v18;
  }
  ++*(_DWORD *)(a1 + 36);
  result = FsRtlIsNotifyOnList(v5, a3);
  if ( result )
    result = FsRtlNotifyCleanupOneEntry(result, &v17);
  v13 = varg_r0;
  v14 = varg_r0[9] - 1;
  varg_r0[9] = v14;
  if ( !v14 )
  {
    v13[8] = 0;
    v13[1] = 0;
    __dmb(0xBu);
    do
      v15 = __ldrex(v13);
    while ( !v15 && __strex(1u, v13) );
    if ( v15 )
      ExpReleaseFastMutexContended(v13, v15);
    result = KeAbPostRelease((unsigned int)v13);
  }
  v16 = v17;
  if ( v17 )
  {
    SeReleaseSubjectContext(v17);
    result = ExFreePoolWithTag(v16);
  }
  return result;
}
