// RtlpInsertFreeBlock 
 
int __fastcall RtlpInsertFreeBlock(int result, unsigned __int16 *a2, unsigned int a3)
{
  unsigned int v3; // r8
  unsigned __int16 *v4; // r5
  int v5; // r6
  int v6; // r1
  unsigned __int8 v7; // r2
  int *v8; // r10
  unsigned int v9; // r4
  int v10; // r1
  char v11; // r3
  char v12; // r3
  int **v13; // r3
  int *v14; // r7
  _DWORD *v15; // r1
  unsigned int v16; // r2
  unsigned int i; // r3
  _DWORD *v18; // r3
  int v19; // r3
  int v20; // r1
  signed int v21; // r7
  int v22; // r2
  unsigned int v23; // r3
  int v24; // r0
  int v25; // [sp+8h] [bp-30h]
  int v26; // [sp+10h] [bp-28h]

  v3 = a3;
  v4 = a2;
  v5 = result;
  if ( a3 )
  {
    v6 = *(unsigned __int16 *)(result + 84) ^ a2[2];
    if ( v6 )
    {
      if ( *((_BYTE *)v4 + 6) )
        JUMPOUT(0x553FB6);
      v7 = *((_BYTE *)v4 + 2);
      v8 = (int *)(result + 192);
      v25 = v7;
      while ( 1 )
      {
        if ( v3 > 0xFE00 )
        {
          v9 = 65024;
          if ( v3 == 65025 )
            v9 = 65008;
          *((_BYTE *)v4 + 2) = 0;
        }
        else
        {
          v9 = (unsigned __int16)v3;
          *((_BYTE *)v4 + 2) = v7;
        }
        v4[2] = *(_WORD *)(v5 + 84) ^ v6;
        v10 = *(_DWORD *)(v5 + 24);
        if ( v10 == v5 )
        {
          v11 = 0;
        }
        else
        {
          v21 = (((unsigned int)v4 - v5) >> 16) + 1;
          if ( v21 <= 0 || v21 >= 254 )
            RtlpLogHeapFailure(3, v10);
          v11 = (((unsigned int)v4 - v5) >> 16) + 1;
        }
        *((_BYTE *)v4 + 6) = v11;
        v12 = *((_BYTE *)v4 + 2);
        *v4 = v9;
        *((_BYTE *)v4 + 3) = 0;
        *((_BYTE *)v4 + 2) = v12 & 0xF0;
        *((_BYTE *)v4 + 7) = 0;
        if ( (*(_DWORD *)(v5 + 64) & 0x40) != 0 )
        {
          RtlFillMemoryUlong((_DWORD *)v4 + 4, 8 * v9 - 16, -17891602);
          *((_BYTE *)v4 + 2) |= 4u;
        }
        if ( *(_DWORD *)(v5 + 180) )
          result = RtlpFindEntry(v5, v9);
        else
          result = *v8;
        if ( v8 != (int *)result )
        {
          v20 = *(_DWORD *)(v5 + 76);
          do
          {
            if ( v20 )
            {
              v22 = *(_DWORD *)(result - 8);
              v20 = *(_DWORD *)(v5 + 76);
              LOWORD(v26) = v22;
              if ( (v20 & v22) != 0 )
                v26 = *(_DWORD *)(v5 + 80) ^ v22;
              v23 = (unsigned __int16)v26;
            }
            else
            {
              v23 = *(unsigned __int16 *)(result - 8);
            }
            if ( v9 <= v23 )
              break;
            result = *(_DWORD *)result;
          }
          while ( v8 != (int *)result );
        }
        v13 = *(int ***)(result + 4);
        v14 = (int *)(v4 + 4);
        if ( *v13 == (int *)result )
        {
          *v14 = result;
          *((_DWORD *)v4 + 3) = v13;
          *v13 = v14;
          *(_DWORD *)(result + 4) = v14;
        }
        else
        {
          result = RtlpLogHeapFailure(12, 0);
        }
        v15 = *(_DWORD **)(v5 + 180);
        *(_DWORD *)(v5 + 116) += *v4;
        if ( v15 )
        {
          v16 = *v4;
          for ( i = v15[1]; v16 >= i; i = v18[1] )
          {
            v18 = (_DWORD *)*v15;
            if ( !*v15 )
            {
              v19 = v15[1] - 1;
              goto LABEL_22;
            }
            v15 = (_DWORD *)*v15;
          }
          v19 = *v4;
LABEL_22:
          result = RtlpHeapAddListEntry(v5, v15, v16, (int)(v4 + 4), v19);
        }
        if ( *(_DWORD *)(v5 + 76) )
        {
          *((_BYTE *)v4 + 3) = *(_BYTE *)v4 ^ *((_BYTE *)v4 + 2) ^ *((_BYTE *)v4 + 1);
          *(_DWORD *)v4 ^= *(_DWORD *)(v5 + 80);
        }
        v4 += 4 * v9;
        LOWORD(v6) = v9;
        v3 -= v9;
        if ( (unsigned int)v4 >= *(_DWORD *)(v5 + 40) )
          break;
        v7 = v25;
        result = 0;
        if ( !v3 )
        {
          v4[2] = *(_WORD *)(v5 + 84) ^ v9;
          if ( !v9
            && RtlpHeapErrorHandlerThreshold >= 1
            && (unsigned __int16 *)(((unsigned int)v4 + 4095) & 0xFFFFF000) != v4 )
          {
            v24 = DbgPrint("ROUND_UP_TO_POWER2(FreeBlock, PAGE_SIZE) == (ULONG_PTR)FreeBlock", v9, v25);
            RtlpHeapHandleError(v24);
          }
          return result;
        }
      }
    }
    else
    {
      result = sub_553F8C();
    }
  }
  return result;
}
