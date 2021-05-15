// PspAssociateCompletionPortCallback 
 
int __fastcall PspAssociateCompletionPortCallback(int a1, int a2)
{
  if ( (*(_DWORD *)(a1 + 188) & 1) == 0 )
  {
    RtlInterlockedSetClearBits((unsigned int *)(a1 + 188), 4);
    PspSendJobNotification(a2);
  }
  return 0;
}
