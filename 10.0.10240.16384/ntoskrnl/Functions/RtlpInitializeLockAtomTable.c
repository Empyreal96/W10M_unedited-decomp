// RtlpInitializeLockAtomTable 
 
int __fastcall RtlpInitializeLockAtomTable(int result)
{
  *(_DWORD *)(result + 8) = 0;
  return result;
}
