// RtlStringCbCopyNW 
 
int __fastcall RtlStringCbCopyNW(_WORD *a1, unsigned int a2, int a3, unsigned int a4)
{
  int result; // r0
  unsigned int v7; // r1
  unsigned int v8; // r2
  int v9; // r5

  result = 0;
  v7 = a2 >> 1;
  if ( !v7 )
    result = -1073741811;
  if ( result >= 0 )
  {
    if ( a4 >> 1 == 0x7FFFFFFF )
    {
      result = -1073741811;
    }
    else
    {
      result = 0;
      if ( !v7 )
        goto LABEL_12;
      v8 = (a4 >> 1) - v7;
      v9 = a3 - (_DWORD)a1;
      do
      {
        if ( !(v8 + v7) )
          break;
        if ( !*(_WORD *)((char *)a1 + v9) )
          break;
        *a1 = *(_WORD *)((char *)a1 + v9);
        ++a1;
        --v7;
      }
      while ( v7 );
      if ( !v7 )
      {
LABEL_12:
        --a1;
        result = -2147483643;
      }
    }
    *a1 = 0;
  }
  return result;
}
