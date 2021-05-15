// PiCMReturnStatusResultData 
 
int __fastcall PiCMReturnStatusResultData(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7, _DWORD *a8)
{
  int v8; // r4
  _DWORD v10[10]; // [sp+8h] [bp-28h] BYREF

  *a8 = 0;
  v8 = 0;
  if ( a7 < 0x14 || a5 != 20 )
    return -1073741811;
  v10[0] = 20;
  v10[1] = a1;
  v10[2] = a2;
  v10[3] = a3;
  v10[4] = a4;
  ProbeForWrite(a6, a7, 4);
  memmove(a6, (int)v10, 0x14u);
  *a8 = 20;
  return v8;
}
