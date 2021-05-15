// IoQueryVhdBootInformation 
 
int __fastcall IoQueryVhdBootInformation(int a1, int a2, unsigned int a3, int *a4)
{
  int *v4; // r5
  int v5; // r4
  int result; // r0

  v4 = a4;
  *a4 = 0;
  v5 = dword_6180FC;
  if ( a3 < dword_6180FC )
  {
    result = -1073741789;
  }
  else
  {
    memmove(a2, (int)off_6180F8, dword_6180FC);
    result = 0;
  }
  *v4 = v5;
  return result;
}
