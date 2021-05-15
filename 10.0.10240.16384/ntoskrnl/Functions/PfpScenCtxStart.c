// PfpScenCtxStart 
 
int __fastcall PfpScenCtxStart(int a1, int a2, int a3, int a4)
{
  _DWORD v6[4]; // [sp+0h] [bp-10h] BYREF

  v6[1] = a3;
  v6[2] = a4;
  RtlInitUnicodeString((unsigned int)v6, L"\\KernelObjects\\SuperfetchScenarioNotify");
  return PfpCreateEvent(v6, 0, a1 + 40);
}
