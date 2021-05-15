// DrvDbSuspendDatabase 
 
int __fastcall DrvDbSuspendDatabase(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v8; // r3
  unsigned int v9; // r3
  int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[1] = a4;
  v10[0] = 0;
  if ( !a2 || !wcsicmp(a2, L"*") )
    return sub_7CF35C();
  result = DrvDbFindDatabaseNode(a1, a2, v10);
  if ( result >= 0 )
  {
    v8 = *(_DWORD *)(v10[0] + 28);
    if ( a3 )
      v9 = v8 | 4;
    else
      v9 = v8 & 0xFFFFFFFB;
    *(_DWORD *)(v10[0] + 28) = v9;
  }
  return result;
}
