// FsFilterPerformCallbacks 
 
int __fastcall FsFilterPerformCallbacks(int a1, int a2, int a3, _BYTE *a4)
{
  int v5; // r5
  BOOL v6; // r8
  int v7; // r0
  int (__fastcall *v8)(int, _DWORD *); // r7
  int v9; // r2
  unsigned int v10; // r1
  _DWORD *v11; // r4
  int v12; // r3
  _DWORD *v13; // r1
  int result; // r0
  int v15[2]; // [sp+8h] [bp-30h] BYREF
  int v16[10]; // [sp+10h] [bp-28h] BYREF

  v5 = *(_DWORD *)(a1 + 8);
  v16[1] = a3;
  v15[1] = a2;
  *a4 = 0;
  if ( !v5 )
    return 0;
  while ( 1 )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(v5 + 176) + 24) != 0;
    v7 = *(unsigned __int8 *)(a1 + 4);
    *(_DWORD *)(a1 + 8) = v5;
    FsFilterGetCallbacks(v7, v5, v16, v15);
    v8 = (int (__fastcall *)(int, _DWORD *))v16[0];
    v9 = v15[0];
    if ( v16[0] )
      break;
    if ( v15[0] )
      goto LABEL_4;
LABEL_15:
    v5 = *(_DWORD *)(*(_DWORD *)(v5 + 176) + 24);
    if ( !v5 )
      return 0;
  }
  if ( !v15[0] )
  {
    v11 = 0;
    goto LABEL_7;
  }
LABEL_4:
  v10 = *(unsigned __int16 *)(a1 + 46);
  if ( v10 >= *(unsigned __int16 *)(a1 + 44)
    || (v11 = (_DWORD *)(*(_DWORD *)(a1 + 48) + 16 * v10), *(_WORD *)(a1 + 46) = v10 + 1, !v11) )
  {
    JUMPOUT(0x546AB4);
  }
  *v11 = *(_DWORD *)(a1 + 8);
  v12 = *(_DWORD *)(a1 + 12);
  v11[3] = v9;
  v11[1] = v12;
  v11[2] = 0;
LABEL_7:
  if ( !v8 )
    goto LABEL_13;
  if ( v11 )
    v13 = v11 + 2;
  else
    v13 = 0;
  result = v8(a1, v13);
  if ( result < 0 )
    return sub_546A6C();
  if ( !result )
  {
LABEL_13:
    if ( v5 != *(_DWORD *)(a1 + 8) )
      JUMPOUT(0x546A96);
    if ( !v6 )
      JUMPOUT(0x546AA4);
    goto LABEL_15;
  }
  if ( v11 )
    --*(_WORD *)(a1 + 46);
  return result;
}
