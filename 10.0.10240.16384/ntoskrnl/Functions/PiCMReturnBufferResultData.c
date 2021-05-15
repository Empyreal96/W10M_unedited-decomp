// PiCMReturnBufferResultData 
 
int __fastcall PiCMReturnBufferResultData(int a1, int a2, int a3, int a4, unsigned int a5, int a6, int a7, unsigned int a8, _DWORD *a9)
{
  int v11; // r4
  _DWORD v15[12]; // [sp+10h] [bp-30h] BYREF

  *a9 = 0;
  v11 = 0;
  if ( a8 < a5 + 20 || a6 != 20 )
    return -1073741811;
  memset(v15, 0, 20);
  v15[0] = 20;
  v15[1] = a1;
  v15[2] = a2;
  v15[3] = a3;
  ProbeForWrite(a7, a8, 4);
  memmove(a7, (int)v15, 0x14u);
  if ( a5 )
    memmove(a7 + 16, a4, a5);
  *a9 = a5 + 20;
  return v11;
}
