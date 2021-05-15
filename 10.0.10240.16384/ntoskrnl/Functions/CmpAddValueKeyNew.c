// CmpAddValueKeyNew 
 
int __fastcall CmpAddValueKeyNew(int a1, unsigned __int16 *a2, int a3, int a4, unsigned int a5, int a6)
{
  int v7; // r7
  int v11; // r0
  int v12; // r8
  _WORD *v13; // r4
  _WORD *v14; // r0
  unsigned int v15; // r0
  int v17; // [sp+8h] [bp-28h] BYREF
  int v18[9]; // [sp+Ch] [bp-24h] BYREF

  v7 = -1;
  v17 = -1;
  v11 = CmpNameSize(a2);
  v12 = HvAllocateCell(a1, v11 + 20, a6, v18, &v17);
  if ( v12 != -1 )
  {
    v13 = (_WORD *)v18[0];
    v14 = (_WORD *)(v18[0] + 20);
    *(_WORD *)v18[0] = 27510;
    v15 = CmpCopyName(v14, a2);
    v13[1] = v15;
    v13[8] = v15 < *a2;
    if ( a5 <= 4 )
    {
      *((_DWORD *)v13 + 1) = a5 + 0x80000000;
      *((_DWORD *)v13 + 2) = 0;
      memmove((int)(v13 + 4), a4, a5);
    }
    else
    {
      if ( CmpSetValueDataNew(a1, a4, a5, a6, (int *)v13 + 2) < 0 )
        return sub_803B84();
      *((_DWORD *)v13 + 1) = a5;
    }
    *((_DWORD *)v13 + 3) = a3;
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v17);
    v7 = v12;
  }
  return v7;
}
