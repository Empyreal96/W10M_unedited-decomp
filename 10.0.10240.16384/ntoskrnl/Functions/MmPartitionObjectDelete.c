// MmPartitionObjectDelete 
 
int __fastcall MmPartitionObjectDelete(int *a1, int a2, int a3)
{
  int result; // r0
  int v4; // r3

  result = *a1;
  v4 = *(_DWORD *)(result + 4);
  if ( (v4 & 2) != 0 )
    result = MiDereferencePartition(result, a2, a3, v4);
  return result;
}
