// PiCMReturnBasicResultData 
 
int __fastcall PiCMReturnBasicResultData(int a1, int a2, _DWORD *a3, unsigned int a4, _DWORD *a5)
{
  int v7; // r4

  *a5 = 0;
  v7 = 0;
  if ( a4 < 8 || a2 != 8 )
    return -1073741811;
  ProbeForWrite((unsigned int)a3, a4, 4);
  *a3 = 8;
  a3[1] = a1;
  *a5 = 8;
  return v7;
}
