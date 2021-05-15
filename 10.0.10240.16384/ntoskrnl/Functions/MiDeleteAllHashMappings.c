// MiDeleteAllHashMappings 
 
int __fastcall MiDeleteAllHashMappings(int a1)
{
  int v1; // r4
  int result; // r0

  v1 = *(_DWORD *)(a1 + 92);
  result = MiDeletePteRange();
  *(_DWORD *)(v1 + 48) = dword_6342A8;
  return result;
}
