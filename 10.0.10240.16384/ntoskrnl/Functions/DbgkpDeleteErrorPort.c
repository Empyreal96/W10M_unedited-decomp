// DbgkpDeleteErrorPort 
 
unsigned int __fastcall DbgkpDeleteErrorPort(unsigned int a1)
{
  ObCloseHandle(*(_DWORD *)(a1 + 8));
  return ExFreePoolWithTag(a1);
}
