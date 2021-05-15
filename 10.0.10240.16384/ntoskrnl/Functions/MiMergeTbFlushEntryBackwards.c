// MiMergeTbFlushEntryBackwards 
 
int __fastcall MiMergeTbFlushEntryBackwards(int result, int a2, int a3)
{
  int v4; // r4
  int v5; // r2
  int v6; // r3

  v4 = result + 4 * *(_DWORD *)(result + 12);
  v5 = *(_DWORD *)(v4 + 16);
  if ( (v5 & 0x800) != 0 )
    v6 = 0x400000;
  else
    v6 = 4096;
  *(_DWORD *)(result + 16) += a3;
  *(_DWORD *)(v4 + 16) = (v5 - v6 * a3) & 0xFFFFF800 | (v5 - v6 * a3 + a3) & 0x7FF;
  return result;
}
