// IopFileUtilRename 
 
int __fastcall IopFileUtilRename(int a1, unsigned __int16 *a2, int a3)
{
  int v5; // r5
  int v7; // r4

  v5 = ExAllocatePoolWithTag(1, *a2 + 16, 1967550281);
  if ( !v5 )
    return -1073741670;
  if ( a3 )
    return sub_96ED64();
  v7 = ZwOpenFile();
  if ( v7 >= 0 )
  {
    memmove(v5 + 12, *((_DWORD *)a2 + 1), *a2);
    *(_DWORD *)(v5 + 4) = 0;
    *(_BYTE *)v5 = 0;
    *(_DWORD *)(v5 + 8) = *a2;
    v7 = ZwSetInformationFile();
    ExFreePoolWithTag(v5);
    ZwClose();
  }
  else
  {
    ExFreePoolWithTag(v5);
  }
  return v7;
}
