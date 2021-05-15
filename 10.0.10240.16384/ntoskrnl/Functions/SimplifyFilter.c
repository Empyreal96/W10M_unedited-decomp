// SimplifyFilter 
 
int __fastcall SimplifyFilter(int result, int *a2, int *a3, int a4)
{
  BOOL v5; // r7
  int i; // r8
  int v9; // r3
  int v10; // t1
  int v11; // r4
  int v12; // r3
  int v13; // r3
  int v14; // [sp+0h] [bp-20h]

  v5 = 0;
  *a3 = 0;
  for ( i = result; i; --i )
  {
    v10 = *a2;
    a2 += 11;
    v9 = v10;
    if ( v10 == 5242880 || v9 == 6291456 )
    {
      v5 = !v5;
      continue;
    }
    v11 = 44 * *a3;
    v14 = *a3;
    result = memmove(v11 + a4, (int)(a2 - 11), 0x2Cu);
    if ( v5 )
    {
      v12 = *(_DWORD *)(v11 + a4);
      if ( (v12 & 0xFF00000) != 0 )
      {
        if ( v12 == 0x100000 )
        {
          v13 = 3145728;
        }
        else
        {
          if ( v12 != 0x200000 )
          {
            if ( v12 == 3145728 )
            {
              *(_DWORD *)(v11 + a4) = 0x100000;
            }
            else if ( v12 == 0x400000 )
            {
              *(_DWORD *)(v11 + a4) = 0x200000;
            }
            goto LABEL_16;
          }
          v13 = 0x400000;
        }
      }
      else
      {
        v13 = v12 ^ 0x10000;
      }
      *(_DWORD *)(v11 + a4) = v13;
    }
LABEL_16:
    *a3 = v14 + 1;
  }
  return result;
}
