// IopFileUtilWalkDirectoryTreeTopDown 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IopFileUtilWalkDirectoryTreeTopDown(unsigned __int16 *a1, int a2, int a3, int a4)
{
  int v5; // r5
  unsigned int v6; // r4
  int v7; // r1 OVERLAPPED
  int v8; // r1 OVERLAPPED
  int v10; // [sp+4h] [bp-424h]
  int v11; // [sp+4h] [bp-424h]
  int v12[2]; // [sp+10h] [bp-418h] BYREF
  char v13[1040]; // [sp+18h] [bp-410h] BYREF

  v12[1] = (int)v12;
  v12[0] = (int)v12;
  v5 = IopFileUtilWalkDirectoryTreeHelper(
         a1,
         13,
         (int (__fastcall *)(unsigned int, unsigned __int16 *))PiLastGoodRevertCopyCallback,
         a4,
         (int)v13,
         v10,
         (int)v12);
  while ( 1 )
  {
    v6 = v12[0];
    if ( (int *)v12[0] == v12 )
      break;
    if ( v5 < 0 )
      goto LABEL_9;
    *(_QWORD *)&v7 = *(_QWORD *)v12[0];
    if ( *(int **)(v12[0] + 4) != v12 || *(_DWORD *)(v7 + 4) != v12[0] )
      __fastfail(3u);
    v12[0] = v7;
    *(_DWORD *)(v7 + 4) = v12;
    v5 = IopFileUtilWalkDirectoryTreeHelper(
           (unsigned __int16 *)(v6 + 8),
           13,
           (int (__fastcall *)(unsigned int, unsigned __int16 *))PiLastGoodRevertCopyCallback,
           a4,
           (int)v13,
           v11,
           (int)v12);
    ExFreePoolWithTag(v6);
  }
  if ( v5 >= 0 )
    return v5;
LABEL_9:
  while ( (int *)v6 != v12 )
  {
    *(_QWORD *)&v8 = *(_QWORD *)v6;
    if ( *(int **)(v6 + 4) != v12 || *(_DWORD *)(v8 + 4) != v6 )
      __fastfail(3u);
    v12[0] = v8;
    *(_DWORD *)(v8 + 4) = v12;
    ExFreePoolWithTag(v6);
    v6 = v12[0];
  }
  return v5;
}
