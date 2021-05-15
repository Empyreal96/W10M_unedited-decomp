// RtlSidDominates 
 
int __fastcall RtlSidDominates(unsigned __int16 *a1, unsigned __int16 *a2, _BYTE *a3)
{
  int result; // r0
  unsigned int v7; // r2
  char v8[24]; // [sp+0h] [bp-18h] BYREF

  v8[2] = 0;
  v8[5] = 16;
  v8[1] = 0;
  v8[4] = 0;
  v8[0] = 0;
  v8[3] = 0;
  *a3 = 0;
  if ( memcmp((unsigned int)(a1 + 1), (unsigned int)v8, 6) || memcmp((unsigned int)(a2 + 1), (unsigned int)v8, 6) )
    return -1073741811;
  if ( *a1 == *a2 && !memcmp((unsigned int)a1, (unsigned int)a2, 4 * (*((unsigned __int8 *)a1 + 1) + 2))
    || (!*((_BYTE *)a1 + 1) ? (v7 = 0) : (v7 = *(_DWORD *)&a1[2 * *((unsigned __int8 *)a1 + 1) + 2]),
        !*((_BYTE *)a2 + 1) || v7 >= *(_DWORD *)&a2[2 * *((unsigned __int8 *)a2 + 1) + 2]) )
  {
    *a3 = 1;
    result = 0;
  }
  else
  {
    *a3 = 0;
    result = 0;
  }
  return result;
}
