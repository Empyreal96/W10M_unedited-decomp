// MiFinishResume 
 
int __fastcall MiFinishResume(int a1)
{
  unsigned int v1; // r1

  if ( a1 )
  {
    MiPurgeTransitionList();
    dword_634348 = 0;
  }
  MiPurgeZeroList();
  __dmb(0xBu);
  do
    v1 = __ldrex((unsigned int *)&dword_634C84);
  while ( __strex(v1 - 1, (unsigned int *)&dword_634C84) );
  dword_634374 = -1;
  return KeSetEvent((int)&unk_634358, 0, 0);
}
