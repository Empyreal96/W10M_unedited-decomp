// Normalization__GetLastChar 
 
int __fastcall Normalization__GetLastChar(int a1, int a2, unsigned __int16 **a3, int *a4, _BYTE *a5, _BYTE *a6)
{
  unsigned __int16 *v8; // r1
  unsigned __int16 *v10; // r4
  int result; // r0
  unsigned int v13; // r2
  int v14; // r3
  char v15; // r2
  _BYTE *v16; // r3
  char v17; // r1

  v8 = *a3;
  v10 = (unsigned __int16 *)(a2 - 2);
  result = *a4;
  if ( *a3 != v10 )
  {
    v13 = *v10;
    if ( v13 < 0xD800 || v13 > 0xDFFF || (--v10, v8 != v10) )
    {
      result = *v10;
      if ( (unsigned int)(result - 55296) <= 0x7FF )
        result += (*(v10 - 1) - 55287) << 10;
      v14 = *(_DWORD *)(a1 + 20);
      if ( *(_BYTE *)((result >> 7) + v14) )
      {
        v17 = *(_BYTE *)(*(_DWORD *)(a1 + 24) + (result & 0x7F) + (*(unsigned __int8 *)((result >> 7) + v14) << 7) - 128);
        *a5 = v17 & 0x3F;
        v16 = a6;
        v15 = v17 & 0xC0;
      }
      else
      {
        v15 = 0;
        *a6 = 0;
        v16 = a5;
      }
      *v16 = v15;
      *a3 = v10;
      *a4 = result;
    }
  }
  return result;
}
