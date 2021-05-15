// RtlReserveChunkLZNT1 
 
int __fastcall RtlReserveChunkLZNT1(unsigned int a1, unsigned int a2, unsigned int *a3, int a4)
{
  unsigned int v5; // r6
  int v6; // r5
  int v8; // r7
  int result; // r0
  unsigned int v11; // r3
  unsigned int v12; // r6
  unsigned int v13; // r2
  _BYTE *v14; // r2
  _BYTE *v15; // r2
  unsigned int v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // [sp+0h] [bp-28h] BYREF
  unsigned int v19; // [sp+4h] [bp-24h] BYREF
  _DWORD v20[8]; // [sp+8h] [bp-20h] BYREF

  v18 = a1;
  v19 = a2;
  v20[0] = a3;
  v20[1] = a4;
  v5 = *(_DWORD *)a1;
  v6 = a4;
  v18 = v5;
  v8 = v5;
  while ( 1 )
  {
    result = RtlDescribeChunkLZNT1(&v18, a2, (int)v20, (int *)&v19);
    if ( result < 0 )
      break;
    if ( v8 == v5 )
      v8 = v18;
  }
  if ( result == -2147483622 )
  {
    v11 = v18;
    *a3 = v5;
    v12 = *(_DWORD *)a1;
    v13 = v11 - v8 + 2;
    result = -1073741789;
    if ( *(_DWORD *)a1 <= a2 - v6 )
    {
      if ( v6 == 4096 )
      {
        v6 = 4098;
        if ( v12 + v13 + 4098 <= a2 )
        {
          memmove(v12 + 4098, v8, v13);
          v14 = *(_BYTE **)a1;
          if ( (*(_DWORD *)a1 & 1) != 0 )
          {
            *v14 = -1;
            *(_BYTE *)(*(_DWORD *)a1 + 1) = 63;
          }
          else
          {
            *(_WORD *)v14 = 0x3FFF;
          }
          *a3 += 2;
          goto LABEL_26;
        }
      }
      else if ( v6 )
      {
        if ( v12 + v13 + v6 <= a2 )
        {
          memmove(v12 + v6, v8, v13);
LABEL_26:
          result = 0;
          goto LABEL_27;
        }
      }
      else
      {
        v6 = 6;
        if ( v12 + v13 + 6 <= a2 )
        {
          memmove(v12 + 6, v8, v13);
          v15 = *(_BYTE **)a1;
          if ( (*(_DWORD *)a1 & 1) != 0 )
          {
            *v15 = 3;
            *(_BYTE *)(*(_DWORD *)a1 + 1) = -80;
          }
          else
          {
            *(_WORD *)v15 = -20477;
          }
          v16 = *(_DWORD *)a1;
          if ( (*(_DWORD *)a1 & 1) != 0 )
          {
            *(_BYTE *)(v16 + 2) = 2;
            *(_BYTE *)(*(_DWORD *)a1 + 3) = 0;
          }
          else
          {
            *(_WORD *)(v16 + 2) = 2;
          }
          v17 = *(_DWORD *)a1;
          if ( (*(_DWORD *)a1 & 1) != 0 )
          {
            *(_BYTE *)(v17 + 4) = -4;
            *(_BYTE *)(*(_DWORD *)a1 + 5) = 15;
          }
          else
          {
            *(_WORD *)(v17 + 4) = 4092;
          }
          goto LABEL_26;
        }
      }
LABEL_27:
      *(_DWORD *)a1 += v6;
      return result;
    }
  }
  return result;
}
