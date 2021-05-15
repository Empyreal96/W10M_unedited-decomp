// PspEnableProcessWakeCounters 
 
int __fastcall PspEnableProcessWakeCounters(int a1)
{
  int v1; // r4
  int result; // r0

  v1 = *(_DWORD *)(a1 + 288);
  __dmb(0xBu);
  if ( (*(_DWORD *)(v1 + 744) & 0x1000) != 0 )
    result = 0;
  else
    result = sub_7EB1FC();
  return result;
}
