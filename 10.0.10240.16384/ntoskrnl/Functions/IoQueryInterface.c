// IoQueryInterface 
 
int __fastcall IoQueryInterface(int a1, int a2, int a3, int a4, unsigned __int16 a5)
{
  int result; // r0

  if ( (a2 & 1) != 0 )
    result = IopQueryInterfaceRecurseUp(a1, a3, a4, a5);
  else
    result = sub_818DFC();
  return result;
}
