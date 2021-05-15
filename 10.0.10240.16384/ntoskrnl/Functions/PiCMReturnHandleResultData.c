// PiCMReturnHandleResultData 
 
int __fastcall PiCMReturnHandleResultData(int a1, int a2, int a3, int a4, unsigned int a5, _DWORD *a6)
{
  int v9; // r4

  *a6 = 0;
  v9 = 0;
  if ( a5 < 0x10 || a3 != 16 )
    return -1073741811;
  ProbeForWrite(a4, a5, 4);
  *(_DWORD *)a4 = 16;
  *(_DWORD *)(a4 + 4) = a1;
  *(_QWORD *)(a4 + 8) = a2;
  *a6 = 16;
  return v9;
}
