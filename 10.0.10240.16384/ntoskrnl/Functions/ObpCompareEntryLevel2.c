// ObpCompareEntryLevel2 
 
int __fastcall ObpCompareEntryLevel2(int a1, int a2)
{
  _DWORD *v3; // r1
  int v4; // r5

  v3 = *(_DWORD **)(a2 + 8);
  v4 = *(_DWORD *)(a1 + 4);
  if ( v4 == v3[1]
    && *(_DWORD *)a1 == *v3
    && RtlCompareMemory((unsigned __int8 *)a1, (int)v3, *(_DWORD *)(a1 + 4)) == v4 )
  {
    ++*(_DWORD *)(a2 + 16);
  }
  return 1;
}
