// RtlUnalignedStringCchLengthW 
 
int __fastcall RtlUnalignedStringCchLengthW(unsigned __int16 *a1, int a2, _DWORD *a3)
{
  unsigned __int16 *v3; // r5
  int v4; // r4
  int result; // r0

  v3 = a1;
  if ( a1 )
  {
    v4 = a2;
    result = 0;
    do
    {
      if ( !*v3++ )
        break;
      --v4;
    }
    while ( v4 );
    if ( !v4 )
      result = -1073741811;
    if ( a3 )
    {
      if ( result < 0 )
        *a3 = 0;
      else
        *a3 = a2 - v4;
    }
  }
  else
  {
    result = -1073741811;
  }
  if ( result < 0 )
    result = sub_50A524();
  return result;
}
