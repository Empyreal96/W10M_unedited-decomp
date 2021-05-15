// HvGetHiveLogFileStatus 
 
int __fastcall HvGetHiveLogFileStatus(int a1, unsigned int a2, int *a3)
{
  unsigned int v6; // r4
  unsigned int v7; // r7
  unsigned __int64 v8; // kr08_8
  int result; // r0
  BOOL v10; // r2
  int v11; // r2
  int v12; // r3

  v8 = (unsigned int)(8 * HvpCountSetRangesInVector(a1 + 36))
     + (unsigned __int64)(unsigned int)(*(_DWORD *)(a1 + 44) << 9)
     + 40;
  v6 = HIDWORD(v8);
  v7 = v8;
  result = RtlAreBitsClear((unsigned int *)(a1 + 36), 0, 8u);
  if ( result )
  {
    v6 = (v8 + 4104) >> 32;
    v7 = v8 + 4104;
  }
  v10 = __PAIR64__(v6, *(_DWORD *)(a1 + 108)) + v7 > 0x2000000;
  *a3 = 0;
  if ( *(_BYTE *)(a1 + 123) )
    *a3 = 2;
  if ( v10 )
    return sub_7D37B0();
  if ( *(_DWORD *)(a1 + 100) == -1 )
    *a3 |= 8u;
  v11 = *a3;
  if ( *a3 && (*(_DWORD *)(a1 + 3312) & 2) != 0 )
  {
    v12 = v11 | 1;
LABEL_16:
    *a3 = v12;
    return result;
  }
  if ( __PAIR64__(v6, *(_DWORD *)(a1 + 108)) + v7 >= a2 )
    *a3 = v11 | 0x10;
  if ( __PAIR64__(v6, *(_DWORD *)(a1 + 108)) + v7 >= a2 )
  {
    v12 = *a3 | 0x20;
    goto LABEL_16;
  }
  return result;
}
