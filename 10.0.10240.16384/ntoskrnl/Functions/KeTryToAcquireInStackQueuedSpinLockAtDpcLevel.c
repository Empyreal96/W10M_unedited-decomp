// KeTryToAcquireInStackQueuedSpinLockAtDpcLevel 
 
int __fastcall KeTryToAcquireInStackQueuedSpinLockAtDpcLevel(unsigned int *a1, _DWORD *a2)
{
  unsigned int v3; // r2

  *a2 = 0;
  a2[1] = a1;
  __dmb(0xBu);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_513DC0();
  do
    v3 = __ldrex(a1);
  while ( !v3 && __strex((unsigned int)a2, a1) );
  __dmb(0xBu);
  if ( !v3 )
    return 1;
  __dmb(0xAu);
  __yield();
  return 0;
}
