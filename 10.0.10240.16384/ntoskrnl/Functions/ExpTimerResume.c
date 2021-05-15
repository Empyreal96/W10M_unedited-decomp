// ExpTimerResume 
 
int __fastcall ExpTimerResume(int result, int a2, int a3, int a4)
{
  int v4; // r4

  v4 = result;
  if ( *(_BYTE *)(result + 145) )
  {
    if ( *(_BYTE *)(result + 145) == 3 )
      return sub_50F864(result, a4, *(_DWORD *)(result + 176), *(_DWORD *)(result + 180));
    result = KeSetCoalescableTimer(result);
  }
  *(_BYTE *)(v4 + 144) &= 0xFDu;
  return result;
}
