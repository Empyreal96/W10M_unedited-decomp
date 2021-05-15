// CmpFindSubKeyByNumber 
 
int __fastcall CmpFindSubKeyByNumber(int a1, _DWORD *a2, unsigned int a3, _DWORD *a4)
{
  unsigned int v5; // r0
  unsigned int v7; // r7
  int v8; // r6
  int v9; // r4
  int v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = (int)a4;
  v5 = a2[5];
  v7 = a3;
  v11[0] = -1;
  *a4 = -1;
  if ( a3 >= v5 )
  {
    if ( *(_DWORD *)(a1 + 144) <= 1u )
      return 0;
    v7 = a3 - v5;
    if ( a3 - v5 >= a2[6] )
      return 0;
    v8 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, a2[8], v11);
    if ( !v8 )
      return -1073741670;
  }
  else
  {
    v8 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, a2[7], v11);
    if ( !v8 )
      return -1073741670;
  }
  *a4 = CmpDoFindSubKeyByNumber(a1, v8, v7);
  v9 = 0;
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v11);
  return v9;
}
