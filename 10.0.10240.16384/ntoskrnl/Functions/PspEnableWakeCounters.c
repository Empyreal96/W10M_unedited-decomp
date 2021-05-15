// PspEnableWakeCounters 
 
int __fastcall PspEnableWakeCounters(int a1)
{
  int v1; // r5
  unsigned __int8 *v3; // r3
  unsigned int v4; // r2

  v1 = *(_DWORD *)(a1 + 572);
  if ( v1 )
  {
    if ( (*(_DWORD *)(v1 + 744) & 0x1000) == 0 )
      return sub_7EAD30();
  }
  else if ( (*(_DWORD *)(a1 + 744) & 0x1000) == 0 )
  {
    __dmb(0xBu);
    v3 = (unsigned __int8 *)(a1 + 745);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 | 0x10, v3) );
    __dmb(0xBu);
  }
  return 0;
}
