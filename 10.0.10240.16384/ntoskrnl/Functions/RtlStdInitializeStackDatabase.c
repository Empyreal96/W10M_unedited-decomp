// RtlStdInitializeStackDatabase 
 
int __fastcall RtlStdInitializeStackDatabase(int a1, int a2, unsigned int a3, _DWORD *a4)
{
  int v7; // r1
  unsigned int v8; // r7
  unsigned int v9; // r3
  unsigned int v10; // r1
  int v11; // r2

  if ( a2 && (a2 != a3 || !a1) )
    return -1073741811;
  v7 = 5569;
  if ( a3 >= 0x1000000 )
    v7 = 9551;
  v8 = 12 * v7 + 392;
  if ( a3 <= v8 || !a1 || a2 != a3 )
    return -1073741811;
  *(_BYTE *)(a1 + 68) = 1;
  *(_DWORD *)(a1 + 376) = v7;
  *(_DWORD *)(a1 + 88) = a1 + a3;
  *(_DWORD *)(a1 + 100) = a1 + a3;
  *(_DWORD *)(a1 + 72) = a1;
  memset((_BYTE *)(a1 + 380), 0, 12 * v7);
  v9 = ((v8 + 7) & 0xFFFFFFF8) + a1 + 4;
  *(_DWORD *)(a1 + 84) = v9;
  *(_DWORD *)(a1 + 64) = v9;
  memset((_BYTE *)(a1 + 120), 0, 256);
  *(_DWORD *)a1 = 0;
  *(_BYTE *)(a1 + 4) = 0;
  v10 = 0;
  if ( *(_DWORD *)(a1 + 376) )
  {
    v11 = a1 + 384;
    do
    {
      *(_DWORD *)v11 = 0;
      *(_BYTE *)(v11 + 4) = 0;
      ++v10;
      v11 += 12;
    }
    while ( v10 < *(_DWORD *)(a1 + 376) );
  }
  *a4 = a1;
  return 0;
}
