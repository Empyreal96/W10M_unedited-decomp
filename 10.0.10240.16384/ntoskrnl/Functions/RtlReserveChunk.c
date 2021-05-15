// RtlReserveChunk 
 
int __fastcall RtlReserveChunk(unsigned __int8 a1, int a2, int a3, int a4, int a5)
{
  if ( !a1 || a1 == 1 )
    return -1073741811;
  if ( a1 <= 4u )
    return ((int (__fastcall *)(int, int, int, int))RtlReserveChunkProcs[a1])(a2, a3, a4, a5);
  return -1073741217;
}
