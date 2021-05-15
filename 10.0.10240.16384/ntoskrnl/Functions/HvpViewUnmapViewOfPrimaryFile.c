// HvpViewUnmapViewOfPrimaryFile 
 
int __fastcall HvpViewUnmapViewOfPrimaryFile(int a1, int a2, unsigned int a3, _DWORD *a4)
{
  _DWORD *v5; // r4
  int result; // r0

  v5 = (_DWORD *)(*(_DWORD *)(a2 + 4 * (HIBYTE(a3) & 0x7F)) + 24 * ((a3 >> 18) & 0x3F));
  MmProtectSystemCacheView(*v5 & 0xFFFFFFFE, v5[4], 4u);
  CcUnpinData(v5[1]);
  *a4 = HvpViewMapCountPinMaskSetBits(v5[2], v5[3]);
  result = CmpReleaseGlobalQuota(v5[4]);
  *v5 = 0;
  v5[1] = 0;
  v5[3] = 0;
  v5[4] = 0;
  v5[2] = 0;
  return result;
}
