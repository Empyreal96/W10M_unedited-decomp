// IovpValidateStatusInformation 
 
int __fastcall IovpValidateStatusInformation(int result, _DWORD *a2, unsigned __int8 *a3, int a4)
{
  int v4; // r4
  int v5; // r5
  unsigned int v6; // r4
  bool v7; // zf
  unsigned int v8; // r2
  int v9; // r2

  v4 = a2[2];
  if ( (v4 & 0x10) != 0 && (v4 & 0x40) != 0 && (v4 & 0x20) != 0 )
  {
    v5 = a2[6];
    if ( v5 != -2147483626 && (v5 & 0xC0000000) != -1073741824 )
    {
      v6 = *a3;
      if ( v6 <= 0xA )
      {
        if ( v6 == 10 || v6 == 3 || v6 == 5 )
        {
LABEL_13:
          v8 = *((_DWORD *)a3 + 2);
          goto LABEL_14;
        }
        v7 = v6 == 7;
LABEL_11:
        if ( !v7 )
          return result;
        goto LABEL_13;
      }
      if ( *a3 < 0xCu )
        return result;
      if ( *a3 <= 0xDu )
        goto LABEL_13;
      if ( *a3 > 0xFu )
      {
        v7 = v6 == 25;
        goto LABEL_11;
      }
      v9 = *(_DWORD *)(result + 120);
      if ( v9 && v9 == a2[3] )
      {
        v8 = *(_DWORD *)(result + 124);
LABEL_14:
        if ( a2[7] > v8 )
          result = VfErrorReport1(786, a4, a2);
        return result;
      }
    }
  }
  return result;
}
