// InbvPortPutByte 
 
int __fastcall InbvPortPutByte(int a1)
{
  return PortPutByte(&Port[3 * a1]);
}
