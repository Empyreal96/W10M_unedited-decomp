// RaspInterpolatePoint 
 
int __fastcall RaspInterpolatePoint(int a1, int a2)
{
  int result; // r0

  result = RaspAllocateMemory(17);
  if ( !result )
    return 0;
  *(_DWORD *)result = (*(_DWORD *)a2 + *(_DWORD *)a1) / 2;
  *(_DWORD *)(result + 4) = (*(_DWORD *)(a2 + 4) + *(_DWORD *)(a1 + 4)) / 2;
  *(_DWORD *)(result + 8) = (*(_DWORD *)(a2 + 8) + *(_DWORD *)(a1 + 8)) / 2;
  *(_DWORD *)(result + 12) = (*(_DWORD *)(a2 + 12) + *(_DWORD *)(a1 + 12)) / 2;
  *(_BYTE *)(result + 16) = *(_BYTE *)(a2 + 16) | *(_BYTE *)(a1 + 16) | 1;
  return result;
}
