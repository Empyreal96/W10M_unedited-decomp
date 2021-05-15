// EtwpUpdateEnableMask 
 
int __fastcall EtwpUpdateEnableMask(int result, int a2, char a3, _BYTE *a4)
{
  int v4; // r9
  int v6; // r5
  unsigned int i; // r4
  int v8; // r7
  _DWORD *v9; // r6
  int v10; // r3

  v4 = a3;
  v6 = result;
  if ( !a2 )
  {
    for ( i = 0; i < 8; ++i )
    {
      if ( *(_DWORD *)(v6 + 88) )
      {
        v8 = 0;
        result = EtwpAcquireLoggerContextByLoggerId(*(unsigned __int16 *)(v6 + 94), 0);
        v9 = (_DWORD *)result;
        if ( result )
        {
          v10 = *(_DWORD *)(result + 12);
          if ( v4 )
          {
            if ( (v10 & 0x80) != 0 )
              v8 = EtwpCheckLoggerControlAccess(512, result);
          }
          else if ( (v10 & 0x1000000) != 0 )
          {
            v8 = -1073741790;
          }
          result = EtwpReleaseLoggerContext(v9, 0);
          if ( !v8 )
            *a4 |= 1 << i;
        }
      }
      v6 += 32;
    }
  }
  return result;
}
