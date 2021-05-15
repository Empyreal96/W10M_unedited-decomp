// RtlpHeapListCompare 
 
int __fastcall RtlpHeapListCompare(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // [sp+8h] [bp-10h]

  if ( !a4 )
    return a3 - *(_DWORD *)(a2 + 20);
  v5 = *(_DWORD *)(a2 - 8);
  if ( !*(_DWORD *)(a1 + 76)
    || (v5 = *(_DWORD *)(a1 + 80) ^ *(_DWORD *)(a2 - 8), HIBYTE(v5) == (BYTE1(v5) ^ (unsigned __int8)v5 ^ BYTE2(v5))) )
  {
    result = a3 - (unsigned __int16)v5;
  }
  else
  {
    result = sub_528B10();
  }
  return result;
}
