// IopDmaPackResource 
 
int __fastcall IopDmaPackResource(int a1, int a2, unsigned int a3, int a4, int a5)
{
  __int16 v5; // r3

  *(_BYTE *)a5 = 4;
  *(_BYTE *)(a5 + 1) = *(_BYTE *)(a1 + 2);
  v5 = *(_WORD *)(a1 + 4);
  *(_WORD *)(a5 + 2) = v5;
  if ( (v5 & 0x80) != 0 )
  {
    *(_DWORD *)(a5 + 4) = *(_DWORD *)(a1 + 16);
    *(_DWORD *)(a5 + 8) = *(_DWORD *)(a1 + 8);
    *(_BYTE *)(a5 + 12) = *(_DWORD *)(a1 + 20);
  }
  else
  {
    *(_QWORD *)(a5 + 4) = a3;
  }
  return 0;
}
