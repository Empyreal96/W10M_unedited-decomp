// LpcRequestWaitReplyPort 
 
int __fastcall LpcRequestWaitReplyPort(int a1, int a2, unsigned int a3)
{
  return LpcpRequestWaitReplyPort(a1, a2, a3, 0, 0, 2);
}
