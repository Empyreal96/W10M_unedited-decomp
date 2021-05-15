// KeInitializePriQueue 
 
int __fastcall KeInitializePriQueue(int result, int a2)
{
  _DWORD *v2; // r3
  int v3; // r2
  int v4; // r4

  *(_BYTE *)result = 21;
  *(_BYTE *)(result + 2) = 103;
  *(_BYTE *)(result + 1) = 0;
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 8) = result + 8;
  *(_DWORD *)(result + 12) = result + 8;
  *(_DWORD *)(result + 404) = result + 404;
  *(_DWORD *)(result + 408) = result + 404;
  v2 = (_DWORD *)(result + 16);
  v3 = result;
  v4 = 32;
  do
  {
    *v2 = v2;
    v2[1] = v2;
    *(_DWORD *)(v3 + 272) = 0;
    v3 += 4;
    v2 += 2;
    --v4;
  }
  while ( v4 );
  if ( !a2 )
    return sub_50F1A0(result, 0, v3, v2);
  *(_DWORD *)(result + 400) = a2;
  return result;
}
