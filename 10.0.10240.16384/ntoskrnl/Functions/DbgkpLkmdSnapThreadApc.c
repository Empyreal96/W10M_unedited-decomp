// DbgkpLkmdSnapThreadApc 
 
int __fastcall DbgkpLkmdSnapThreadApc(int a1, int a2, int a3, unsigned int *a4, int *a5)
{
  int v5; // r5
  unsigned int v6; // r0
  int v7; // r4
  unsigned int v8; // r2

  v5 = __mrc(15, 0, 13, 0, 3);
  v6 = *a4;
  v7 = *a5;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)v7);
  while ( !v8 && __strex(2u, (unsigned int *)v7) );
  __dmb(0xBu);
  if ( v8 )
    return ExFreePoolWithTag(v6);
  if ( DbgkpLkmdSnapThreadInContext(*(_DWORD *)(v7 + 4), v5 & 0xFFFFFFC0, *(_DWORD *)(v7 + 12)) >= 0 )
    DbgkpLkmdSnapPendingIrps(*(_DWORD *)(v7 + 4), v5 & 0xFFFFFFC0, *(int **)(v7 + 12));
  return KeSetEvent(v7 + 16, 0, 0);
}
