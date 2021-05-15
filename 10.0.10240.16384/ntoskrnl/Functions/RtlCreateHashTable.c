// RtlCreateHashTable 
 
int __fastcall RtlCreateHashTable(int a1, int a2, int a3)
{
  return RtlpCreateHashTable(a1, 128, a2, a3);
}
