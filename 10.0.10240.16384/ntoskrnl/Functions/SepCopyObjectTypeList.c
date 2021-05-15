// SepCopyObjectTypeList 
 
int __fastcall SepCopyObjectTypeList(int a1, int a2, int *a3)
{
  int v3; // r7
  int v6; // r0
  int v8; // lr
  int v9; // r9
  int v10; // r1
  int v11; // r2
  int v12; // r3

  v3 = a2;
  *a3 = 0;
  if ( a2 )
  {
    v6 = ExAllocatePoolWithTag(1, 44 * a2);
    if ( !v6 )
      return -1073741670;
    if ( v3 )
    {
      v8 = v6;
      v9 = a1 - v6;
      do
      {
        *(_WORD *)v8 = *(_WORD *)(v9 + v8);
        *(_WORD *)(v8 + 2) = *(_WORD *)(v9 + v8 + 2);
        *(_DWORD *)(v8 + 20) = *(_DWORD *)(v9 + v8 + 20);
        v10 = *(_DWORD *)(v9 + v8 + 8);
        v11 = *(_DWORD *)(v9 + v8 + 12);
        v12 = *(_DWORD *)(v9 + v8 + 16);
        *(_DWORD *)(v8 + 4) = *(_DWORD *)(v9 + v8 + 4);
        *(_DWORD *)(v8 + 8) = v10;
        *(_DWORD *)(v8 + 12) = v11;
        *(_DWORD *)(v8 + 16) = v12;
        *(_DWORD *)(v8 + 24) = 0;
        *(_DWORD *)(v8 + 28) = 0;
        *(_DWORD *)(v8 + 32) = 0;
        *(_DWORD *)(v8 + 40) = 0;
        v8 += 44;
        --v3;
      }
      while ( v3 );
    }
    *a3 = v6;
  }
  return 0;
}
