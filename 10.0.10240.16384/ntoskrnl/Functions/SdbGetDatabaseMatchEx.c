// SdbGetDatabaseMatchEx 
 
int __fastcall SdbGetDatabaseMatchEx(int a1, int a2, unsigned __int16 *a3, int a4, int a5, int a6, int a7)
{
  int v7; // r6
  int v9; // r9
  unsigned __int16 *v10; // r0
  unsigned __int16 *v11; // r4
  int v12; // r0
  char v14[72]; // [sp+18h] [bp-48h] BYREF

  v7 = *(_DWORD *)(a1 + 4);
  if ( a2 )
  {
    v9 = 28698;
  }
  else
  {
    v9 = 28700;
    v10 = wcsrchr(a3, 92);
    if ( v10 )
    {
      v11 = v10 + 1;
      goto LABEL_4;
    }
  }
  v11 = a3;
LABEL_4:
  v12 = SdbFindFirstStringIndexedTag(v7, v9, 24577, v11, v14);
  if ( v12 )
    return sub_7CC918(v12, a5, a6, a7);
  if ( SdbpFindFirstIndexedWildCardTag(v7, v9, a6, v11, v14) )
    JUMPOUT(0x7CC94E);
  return 0;
}
