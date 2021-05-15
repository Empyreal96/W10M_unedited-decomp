// ExpGetSystemBasicInformation 
 
int __fastcall ExpGetSystemBasicInformation(int a1)
{
  int v1; // r3

  if ( *(_BYTE *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x99C) )
    v1 = 0;
  else
    v1 = dword_681D78[0];
  *(_DWORD *)(a1 + 36) = v1;
  *(_BYTE *)(a1 + 40) = *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v1 >> 24))
                      + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v1 >> 16))
                      + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v1)
                      + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v1 >> 8));
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = KeMaximumIncrement;
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(*(_DWORD *)dword_634340 + 3592);
  *(_DWORD *)(a1 + 16) = *(_DWORD *)(*(_DWORD *)dword_634340 + 3584);
  *(_DWORD *)(a1 + 20) = *(_DWORD *)(*(_DWORD *)dword_634340 + 3588);
  *(_DWORD *)(a1 + 8) = 4096;
  *(_DWORD *)(a1 + 24) = 0x10000;
  *(_DWORD *)(a1 + 28) = 0x10000;
  *(_DWORD *)(a1 + 32) = MmHighestUserAddress;
  return 0;
}
