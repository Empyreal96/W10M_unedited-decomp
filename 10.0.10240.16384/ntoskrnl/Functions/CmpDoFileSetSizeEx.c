// CmpDoFileSetSizeEx 
 
int __fastcall CmpDoFileSetSizeEx(int a1, int a2, unsigned int a3, unsigned int a4, char a5)
{
  int v9; // r10
  unsigned __int64 v10; // r0
  int v11; // r4
  __int64 v13; // [sp+8h] [bp-30h]

  if ( !*(_DWORD *)(a1 + 4 * a2 + 1776) )
    return 0;
  v9 = IoSetThreadHardErrorMode(0);
  LODWORD(v10) = CmpGetLastSetFileSize(a1, a2);
  if ( (a5 & 1) != 0 && v10 && __PAIR64__(a4, a3) <= v10 )
    return 0;
  v13 = CmpAdjustRequestedFileSize(a1, a2, v10, HIDWORD(v10), a3, a4);
  v11 = ZwSetInformationFile();
  if ( v11 >= 0 )
  {
    if ( a2 )
    {
      if ( a2 == 4 || a2 == 5 || a2 == 1 )
        *(_QWORD *)(a1 + 8 * HvpLogTypeToLogArrayIndex(a2) + 1952) = v13;
      goto LABEL_10;
    }
    if ( (*(_BYTE *)(a1 + 72) & 4) == 0
      || (v11 = HvViewMapChangeFileSize(a1 + 152, a1, v13, HIDWORD(v13), 20), v11 >= 0) )
    {
      *(_QWORD *)(a1 + 1944) = v13;
LABEL_10:
      IoSetThreadHardErrorMode(v9);
      return v11;
    }
  }
  return sub_7C3390();
}
