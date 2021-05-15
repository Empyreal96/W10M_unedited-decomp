// EtwpUpdatePmcEvents 
 
int __fastcall EtwpUpdatePmcEvents(int a1, int a2, unsigned int a3, int a4)
{
  unsigned int v4; // r6
  int v6; // r5
  int result; // r0
  int v8; // r3
  unsigned int i; // r4
  int v10; // r3
  int varg_r1; // [sp+2Ch] [bp+Ch]

  varg_r1 = a2;
  v4 = a3;
  v6 = a1;
  result = 0;
  if ( !a3 || a3 > 4 )
    return -1073741811;
  if ( *(_DWORD *)(v6 + 628) || (result = EtwpAllocatePmcData(v6, a2)) == 0 )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(v6 + 628) + 16);
    __dmb(0xBu);
    if ( v8 )
      result = -1073741053;
    for ( i = 0; i < v4; ++i )
      *(_WORD *)(*(_DWORD *)(v6 + 628) + 2 * (i + 10)) = *(_DWORD *)(a2 + 4 * i);
    __dmb(0xFu);
    v10 = *(_DWORD *)(v6 + 628);
    __dmb(0xBu);
    *(_DWORD *)(v10 + 16) = v4;
  }
  return result;
}
