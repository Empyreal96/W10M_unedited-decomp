// AdtpGetCategoryAndSubCategoryId 
 
int __fastcall AdtpGetCategoryAndSubCategoryId(int a1, unsigned int *a2, _DWORD *a3)
{
  unsigned int v3; // r6
  int v4; // r4
  __int16 *v6; // r5
  unsigned int v7; // r0
  int v8; // t1
  int v9; // r3

  v3 = a1 - 100;
  v4 = 0;
  if ( (unsigned int)(a1 - 100) > 0x39 )
    return -1073741811;
  if ( !a2 )
    return sub_815E10();
  v6 = &AdtpPerCategoryCount;
  v7 = 0;
  while ( 1 )
  {
    v8 = (unsigned __int16)*v6++;
    v9 = v8 + v4;
    if ( v8 + v4 > v3 )
      break;
    ++v7;
    v4 = v9;
    if ( v7 >= 9 )
      return -1073741823;
  }
  *a2 = v7;
  if ( a3 )
    *a3 = v3 - v4;
  return 0;
}
