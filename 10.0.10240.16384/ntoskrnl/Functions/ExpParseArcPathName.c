// ExpParseArcPathName 
 
int __fastcall ExpParseArcPathName(char *a1, char **a2, char **a3, _DWORD *a4, char *a5)
{
  char *v5; // r4
  char *v6; // r9
  int v7; // r5
  char v8; // r10
  int v9; // r6
  char *v10; // r7
  int v11; // r0
  int v12; // t1
  int v13; // r2
  int v14; // r3
  char *v15; // r1
  int result; // r0
  char v20[56]; // [sp+10h] [bp-38h] BYREF

  v5 = a1;
  v6 = 0;
  v7 = 1;
  v8 = 0;
  if ( !a1 )
    return -1073741811;
  wcscpy_s(v20, 11, (char *)L"signature(");
  v9 = 0;
  v10 = v20;
  while ( 1 )
  {
    v11 = towlower(*(unsigned __int16 *)&v10[v5 - v20]);
    v12 = *(unsigned __int16 *)v10;
    v10 += 2;
    if ( v11 != v12 )
      break;
    if ( (unsigned int)++v9 >= 0xA )
      goto LABEL_7;
  }
  v7 = 0;
LABEL_7:
  if ( v7 == 1 )
    v5 += 20;
  v13 = *(unsigned __int16 *)v5;
  v14 = 0;
  if ( *(_WORD *)v5 )
  {
    v15 = v5;
    while ( v13 != 92 )
    {
      if ( v7 == 1 && v13 == 41 )
      {
        v7 = 0;
        v8 = 1;
        if ( *((_WORD *)v15 + 1) != 92 )
        {
          if ( *((_WORD *)v15 + 1) )
            return -1073741811;
        }
      }
      ++v14;
      v15 = &v5[2 * v14];
      v13 = *(unsigned __int16 *)v15;
      if ( !*(_WORD *)v15 )
        goto LABEL_19;
    }
    v6 = &v5[2 * v14];
  }
LABEL_19:
  if ( v7 == 1 || !v14 )
    return -1073741811;
  result = 0;
  *a2 = v5;
  *a3 = v6;
  *a4 = v14;
  *a5 = v8;
  return result;
}
