// CmpRegisterCallbackInternal 
 
int __fastcall CmpRegisterCallbackInternal(unsigned int a1, unsigned int a2, unsigned __int16 *a3, int a4, _DWORD *a5)
{
  unsigned __int64 v6; // r6
  int v8; // r0
  _DWORD *v9; // r4
  int v10; // r5
  __int16 v11; // r3
  int v12; // r0
  unsigned int v13; // r0

  v6 = __PAIR64__(a1, a2);
  v8 = ExAllocatePoolWithTag(1, 48, 1650675011);
  v9 = (_DWORD *)v8;
  if ( !v8 )
    return -1073741670;
  *(_DWORD *)v8 = v8;
  *(_DWORD *)(v8 + 4) = v8;
  *(_DWORD *)(v8 + 40) = v8 + 40;
  *(_DWORD *)(v8 + 44) = v8 + 40;
  __dmb(0xBu);
  *(_DWORD *)(v8 + 8) = 0;
  *(_QWORD *)(v8 + 24) = v6;
  v11 = *a3;
  *(_WORD *)(v8 + 34) = *a3;
  *(_WORD *)(v8 + 32) = v11;
  v12 = ExAllocatePoolWithTag(1, *a3, 1633897795);
  v9[9] = v12;
  if ( v12 )
  {
    memmove(v12, *((_DWORD *)a3 + 1), *a3);
    v10 = CmpInsertCallbackInListByAltitude((int)v9, a4);
    *a5 = v9[4];
    a5[1] = v9[5];
    if ( v10 >= 0 )
      return v10;
  }
  else
  {
    v10 = -1073741670;
  }
  v13 = v9[9];
  if ( v13 )
    ExFreePoolWithTag(v13);
  ExFreePoolWithTag((unsigned int)v9);
  return v10;
}
