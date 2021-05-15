// KiCustomAccessHandler2 
 
int __fastcall KiCustomAccessHandler2(unsigned int *a1, int a2, _DWORD *a3)
{
  int v3; // r4

  if ( (a1[1] & 2) == 0 )
  {
    v3 = __mrc(15, 0, 9, 13, 0);
    a1[6] ^= v3;
    a3[14] -= v3 & 0x38;
    *a1 = v3 & 0x7F | 0xC0000000;
    a1[3] = (unsigned int)&loc_5C47D8;
    a3[16] = &loc_5C47D8;
    a3[2] = 0;
  }
  return 1;
}
