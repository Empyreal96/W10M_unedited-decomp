// sub_7D5CCC 
 
void __fastcall sub_7D5CCC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8)
{
  int v8; // r0
  int v9; // r0
  int v10; // r5
  int v11; // r0
  int v12; // r3
  int v13; // r2
  int v14; // r3
  int v15; // r4
  unsigned int v16; // r7
  _DWORD *v17; // r8
  _DWORD *v18; // r10
  _DWORD *v19; // r6
  int v20; // [sp+8h] [bp-50h]
  int v21; // [sp+Ch] [bp-4Ch]
  int *v22; // [sp+10h] [bp-48h]
  unsigned int v23; // [sp+14h] [bp-44h] BYREF
  char v24[64]; // [sp+18h] [bp-40h] BYREF

  v19 = a8;
  v8 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  if ( *v22 != -1 && *v22 == v8 )
  {
    v15 = ExGetAttachedSessionPoolTagInfo(a8, v16, v18, v8);
    if ( v15 >= 0 )
    {
      v17 = a8;
      goto LABEL_13;
    }
    goto LABEL_16;
  }
  v20 = 0;
  while ( 1 )
  {
    do
    {
      v9 = MmGetNextSession();
      v10 = v9;
      if ( !v9 )
        goto LABEL_12;
      v11 = MmGetSessionIdEx(v9);
      v21 = v11;
      v12 = *v22;
    }
    while ( *v22 != -1 && v12 != v11 );
    v15 = MmAttachSession(v10, (int)v24, v11, v12);
    if ( v15 < 0 )
      goto LABEL_12;
    v15 = ExGetAttachedSessionPoolTagInfo(v19, v16, &v23, v21);
    MmDetachSession(v10, (int)v24, v13, v14);
    if ( v15 < 0 )
    {
      if ( v15 != -1073741820 )
        goto LABEL_26;
      v16 = 0;
    }
    else
    {
      if ( v23 > v16 || v23 < 0x28 )
      {
        v15 = -1073741675;
LABEL_26:
        ObfDereferenceObject(v10);
LABEL_12:
        *v18 = v20;
LABEL_13:
        if ( v15 >= 0 && v17 )
          *v17 = 0;
LABEL_16:
        if ( a7 )
          ExUnlockUserBuffer(a7);
        JUMPOUT(0x6DB184);
      }
      v17 = v19;
      v19 = (_DWORD *)((char *)v19 + v23);
      v16 -= v23;
    }
    v20 += v23;
    if ( *v22 != -1 )
      goto LABEL_26;
  }
}
