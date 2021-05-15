// RtlpCreateUCREntry 
 
int __fastcall RtlpCreateUCREntry(int a1, _DWORD *a2, int a3, int a4, unsigned int a5, int *a6)
{
  unsigned int v6; // r4
  int result; // r0
  bool v11; // zf
  unsigned int v12; // r2
  int v13; // r0

  *(_DWORD *)(a3 + 16) = a3 + 24;
  *(_DWORD *)(a3 + 20) = a4;
  v6 = a3 - 8;
  *(_BYTE *)(v6 + 2) = 1;
  *(_WORD *)v6 = 4;
  *(_BYTE *)(v6 + 7) = 3;
  *(_BYTE *)(v6 + 3) = 0;
  if ( (_DWORD *)a2[6] != a2 )
    return sub_554090();
  *(_BYTE *)(a3 - 2) = 0;
  if ( RtlpHeapErrorHandlerThreshold >= 1 )
  {
    v11 = a5 == v6;
    if ( a5 > v6 )
    {
      v13 = DbgPrint("((PHEAP_ENTRY)LastKnownEntry <= Entry)");
      RtlpHeapHandleError(v13);
    }
  }
  else
  {
    v11 = a5 == v6;
  }
  if ( !v11 )
    *(_WORD *)(a3 - 4) = *(_WORD *)(a1 + 84);
  if ( *(_DWORD *)(a1 + 76) )
  {
    *(_BYTE *)(a3 - 5) = *(_BYTE *)(a3 - 8) ^ *(_BYTE *)(a3 - 6) ^ *(_BYTE *)(a3 - 7);
    *(_DWORD *)v6 ^= *(_DWORD *)(a1 + 80);
  }
  result = RtlpInsertUCRBlock(a1, a3);
  ++a2[12];
  a2[11] += *(_DWORD *)(a3 + 20) >> 12;
  *(_DWORD *)(a1 + 484) -= *(_DWORD *)(a3 + 20);
  ++*(_DWORD *)(a1 + 500);
  v12 = *(_DWORD *)(a3 + 20);
  if ( v12 >= 0x7F000 )
    *(_DWORD *)(a1 + 488) += v12;
  *a6 = (int)(v6 - a5) >> 3;
  return result;
}
