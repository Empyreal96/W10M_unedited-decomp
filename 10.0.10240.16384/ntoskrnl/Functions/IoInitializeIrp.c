// IoInitializeIrp 
 
_BYTE *__fastcall IoInitializeIrp(int a1, __int16 a2, char a3)
{
  int v3; // r5
  _BYTE *result; // r0

  v3 = a3;
  if ( (MmVerifierData & 0x10) != 0 )
    return (_BYTE *)sub_524D00();
  result = memset((_BYTE *)a1, 0, a2);
  *(_WORD *)a1 = 6;
  *(_BYTE *)(a1 + 35) = v3 + 1;
  *(_WORD *)(a1 + 2) = a2;
  *(_BYTE *)(a1 + 34) = v3;
  *(_BYTE *)(a1 + 38) = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A);
  *(_DWORD *)(a1 + 16) = a1 + 16;
  *(_DWORD *)(a1 + 20) = a1 + 16;
  *(_DWORD *)(a1 + 96) = a1 + 40 * v3 + 112;
  return result;
}
