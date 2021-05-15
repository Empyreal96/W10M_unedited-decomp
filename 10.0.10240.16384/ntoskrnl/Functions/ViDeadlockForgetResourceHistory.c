// ViDeadlockForgetResourceHistory 
 
int __fastcall ViDeadlockForgetResourceHistory(int result, unsigned int a2, unsigned int a3, int *a4)
{
  int v4; // r7
  int v6; // r1
  _DWORD *v7; // r9
  int v8; // r8
  unsigned int v9; // r6
  _DWORD *v10; // r5
  _DWORD *v11; // r4
  unsigned int v12; // r3
  int v13; // r3
  _DWORD *v14; // r5
  int v15; // r6
  _DWORD *v16; // r4
  int v17; // r3
  int v18; // [sp+0h] [bp-28h]
  unsigned int v20; // [sp+8h] [bp-20h]

  v4 = result;
  v6 = 0;
  v20 = a3;
  v18 = 0;
  if ( *(_DWORD *)(result + 12) || *(unsigned __int16 *)(result + 4) < a2 )
    return result;
  v7 = (_DWORD *)(result + 16);
  v8 = ViDeadlockGlobals;
  v9 = *(_DWORD *)(ViDeadlockGlobals + 16420);
  v10 = *(_DWORD **)(result + 16);
  while ( v10 != v7 )
  {
    v11 = v10 - 5;
    v12 = v10[4];
    v10 = (_DWORD *)*v10;
    if ( v9 <= v12 >> 3 )
    {
      if ( (v12 >> 3) - v9 < a3 )
        goto LABEL_8;
    }
    else if ( v9 - (v12 >> 3) > a3 )
    {
LABEL_8:
      result = ViDeadlockRemoveNode(v11, 0);
      a3 = v20;
      v13 = *a4;
      v6 = v18 + 1;
      *a4 = (int)v11;
      *v11 = v13;
      ++v18;
    }
  }
  *(_DWORD *)(v8 + 16404) += v6;
  if ( *(unsigned __int16 *)(v4 + 4) >= a2 )
  {
    v14 = *(_DWORD **)(v4 + 16);
    v15 = 0;
    while ( v14 != v7 && *(unsigned __int16 *)(v4 + 4) >= a2 )
    {
      v16 = v14 - 5;
      v14 = (_DWORD *)*v14;
      result = ViDeadlockRemoveNode(v16, 0);
      ++v15;
      v17 = *a4;
      *a4 = (int)v16;
      *v16 = v17;
    }
    *(_DWORD *)(v8 + 16408) += v15;
  }
  return result;
}
