// PoFxCompleteIdleState 
 
void *__fastcall PoFxCompleteIdleState(int a1, int a2)
{
  void *result; // r0
  int v5; // r1
  unsigned int *v6; // r2
  unsigned int v7; // r4
  unsigned int v8; // r4
  int v9; // [sp+0h] [bp-30h] BYREF
  char v10[28]; // [sp+4h] [bp-2Ch] BYREF

  v9 = 0;
  result = memset(v10, 0, sizeof(v10));
  v5 = *(_DWORD *)(*(_DWORD *)(a1 + 392) + 4 * a2);
  __dmb(0xBu);
  v6 = (unsigned int *)(v5 + 88);
  do
  {
    v7 = __ldrex(v6);
    v8 = v7 - 1;
  }
  while ( __strex(v8, v6) );
  __dmb(0xBu);
  if ( !v8 )
  {
    PopDiagTraceFxComponentIdleState(*(_DWORD *)(a1 + 28), a2, *(_DWORD *)(v5 + 104));
    result = (void *)PopPluginComponentIdleState(a1, a2);
    if ( result )
      result = PopFxProcessWork(0, &v9);
  }
  return result;
}
