// MmQuerySpecialPoolBlockSize 
 
int __fastcall MmQuerySpecialPoolBlockSize(int a1)
{
  int v1; // r3
  _DWORD *v2; // r0

  v1 = a1 & 0xFFF;
  v2 = (_DWORD *)(a1 & 0xFFFFF000);
  if ( !v1 )
    v2 += 1022;
  return *v2 & 0xFFF;
}
