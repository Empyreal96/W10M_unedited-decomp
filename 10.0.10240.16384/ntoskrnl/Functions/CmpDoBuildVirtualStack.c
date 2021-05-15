// CmpDoBuildVirtualStack 
 
int __fastcall CmpDoBuildVirtualStack(unsigned __int16 *a1, unsigned int a2, int a3, int a4)
{
  unsigned int i; // r5
  int v8; // r3
  int v9; // r0
  int v10; // r2
  unsigned int v11; // r1
  int v12; // r0
  int v14[6]; // [sp+0h] [bp-18h] BYREF

  v14[0] = a3;
  v14[1] = a4;
  for ( i = 0; i < a2; a1 += 14 )
  {
    CmpFindSubKeyByNameWithStatus(a3, *((_DWORD *)a1 + 2), (int)a1, v14);
    v8 = v14[0];
    *((_DWORD *)a1 + 5) = v14[0];
    if ( v8 == -1 )
    {
      if ( !HvpMarkCellDirty(a3, *((_DWORD *)a1 + 4), 0, 0) )
        return -1073741443;
      v9 = CmpCreateEmptyKey(a3, a1, *((_DWORD *)a1 + 4));
      *((_DWORD *)a1 + 5) = v9;
      if ( v9 == -1 || !CmpAddSubKeyEx(a3, *((_DWORD *)a1 + 4), v9, 0) )
        return -1073741670;
      if ( i )
      {
        v10 = *((_DWORD *)a1 + 2);
        v11 = *a1;
        if ( *(unsigned __int16 *)(v10 + 52) < v11 )
          *(_WORD *)(v10 + 52) = v11;
      }
    }
    if ( i < a2 - 1 )
    {
      *((_DWORD *)a1 + 11) = *((_DWORD *)a1 + 5);
      v12 = (*(int (__fastcall **)(int))(a3 + 4))(a3);
      *((_DWORD *)a1 + 9) = v12;
      if ( !v12 )
        return -1073741670;
    }
    ++i;
  }
  return 0;
}
