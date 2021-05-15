// PnpFinalizeVetoedRemove 
 
unsigned __int16 *__fastcall PnpFinalizeVetoedRemove(_DWORD *a1, int a2, unsigned __int16 *a3)
{
  _DWORD *v4; // r3
  unsigned __int16 *result; // r0
  int v8; // r3
  int v9; // r1
  unsigned __int16 *v10; // r2

  v4 = (_DWORD *)a1[6];
  if ( v4 )
    *v4 = a2;
  result = (unsigned __int16 *)a1[7];
  if ( result && a3 )
    result = (unsigned __int16 *)RtlCopyUnicodeString(result, a3);
  if ( (a1[22] & 8) != 0 && a2 == 6 )
  {
    result = (unsigned __int16 *)*((_DWORD *)a3 + 1);
    v8 = *a3;
    v9 = 0;
    v10 = result;
    if ( result < (unsigned __int16 *)((char *)result + v8) )
    {
      while ( *v10 != 92 || ++v9 != 3 )
      {
        if ( ++v10 >= (unsigned __int16 *)((char *)result + v8) )
          return result;
      }
      *a3 = (_WORD)v10 - (_WORD)result;
    }
  }
  return result;
}
