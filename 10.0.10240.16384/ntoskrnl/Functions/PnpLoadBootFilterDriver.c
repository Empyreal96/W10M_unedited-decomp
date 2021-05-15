// PnpLoadBootFilterDriver 
 
int __fastcall PnpLoadBootFilterDriver(int a1, unsigned __int16 *a2, unsigned int a3, int *a4)
{
  int v5; // r4
  int v6; // r7
  bool v8; // zf
  unsigned int v10; // r5
  int **v11; // r0
  int *i; // r2
  int **v13; // r3
  int *v14; // r5
  int v15; // r0
  int v16; // r6
  int v18; // [sp+Ch] [bp-3Ch]
  int v19; // [sp+18h] [bp-30h] BYREF
  unsigned __int16 v20; // [sp+20h] [bp-28h] BYREF
  unsigned int v21; // [sp+24h] [bp-24h]

  v5 = -1073741823;
  v6 = IopGroupTable;
  v8 = IopGroupTable == 0;
  *a4 = 0;
  if ( !v8 && a3 < IopGroupIndex )
  {
    v10 = 0;
    if ( a3 )
    {
      v11 = (int **)v6;
      do
      {
        for ( i = *v11; i != (int *)v11; i = (int *)*i )
        {
          if ( !*((_BYTE *)i + 27) )
            return v5;
        }
        ++v10;
        v11 += 2;
      }
      while ( v10 < a3 );
    }
    v13 = (int **)(v6 + 8 * a3);
    v14 = *v13;
    while ( v14 != (int *)v13 )
    {
      if ( IopGetDriverNameFromKeyNode(v14[4]) >= 0 )
      {
        if ( RtlEqualUnicodeString(a2, &v20, 1) )
        {
          if ( *((_BYTE *)v14 + 27) )
          {
            if ( v14[5] < 0 )
              v5 = v14[5];
          }
          else
          {
            v15 = PnpInitializeBootStartDriver(
                    &v20,
                    (__int64 *)(v14[3] + 16),
                    *(_DWORD *)(*(_DWORD *)(v14[3] + 24) + 28),
                    *(_DWORD *)(v14[3] + 24),
                    (int)KeLoaderBlock_0 + 16,
                    1u,
                    1,
                    v18,
                    (int)&v19);
            v16 = v19;
            v5 = v15;
            v14[5] = v15;
            v14[2] = v16;
            *((_BYTE *)v14 + 27) = 1;
            if ( v16 )
            {
              ObfReferenceObjectWithTag(v16);
              *a4 = v16;
            }
            else
            {
              *((_BYTE *)v14 + 26) = 1;
            }
          }
          ExFreePoolWithTag(v21);
          return v5;
        }
        ExFreePoolWithTag(v21);
      }
      v14 = (int *)*v14;
      v13 = (int **)(IopGroupTable + 8 * a3);
    }
  }
  return v5;
}
