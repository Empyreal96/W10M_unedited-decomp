// CmpFilterAcpiDockingState 
 
int __fastcall CmpFilterAcpiDockingState(unsigned __int8 *a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v6; // r9
  int v7; // r5
  int v8; // r7
  int v11; // lr
  _DWORD *v13; // r4
  int v14; // r2
  int v15; // r5
  unsigned int v16; // r0
  int v17; // r1
  int v18; // t1
  unsigned int v19; // r4
  int v20; // r5
  int v21; // r0
  int v22; // r3
  int v23; // [sp+0h] [bp-38h]
  int v24; // [sp+4h] [bp-34h]
  unsigned int v26; // [sp+Ch] [bp-2Ch]
  int v28; // [sp+14h] [bp-24h]

  v6 = 0;
  v24 = 0;
  v7 = 0;
  v8 = a6;
  v23 = 0;
  v26 = 0;
  v11 = 0;
  v28 = 0;
  if ( !a6 || !*(_DWORD *)(a6 + 4) )
    return sub_80BDF8();
  v13 = (_DWORD *)(a6 + 8);
  do
  {
    v14 = v13[1] & 3;
    if ( !v14 || v14 == (*(_WORD *)a1 & 3) )
    {
      v15 = v13[2];
      if ( v15 != *((unsigned __int16 *)a1 + 1) )
        goto LABEL_37;
      if ( v15 != RtlCompareMemory(a1 + 4, v13[3], v13[2]) || (v16 = 0, !*(_DWORD *)(a5 + 4)) )
      {
        v11 = v24;
LABEL_37:
        v7 = v23;
        goto LABEL_20;
      }
      v17 = a5;
      do
      {
        v18 = *(_DWORD *)(v17 + 20);
        v17 += 20;
        if ( v18 == *v13 )
        {
          v11 = 1;
          v24 = 1;
          *(_DWORD *)(v17 + 4) |= 2u;
        }
        else
        {
          v11 = v24;
        }
        if ( a2 != *(unsigned __int16 *)a1 || a3 )
        {
          v7 = v23;
        }
        else
        {
          v7 = 1;
          v23 = 1;
        }
        if ( *v13 == a4 )
          v28 = 1;
        ++v16;
      }
      while ( v16 < *(_DWORD *)(a5 + 4) );
      v8 = a6;
      v6 = v26;
    }
LABEL_20:
    ++v6;
    v13 += 4;
    v26 = v6;
  }
  while ( v6 < *(_DWORD *)(v8 + 4) );
  if ( !v7 )
    return sub_80BDF8();
  v19 = 0;
  if ( *(_DWORD *)(a5 + 4) )
  {
    v20 = 0;
    do
    {
      v21 = v20 + a5;
      v22 = *(_DWORD *)(v20 + a5 + 24);
      if ( v23 )
      {
        if ( (v22 & 2) == 0 )
          goto LABEL_32;
        if ( v28 )
        {
          if ( *(_DWORD *)(v21 + 20) != a4 )
            goto LABEL_32;
        }
        else
        {
          *(_DWORD *)(v21 + 24) = v22 | 8;
        }
      }
      else if ( ((v22 & 4) == 0 || v11) && (v22 & 1) == 0 && (v22 & 2) == 0 )
      {
LABEL_32:
        if ( *(_DWORD *)(a5 + 4) - v19 != 1 )
        {
          memmove(v21 + 8, v21 + 28, 20 * (*(_DWORD *)(a5 + 4) - v19 - 1));
          v11 = v24;
        }
        --*(_DWORD *)(a5 + 4);
        continue;
      }
      ++v19;
      v20 += 20;
    }
    while ( v19 < *(_DWORD *)(a5 + 4) );
  }
  return 0;
}
