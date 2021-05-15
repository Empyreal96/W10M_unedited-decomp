// CmpEtwDumpKcb 
 
int __fastcall CmpEtwDumpKcb(int result, int a2)
{
  int v3; // r5
  void (__fastcall *v4)(int, _DWORD *, _DWORD, _DWORD, int, int); // r6
  unsigned int v5; // r4
  _DWORD v6[10]; // [sp+8h] [bp-28h] BYREF

  v3 = result;
  v4 = (void (__fastcall *)(int, _DWORD *, _DWORD, _DWORD, int, int))CmpTraceRoutine;
  v6[0] = 0;
  v6[1] = 0;
  v6[2] = 0;
  v6[3] = 0;
  if ( CmpTraceRoutine )
  {
    result = CmpConstructName(result);
    v5 = result;
    if ( result )
    {
      v4(a2, v6, 0, 0, v3, result);
      result = ExFreePoolWithTag(v5);
    }
  }
  return result;
}
