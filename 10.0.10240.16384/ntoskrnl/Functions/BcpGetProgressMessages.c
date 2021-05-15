// BcpGetProgressMessages 
 
int __fastcall BcpGetProgressMessages(int a1, int *a2, _DWORD *a3)
{
  int v5; // r5
  int v6; // r7
  unsigned int v7; // r6
  int v8; // r0
  int v9; // r4

  v5 = BcpFindMessage();
  v6 = wcsstr(v5, L"%1");
  v7 = v6 - v5;
  v8 = BgpFwAllocateMemory(v6 - v5 + 2);
  v9 = v8;
  if ( !v8 )
    return -1073741801;
  memmove(v8, v5, v7);
  *(_WORD *)(v9 + 2 * (v7 >> 1)) = 0;
  *a2 = v9;
  *a3 = v6 + 2 * wcslen(L"%1");
  return 0;
}
