// sub_80D520 
 
void __fastcall sub_80D520(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r6
  int v8; // r7
  __int64 *v9; // r8
  int v10; // r10
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r0
  int v14; // r2
  unsigned __int64 v15; // kr08_8
  unsigned __int64 v16; // kr10_8

  v11 = v7;
  if ( v10 != v7 + 28 )
  {
    v12 = *((_DWORD *)v9 + 3);
    v13 = a5;
    while ( __PAIR64__(v12, *((_DWORD *)v9 + 2)) >= *(_QWORD *)v11 )
    {
      if ( (*(_WORD *)(v11 + 26) & (unsigned __int16)v8) != 0 )
      {
        v14 = *(_DWORD *)(v11 + 16) - 28;
        if ( v11 + 16 != *(_DWORD *)(v11 + 16) )
        {
          v15 = *v9;
          do
          {
            v16 = *(_QWORD *)v14;
            if ( (*(_QWORD *)v14 >= v15 || *(_QWORD *)(v14 + 8) >= v15)
              && (v15 >= v16 || v9[1] >= v16)
              && ((a7 & 1) == 0 || (*(_BYTE *)(v14 + 25) & 1) == 0) )
            {
              goto LABEL_22;
            }
            v14 = *(_DWORD *)(v14 + 28) - 28;
          }
          while ( v11 + 16 != v14 + 28 );
          v13 = a5;
          v8 = 1;
        }
        a3 = a7;
      }
      else if ( (a3 & v8) == 0 || (*(_BYTE *)(v11 + 25) & (unsigned __int8)v8) == 0 )
      {
LABEL_22:
        JUMPOUT(0x79486E);
      }
      v11 = *(_DWORD *)(v11 + 28) - 28;
      if ( v13 == v11 + 28 )
        break;
      v12 = *((_DWORD *)v9 + 3);
    }
  }
  JUMPOUT(0x794806);
}
