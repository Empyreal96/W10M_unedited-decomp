// FsRtlNotifyCleanupAll 
 
unsigned int __fastcall FsRtlNotifyCleanupAll(unsigned int result, _DWORD **a2)
{
  int v3; // r4
  unsigned int v4; // r8
  unsigned int v5; // r9
  unsigned int v6; // r5
  unsigned int v7; // r2
  _DWORD *v8; // r4
  int v9; // r0
  int v10; // r3
  unsigned int v11; // r1
  unsigned int *vars8; // [sp+28h] [bp+8h]
  _DWORD **_2C; // [sp+2Ch] [bp+Ch]

  _2C = a2;
  v3 = result;
  vars8 = (unsigned int *)result;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( v4 != *(_DWORD *)(result + 32) )
  {
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    result = KeAbPreAcquire(result, 0, 0);
    v6 = result;
    do
      v7 = __ldrex((unsigned __int8 *)v3);
    while ( __strex(v7 & 0xFE, (unsigned __int8 *)v3) );
    __dmb(0xBu);
    if ( (v7 & 1) == 0 )
      result = ExpAcquireFastMutexContended(v3, result);
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    *(_DWORD *)(v3 + 4) = v5;
    *(_DWORD *)(v3 + 32) = v4;
  }
  ++*(_DWORD *)(v3 + 36);
  v8 = *a2;
  while ( v8 != a2 )
  {
    v9 = (int)(v8 - 4);
    v8 = (_DWORD *)*v8;
    result = FsRtlNotifyCleanupOneEntry(v9);
  }
  v10 = vars8[9] - 1;
  vars8[9] = v10;
  if ( !v10 )
  {
    vars8[8] = 0;
    vars8[1] = 0;
    __dmb(0xBu);
    do
      v11 = __ldrex(vars8);
    while ( !v11 && __strex(1u, vars8) );
    if ( v11 )
      ExpReleaseFastMutexContended(vars8, v11);
    result = KeAbPostRelease((unsigned int)vars8);
  }
  return result;
}
