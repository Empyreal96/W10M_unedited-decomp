// IoBoostThreadIo 
 
int __fastcall IoBoostThreadIo(int a1, int a2, int a3, int a4)
{
  if ( a4 )
    return -1073741811;
  if ( a3 == 1 )
  {
    PsBoostThreadIoEx(a1, 1, 1);
  }
  else
  {
    PsBoostThreadIoEx(a1, 0, 1);
    IoBoostThreadIoPriority(a1, a2, 0x80000000);
  }
  return 0;
}
