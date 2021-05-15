// MiStoreFaultComplete 
 
int __fastcall MiStoreFaultComplete(int result, int *a2)
{
  __int64 v2; // kr00_8
  int v3; // r4

  v2 = *(_QWORD *)(result + 48);
  if ( (int)v2 < 0 )
  {
    v3 = 65537;
    if ( (_DWORD)v2 == -1073741275 )
    {
      if ( (*(_DWORD *)(MmPfnDatabase + 24 * *(_DWORD *)(result + 180) + 12) & 0x40000000) == 0 )
        KeBugCheckEx(26, 24576, result, -1073741275, 0);
    }
    else if ( (_DWORD)v2 != -1073741791 )
    {
      v3 = 65539;
      goto LABEL_9;
    }
    *(_DWORD *)(result + 48) = -1073741801;
  }
  else
  {
    v3 = (HIDWORD(v2) << 16) | 1;
    *(_DWORD *)(result + 52) = WORD2(v2) << 12;
  }
LABEL_9:
  *a2 = v3;
  return result;
}
