// KeRemoveQueueEntry 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeRemoveQueueEntry(int a1, int a2)
{
  int v3; // r6
  int v5; // r0
  unsigned int v6; // r2
  int v8; // r1 OVERLAPPED
  _DWORD *v9; // r2 OVERLAPPED
  unsigned int v10; // r1

  v3 = 0;
  v5 = KfRaiseIrql(2);
  do
    v6 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v6 | 0x80, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    return sub_525A94(v5);
  if ( *(_DWORD *)a2 )
  {
    --*(_DWORD *)(a1 + 4);
    *(_QWORD *)&v8 = *(_QWORD *)a2;
    if ( *(_DWORD *)(*(_DWORD *)a2 + 4) != a2 || *v9 != a2 )
      __fastfail(3u);
    *v9 = v8;
    *(_DWORD *)(v8 + 4) = v9;
    v3 = 1;
  }
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)a1);
  while ( __strex(v10 & 0xFFFFFF7F, (unsigned int *)a1) );
  KfLowerIrql(v5);
  return v3;
}
