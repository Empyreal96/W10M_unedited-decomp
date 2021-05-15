// EtwWriteTransfer 
 
int __fastcall EtwWriteTransfer(int a1, int a2, int a3)
{
  return EtwWriteEx(a1, a2, a3, 0, 0, 0, 0);
}
