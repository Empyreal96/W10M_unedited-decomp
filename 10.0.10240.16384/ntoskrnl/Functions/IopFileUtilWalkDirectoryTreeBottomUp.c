// IopFileUtilWalkDirectoryTreeBottomUp 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IopFileUtilWalkDirectoryTreeBottomUp(unsigned __int16 *a1)
{
  int v2; // r7
  int v3; // r5
  _BYTE *v4; // r0
  unsigned int v5; // r4
  int *v6; // r1
  unsigned int v7; // r4
  __int64 v8; // kr00_8
  int *v9; // r1 OVERLAPPED
  int *v11; // [sp+10h] [bp-428h] BYREF
  int **v12; // [sp+14h] [bp-424h]
  int v13[2]; // [sp+18h] [bp-420h] BYREF
  char v14[1048]; // [sp+20h] [bp-418h] BYREF

  v12 = &v11;
  v2 = *a1;
  v11 = (int *)&v11;
  v13[1] = (int)v13;
  v13[0] = (int)v13;
  v3 = 0;
  v4 = (_BYTE *)ExAllocatePoolWithTag(1, v2 + 18, 1967550281);
  v5 = (unsigned int)v4;
  if ( v4 )
  {
    memset(v4, 0, v2 + 18);
    *(_WORD *)(v5 + 8) = 0;
    *(_WORD *)(v5 + 10) = *a1;
    *(_DWORD *)(v5 + 12) = v5 + 16;
    RtlCopyUnicodeString((unsigned __int16 *)(v5 + 8), a1);
    v6 = v11;
    *(_DWORD *)v5 = v11;
    *(_DWORD *)(v5 + 4) = &v11;
    if ( (int **)v6[1] != &v11 )
      __fastfail(3u);
    v6[1] = v5;
    v11 = (int *)v5;
    if ( (int **)v5 == &v11 )
      goto LABEL_9;
    while ( 1 )
    {
      v3 = IopFileUtilWalkDirectoryTreeHelper(v5 + 8, 8, 0, 0, v14);
      if ( v3 < 0 )
        break;
      v5 = *(_DWORD *)v5;
      if ( (int **)v5 == &v11 )
      {
        while ( 1 )
        {
          v5 = (unsigned int)v11;
LABEL_9:
          if ( (int **)v5 == &v11 )
            break;
          v7 = (unsigned int)v12;
          v8 = *(_QWORD *)v12;
          if ( *v12 != (int *)&v11 || *(int ***)HIDWORD(v8) != v12 )
            __fastfail(3u);
          v12 = (int **)v12[1];
          *(_DWORD *)HIDWORD(v8) = &v11;
          v3 = IopFileUtilWalkDirectoryTreeHelper(v7 + 8, 7, PpLastGoodDeleteFilesCallback, 0, v14);
          ExFreePoolWithTag(v7);
        }
        if ( v3 < 0 )
          goto LABEL_16;
        return v3;
      }
    }
  }
  else
  {
    v3 = -1073741670;
  }
  while ( 1 )
  {
    v5 = (unsigned int)v11;
LABEL_16:
    if ( (int **)v5 == &v11 )
      break;
    *(_QWORD *)&v9 = *(_QWORD *)v5;
    if ( *(int ***)(v5 + 4) != &v11 || v9[1] != v5 )
      __fastfail(3u);
    v11 = v9;
    v9[1] = (int)&v11;
    ExFreePoolWithTag(v5);
  }
  return v3;
}
