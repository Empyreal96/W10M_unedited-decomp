// ExpInitializeThreadHistory 
 
__int64 __fastcall ExpInitializeThreadHistory(__int64 result)
{
  unsigned __int8 v1; // r2
  int v2; // r3

  v1 = 0;
  *(_DWORD *)(result + 88) &= 0xFFFFFFF8;
  v2 = 0;
  HIDWORD(result) = 0;
  do
  {
    *(_DWORD *)(result + 4 * v2 + 32) = 0;
    v2 = ++v1;
  }
  while ( v1 < 4u );
  return result;
}
