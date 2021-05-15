// FopReadNamingTable 
 
int __fastcall FopReadNamingTable(_DWORD *a1, int a2, int *a3)
{
  int v5; // r4
  unsigned int v6; // r0
  unsigned int v7; // r7
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r8
  int v11; // r9
  int v12; // r6
  int v15; // [sp+8h] [bp-38h] BYREF
  unsigned __int16 v16; // [sp+Ch] [bp-34h]

  v5 = FioFwReadBytesAtOffset(a1, a2, 6u, (int)&v15);
  if ( v5 >= 0 )
  {
    v6 = 18;
    LOWORD(v15) = __rev16((unsigned __int16)v15);
    v7 = __rev16(HIWORD(v15));
    HIWORD(v15) = v7;
    v16 = __rev16(v16);
    if ( v7 )
    {
      v6 = 12 * v7 + 18;
      if ( v6 < 0x12 )
        return -1073741675;
      v5 = 0;
    }
    v8 = BgpFwAllocateMemory(v6);
    v9 = v8;
    if ( v8 )
    {
      v10 = 0;
      v11 = a2 + 6;
      *(_DWORD *)v8 = v15;
      *(_WORD *)(v8 + 4) = v16;
      if ( v7 )
      {
        v12 = v8 + 6;
        while ( 1 )
        {
          v5 = FopReadNameRecord(a1, v11, v12);
          if ( v5 < 0 )
            break;
          ++v10;
          v12 += 12;
          v11 += 12;
          if ( v10 >= v7 )
            goto LABEL_10;
        }
        BgpFwFreeMemory(v9);
      }
      else
      {
LABEL_10:
        *a3 = v9;
      }
    }
    else
    {
      v5 = -1073741801;
    }
  }
  return v5;
}
