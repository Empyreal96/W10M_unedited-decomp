// InbvPortTerminate 
 
int __fastcall InbvPortTerminate(int a1)
{
  Port[3 * a1] = 0;
  return 1;
}
