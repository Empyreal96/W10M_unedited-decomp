// HvpViewMapUnpinViewOfPrimaryFile 
 
int __fastcall HvpViewMapUnpinViewOfPrimaryFile(int a1, int a2)
{
  _DWORD *v2; // r4

  v2 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 12) + 4 * (((a2 & 0xFFFC0000) >> 24) & 0x7F))
                + 24 * (((a2 & 0xFFFC0000) >> 18) & 0x3F));
  if ( (*v2 & 1) != 0 )
    MmProtectSystemCacheView(*v2 & 0xFFFFFFFE, (v2[4] + 4095) & 0xFFFFF000, 2);
  *v2 &= 0xFFFFFFFE;
  return 0;
}
