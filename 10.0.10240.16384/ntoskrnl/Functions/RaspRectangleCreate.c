// RaspRectangleCreate 
 
int __fastcall RaspRectangleCreate(_DWORD *a1, int a2, _DWORD *a3)
{
  unsigned int v6; // r4
  int v7; // r2
  int result; // r0
  int v9; // r2

  v6 = (unsigned int)(a1[1] * *a1 * a2 + 7) >> 3;
  v7 = RaspAllocateMemory(v6 + 64);
  if ( !v7 )
    return -1073741801;
  result = BgpGxInitializeRectangle(a1, a2, v7, v6 + 64);
  *a3 = v9;
  return result;
}
