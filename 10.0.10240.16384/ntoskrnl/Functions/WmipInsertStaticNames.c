// WmipInsertStaticNames 
 
unsigned int *__fastcall WmipInsertStaticNames(unsigned int *result, unsigned int a2, int a3)
{
  char *v5; // r6
  unsigned int v6; // r9
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned int *v9; // r8
  char *v10; // r10
  int v11; // r3
  char *v12; // r2
  char *v13; // r4
  unsigned int v14; // r5
  char *v15; // r10
  unsigned int v16; // r8
  int v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r10
  unsigned int v20; // r5
  unsigned int v21; // r8
  char *v22; // [sp+0h] [bp-40h]
  char *v23; // [sp+4h] [bp-3Ch]
  char *v24; // [sp+8h] [bp-38h]
  _WORD v25[24]; // [sp+10h] [bp-30h] BYREF

  v5 = (char *)result;
  if ( (*(_DWORD *)(a3 + 8) & 3) != 0 )
  {
    v6 = *(_DWORD *)(a3 + 36);
    v7 = *result + 3;
    if ( v7 >= *result )
    {
      v8 = v7 & 0xFFFFFFFC;
      result = (unsigned int *)WmipStaticInstanceNameSize(a3);
      v9 = result;
      if ( (unsigned int)result <= -1 - v8 )
      {
        v10 = (char *)result + v8;
        v24 = (char *)result + v8;
        if ( (unsigned int)result + v8 > a2 )
        {
          *(_DWORD *)v5 = 56;
          *((_DWORD *)v5 + 11) = 32;
          *((_DWORD *)v5 + 12) = v10;
          return result;
        }
        *((_DWORD *)v5 + 14) = v8;
        v11 = *(_DWORD *)(a3 + 8);
        v12 = &v5[v8];
        v13 = &v5[4 * v6 + v8];
        v22 = v13;
        if ( (v11 & 1) != 0 )
        {
          if ( (v11 & 0x20000) != 0 )
            *((_DWORD *)v5 + 11) |= 0x10000u;
          v14 = 0;
          if ( !v6 )
            goto LABEL_12;
          v15 = v12;
          do
          {
            *(_DWORD *)v15 = v13 - v5;
            v15 += 4;
            v16 = (unsigned int)v9 - 2;
            RtlStringCbCopyW((int)(v13 + 2), v16);
            RtlStringCbPrintfW(v25, 0xEu, (int)L"%d", **(_DWORD **)(a3 + 48) + v14);
            RtlStringCbCatW((unsigned __int16 *)v13 + 1, v16, (int)v25, v17);
            result = (unsigned int *)wcslen((unsigned __int16 *)v13 + 1);
            v18 = 2 * ((_DWORD)result + 1);
            ++v14;
            *(_WORD *)v13 = v18;
            v13 += 2 * (v18 >> 1) + 2;
            v9 = (unsigned int *)(v16 - v18);
          }
          while ( v14 < v6 );
        }
        else
        {
          if ( (v11 & 2) == 0 || !v6 )
            goto LABEL_12;
          v19 = 0;
          do
          {
            *(_DWORD *)v12 = v13 - v5;
            v23 = v12 + 4;
            v20 = 2 * (wcslen(*(unsigned __int16 **)(*(_DWORD *)(a3 + 48) + 4 * v19)) + 1);
            v21 = (unsigned int)v9 - 2;
            *(_WORD *)v22 = v20;
            result = (unsigned int *)RtlStringCbCopyW((int)(v22 + 2), v21);
            v13 = &v22[2 * (v20 >> 1) + 2];
            ++v19;
            v12 = v23;
            v22 = v13;
            v9 = (unsigned int *)(v21 - v20);
          }
          while ( v19 < v6 );
        }
        v10 = v24;
LABEL_12:
        *(_DWORD *)v5 = v10;
        return result;
      }
    }
  }
  return result;
}
