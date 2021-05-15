// HvpAdjustHiveFreeDisplay 
 
int __fastcall HvpAdjustHiveFreeDisplay(int a1, unsigned int a2, int a3)
{
  int v5; // r4
  int i; // r5
  int result; // r0

  if ( a2 > 0x7FFFE000 )
    return -1073741492;
  v5 = 0;
  for ( i = a1 + 412 * a3 + 968; ; i += 16 )
  {
    result = HvpAdjustBitmap(a1, a2, i);
    if ( result < 0 )
      break;
    if ( (unsigned int)++v5 >= 0x18 )
      return 0;
  }
  return result;
}
