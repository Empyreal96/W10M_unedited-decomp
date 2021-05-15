// LpcReplyWaitReplyPort 
 
int __fastcall LpcReplyWaitReplyPort(int a1, char a2, int a3)
{
  return LpcpReplyWaitReplyPort(a1, a3, 0, a2);
}
