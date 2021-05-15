// AslPathToNetworkPathNt 
 
int __fastcall AslPathToNetworkPathNt(char **a1, int a2)
{
  int v4; // r4
  unsigned int v5; // r4
  int v6; // r0
  int v7; // r4
  char *v8; // r0
  char *v9; // r7

  *a1 = 0;
  if ( AslpDetermineDosPathNameType(a2) != 1 )
    return -1073741811;
  v5 = wcslen(L"\\??\\UNC\\");
  v6 = wcslen((unsigned __int16 *)a2);
  v7 = v5 + v6 + 1;
  v8 = AslAlloc(v6, 2 * v7);
  v9 = v8;
  if ( v8 )
  {
    wcscpy_s(v8, v7, (char *)L"\\??\\UNC\\");
    wcscat_s(v9, v7, (char *)(a2 + 4));
    v4 = 0;
    *a1 = v9;
  }
  else
  {
    v4 = -1073741801;
    AslLogCallPrintf(1, (int)"AslPathToNetworkPathNt", 249, "Out of memory");
  }
  return v4;
}
