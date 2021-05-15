// HvpCleanMap 
 
int __fastcall HvpCleanMap(int a1)
{
  int result; // r0
  int v3; // r3
  unsigned int v4; // r3
  int v5; // r5
  int v6; // r1
  int v7; // r0

  result = *(_DWORD *)(a1 + 40);
  if ( result )
  {
    (*(void (__fastcall **)(int, _DWORD))(a1 + 16))(result, *(_DWORD *)(a1 + 48));
    result = (*(int (__fastcall **)(_DWORD, _DWORD))(a1 + 16))(*(_DWORD *)(a1 + 56), *(_DWORD *)(a1 + 48));
    *(_DWORD *)(a1 + 40) = 0;
    *(_DWORD *)(a1 + 56) = 0;
    *(_DWORD *)(a1 + 48) = 0;
  }
  v3 = *(_DWORD *)(a1 + 952) >> 12;
  if ( v3 )
    v4 = (unsigned int)(v3 - 1) >> 9;
  else
    v4 = 0;
  v5 = *(_DWORD *)(a1 + 956);
  if ( v5 == a1 + 960 )
  {
    v7 = *(_DWORD *)(a1 + 960);
    v6 = 10240;
    goto LABEL_10;
  }
  if ( v5 )
  {
    HvpFreeMap(a1, *(_DWORD *)(a1 + 956), 0, v4);
    v6 = 4096;
    v7 = v5;
LABEL_10:
    result = (*(int (__fastcall **)(int, int))(a1 + 16))(v7, v6);
  }
  *(_DWORD *)(a1 + 960) = 0;
  *(_DWORD *)(a1 + 956) = 0;
  return result;
}
