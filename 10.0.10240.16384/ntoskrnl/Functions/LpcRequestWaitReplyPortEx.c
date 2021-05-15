// LpcRequestWaitReplyPortEx 
 
int LpcRequestWaitReplyPortEx()
{
  __mrc(15, 0, 13, 0, 3);
  return LpcpRequestWaitReplyPort();
}
