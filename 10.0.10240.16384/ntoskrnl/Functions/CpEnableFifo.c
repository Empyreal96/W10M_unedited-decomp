// CpEnableFifo 
 
int __fastcall CpEnableFifo(int a1, int a2)
{
  return WRITE_UCHAR(a1 + 2 * CpRegisterWidth, a2);
}
