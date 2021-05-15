// InbvPortEnableFifo 
 
int __fastcall InbvPortEnableFifo(int a1)
{
  return PortEnableFifo(Port[3 * a1]);
}
