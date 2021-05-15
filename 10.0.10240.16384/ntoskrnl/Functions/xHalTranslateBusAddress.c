// xHalTranslateBusAddress 
 
void __fastcall __noreturn xHalTranslateBusAddress(int a1, int a2, int a3, int a4)
{
  KeBugCheckEx(92, 0, 0, 0, 7);
}
