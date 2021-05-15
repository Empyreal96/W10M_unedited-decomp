// MmMapIoSpace 
 
int __fastcall MmMapIoSpace(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r3

  v4 = (unsigned __int8)a4;
  if ( (unsigned __int8)a4 >= 6u )
    return 0;
  v5 = 4;
  if ( v4 != 1 )
  {
    if ( v4 == 2 )
      v5 = 1028;
    else
      v5 = 516;
  }
  return MmMapIoSpaceEx(a1, a2, a3, v5);
}
