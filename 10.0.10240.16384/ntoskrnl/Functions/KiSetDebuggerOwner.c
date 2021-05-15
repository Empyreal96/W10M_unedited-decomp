// KiSetDebuggerOwner 
 
unsigned int __fastcall KiSetDebuggerOwner(unsigned int result)
{
  unsigned int v1; // r4
  int *v2; // r2
  unsigned int v3; // r5

  v1 = result;
  if ( result && !KiDebuggerIsStallOwner && KeNumberProcessors_0 != 1 && !MEMORY[0xFFFF93C6] )
    return sub_51C0B4();
  KiFreezeStallOwner = result;
  __dmb(0xBu);
  v2 = &KiDebuggerOwner;
  do
    v3 = __ldrex((unsigned int *)&KiDebuggerOwner);
  while ( __strex(result, (unsigned int *)&KiDebuggerOwner) );
  __dmb(0xBu);
  if ( result )
  {
    if ( result != ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408 )
    {
      KiSetSafeToPowerDownFrozenProcessor(result, 0, &KiDebuggerOwner);
      result = KiTurnOnFrozenProcessorInternal(v1);
      if ( result )
        result = KiWaitForProcessorResume(v1);
    }
    if ( v3 )
      result = KiSetSafeToPowerDownFrozenProcessor(v3, 1, v2);
  }
  __dsb(0xFu);
  __sev();
  return result;
}
