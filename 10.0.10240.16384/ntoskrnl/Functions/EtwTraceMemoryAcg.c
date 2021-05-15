// EtwTraceMemoryAcg 
 
int __fastcall EtwTraceMemoryAcg(int a1, int a2)
{
  int result; // r0

  result = EtwProviderEnabled(EtwpMemoryProvRegHandle, unk_61A944, 0);
  if ( result )
    result = sub_51D2D8();
  return result;
}
