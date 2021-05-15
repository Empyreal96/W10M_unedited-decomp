// IopMemQueryConflict 
 
int __fastcall IopMemQueryConflict(int a1, int a2, int a3, int a4)
{
  int v4; // r9
  int v5; // r2
  unsigned int v6; // r3
  int v7; // r6
  unsigned int v8; // r10
  unsigned int v9; // r7
  _DWORD *v10; // r8
  _DWORD *v11; // r9
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r3
  int v17; // [sp+0h] [bp-28h] BYREF
  int v18; // [sp+4h] [bp-24h]
  int v19; // [sp+8h] [bp-20h]

  v17 = a2;
  v19 = a4;
  v4 = a2;
  v18 = a2;
  v7 = ArbQueryConflict();
  if ( v7 >= 0 )
  {
    v7 = IopIsPciRootBus(*(_DWORD *)v4, &v17, v5, v6);
    if ( v7 >= 0 && (_BYTE)v17 )
    {
      v8 = 0;
      v9 = **(_DWORD **)(v4 + 8);
      v10 = **(_DWORD ***)(v4 + 12);
      if ( v9 )
      {
        v11 = &v10[6 * v9];
        do
        {
          if ( ArbIsConflictWithMmConfigRange(v10[2], v10[3], v10[4], v10[5]) )
          {
            v11 -= 6;
            v12 = v11[1];
            v13 = v11[2];
            v14 = v11[3];
            *v10 = *v11;
            v10[1] = v12;
            v10[2] = v13;
            v10[3] = v14;
            v15 = v11[5];
            --v9;
            v10[4] = v11[4];
            v10[5] = v15;
          }
          else
          {
            ++v8;
            v10 += 6;
          }
        }
        while ( v8 < v9 );
        v4 = v18;
      }
      **(_DWORD **)(v4 + 8) = v9;
    }
    else
    {
      v7 = 0;
    }
  }
  return v7;
}
