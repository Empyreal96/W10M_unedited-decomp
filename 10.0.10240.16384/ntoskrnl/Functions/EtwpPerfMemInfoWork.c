// EtwpPerfMemInfoWork 
 
int __fastcall EtwpPerfMemInfoWork(unsigned int a1)
{
  int v1; // r4

  v1 = *(_DWORD *)(a1 + 16);
  ExFreePoolWithTag(a1);
  return EtwpLogMemInfoWs(0, v1);
}
