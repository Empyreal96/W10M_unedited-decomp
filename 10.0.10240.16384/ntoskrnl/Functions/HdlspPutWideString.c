// HdlspPutWideString 
 
int __fastcall HdlspPutWideString(_WORD *a1, int a2, int a3, int a4)
{
  _BYTE *v5; // r6
  _BYTE *v6; // r4
  unsigned int i; // r3
  char v9; // [sp+0h] [bp-20h] BYREF
  __int16 v10; // [sp+1h] [bp-1Fh]
  char v11; // [sp+3h] [bp-1Dh]
  int v12; // [sp+4h] [bp-1Ch]

  v11 = HIBYTE(a3);
  v12 = a4;
  v9 = 0;
  v10 = 0;
  v5 = *(_BYTE **)(HeadlessGlobals + 12);
  v6 = v5;
  while ( *a1 )
  {
    if ( v6 < v5 + 79 )
    {
      HdlspUTF8Encode((unsigned __int16)*a1, &v9);
      for ( i = 0; i < 3; ++i )
      {
        if ( *(&v9 + i) )
        {
          *v6++ = *(&v9 + i);
          *(&v9 + i) = 0;
        }
      }
      ++a1;
    }
    else
    {
      v5[79] = 0;
      HdlspSendStringAtBaud(v5);
      v6 = *(_BYTE **)(HeadlessGlobals + 12);
    }
  }
  *v6 = 0;
  return HdlspSendStringAtBaud(v5);
}
