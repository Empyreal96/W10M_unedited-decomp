// KeValidateBugCheckCallbackRecord 
 
int __fastcall KeValidateBugCheckCallbackRecord(int a1, int a2, _DWORD *a3)
{
  int v3; // r7
  int v7; // r8
  unsigned int v8; // r3
  unsigned int v9; // r4
  unsigned int v10; // r6
  unsigned int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3

  v3 = 0;
  v7 = 0;
  if ( (a1 & 3) == 0 )
  {
    v8 = (a1 & 0xFFF) + 4123;
    v9 = v8 >> 12;
    v10 = a1 & 0xFFFFF000;
    if ( v8 >> 12 )
    {
      while ( MiIsAddressValid(v10, 0, (int)a3, v8) )
      {
        v10 += 4096;
        if ( !--v9 )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      if ( *(_DWORD *)(a1 + 4) == *a3 )
      {
        v7 = a1;
        if ( *(_BYTE *)(a1 + 24) == 1 )
        {
          v11 = *(_DWORD *)(a1 + 8);
          v12 = *(_DWORD *)(a1 + 20);
          v13 = *(_DWORD *)(a1 + 12) + v11 + v12;
          v14 = *(_DWORD *)(a1 + 16);
          if ( v14 == v13 && v12 == a2 && MiIsAddressValid(v11, 0, v13, v14) )
            v3 = 1;
        }
      }
    }
  }
  *a3 = v7;
  return v3;
}
