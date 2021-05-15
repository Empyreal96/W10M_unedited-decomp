// PipSmBiosFindStruct 
 
int __fastcall PipSmBiosFindStruct(int a1, int a2, unsigned __int8 *a3, int a4)
{
  int result; // r0
  unsigned int v6; // r5
  int v7; // r3
  unsigned __int8 *i; // r2

  result = 0;
  v6 = (unsigned int)&a3[a4 - 2];
  while ( (unsigned int)a3 < v6 )
  {
    v7 = *a3;
    if ( v7 == a1 )
    {
      result = (int)a3;
      if ( v7 == 2 )
        result = sub_9688F4(a3);
      return result;
    }
    for ( i = &a3[a3[1]]; (unsigned int)i < v6 && *(_WORD *)i; ++i )
      ;
    a3 = i + 2;
  }
  return result;
}
