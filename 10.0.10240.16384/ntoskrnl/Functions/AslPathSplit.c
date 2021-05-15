// AslPathSplit 
 
int __fastcall AslPathSplit(unsigned __int16 *a1, _WORD *a2, unsigned int a3, _WORD *a4, int a5, _WORD *a6)
{
  unsigned __int16 *v10; // r0
  unsigned __int16 *v11; // r5
  unsigned __int16 *v13; // r5
  unsigned __int16 v14[280]; // [sp+4h] [bp-230h] BYREF

  *a2 = 0;
  *a6 = 0;
  *a4 = 0;
  v14[0] = 0;
  v10 = wcsrchr(a1, 92);
  v11 = v10;
  if ( v10 )
  {
    if ( RtlStringCchCopyNW(a2, a3, (int)a1, v10 - a1 + 1) < 0 )
      return sub_7CBAA8();
  }
  else
  {
    v11 = a1;
  }
  if ( *v11 == 92 )
    ++v11;
  if ( RtlStringCchCopyW(v14, 0x105u, (int)v11) < 0 )
    goto LABEL_17;
  v13 = wcsrchr(v14, 46);
  if ( !v13 )
  {
    if ( RtlStringCchCopyW(a4, 0x104u, (int)v14) < 0 )
      JUMPOUT(0x7CBAB6);
    return 0;
  }
  if ( RtlStringCchCopyNW(a4, 0x104u, (int)v14, v13 - v14) < 0 )
    JUMPOUT(0x7CBAAE);
  a4[v13 - v14] = 0;
  if ( RtlStringCchCopyW(a6, 0x104u, (int)v13) < 0 )
LABEL_17:
    JUMPOUT(0x7CBABC);
  return 0;
}
