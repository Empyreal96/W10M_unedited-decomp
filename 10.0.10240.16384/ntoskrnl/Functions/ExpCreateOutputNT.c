// ExpCreateOutputNT 
 
int __fastcall ExpCreateOutputNT(int a1, unsigned int *a2, char **a3, int a4)
{
  int result; // r0
  int v8; // r8
  unsigned int v9; // r5

  if ( a4 )
    return sub_8154A4();
  v8 = ((unsigned int)*(unsigned __int16 *)a3 + 4) >> 1;
  v9 = *(unsigned __int16 *)a3 + 16;
  if ( a1 && *a2 >= v9 )
  {
    *(_DWORD *)a1 = 1;
    *(_DWORD *)(a1 + 4) = v9;
    *(_DWORD *)(a1 + 8) = 3;
    wcscpy_s((char *)(a1 + 12), v8, a3[1]);
    *(_WORD *)(*(unsigned __int16 *)a3 + a1 + 12 + 2) = 0;
    result = 0;
  }
  else
  {
    result = -1073741789;
  }
  *a2 = v9;
  return result;
}
