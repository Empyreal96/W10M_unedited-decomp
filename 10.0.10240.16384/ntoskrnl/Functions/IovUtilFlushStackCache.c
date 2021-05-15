// IovUtilFlushStackCache 
 
int __fastcall IovUtilFlushStackCache(int result)
{
  int v1; // r1

  do
  {
    v1 = result;
    result = *(_DWORD *)(*(_DWORD *)(result + 176) + 24);
  }
  while ( result );
  do
  {
    *(_DWORD *)(*(_DWORD *)(v1 + 176) + 16) &= 0x3FFFFFFFu;
    v1 = *(_DWORD *)(v1 + 16);
  }
  while ( v1 );
  return result;
}
