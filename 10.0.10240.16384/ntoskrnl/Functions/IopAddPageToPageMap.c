// IopAddPageToPageMap 
 
int __fastcall IopAddPageToPageMap(unsigned int a1, unsigned int *a2, unsigned int a3, int a4, char a5)
{
  unsigned int v5; // r5
  unsigned int v6; // r4
  unsigned int v8; // r2
  unsigned int v9; // r3
  int result; // r0
  int v11; // r3
  unsigned int v12; // r7
  unsigned int v13; // r0
  unsigned int v14; // r5
  unsigned int v15; // r4
  unsigned int v16; // r3
  unsigned int v17[2]; // [sp+0h] [bp-20h] BYREF
  unsigned int v18; // [sp+8h] [bp-18h] BYREF
  int v19; // [sp+Ch] [bp-14h]

  v17[0] = a1;
  v17[1] = (unsigned int)a2;
  v18 = a3;
  v19 = a4;
  v5 = a4;
  v6 = a3;
  if ( a4 )
  {
    v8 = *(_DWORD *)a1;
    v9 = v6 + a4 - 1;
    if ( v6 < *(_DWORD *)a1 )
    {
      if ( v9 >= v8 )
      {
        if ( !a5 )
          return -1073741503;
        v5 = v8 - v6;
      }
      if ( v5 )
      {
        if ( a2 )
        {
          v11 = *(_DWORD *)(a1 + 4);
          v12 = v6 + v5;
          v18 = v6 + v5;
          v19 = v11;
          v17[0] = v6;
          do
          {
            v13 = RtlFindNextForwardRunClearCapped(&v18, v6, 0xFFFFFFFF, v17);
            v14 = v13;
            if ( !v13 )
              break;
            if ( v13 > *a2 )
            {
              RtlSetBits(&v18, v17[0], *a2);
              result = -1073741789;
              *a2 = 0;
              return result;
            }
            v15 = v17[0];
            RtlSetBits(&v18, v17[0], v13);
            v16 = *a2;
            v6 = v15 + v14;
            v17[0] = v6;
            *a2 = v16 - v14;
          }
          while ( v6 < v12 );
        }
        else
        {
          RtlSetBits((_BYTE *)a1, v6, v5);
        }
      }
    }
    else if ( !a5 )
    {
      return -1073741503;
    }
  }
  return 0;
}
