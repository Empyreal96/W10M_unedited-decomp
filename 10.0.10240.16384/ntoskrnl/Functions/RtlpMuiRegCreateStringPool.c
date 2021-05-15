// RtlpMuiRegCreateStringPool 
 
_BYTE *__fastcall RtlpMuiRegCreateStringPool(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r5
  int v5; // r4
  _BYTE *result; // r0
  _WORD *v7; // r3
  _WORD *v8; // r3
  int v9[4]; // [sp+8h] [bp-10h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v4 = a1;
  v5 = a2;
  if ( a1 < 1 )
    v4 = 4;
  if ( a2 < 1 )
    v5 = 40;
  result = sub_4F4478(0x14u, v4, 2u, v5, 2u, v9);
  if ( result )
  {
    *(_DWORD *)result = v9[0];
    *((_DWORD *)result + 3) = result + 20;
    v7 = &result[2 * (unsigned __int16)v4 + 20];
    *((_DWORD *)result + 4) = v7;
    *((_WORD *)result + 2) = v4;
    *((_WORD *)result + 4) = v5;
    *v7 = 0;
    v8 = (_WORD *)*((_DWORD *)result + 3);
    *((_WORD *)result + 5) = 1;
    *v8 = 0;
    *((_WORD *)result + 3) = 1;
  }
  return result;
}
