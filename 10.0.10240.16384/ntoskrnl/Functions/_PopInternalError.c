// _PopInternalError 
 
void __fastcall __noreturn PopInternalError(int a1)
{
  KeBugCheckEx(160, 2, a1, 0, 0);
}
