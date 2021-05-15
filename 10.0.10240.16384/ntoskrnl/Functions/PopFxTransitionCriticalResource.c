// PopFxTransitionCriticalResource 
 
int __fastcall PopFxTransitionCriticalResource(int a1, int a2, int a3)
{
  int v4; // r5
  unsigned int *v5; // r6
  unsigned int v6; // r4
  unsigned int v7; // r3
  unsigned int v8; // r1

  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 392) + 4 * a2);
  __dmb(0xBu);
  v5 = (unsigned int *)(v4 + 56);
  do
    v6 = __ldrex(v5);
  while ( !v6 && __strex(0, v5) );
  __dmb(0xBu);
  if ( a3 )
  {
    if ( (v6 & 1) == 0 )
      PopFxBugCheck(1542, v4, *v5, a3);
    v7 = v6 & 0xFFFFFFFE;
  }
  else
  {
    if ( (v6 & 1) != 0 )
      PopFxBugCheck(1542, v4, *v5, 0);
    v7 = v6 | 1;
  }
  __dmb(0xBu);
  do
    v8 = __ldrex(v5);
  while ( v8 == v6 && __strex(v7, v5) );
  __dmb(0xBu);
  if ( v8 != v6 )
    PopFxBugCheck(1542, v4, v4 + 52, v7);
  return (*(int (__fastcall **)(_DWORD, int, int))(a1 + 84))(*(_DWORD *)(a1 + 88), a2, a3);
}
