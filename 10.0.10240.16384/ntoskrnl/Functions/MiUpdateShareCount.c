// MiUpdateShareCount 
 
int __fastcall MiUpdateShareCount(int a1, int a2)
{
  int v3; // r2
  int result; // r0

  v3 = *(_DWORD *)(a1 + 12);
  result = (v3 & 0x3FFFFFFF) + a2;
  *(_DWORD *)(a1 + 12) = v3 & 0xC0000000 | result & 0x3FFFFFFF;
  return result;
}
