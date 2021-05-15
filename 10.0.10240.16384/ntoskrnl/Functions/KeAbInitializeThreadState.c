// KeAbInitializeThreadState 
 
int __fastcall KeAbInitializeThreadState(int result)
{
  unsigned int v1; // r2
  int v2; // r1
  int v3; // r4
  int v4; // r3

  v1 = 488;
  v2 = result + 488;
  v3 = 6;
  do
  {
    *(_BYTE *)(v2 + 12) = v1 >> 3;
    v2 += 48;
    v1 += 48;
    --v3;
  }
  while ( v3 );
  *(_BYTE *)(result + 484) = 63;
  v4 = *(_DWORD *)(result + 76);
  *(_DWORD *)(result + 776) = 1;
  *(_DWORD *)(result + 780) = 1;
  *(_DWORD *)(result + 76) = v4 | 1;
  return result;
}
