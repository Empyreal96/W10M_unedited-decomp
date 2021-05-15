// RtlpMuiRegGetLanguageSpec 
 
int __fastcall RtlpMuiRegGetLanguageSpec(_DWORD *a1, unsigned __int16 *a2, char *a3, int a4, __int16 *a5)
{
  __int16 v6; // r4
  char v9; // r5
  int result; // r0
  __int16 v11; // [sp+0h] [bp-28h] BYREF
  int v12; // [sp+4h] [bp-24h] BYREF
  unsigned __int16 v13[16]; // [sp+8h] [bp-20h] BYREF

  v6 = 0;
  v11 = 0;
  v9 = 0;
  RtlInitUnicodeString((unsigned int)v13, a2);
  if ( RtlCultureNameToLCID(v13, &v12) )
  {
    if ( v12 == 4096 || v12 == 5120 )
    {
      result = RtlpMuiRegGetOrAddString(a1, a2, 1, &v11);
      if ( result < 0 )
      {
        v6 = 0;
        goto LABEL_10;
      }
      v6 = v11;
      v9 = 3;
    }
    else
    {
      v9 = 1;
      v6 = v12;
    }
    result = 0;
  }
  else
  {
    result = -1073741811;
  }
LABEL_10:
  if ( a3 )
    *a3 = v9;
  if ( a5 )
    *a5 = v6;
  return result;
}
