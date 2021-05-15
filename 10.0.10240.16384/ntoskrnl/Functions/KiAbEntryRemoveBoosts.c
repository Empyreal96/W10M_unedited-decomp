// KiAbEntryRemoveBoosts 
 
int __fastcall KiAbEntryRemoveBoosts(int result, int a2, int a3)
{
  int v3; // r5
  __int16 v4; // r3
  unsigned int *v6; // r2
  unsigned int v7; // r4

  v3 = result;
  v4 = *(_WORD *)(result + 44);
  if ( v4 )
  {
    if ( (v4 & 1) != 0 )
    {
      __dmb(0xBu);
      v6 = (unsigned int *)(a2 + 804);
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 - 1, v6) );
      __dmb(0xBu);
      result = PsBoostThreadIoEx(a2, 1, 0);
    }
    if ( (*(_WORD *)(v3 + 44) & 0xFFFE) != 0 )
      result = KiAbThreadUnboostCpuPriority(a2, v3, a3, *(_WORD *)(v3 + 44) & 0xFFFE);
    if ( (dword_682604 & 0x200) != 0 )
      result = sub_50CEC0(result);
    else
      *(_WORD *)(v3 + 44) = 0;
  }
  return result;
}
