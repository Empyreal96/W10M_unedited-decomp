// PopUserPresentSetWorker 
 
int __fastcall PopUserPresentSetWorker(int a1, int a2)
{
  int result; // r0
  unsigned int v3; // r1
  unsigned int v4; // r1

  if ( byte_61EC11 )
    return sub_7EA95C();
  PopNotifyConsoleUserPresent(0, a2, a1);
  __dmb(0xBu);
  result = 0;
  do
    v3 = __ldrex((unsigned int *)&PopUserPresentSetStatus);
  while ( __strex(0, (unsigned int *)&PopUserPresentSetStatus) );
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&algn_61EC13[1]);
  while ( !v4 && __strex(0, (unsigned int *)&algn_61EC13[1]) );
  __dmb(0xBu);
  if ( v4 )
    result = KeSetEvent((int)&PopUserPresentCompletedEvent, 0, 0);
  return result;
}
