// PspSelectNodeForProcess 
 
int PspSelectNodeForProcess()
{
  unsigned int v0; // r1
  signed int v1; // r1
  int v2; // r1
  int result; // r0

  __dmb(0xBu);
  do
  {
    v0 = __ldrex(&PspProcessNodeAssignment);
    v1 = v0 + 1;
  }
  while ( __strex(v1, &PspProcessNodeAssignment) );
  __dmb(0xBu);
  if ( !KeNumberNodes )
    __brkdiv0();
  v2 = v1 % (unsigned __int16)KeNumberNodes;
  if ( *((_DWORD *)*(&KeNodeBlock + (unsigned __int16)v2) + 65) )
    result = (int)*(&KeNodeBlock + (unsigned __int16)v2);
  else
    result = sub_7E9D90();
  return result;
}
