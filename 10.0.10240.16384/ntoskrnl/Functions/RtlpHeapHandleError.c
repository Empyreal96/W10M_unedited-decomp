// RtlpHeapHandleError 
 
void __noreturn RtlpHeapHandleError()
{
  KeBugCheck2(314, dword_618308, dword_61830C, dword_618310, 0, 0);
}
