// ExRaiseHardError 
 
int __fastcall ExRaiseHardError(int a1, unsigned int a2, int a3, _DWORD **a4, int a5, int *a6)
{
  _DWORD **v6; // r8
  int *v9; // r5
  int v10; // r3
  int v11; // r4
  int v12; // r4
  unsigned int v13; // r0
  _DWORD *v14; // r1
  _DWORD **v15; // r5
  _DWORD *v16; // r2
  int v17; // r0
  unsigned int i; // r6
  _DWORD *v19; // r5
  _DWORD *v20; // r4
  _DWORD **v22; // [sp+10h] [bp-78h]
  int v23; // [sp+1Ch] [bp-6Ch]
  int v24; // [sp+30h] [bp-58h]
  _DWORD _40[24]; // [sp+40h] [bp-48h] BYREF

  _40[23] = a4;
  v6 = a4;
  _40[22] = a3;
  _40[21] = a2;
  v24 = a1;
  _40[20] = a1;
  v9 = a6;
  if ( ExpTooLateForErrors )
  {
    v10 = 1;
    v11 = 0;
LABEL_25:
    *v9 = v10;
    return v11;
  }
  if ( a2 > 5 )
    return -1073741584;
  v22 = 0;
  if ( !a4 )
  {
LABEL_21:
    v11 = ExpRaiseHardError(a1, a2, a3);
    if ( v22 && v22 != v6 )
      ZwFreeVirtualMemory();
    v10 = (int)a6;
    goto LABEL_25;
  }
  if ( !a3 )
  {
    v22 = a4;
    goto LABEL_21;
  }
  v12 = 68;
  v13 = 0;
  v14 = _40;
  v15 = a4;
  while ( v13 < a2 )
  {
    if ( ((1 << v13) & a3) != 0 )
    {
      v16 = *v15;
      *v14 = **v15;
      v14[1] = v16[1];
      v12 += *((unsigned __int16 *)v14 + 1);
    }
    ++v13;
    ++v15;
    v14 += 2;
  }
  v11 = ZwAllocateVirtualMemory();
  if ( v11 >= 0 )
  {
    v17 = 60;
    v23 = 60;
    for ( i = 0; i < a2; ++i )
    {
      if ( ((1 << i) & a3) != 0 )
      {
        v19 = (_DWORD *)(8 * i + 20);
        *(_DWORD *)(4 * i) = v19;
        v20 = &_40[2 * i];
        memmove(v17, v20[1], *((unsigned __int16 *)v20 + 1));
        _40[2 * i + 1] = v23;
        *v19 = *v20;
        v19[1] = v20[1];
        v17 = v23 + *((unsigned __int16 *)v20 + 1);
        v23 = v17;
      }
      else
      {
        *(_DWORD *)(4 * i) = v6[i];
      }
    }
    v9 = a6;
    a1 = v24;
    goto LABEL_21;
  }
  return v11;
}
