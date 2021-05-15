// VfBugCheckNoStackUsage 
 
void __noreturn VfBugCheckNoStackUsage()
{
  KeBugCheck2(VfBugcheckTmpData, dword_909044, dword_909048, dword_90904C, dword_909050, 0);
}
