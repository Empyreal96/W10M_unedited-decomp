// PopDefaultPolicy 
 
int __fastcall PopDefaultPolicy(int a1)
{
  int result; // r0
  int v3; // r3
  int v4; // r2

  memset((_BYTE *)a1, 0, 232);
  result = 0;
  *(_DWORD *)a1 = 1;
  *(_DWORD *)(a1 + 40) = 1;
  *(_DWORD *)(a1 + 68) = 2;
  *(_DWORD *)(a1 + 72) = 4;
  *(_DWORD *)(a1 + 92) = 1;
  v3 = a1;
  v4 = 4;
  *(_DWORD *)(a1 + 76) = 2;
  *(_DWORD *)(a1 + 80) = 0;
  *(_DWORD *)(a1 + 220) = 0;
  do
  {
    *(_DWORD *)(v3 + 116) = 2;
    v3 += 24;
    --v4;
  }
  while ( v4 );
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 4) = 6;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 16) = 2;
  *(_DWORD *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 28) = 0;
  return result;
}
