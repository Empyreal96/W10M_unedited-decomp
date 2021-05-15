// PspQueryLastCallThread 
 
int __fastcall PspQueryLastCallThread(int a1, int a2, int a3, int *a4)
{
  BOOL v5; // r4
  int result; // r0
  int v7; // r2
  int v8; // r3
  int v9; // r6
  int v10; // lr
  int v11; // r8
  unsigned __int64 v12; // kr00_8
  int v13; // r3

  v5 = a3 == 8;
  if ( a3 != 16 && a3 != 8 )
    return -1073741820;
  if ( a1 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
    return -1073741811;
  v7 = *(_DWORD *)(a1 + 128);
  __dmb(0xFu);
  v8 = *(unsigned __int8 *)(a1 + 132);
  __dmb(0xBu);
  if ( v8 != 5 )
    return -1073741823;
  if ( *(_BYTE *)(a1 + 346) != 1 )
    return -1073741823;
  v9 = *(_DWORD *)(a1 + 92);
  v10 = *(_DWORD *)(a1 + 88);
  v11 = *(_DWORD *)(a1 + 304);
  __dmb(0xFu);
  if ( v7 != *(_DWORD *)(a1 + 128) )
    return -1073741823;
  v12 = (unsigned int)(KeTickCount - v11) * (unsigned __int64)(unsigned int)KeMaximumIncrement;
  result = 0;
  *(_DWORD *)a2 = v9;
  *(_WORD *)(a2 + 4) = v10;
  if ( !v5 )
    *(_QWORD *)(a2 + 8) = v12;
  if ( a4 )
  {
    if ( v5 )
      v13 = 8;
    else
      v13 = 16;
    *a4 = v13;
  }
  return result;
}
