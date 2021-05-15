// MI_INITIALIZE_COLOR_BASE 
 
int __fastcall MI_INITIALIZE_COLOR_BASE(int result, int a2, int a3)
{
  unsigned int v4; // r2
  int v5; // r3
  unsigned int v6; // r3

  if ( a2 )
  {
    v4 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    v5 = (a2 + 0xFFFF) << byte_6337F5;
  }
  else
  {
    v4 = (unsigned int)*(&KiProcessorBlock + *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16C));
    v5 = *(_DWORD *)(v4 + 2732);
  }
  *(_WORD *)(a3 + 6) = v5;
  *(_WORD *)(a3 + 4) = (1 << byte_6337FC) - 1;
  if ( result && (*(_BYTE *)(result + 112) & 7u) < 2 )
    v6 = result + 96;
  else
    v6 = v4 + 2724;
  *(_DWORD *)a3 = v6;
  return result;
}
