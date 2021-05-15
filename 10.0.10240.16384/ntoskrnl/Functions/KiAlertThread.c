// KiAlertThread 
 
int __fastcall KiAlertThread(int a1, int a2, char a3)
{
  int v4; // r6
  int v5; // r5
  int v7; // r3
  int v8; // r0

  v4 = a3 + a2;
  v5 = *(unsigned __int8 *)(v4 + 74);
  if ( !*(_BYTE *)(v4 + 74) )
  {
    if ( *(_BYTE *)(a2 + 132) != 5
      || (v7 = *(_BYTE *)(a2 + 72) & 7, v7 == 4)
      || v7 == 3
      || (*(_DWORD *)(a2 + 76) & 0x10) == 0
      || a3 > *(char *)(a2 + 135)
      || (v8 = KiSignalThread(a1, a2, 257, 0), *(_BYTE *)(a2 + 72) |= 0x80u, !v8) )
    {
      *(_BYTE *)(v4 + 74) = 1;
    }
  }
  return v5;
}
