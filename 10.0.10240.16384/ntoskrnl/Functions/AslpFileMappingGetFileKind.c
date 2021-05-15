// AslpFileMappingGetFileKind 
 
int __fastcall AslpFileMappingGetFileKind(_DWORD *a1, int *a2)
{
  int *v2; // r8
  unsigned int v3; // r4
  unsigned int v4; // r6
  int v5; // r3
  int v6; // r1
  int v7; // r5
  int v8; // r0
  int v9; // r4

  v2 = a2;
  v3 = a1[2];
  v4 = a1[3];
  if ( !*((_QWORD *)a1 + 1) || !a1[5] )
  {
    v5 = 1;
    goto LABEL_18;
  }
  if ( __PAIR64__(v4, v3) < 0x40 )
  {
    v5 = 3;
LABEL_18:
    v9 = 0;
    *a2 = v5;
    return v9;
  }
  v6 = a1[4];
  v7 = 3;
  if ( !v6 || v6 == -1 )
  {
    v9 = -1073741811;
    AslLogCallPrintf(1, "AslpFileMappingGetFileKind", 1025, "File mapping invalid [%x]", -1073741811);
  }
  else
  {
    if ( __PAIR64__(v4, v3) >= 4 && *(_WORD *)v6 == 23117 )
    {
      v7 = 4;
      v8 = *(_DWORD *)(v6 + 60);
      if ( __PAIR64__(v4, v3) >= (unsigned int)(v8 + 4) )
      {
        if ( *(_DWORD *)(v6 + v8) == 17744 )
        {
          v7 = 6;
        }
        else if ( *(_WORD *)(v6 + v8) == 17742 )
        {
          v7 = 5;
        }
      }
    }
    v9 = 0;
  }
  *v2 = v7;
  return v9;
}
