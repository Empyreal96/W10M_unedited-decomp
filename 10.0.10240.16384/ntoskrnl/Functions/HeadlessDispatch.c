// HeadlessDispatch 
 
int __fastcall HeadlessDispatch(int a1, int a2, int a3, _BYTE *a4, int *a5)
{
  if ( HeadlessGlobals )
    return sub_519784();
  if ( a1 == 21 || a1 == 1 )
    return -1073741823;
  if ( a1 != 16 && a1 != 12 && a1 != 13 && a1 != 2 && a1 != 11 )
    return 0;
  if ( a4 && a5 )
  {
    memset(a4, 0, *a5);
    return 0;
  }
  return -1073741811;
}
