// SepAdtCheckPrivilegeForSensitivity 
 
unsigned int *__fastcall SepAdtCheckPrivilegeForSensitivity(unsigned int *result, _BYTE *a2, _BYTE *a3)
{
  unsigned int v4; // r4
  unsigned int v5; // r5
  int *v6; // r9
  int **v7; // r1
  int v8; // r8
  int v9; // t1

  *a2 = 0;
  *a3 = 0;
  if ( result )
  {
    v4 = *result;
    if ( *result )
    {
      v5 = 0;
      if ( v4 )
      {
        v6 = (int *)(result + 2);
        result += 3;
        do
        {
          if ( *a2 && *a3 )
            break;
          v7 = SepSensitivePrivileges;
          v9 = *v6;
          v6 += 3;
          v8 = v9;
          do
          {
            if ( v8 == **v7 && *result == (*v7)[1] )
              break;
            ++v7;
          }
          while ( *v7 );
          if ( *v7 )
            *a2 = 1;
          else
            *a3 = 1;
          ++v5;
          result += 3;
        }
        while ( v5 < v4 );
      }
    }
  }
  return result;
}
