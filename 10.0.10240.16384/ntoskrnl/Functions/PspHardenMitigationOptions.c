// PspHardenMitigationOptions 
 
int __fastcall PspHardenMitigationOptions(unsigned int *a1)
{
  unsigned int v2; // r2
  unsigned int v3; // r5
  int result; // r0

  v3 = a1[1];
  v2 = *a1;
  result = 0;
  if ( __PAIR64__(v3, v2) == 1118993 )
    return 0;
  if ( (v2 & 3) != 1 )
    return sub_7F66C0(0);
  if ( (v2 & 0x300) != 768 )
  {
    result = -1073741811;
    v2 |= 0x300u;
  }
  if ( (v2 & 0x3000) != 4096 )
  {
    result = -1073741811;
    v2 = v2 & 0xFFFFCFFF | 0x1000;
  }
  if ( (v2 & 0x30) != 16 )
  {
    result = -1073741811;
    v2 = v2 & 0xFFFFFFCF | 0x10;
  }
  if ( (v2 & 0x30000) != 0x10000 )
  {
    result = -1073741811;
    v2 = v2 & 0xFFFCFFFF | 0x10000;
  }
  if ( (v2 & 0x300000) != 0x100000 && (v2 & 0x300000) != 0x200000 && (PspSystemMitigationOptions & 0x300000) != 0x200000 )
  {
    result = -1073741811;
    v2 = v2 & 0xFFCFFFFF | 0x100000;
  }
  *a1 = v2;
  a1[1] = v3;
  return result;
}
