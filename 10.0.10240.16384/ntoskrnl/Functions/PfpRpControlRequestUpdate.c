// PfpRpControlRequestUpdate 
 
int __fastcall PfpRpControlRequestUpdate(int a1, int *a2)
{
  int *v3; // r4
  unsigned int v5; // r10
  _DWORD *v6; // r9
  int *v7; // r8
  unsigned int v8; // r7
  int v9; // r0
  int v10; // r4
  int v11; // t1
  int v12; // lr
  unsigned int v13; // r3
  unsigned int *v14; // r2
  unsigned int v15; // r0
  unsigned int v16; // r4
  int result; // r0
  unsigned int v18; // r3
  int *v19; // r4
  unsigned int v20; // r3
  int v21; // [sp+8h] [bp-28h] BYREF
  unsigned int v22; // [sp+Ch] [bp-24h]

  v3 = a2 + 5;
  v5 = a2[2] + a2[1];
  v22 = ((unsigned int)&a2[2 * v5 + 5] + 3) & 0xFFFFFFFC;
  v6 = a2 + 5;
  v7 = a2 + 5;
  v8 = 0;
  if ( v5 )
  {
    do
    {
      v9 = v7[1];
      v11 = *v7;
      v7 += 2;
      v10 = v11;
      *v6++ = v11;
      if ( v9 && PsLookupProcessByProcessId(v9, &v21) >= 0 )
      {
        v12 = v21;
        if ( *(_DWORD *)(v21 + 408) == v10 )
        {
          v13 = a2[1];
          __dmb(0xBu);
          v14 = (unsigned int *)(v12 + 192);
          if ( v8 >= v13 )
          {
            do
              v16 = __ldrex(v14);
            while ( __strex(v16 & 0xFFFFBFFF, v14) );
          }
          else
          {
            do
              v15 = __ldrex(v14);
            while ( __strex(v15 | 0x4000, v14) );
          }
          __dmb(0xBu);
        }
        ObfDereferenceObjectWithTag(v12);
      }
      ++v8;
    }
    while ( v8 < v5 );
    v3 = a2 + 5;
  }
  result = PfpRpCHashAddEntries(a1, (_DWORD *)(a1 + 56), (unsigned __int8 *)(a1 + 72), v3, a2[1]);
  if ( result >= 0 )
  {
    v18 = a2[2];
    if ( !v18
      || !*(_DWORD *)(a1 + 68)
      || (result = PfpRpCHashDeleteEntries(a1, a1 + 56, (unsigned int *)(a1 + 72), v18, &v3[a2[1]]), result >= 0) )
    {
      v19 = (int *)v22;
      PfpRpCHashAddEntries(a1, (_DWORD *)(a1 + 32), (unsigned __int8 *)(a1 + 52), (int *)(v22 + 4 * a2[3]), a2[4]);
      v20 = a2[3];
      if ( v20 && *(_DWORD *)(a1 + 44) )
      {
        result = PfpRpCHashDeleteEntries(a1, a1 + 32, (unsigned int *)(a1 + 52), v20, v19);
        if ( result < 0 )
          return result;
        *(_DWORD *)(a1 + 48) = 0;
      }
      result = 0;
    }
  }
  return result;
}
