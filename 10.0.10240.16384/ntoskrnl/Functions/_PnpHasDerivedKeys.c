// _PnpHasDerivedKeys 
 
int __fastcall PnpHasDerivedKeys(unsigned int a1, int a2, unsigned int a3)
{
  unsigned int v3; // r5
  unsigned int v7; // r7
  int v8; // r6
  int v9; // r2
  unsigned int *v10; // r9
  unsigned int v11; // r1
  unsigned int v12; // t1
  int v14; // [sp+0h] [bp-20h]

  v3 = 0;
  if ( !a3 )
    return 0;
  while ( 1 )
  {
    v7 = *(_DWORD *)(a2 + 4);
    v8 = 0;
    if ( v7 )
      break;
LABEL_6:
    ++v3;
    a2 += 12;
    if ( v3 >= a3 )
      return 0;
  }
  v9 = *(_DWORD *)(a1 + 16);
  v10 = *(unsigned int **)a2;
  v14 = v9;
  while ( 1 )
  {
    v12 = *v10++;
    v11 = v12;
    if ( v9 == *(_DWORD *)(v12 + 16) )
      break;
LABEL_5:
    if ( ++v8 >= v7 )
      goto LABEL_6;
  }
  if ( memcmp(a1, v11, 16) )
  {
    v9 = v14;
    goto LABEL_5;
  }
  return 1;
}
