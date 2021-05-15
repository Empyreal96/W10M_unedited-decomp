// AslpFileQuery16BitModuleName 
 
int __fastcall AslpFileQuery16BitModuleName(_BYTE *a1, _DWORD *a2)
{
  int v3; // r4
  int v4; // r5
  int v5; // r0
  unsigned int v6; // r2
  unsigned int v7; // r8
  int v8; // r1
  _BYTE *v9; // lr
  unsigned int v10; // r5
  int v11; // r2

  v3 = 0;
  *a1 = 0;
  if ( a2[138] == 5 )
  {
    v4 = a2[134];
    v5 = *(_DWORD *)(v4 + 60);
    v6 = a2[132];
    v7 = a2[133];
    if ( __PAIR64__(v7, v6) < (unsigned int)(v5 + 64)
      || (v8 = *(unsigned __int16 *)(v5 + v4 + 38), __PAIR64__(v7, v6) < (unsigned int)(v8 + 1)) )
    {
      v11 = 3137;
    }
    else
    {
      v9 = (_BYTE *)(v8 + v5 + v4);
      v10 = (unsigned __int8)*v9;
      if ( *v9 )
      {
        if ( __PAIR64__(v7, v6) >= v8 + v5 + v10 + 1 )
        {
          memmove((int)a1, (int)(v9 + 1), v10);
          a1[v10] = 0;
          return v3;
        }
        v11 = 3153;
      }
      else
      {
        v11 = 3146;
      }
    }
    v3 = -1073741701;
    AslLogCallPrintf(1, (int)"AslpFileQuery16BitModuleName", v11, "File mapping invalid");
    return v3;
  }
  return -1073741637;
}
