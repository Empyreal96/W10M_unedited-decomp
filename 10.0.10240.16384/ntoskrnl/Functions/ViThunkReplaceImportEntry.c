// ViThunkReplaceImportEntry 
 
int __fastcall ViThunkReplaceImportEntry(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v3; // r4
  int result; // r0
  unsigned int v6; // r7
  unsigned int v7; // r6
  _DWORD *v8; // r2

  v3 = (_DWORD *)*a1;
  result = 0;
  while ( v3 != a1 )
  {
    v6 = v3[3];
    v7 = 0;
    v8 = v3 + 4;
    if ( v6 )
    {
      while ( *a2 != *v8 )
      {
        ++v7;
        v8 += 2;
        if ( v7 >= v6 )
          goto LABEL_7;
      }
      MmReplaceImportEntry((unsigned int)a2, v8[1]);
      result = 1;
    }
LABEL_7:
    if ( result == 1 )
      break;
    v3 = (_DWORD *)*v3;
  }
  return result;
}
