// CcFastCopyRead 
 
int __fastcall CcFastCopyRead(int a1, int a2, unsigned int a3, int a4, int a5, _DWORD *a6)
{
  _DWORD v7[4]; // [sp+10h] [bp-10h] BYREF

  v7[0] = a2;
  v7[1] = 0;
  return CcCopyReadEx(a1, v7, a3, 1, a5, a6, 0);
}
