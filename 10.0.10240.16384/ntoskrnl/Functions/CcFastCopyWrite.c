// CcFastCopyWrite 
 
__int64 __fastcall CcFastCopyWrite(_DWORD *a1, unsigned int a2, unsigned int a3, int a4)
{
  __int64 v5; // [sp+0h] [bp-10h]
  __int64 v6; // [sp+8h] [bp-8h] BYREF

  v6 = a2;
  CcCopyWriteEx(a1, &v6, a3, 1, a4, 0);
  return v5;
}
