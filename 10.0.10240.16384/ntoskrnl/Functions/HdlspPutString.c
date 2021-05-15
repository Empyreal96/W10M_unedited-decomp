// HdlspPutString 
 
int __fastcall HdlspPutString(char *a1, int a2, int a3, int a4)
{
  char *v4; // r5
  int v5; // r6
  char *v6; // r4
  int v7; // r2
  char v8; // r2
  unsigned int i; // r2
  _DWORD v11[8]; // [sp+0h] [bp-20h] BYREF

  v11[0] = a4;
  v4 = a1;
  v5 = HeadlessGlobals;
  v6 = *(char **)(HeadlessGlobals + 12);
  while ( *v4 )
  {
    v7 = *(_DWORD *)(v5 + 12);
    if ( (unsigned int)v6 < v7 + 79 )
    {
      v8 = *v4;
      if ( (*v4 & 0x80) != 0 )
      {
        switch ( *v4 )
        {
          case -87:
          case -86:
          case -69:
          case -68:
          case -65:
          case -64:
          case -56:
          case -55:
          case -39:
          case -38:
            v8 = 43;
            break;
          case -80:
          case -77:
          case -70:
            v8 = 124;
            break;
          case -79:
          case -36:
          case -35:
          case -34:
          case -33:
            v8 = 37;
            break;
          case -78:
          case -37:
            v8 = 35;
            break;
          case -60:
            v8 = 45;
            break;
          case -51:
            v8 = 61;
            break;
          default:
            break;
        }
      }
      if ( (v8 & 0x80) != 0 )
      {
        LOBYTE(v11[0]) = 0;
        *(_WORD *)((char *)v11 + 1) = 0;
        HdlspUTF8Encode(*((unsigned __int16 *)HdlpsPcAnsiToUnicode + (v8 & 0x7F)), v11);
        for ( i = 0; i < 3; ++i )
        {
          if ( *((_BYTE *)v11 + i) )
            *v6++ = *((_BYTE *)v11 + i);
        }
      }
      else
      {
        *v6++ = v8;
      }
      ++v4;
    }
    else
    {
      *(_BYTE *)(v7 + 79) = 0;
      HdlspSendStringAtBaud(*(_DWORD *)(v5 + 12));
      v5 = HeadlessGlobals;
      v6 = *(char **)(HeadlessGlobals + 12);
    }
  }
  *v6 = 0;
  return HdlspSendStringAtBaud(*(_DWORD *)(v5 + 12));
}
