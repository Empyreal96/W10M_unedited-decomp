// MiPrefetchJumpVad 
 
int __fastcall MiPrefetchJumpVad(int result, int a2, unsigned int a3)
{
  int v4; // r4
  unsigned int v5; // r6
  unsigned int v6; // r1
  int v7; // r5
  int v8; // r3
  unsigned int v9; // r4
  unsigned int v10; // r8
  __int16 v11; // r2
  int v12; // t1

  v4 = *(_DWORD *)(a2 + 28);
  v5 = a3;
  v6 = (*(_DWORD *)(a2 + 16) + 1) << 12;
  v7 = result;
  if ( v4 >= 0 )
  {
    v8 = v4 & 7;
    if ( v8 != 1 )
    {
      if ( (v4 & 0x8000) != 0 )
      {
        if ( v8 != 3 && v8 != 5 )
        {
          v9 = ((a3 >> 10) & 0x3FFFFC) - 0x40000000;
          v10 = ((v6 >> 10) & 0x3FFFFC) - 0x40000000;
          if ( v10 > (v9 & 0xFFFFF000) + 4096 )
            v10 = (v9 & 0xFFFFF000) + 4096;
          while ( v9 < v10 )
          {
            v12 = *(_DWORD *)v9;
            v9 += 4;
            v11 = v12;
            if ( v12 )
            {
              if ( (v11 & 2) != 0 )
                goto LABEL_10;
              if ( (v11 & 0x400) != 0 )
                break;
              if ( (v11 & 0x800) != 0 )
              {
LABEL_10:
                MiUpdatePrefetchPriority(v7, v5);
              }
              else if ( (v11 & 0x10) != 0 )
              {
                break;
              }
            }
            v5 += 4096;
          }
          v6 = v9 << 10;
        }
      }
      else if ( (*(_BYTE *)(a2 + 43) & 1) == 0 )
      {
        return result;
      }
    }
  }
  result = MiLeapPrefetch((_DWORD *)v7, v6);
  *(_BYTE *)(v7 + 1) = 1;
  return result;
}
