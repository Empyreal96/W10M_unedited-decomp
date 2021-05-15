// BcdUtilGetBootOptionInteger 
 
int __fastcall BcdUtilGetBootOptionInteger(int a1, int a2)
{
  if ( (a2 & 0xF000000) != 83886080 )
    return -1073741811;
  if ( BcdUtilGetBootOption() )
    return sub_7DCE8C();
  return -1073741275;
}
