// MiSetVadBits 
 
int __fastcall MiSetVadBits(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r1
  unsigned int v5; // r2
  int result; // r0
  unsigned int v7; // r3
  int v8; // [sp+0h] [bp-10h] BYREF
  int v9; // [sp+4h] [bp-Ch]

  v8 = a3;
  v9 = a4;
  v4 = (unsigned __int16)(*(_DWORD *)(a1 + 12) >> 4);
  v5 = (unsigned __int16)(*(_DWORD *)(a1 + 16) >> 4);
  result = MEMORY[0xC040212C] + 1069547520;
  if ( v5 >= 8 * (MEMORY[0xC040212C] + 1069547520) )
  {
    v7 = MEMORY[0xC0402114] + 8 * result;
    if ( v4 < v7 )
    {
      if ( v4 < 8 * result )
        v4 = 8 * result;
      if ( v5 >= v7 )
        v5 = v7 - 1;
      v8 = MEMORY[0xC0402114];
      v9 = MEMORY[0xC040212C];
      result = (int)RtlSetBits(&v8, v4 - 8 * result, v5 - v4 + 1);
    }
  }
  return result;
}
