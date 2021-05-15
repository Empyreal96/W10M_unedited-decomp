// MiGetSessionIdForVa 
 
int __fastcall MiGetSessionIdForVa(unsigned int a1)
{
  int v1; // r1
  int v2; // r2
  int result; // r0
  int v4; // r3

  if ( (a1 < dword_63389C
     || (v4 = *((unsigned __int8 *)&MiState[2423]
              + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v4 == 11)
     || v4 == 1)
    && (v1 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), (v2 = *(_DWORD *)(v1 + 324)) != 0)
    && v1 != PsInitialSystemProcess )
  {
    result = *(_DWORD *)(v2 + 8);
  }
  else
  {
    result = -1;
  }
  return result;
}
