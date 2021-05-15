// KiComputeDueTime 
 
int __fastcall KiComputeDueTime(_DWORD *a1, __int64 a2, unsigned __int8 a3, _DWORD *a4)
{
  int v6; // r1
  unsigned int v7; // r6
  unsigned int v8; // r0
  unsigned int v9; // r7
  int result; // r0
  unsigned int v11; // r0
  unsigned int v12; // r4
  int v13; // [sp+0h] [bp-20h]
  _DWORD *varg_r0; // [sp+28h] [bp+8h]
  __int64 varg_r2; // [sp+30h] [bp+10h]

  varg_r0 = a1;
  varg_r2 = a2;
  v13 = *a1;
  v6 = a3;
  BYTE1(v13) = a3;
  if ( a2 >= 0 )
  {
    v6 = a3 | 1;
    BYTE1(v13) = a3 | 1;
    v11 = MEMORY[0xFFFF9018];
    __dmb(0xBu);
    v12 = MEMORY[0xFFFF9014];
    __dmb(0xBu);
    if ( v11 != MEMORY[0xFFFF901C] )
      return sub_50C8E8();
    if ( (((__PAIR64__(v11, v12) - a2) >> 32) & 0x80000000) == 0i64 )
    {
      *a1 = v13;
      a1[4] = 0;
      a1[5] = 0;
      return 0;
    }
    varg_r2 = __PAIR64__(v11, v12) - a2;
  }
  v7 = 0;
  if ( (v6 & 0xFFFFFFFC) != 0 )
    v7 = (v6 & 0xFFFFFFFC) << 16;
  while ( 1 )
  {
    v8 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    v9 = MEMORY[0xFFFF9008];
    __dmb(0xBu);
    if ( v8 == MEMORY[0xFFFF9010] )
      break;
    __dmb(0xAu);
    __yield();
  }
  *((_QWORD *)a1 + 2) = __PAIR64__(v8, v9) - varg_r2;
  HIBYTE(v13) |= 0x40u;
  BYTE2(v13) = (v9 - (_DWORD)varg_r2 + v7) >> 18;
  *a4 = BYTE2(v13);
  result = 1;
  *a1 = v13;
  return result;
}
