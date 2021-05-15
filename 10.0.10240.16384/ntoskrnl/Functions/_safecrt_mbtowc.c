// _safecrt_mbtowc 
 
int __fastcall safecrt_mbtowc(_WORD *a1, _BYTE *a2, int a3, int a4)
{
  __int16 v7; // r0
  int v8; // r3
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  if ( a2 && a3 )
  {
    if ( *a2 )
    {
      v9[0] = (int)a2;
      v7 = RtlAnsiCharToUnicodeChar(v9);
      v8 = v9[0];
      *a1 = v7;
      return v8 - (_DWORD)a2;
    }
    if ( a1 )
      *a1 = 0;
  }
  return 0;
}
