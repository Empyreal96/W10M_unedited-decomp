// ObpLookupDirectoryEntry 
 
int __fastcall ObpLookupDirectoryEntry(int a1, unsigned __int16 *a2, char a3, int a4, int a5)
{
  int v7; // lr
  int v8; // r8
  unsigned __int16 *v9; // r6
  int v10; // r5
  unsigned int v11; // r4
  unsigned int v12; // r0
  unsigned int v13; // t1
  int v14; // r4
  int result; // r0

  v7 = a1;
  v8 = (a3 & 0x40) != 0;
  v9 = (unsigned __int16 *)*((_DWORD *)a2 + 1);
  v10 = *a2 >> 1;
  v11 = 0;
  if ( v10 )
  {
    do
    {
      v13 = *v9++;
      v12 = v13;
      --v10;
      v14 = 3 * v11 + (v11 >> 1);
      if ( v13 >= 0x61 )
      {
        if ( v12 > 0x7A )
          v11 = v14 + RtlUpcaseUnicodeChar(v12);
        else
          v11 = v12 + v14 - 32;
      }
      else
      {
        v11 = v14 + v12;
      }
    }
    while ( v10 );
    v7 = a1;
  }
  *(_WORD *)(a5 + 16) = v11 % 0x25;
  *(_DWORD *)(a5 + 12) = v11;
  result = ObpLookupDirectoryUsingHash(v7, (int)a2, a5, v8);
  if ( !result )
  {
    if ( a4 )
      result = sub_7DD860();
  }
  return result;
}
