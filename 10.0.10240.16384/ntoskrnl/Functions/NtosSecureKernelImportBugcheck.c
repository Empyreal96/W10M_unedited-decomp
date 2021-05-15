// NtosSecureKernelImportBugcheck 
 
void __noreturn NtosSecureKernelImportBugcheck()
{
  KeBugCheckEx(291, 0, 0, 0, 0);
}
