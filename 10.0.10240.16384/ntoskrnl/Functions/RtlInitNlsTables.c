// RtlInitNlsTables 
 
int __fastcall RtlInitNlsTables(int a1, int a2, int a3)
{
  int result; // r0
  int v6; // r1

  RtlInitCodePageTable(a1, &word_9821B4);
  result = RtlInitCodePageTable(a2, &InitTableInfo);
  v6 = (unsigned __int16)(*(_WORD *)(a3 + 2) + 1);
  dword_9821E0 = a3 + 4;
  dword_9821E4 = a3 + 2 * (v6 + 1);
  return result;
}
