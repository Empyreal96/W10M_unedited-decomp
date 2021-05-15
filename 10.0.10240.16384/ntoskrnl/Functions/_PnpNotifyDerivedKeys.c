// _PnpNotifyDerivedKeys 
 
int __fastcall PnpNotifyDerivedKeys(int result, int a2, int a3, unsigned int a4, int a5, int a6, int a7, int (__fastcall *a8)(int, int, int, int, int))
{
  unsigned int v8; // lr
  int v9; // r5
  unsigned int v11; // r7
  int v12; // r6
  unsigned int *v13; // r8
  int v14; // r10
  unsigned int v15; // r1
  unsigned int v16; // t1
  unsigned int v17; // [sp+8h] [bp-30h]
  int v20; // [sp+14h] [bp-24h]

  v17 = a4;
  v8 = a4;
  v9 = a6;
  v20 = result;
  if ( !a6 )
    return result;
  do
  {
    v11 = *(_DWORD *)(a5 + 4);
    v12 = 0;
    if ( !v11 )
      goto LABEL_6;
    v13 = *(unsigned int **)a5;
    v14 = *(_DWORD *)(v8 + 16);
    while ( 1 )
    {
      v16 = *v13++;
      v15 = v16;
      if ( v14 == *(_DWORD *)(v16 + 16) )
        break;
LABEL_5:
      if ( ++v12 >= v11 )
        goto LABEL_6;
    }
    result = memcmp(v8, v15, 16);
    if ( result )
    {
      v8 = v17;
      goto LABEL_5;
    }
    *(_DWORD *)(a7 + 8) = *(_DWORD *)(a5 + 8);
    result = a8(v20, a2, a3, 4, a7);
LABEL_6:
    v8 = v17;
    a5 += 12;
    --v9;
  }
  while ( v9 );
  return result;
}
