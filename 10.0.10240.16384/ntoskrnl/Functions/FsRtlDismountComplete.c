// FsRtlDismountComplete 
 
void __fastcall FsRtlDismountComplete(int a1, int a2)
{
  unsigned int v2; // r1

  if ( a2 >= 0 )
  {
    __dmb(0xBu);
    do
      v2 = __ldrex((unsigned int *)0xFFFF92DC);
    while ( __strex(v2 + 1, (unsigned int *)0xFFFF92DC) );
    __dmb(0xBu);
  }
}
