// MiLogStrongCodeDriverLoadFailure 
 
unsigned int __fastcall MiLogStrongCodeDriverLoadFailure(unsigned int result, int a2)
{
  _DWORD *v3; // r4
  unsigned int v4; // r7
  int v5; // r2
  char *v6; // r6
  unsigned int v7; // r4
  int v8; // r0
  int v9; // r0
  void ***v10; // r1
  int v11; // [sp+8h] [bp-90h] BYREF
  int v12; // [sp+Ch] [bp-8Ch] BYREF
  int v13[8]; // [sp+10h] [bp-88h] BYREF
  char v14[16]; // [sp+30h] [bp-68h] BYREF
  int *v15; // [sp+40h] [bp-58h]
  int v16; // [sp+44h] [bp-54h]
  int v17; // [sp+48h] [bp-50h]
  int v18; // [sp+4Ch] [bp-4Ch]
  int v19; // [sp+50h] [bp-48h]
  int v20; // [sp+54h] [bp-44h]
  int v21[16]; // [sp+58h] [bp-40h] BYREF

  v3 = (_DWORD *)dword_634CA0;
  v4 = result;
  if ( dword_634CA0 )
  {
    if ( *(_DWORD *)dword_634CA0 > 5u )
    {
      result = TlgKeywordOn(dword_634CA0, 0x400000000000i64);
      if ( result )
      {
        v12 = *(_DWORD *)(a2 + 64);
        v11 = *(_DWORD *)(a2 + 88);
        TlgCreateSz((int)v14, v4);
        v15 = v21;
        v16 = 0;
        v17 = 2;
        v18 = 0;
        v19 = *(_DWORD *)(a2 + 48);
        v20 = 0;
        v21[0] = *(unsigned __int16 *)(a2 + 44);
        v21[1] = 0;
        v21[2] = (int)&v12;
        v21[3] = 0;
        v21[4] = 4;
        v21[5] = 0;
        v21[6] = (int)&v11;
        v21[7] = 0;
        v21[8] = 4;
        v21[9] = 0;
        result = MmTlgWrite(v3, (unsigned __int8 *)&word_413CA2 + 1, v5, (int)&word_413CA2, 7, v13);
      }
    }
  }
  else
  {
    v6 = strlen(result);
    result = ExAllocatePoolWithTag(1, (int)&v6[*(unsigned __int16 *)(a2 + 44) + 29], 1178889549);
    v7 = result;
    if ( result )
    {
      v8 = result + 28;
      *(_DWORD *)(v7 + 8) = v8;
      memmove(v8, v4, (unsigned int)(v6 + 1));
      v9 = (int)&v6[v7 + 29];
      *(_DWORD *)(v7 + 16) = v9;
      result = memmove(v9, *(_DWORD *)(a2 + 48), *(unsigned __int16 *)(a2 + 44));
      *(_WORD *)(v7 + 12) = *(_WORD *)(a2 + 44);
      *(_WORD *)(v7 + 14) = *(_WORD *)(a2 + 44);
      *(_DWORD *)(v7 + 20) = *(_DWORD *)(a2 + 64);
      *(_DWORD *)(v7 + 24) = *(_DWORD *)(a2 + 88);
      v10 = (void ***)off_617894;
      *(_DWORD *)v7 = &MiStrongCodeLoadFailureHead;
      *(_DWORD *)(v7 + 4) = v10;
      if ( *v10 != &MiStrongCodeLoadFailureHead )
        __fastfail(3u);
      *v10 = (void **)v7;
      off_617894 = (void **)v7;
    }
  }
  return result;
}
