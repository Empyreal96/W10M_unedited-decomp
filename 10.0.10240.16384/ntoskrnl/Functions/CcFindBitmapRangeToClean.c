// CcFindBitmapRangeToClean 
 
int *__fastcall CcFindBitmapRangeToClean(_DWORD *a1, int a2, unsigned int a3, unsigned int a4)
{
  int *v5; // r0
  int *i; // r4
  int *v7; // t1

  a1[8] = -1;
  a1[9] = -1;
  v7 = (int *)a1[4];
  v5 = a1 + 4;
  for ( i = v7; ; i = (int *)*i )
  {
    if ( i == v5 )
    {
      a3 = 0;
      a4 = 0;
      continue;
    }
    if ( __SPAIR64__(a4, a3) <= *((_QWORD *)i + 1) + (unsigned int)i[5] && i[6] )
      break;
  }
  return i;
}
