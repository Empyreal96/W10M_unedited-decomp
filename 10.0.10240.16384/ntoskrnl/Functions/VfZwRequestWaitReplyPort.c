// VfZwRequestWaitReplyPort 
 
int __fastcall VfZwRequestWaitReplyPort(int a1, int a2, int a3)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a2);
    ViZwCheckVirtualAddress(a3);
  }
  return pXdvZwRequestWaitReplyPort(a1, a2, a3);
}
