// sub_7D0924 
 
void __fastcall sub_7D0924(int a1, int a2, unsigned int a3)
{
  int v3; // r3
  int v4; // r2
  int v5; // r8
  int v6; // r0
  int v7; // r5
  unsigned int *v8; // r9
  unsigned int v9; // r10
  unsigned int v10; // r6
  _DWORD *v11; // r7
  unsigned int v12; // r7
  int *v13; // r8
  int v14; // r3
  int v15; // r4

  v10 = 0;
  if ( a3 )
  {
    v11 = v8 + 13;
    while ( 1 )
    {
      v3 = v10 >= a3 ? 0 : *v11;
      v4 = *(_DWORD *)(v3 + 3596);
      v5 = v4 + 4 * v7;
      if ( *(_DWORD *)(v5 + 1884) )
      {
        *(_BYTE *)(v4 + v7 + 1880) = 0;
      }
      else
      {
        v6 = ExAllocatePoolWithTag(512, 1024, 2004042563);
        *(_DWORD *)(v5 + 1884) = v6;
        if ( !v6 )
        {
          v12 = 0;
          if ( v10 )
          {
            v13 = (int *)(v8 + 13);
            do
            {
              if ( v12 >= *v8 )
                v14 = 0;
              else
                v14 = *v13;
              v15 = *(_DWORD *)(v14 + 3596) + 4 * v7;
              ExFreePoolWithTag(*(_DWORD *)(v15 + 1884));
              ++v12;
              *(_DWORD *)(v15 + 1884) = 0;
              ++v13;
            }
            while ( v12 < v10 );
          }
          JUMPOUT(0x78A7C8);
        }
      }
      ++v10;
      ++v11;
      **(_DWORD **)(v5 + 1884) = 0;
      if ( v10 >= v9 )
        break;
      a3 = *v8;
    }
  }
  JUMPOUT(0x78A7BC);
}
