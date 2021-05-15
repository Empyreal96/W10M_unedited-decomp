// PopFxCompleteComponentActivation 
 
int __fastcall PopFxCompleteComponentActivation(int a1, _DWORD *a2, int a3)
{
  unsigned int *v6; // r4
  unsigned int v7; // r6
  int v8; // r0
  _DWORD *v10; // [sp+0h] [bp-28h]

  v10 = a2;
  __dmb(0xBu);
  v6 = a2 + 13;
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 | 0x80000000, v6) );
  __dmb(0xBu);
  v8 = KeSetEvent((int)(a2 + 16), 0, 0);
  if ( a3 && a2[33] )
    return sub_540374(v8);
  PopFxIdleComponent(a1, a2[4], 1, 0, v10);
  return PopFxReleaseDevice(a1);
}
