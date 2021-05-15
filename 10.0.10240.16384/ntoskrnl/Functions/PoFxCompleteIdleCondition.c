// PoFxCompleteIdleCondition 
 
int __fastcall PoFxCompleteIdleCondition(int result, int a2)
{
  int v2; // r3
  unsigned int *v3; // r2
  unsigned int v4; // r6
  signed int v5; // r6

  v2 = *(_DWORD *)(*(_DWORD *)(result + 392) + 4 * a2);
  __dmb(0xBu);
  v3 = (unsigned int *)(v2 + 84);
  do
  {
    v4 = __ldrex(v3);
    v5 = v4 - 1;
  }
  while ( __strex(v5, v3) );
  __dmb(0xBu);
  if ( !v5 )
    return sub_521898();
  if ( v5 < 0 )
    PopFxBugCheck(1555, result, a2, 2);
  return result;
}
