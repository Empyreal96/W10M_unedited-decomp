// RtlpMuiRegConfigNodePopulate 
 
int __fastcall RtlpMuiRegConfigNodePopulate(int a1, int a2, _WORD *a3, int a4)
{
  _WORD *v4; // r4
  signed int v7; // r5
  unsigned int v8; // r6
  int result; // r0
  char v10[2]; // [sp+8h] [bp-20h] BYREF
  __int16 v11; // [sp+Ah] [bp-1Eh]
  int v12[7]; // [sp+Ch] [bp-1Ch] BYREF

  v4 = a3;
  if ( !a1 || !a2 || !a3 || !a4 )
    return -1073741811;
  v7 = 2 * a4;
  v8 = 0;
  do
  {
    if ( !*v4 || v7 <= 0 || v8 >= 3 )
      break;
    if ( RtlpMuiRegGetLanguageSpec(a2, v4, v10) >= 0 )
    {
      *(_WORD *)(a1 + 2) = ((v10[0] & 3) << (2 * v8)) | *(_WORD *)(a1 + 2) & ~(3 << (2 * v8));
      *(_WORD *)(2 * v8 + a1 + 6) = v11;
    }
    result = RtlStringCbLengthW((int)v4, v7, v12);
    if ( result < 0 )
      return result;
    v4 = (_WORD *)((char *)v4 + v12[0] + 2);
    v7 = v7 - v12[0] - 2;
    v8 = (unsigned __int16)(v8 + 1);
  }
  while ( v4 );
  return 0;
}
