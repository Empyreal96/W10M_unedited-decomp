// PopFxValidateReturnedUnicodeString 
 
BOOL __fastcall PopFxValidateReturnedUnicodeString(unsigned __int16 *a1, _WORD *a2, unsigned int a3, int a4)
{
  _WORD *v4; // r6
  BOOL v5; // r4
  int v7; // r5
  int v8; // r2
  int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v4 = (_WORD *)*((_DWORD *)a1 + 1);
  v10[0] = 0;
  v5 = v4 == a2;
  if ( !*v4 )
    v5 = 0;
  v7 = *a1;
  if ( !*a1 )
    v5 = 0;
  v8 = a1[1];
  if ( v8 != a3 )
    v5 = 0;
  if ( v7 != 2 * (v7 >> 1) )
    v5 = 0;
  if ( v8 != 2 * (v8 >> 1) )
    v5 = 0;
  if ( v4[(unsigned int)v7 >> 1] )
    v5 = 0;
  if ( v7 >= (unsigned int)v8 )
    v5 = 0;
  if ( RtlStringCbLengthW((int)v4, a3, v10) < 0 || v7 != v10[0] )
    v5 = 0;
  return v5;
}
