// WmipGetSMBiosString 
 
int __fastcall WmipGetSMBiosString(int a1, unsigned int a2, _BYTE *a3, int a4)
{
  int v4; // r5
  _BYTE *v6; // r4
  int result; // r0
  unsigned int v8; // r1
  _DWORD v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = a2;
  v9[1] = a3;
  v9[2] = a4;
  v4 = 1;
  v6 = (_BYTE *)(*(unsigned __int8 *)(a1 + 1) + a1);
  if ( a2 <= 1 )
  {
LABEL_7:
    v8 = (unsigned int)v6;
    while ( *v6 )
    {
      if ( ++v6 == a3 )
        goto LABEL_4;
    }
    RtlInitAnsiString((unsigned int)v9, v8);
    result = RtlAnsiStringToUnicodeString(a4, v9, 1);
  }
  else
  {
    while ( 1 )
    {
      while ( *v6 )
      {
        if ( ++v6 == a3 )
          goto LABEL_4;
      }
      if ( !*++v6 )
        break;
      if ( ++v4 >= a2 )
        goto LABEL_7;
    }
LABEL_4:
    result = -1073741275;
  }
  return result;
}
