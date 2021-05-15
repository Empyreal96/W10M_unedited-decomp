// MiReturnCommit 
 
unsigned int __fastcall MiReturnCommit(int a1, int a2)
{
  unsigned int v4; // r3
  unsigned int result; // r0
  int v6; // r1
  unsigned int v7; // r6
  unsigned int *v8; // r2
  unsigned int v9; // r6
  unsigned int v10; // r2
  unsigned int v11; // r2

  if ( (__int16 *)a1 == MiSystemPartition
    && (v4 = (unsigned int)KeGetPcr(),
        result = (v4 & 0xFFFFF000) + 4988,
        __pld((void *)result),
        v6 = *(_DWORD *)((v4 & 0xFFFFF000) + 0x137C),
        (unsigned int)(v6 + a2) <= 0x100) )
  {
    do
      v7 = __ldrex((unsigned int *)result);
    while ( v7 == v6 && __strex(v6 + a2, (unsigned int *)result) );
    if ( v7 != v6 )
      result = sub_543C10();
  }
  else
  {
    result = -a2;
    v8 = (unsigned int *)(a1 + 3844);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 - a2, v8) );
    v10 = *(_DWORD *)(a1 + 3220);
    if ( v9 >= v10 && v9 - a2 < v10 || (v11 = *(_DWORD *)(a1 + 3216), v9 >= v11) && v9 - a2 < v11 )
      result = MiSyncCommitSignals(a1, 0);
  }
  return result;
}
