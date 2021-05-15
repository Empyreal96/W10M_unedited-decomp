// EtwpSystemImageEnumCallback 
 
int __fastcall EtwpSystemImageEnumCallback(int a1, int *a2)
{
  __int64 v2; // kr00_8
  unsigned int v3; // r2

  v2 = *(_QWORD *)a2;
  *(_DWORD *)*a2 = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(*a2 + 4) = *(_DWORD *)(a1 + 32);
  *(_DWORD *)(*a2 + 12) = *(_DWORD *)(a1 + 64);
  *(_DWORD *)(*a2 + 16) = *(_DWORD *)(a1 + 88);
  *(_BYTE *)(*a2 + 20) = *(_WORD *)(a1 + 58) & 0xF;
  *(_BYTE *)(*a2 + 21) = (*(unsigned __int16 *)(a1 + 58) >> 4) & 7;
  v3 = *(unsigned __int16 *)(a1 + 36);
  *(_QWORD *)(HIDWORD(v2) + 16) = *(unsigned int *)(a1 + 40);
  *(_QWORD *)(HIDWORD(v2) + 24) = v3;
  EtwpLogKernelEvent((int *)HIDWORD(v2), a2[2], 3, *((unsigned __int16 *)a2 + 6), 4200707);
  return 0;
}
