// PopLogSleepDisabled 
 
int __fastcall PopLogSleepDisabled(int a1, char a2, int a3, int a4)
{
  _BYTE *v7; // r0
  int v8; // r4
  int **v10; // r1

  if ( PopGetReasonListByReasonCode(a1) )
    return -1073741771;
  v7 = (_BYTE *)ExAllocatePoolWithTag(1, a4 + 24, 1718968931);
  v8 = (int)v7;
  if ( !v7 )
    return -1073741670;
  memset(v7, 0, a4 + 24);
  *(_DWORD *)(v8 + 16) = a1;
  if ( (a2 & 1) != 0 )
    *(_BYTE *)(v8 + 8) = 1;
  if ( (a2 & 2) != 0 )
    *(_BYTE *)(v8 + 9) = 1;
  if ( (a2 & 4) != 0 )
    *(_BYTE *)(v8 + 10) = 1;
  if ( (a2 & 8) != 0 )
    *(_BYTE *)(v8 + 11) = 1;
  if ( (a2 & 0x10) != 0 )
    *(_BYTE *)(v8 + 14) = 1;
  if ( (a2 & 0x20) != 0 )
    *(_BYTE *)(v8 + 12) = 1;
  if ( a4 )
    return sub_7F1460();
  v10 = (int **)dword_61EF24;
  *(_DWORD *)v8 = &PowerStateDisableReasonListHead;
  *(_DWORD *)(v8 + 4) = v10;
  if ( *v10 != &PowerStateDisableReasonListHead )
    __fastfail(3u);
  *v10 = (int *)v8;
  dword_61EF24 = v8;
  return 0;
}
