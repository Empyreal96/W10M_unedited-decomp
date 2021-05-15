// RtlStringCchCopyW 
 
int __fastcall RtlStringCchCopyW(_WORD *a1, unsigned int a2, int a3)
{
  int result; // r0
  unsigned int v6; // r2
  int v7; // r5

  result = 0;
  if ( !a2 || a2 > 0x7FFFFFFF )
    result = -1073741811;
  if ( result >= 0 )
  {
    result = 0;
    if ( !a2 )
      return sub_50A5EC(0);
    v6 = 2147483646 - a2;
    v7 = a3 - (_DWORD)a1;
    do
    {
      if ( !(v6 + a2) )
        break;
      if ( !*(_WORD *)((char *)a1 + v7) )
        break;
      *a1 = *(_WORD *)((char *)a1 + v7);
      ++a1;
      --a2;
    }
    while ( a2 );
    if ( !a2 )
      return sub_50A5EC(0);
    goto LABEL_11;
  }
  if ( a2 )
LABEL_11:
    *a1 = 0;
  return result;
}
