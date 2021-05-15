// BiUpdateEfiEntry 
 
int __fastcall BiUpdateEfiEntry(int a1, int a2)
{
  unsigned __int16 *v3; // r7
  _DWORD *v4; // r8
  int v5; // r4
  int v6; // r6
  _DWORD *v7; // r9
  unsigned __int16 *v8; // r10
  int v9; // r0
  unsigned int v10; // r5
  int v11; // r2
  int v13; // [sp+8h] [bp-38h] BYREF
  _DWORD *v14; // [sp+Ch] [bp-34h] BYREF
  unsigned __int16 *v15; // [sp+10h] [bp-30h] BYREF
  unsigned __int16 *v16; // [sp+14h] [bp-2Ch] BYREF
  unsigned int v17; // [sp+18h] [bp-28h] BYREF
  int v18; // [sp+1Ch] [bp-24h]

  v3 = 0;
  v17 = 0;
  v18 = a2;
  v15 = 0;
  v16 = 0;
  v4 = 0;
  v13 = 0;
  v14 = 0;
  v5 = BcdOpenObject(a1, a2 + 8, &v13);
  v6 = v13;
  if ( v5 >= 0 )
  {
    BiGetElement(v13, 301989892, &v16, &v13);
    if ( (*(_DWORD *)(a2 + 32) & 8) == 0 )
    {
      BiGetElement(v6, 285212673, &v14, &v13);
      BiGetElement(v6, 301989890, &v15, &v13);
      v4 = v14;
      v3 = v15;
    }
    v7 = *(_DWORD **)(a2 + 28);
    v8 = v16;
    v9 = BiCreateMergedBootEntry(v7, v16, v4, v3, &v17);
    v5 = v9;
    if ( v9 == -1073741766 )
    {
      v5 = 0;
    }
    else if ( v9 >= 0 )
    {
      v10 = v17;
      v11 = v7[1];
      if ( v11 != *(_DWORD *)(v17 + 4) || memcmp((unsigned int)v7, v17, v11) )
        return sub_8137BC();
      ExFreePoolWithTag((unsigned int)v7);
      *(_DWORD *)(v18 + 28) = v10;
    }
    if ( v8 )
      ExFreePoolWithTag((unsigned int)v8);
    if ( v4 )
      ExFreePoolWithTag((unsigned int)v4);
    if ( v3 )
      ExFreePoolWithTag((unsigned int)v3);
  }
  if ( v6 )
    BcdCloseObject(v6);
  return v5;
}
