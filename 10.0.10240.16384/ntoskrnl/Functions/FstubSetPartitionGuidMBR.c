// FstubSetPartitionGuidMBR 
 
int __fastcall FstubSetPartitionGuidMBR(int result, int a2)
{
  int v2; // r3
  int v3; // r3

  v2 = *(unsigned __int8 *)(a2 + 32);
  if ( *(_BYTE *)(a2 + 32) && v2 != 5 && v2 != 15 )
  {
    *(_WORD *)(a2 + 44) = 0;
    *(_WORD *)(a2 + 46) = 0;
    v3 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(a2 + 40) = result;
    *(_DWORD *)(a2 + 48) = v3;
    *(_DWORD *)(a2 + 52) = *(_DWORD *)(a2 + 12);
  }
  return result;
}
