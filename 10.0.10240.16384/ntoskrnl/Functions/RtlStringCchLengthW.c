// RtlStringCchLengthW 
 
int __fastcall RtlStringCchLengthW(unsigned __int16 *a1, unsigned int a2, _DWORD *a3)
{
  unsigned __int16 *v3; // r5
  int result; // r0
  unsigned int v5; // r4

  v3 = a1;
  if ( a1 && a2 <= 0x7FFFFFFF )
  {
    result = 0;
    v5 = a2;
    if ( !a2 )
      goto LABEL_13;
    do
    {
      if ( !*v3++ )
        break;
      --v5;
    }
    while ( v5 );
    if ( !v5 )
LABEL_13:
      result = -1073741811;
    if ( a3 )
    {
      if ( result < 0 )
        *a3 = 0;
      else
        *a3 = a2 - v5;
    }
  }
  else
  {
    result = -1073741811;
  }
  if ( result < 0 )
    result = sub_50A540();
  return result;
}
