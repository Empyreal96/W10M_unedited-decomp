// _CmValidateDeviceName 
 
int __fastcall CmValidateDeviceName(int a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned __int16 *v4; // r5
  int v5; // r4
  int v6; // r6
  int result; // r0
  unsigned int v8; // r3
  unsigned int v9; // t1
  int v10[4]; // [sp+0h] [bp-10h] BYREF

  v10[0] = a4;
  v4 = a2;
  v5 = 0;
  v6 = 1;
  if ( !a2 )
    return -1073741811;
  result = RtlUnalignedStringCchLengthW(a2, 200, v10);
  if ( result >= 0 )
  {
    v8 = *v4;
    if ( *v4 )
    {
      while ( v8 > 0x20 && v8 <= 0x7F && v8 != 44 )
      {
        if ( v8 == 92 )
        {
          if ( !v5 )
            return -1073741773;
          v5 = 0;
          ++v6;
        }
        else
        {
          ++v5;
        }
        v9 = v4[1];
        ++v4;
        v8 = v9;
        if ( !v9 )
        {
          if ( !v5 || v6 != 3 )
            return -1073741773;
          return result;
        }
      }
    }
  }
  return -1073741773;
}
