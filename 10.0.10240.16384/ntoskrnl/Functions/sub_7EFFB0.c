// sub_7EFFB0 
 
void sub_7EFFB0()
{
  int v0; // r7
  unsigned __int8 *v1; // r3
  unsigned int v2; // r1

  __dmb(0xBu);
  v1 = (unsigned __int8 *)(v0 + 613);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 | 1, v1) );
  __dmb(0xBu);
  if ( (v2 & 1) == 0 )
  {
    *(_WORD *)(v0 + 442) = KiClockTimerOwner + 32;
    KeInsertQueueDpc(v0 + 440);
  }
  JUMPOUT(0x7850C6);
}
