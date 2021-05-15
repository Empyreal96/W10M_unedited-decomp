// sub_54D724 
 
void __fastcall sub_54D724(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r4
  int v7; // r6
  int v8; // r7
  int v9; // r4
  int v10; // r8
  int v11; // r5
  int v12; // r0
  int v13; // r1
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r2
  int v18; // r3
  int v19; // r2
  int v20; // r3

  if ( v6 )
  {
    if ( *(_BYTE *)(v7 + 28) )
    {
      if ( *(_BYTE *)(v7 + 29) )
      {
        if ( *(_DWORD *)(v8 + 16) == *(_DWORD *)(v7 + 44)
          && *(_DWORD *)(v8 + 4) == *(_DWORD *)(v7 + 32)
          && *(_DWORD *)(v8 + 8) == *(_DWORD *)(v7 + 36) )
        {
          v19 = *(_DWORD *)(v8 + 12);
          v20 = *(_DWORD *)(v7 + 40);
          if ( v19 == v20 )
          {
            MmGetPhysicalAddress((int)&a5, *(_DWORD *)(v7 + 52), v19, v20);
            if ( *(_DWORD *)(v8 + 24) == a5 && !a6 )
            {
              *(_BYTE *)(v8 + 1) = 1;
              *(_DWORD *)(v8 + 24) = *(_DWORD *)(v7 + 52);
              JUMPOUT(0x4E1F52);
            }
          }
        }
      }
    }
  }
  else
  {
    if ( *(_DWORD *)(v8 + 16) == 4 )
      v9 = 3;
    else
      v9 = 4;
    v10 = *(_DWORD *)(v8 + 24);
    v11 = *(_DWORD *)(v8 + 12) * *(_DWORD *)(v8 + 4);
    v12 = MmMapIoSpaceEx(v10, 0, v11 * v9, 4);
    *(_DWORD *)(v8 + 24) = v12;
    if ( !v12 )
      *(_DWORD *)(v8 + 24) = MmMapIoSpaceEx(v10, 0, v11 * v9, 516);
    if ( *(_DWORD *)(v8 + 24) )
    {
      *(_BYTE *)(v8 + 1) = 1;
      if ( *(_BYTE *)(v7 + 28) && *(_BYTE *)(v7 + 29) )
      {
        if ( *(_DWORD *)(v7 + 44) == 4 )
          v13 = 3;
        else
          v13 = 4;
        MmUnmapIoSpace(*(_DWORD *)(v7 + 52), *(_DWORD *)(v7 + 32) * *(_DWORD *)(v7 + 40) * v13);
      }
      v14 = *(_DWORD *)(v8 + 4);
      v15 = *(_DWORD *)(v8 + 8);
      v16 = *(_DWORD *)(v8 + 12);
      *(_DWORD *)(v7 + 28) = *(_DWORD *)v8;
      *(_DWORD *)(v7 + 32) = v14;
      *(_DWORD *)(v7 + 36) = v15;
      *(_DWORD *)(v7 + 40) = v16;
      v17 = *(_DWORD *)(v8 + 20);
      v18 = *(_DWORD *)(v8 + 24);
      *(_DWORD *)(v7 + 44) = *(_DWORD *)(v8 + 16);
      *(_DWORD *)(v7 + 48) = v17;
      *(_DWORD *)(v7 + 52) = v18;
      JUMPOUT(0x4E1F54);
    }
  }
  JUMPOUT(0x4E1F7A);
}
