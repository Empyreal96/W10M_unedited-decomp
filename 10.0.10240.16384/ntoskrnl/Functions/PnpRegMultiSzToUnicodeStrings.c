// PnpRegMultiSzToUnicodeStrings 
 
int __fastcall PnpRegMultiSzToUnicodeStrings(_DWORD *a1, int *a2, _DWORD *a3)
{
  int v5; // r6
  _WORD *v6; // r2
  int v7; // r3
  _WORD *v8; // r5
  _WORD *v9; // r1
  int v10; // r0
  int v11; // r7
  _WORD *v12; // r4
  int v13; // r9
  _WORD *v14; // r8
  int result; // r0
  int v16; // r0
  unsigned int v17; // r4
  int v18; // r0
  int v19; // r5
  int v20; // [sp+0h] [bp-28h]
  int v21; // [sp+4h] [bp-24h]

  if ( a1[1] != 7 )
    return -1073741811;
  v5 = 0;
  v6 = (_WORD *)((char *)a1 + a1[2]);
  v7 = a1[3];
  v8 = (_WORD *)((char *)v6 + v7);
  if ( v6 == (_WORD *)((char *)v6 + v7) )
    goto LABEL_23;
  v9 = v6 + 1;
  do
  {
    if ( !*v6 )
    {
      ++v5;
      if ( v9 == v8 || !v6[1] )
        break;
    }
    ++v6;
    ++v9;
  }
  while ( v6 != v8 );
  if ( v6 == v8 )
LABEL_23:
    ++v5;
  v10 = ExAllocatePoolWithTag(1, 8 * v5, 1970499664);
  *a2 = v10;
  if ( !v10 )
    JUMPOUT(0x96854E);
  v11 = 0;
  v12 = (_WORD *)((char *)a1 + a1[2]);
  v13 = (int)v12;
  if ( v12 == v8 )
  {
LABEL_24:
    v17 = (unsigned int)v12 - v13;
    v18 = ExAllocatePoolWithTag(1, v17 + 2, 1970499664);
    v19 = *a2 + 8 * v11;
    *(_DWORD *)(v19 + 4) = v18;
    if ( !v18 )
      JUMPOUT(0x968548);
    if ( v17 )
      memmove(v18, v13, v17);
    *(_WORD *)(*(_DWORD *)(v19 + 4) + 2 * (v17 >> 1)) = 0;
    *(_WORD *)v19 = v17;
    *(_WORD *)(v19 + 2) = v17 + 2;
    goto LABEL_16;
  }
  v14 = v12 + 1;
  while ( *v12 )
  {
LABEL_14:
    ++v12;
    ++v14;
    if ( v12 == v8 )
      goto LABEL_15;
  }
  v20 = (int)v12 - v13 + 2;
  v16 = ExAllocatePoolWithTag(1, v20, 1970499664);
  v21 = *a2 + 8 * v11;
  *(_DWORD *)(v21 + 4) = v16;
  if ( !v16 )
    return sub_968544();
  memmove(v16, v13, v20);
  ++v11;
  *(_WORD *)(v21 + 2) = v20;
  *(_WORD *)v21 = (_WORD)v12 - v13;
  if ( v14 != v8 && v12[1] )
  {
    v13 = (int)v14;
    goto LABEL_14;
  }
LABEL_15:
  if ( v12 == v8 )
    goto LABEL_24;
LABEL_16:
  result = 0;
  *a3 = v5;
  return result;
}
