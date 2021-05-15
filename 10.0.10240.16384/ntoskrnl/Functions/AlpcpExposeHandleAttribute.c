// AlpcpExposeHandleAttribute 
 
int __fastcall AlpcpExposeHandleAttribute(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4)
{
  int v7; // r5
  char v8; // r4
  int v9; // r10
  int v10; // r3
  int v11; // r3
  int v12; // r1
  int v13; // r1
  int v14; // r2
  int v15; // r3
  unsigned int *v16; // r2
  unsigned int v17; // r1
  int v18; // r1
  _DWORD *v20; // [sp+8h] [bp-40h]
  int v21; // [sp+1Ch] [bp-2Ch] BYREF
  int v22; // [sp+20h] [bp-28h]
  _DWORD _24[15]; // [sp+24h] [bp-24h] BYREF

  _24[11] = a1;
  _24[13] = a3;
  _24[14] = a4;
  _24[12] = a2;
  if ( !*(_DWORD *)(a2 + 80) )
    return 0;
  v8 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v9 = *(_DWORD *)(a2 + 80);
  v20 = 0;
  if ( (a1[61] & 6) != 2
    || (a1 = (_DWORD *)AlpcpReferenceConnectedPort(*(_DWORD *)(a2 + 12)), v10 = (int)a1, (v20 = a1) != 0) )
  {
    if ( (a1[38] & 0x80000) != 0 )
    {
      v11 = a1[48] & *(_DWORD *)(v9 + 4);
      if ( !v11 )
      {
        v7 = -1073741788;
        goto LABEL_15;
      }
      v12 = a1[3];
      if ( (v12 & 1) != 0 )
        v12 = 0;
      if ( v12 )
      {
        v21 = 0;
        _24[0] = 0;
        v22 = v11;
        v7 = ObCompleteObjectDuplication((_DWORD *)(v9 + 8), v12, v8, &v21, _24);
        if ( v7 >= 0 )
        {
          v13 = v21;
          v14 = v22;
          v15 = _24[0];
          *a3 = 0;
          a3[1] = v13;
          a3[2] = v14;
          a3[3] = v15;
          *a4 |= 0x10000000u;
          v10 = (int)v20;
          goto LABEL_16;
        }
LABEL_15:
        v10 = (int)v20;
        goto LABEL_16;
      }
    }
    v7 = -1073741790;
    goto LABEL_15;
  }
  v7 = -1073741769;
LABEL_16:
  if ( v10 )
    ObfDereferenceObject(v10);
  __dmb(0xBu);
  v16 = (unsigned int *)(v9 - 12);
  do
  {
    v17 = __ldrex(v16);
    v18 = v17 - 1;
  }
  while ( __strex(v18, v16) );
  __dmb(0xBu);
  if ( v18 <= 0 )
  {
    if ( v18 )
      KeBugCheckEx(24, 0, v9, 33, v18);
    AlpcpDestroyBlob(v9);
  }
  *(_DWORD *)(a2 + 80) = 0;
  return v7;
}
