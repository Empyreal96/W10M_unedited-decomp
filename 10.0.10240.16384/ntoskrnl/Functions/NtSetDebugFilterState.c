// NtSetDebugFilterState 
 
int __fastcall NtSetDebugFilterState(unsigned int a1, unsigned int a2, int a3)
{
  int v4; // r4
  int *v6; // r2
  int v7; // r1

  v4 = a2;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    return sub_81BA74();
  v6 = &Kd_WIN2000_Mask;
  if ( a1 >= 0x9A )
  {
    if ( a1 != -1 )
      v6 = &Kd_DEFAULT_Mask;
  }
  else
  {
    v6 = (int *)*(&KdComponentTable + a1);
  }
  if ( a2 <= 0x1F )
    v4 = 1 << a2;
  v7 = v4;
  if ( !a3 )
    v7 = 0;
  *v6 = *v6 & ~v4 | v7;
  return 0;
}
