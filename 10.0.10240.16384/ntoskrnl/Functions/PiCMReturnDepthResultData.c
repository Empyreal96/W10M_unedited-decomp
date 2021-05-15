// PiCMReturnDepthResultData 
 
int __fastcall PiCMReturnDepthResultData(int a1, int a2, int a3, _DWORD *a4, unsigned int a5, _DWORD *a6)
{
  int v9; // r4

  *a6 = 0;
  v9 = 0;
  if ( a5 < 0xC || a3 != 12 )
    return -1073741811;
  ProbeForWrite((unsigned int)a4, a5, 4);
  *a4 = 12;
  a4[1] = a1;
  a4[2] = a2;
  *a6 = 12;
  return v9;
}
