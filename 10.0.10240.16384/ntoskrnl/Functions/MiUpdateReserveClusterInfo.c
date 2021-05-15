// MiUpdateReserveClusterInfo 
 
int __fastcall MiUpdateReserveClusterInfo(int a1, int a2)
{
  int result; // r0
  unsigned int v3; // r1
  unsigned int *v4; // r2

  if ( a2 )
    return sub_555A94();
  v3 = (((*(_DWORD *)(a1 + 512) & 0xFFFFF800 | 0x400) & 0xFFFFF800) + 2048) ^ (*(_DWORD *)(a1 + 512) & 0xFFFFF800 | 0x400) & 0x7FF;
  v4 = (unsigned int *)(a1 + 512);
  do
    result = __ldrex(v4);
  while ( __strex(v3, v4) );
  return result;
}
