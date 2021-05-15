// NtGetCurrentProcessorNumberEx 
 
int __fastcall NtGetCurrentProcessorNumberEx(unsigned int a1, int a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r2

  v2 = a1;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    ProbeForWrite(a1, 4, 1);
  v3 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  *(_WORD *)v2 = *(unsigned __int8 *)(v3 + 2460);
  *(_BYTE *)(v2 + 2) = *(_BYTE *)(v3 + 2461);
  *(_BYTE *)(v2 + 3) = 0;
  return 0;
}
