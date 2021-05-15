// MiInitializeUserNoAccess 
 
int __fastcall MiInitializeUserNoAccess(int a1, unsigned int a2)
{
  int v2; // r7
  _DWORD *v3; // r3
  int v4; // r8
  _DWORD *v5; // lr
  _DWORD *v8; // r5
  unsigned int v9; // r1
  unsigned int v10; // r0
  int v11; // r6
  unsigned int v12; // r4
  _DWORD *v13; // r2
  _DWORD *i; // r3
  int v15; // r3
  unsigned int v16; // r3
  _DWORD *v17; // r0

  v2 = 0;
  v3 = *(_DWORD **)(a1 + 636);
  v4 = 0;
  v5 = 0;
  v8 = 0;
  while ( v3 )
  {
    v8 = v3;
    v3 = (_DWORD *)*v3;
  }
  while ( 1 )
  {
    if ( v8 )
    {
      v12 = v8[1];
      v13 = v8;
      if ( v12 )
      {
        for ( i = *(_DWORD **)v12; i; i = (_DWORD *)*i )
          v12 = (unsigned int)i;
      }
      else
      {
        v15 = v8[2];
        while ( 1 )
        {
          v12 = v15 & 0xFFFFFFFC;
          if ( (v15 & 0xFFFFFFFC) == 0 || *(_DWORD **)v12 == v13 )
            break;
          v15 = *(_DWORD *)(v12 + 8);
          v13 = (_DWORD *)v12;
        }
      }
      v16 = v8[3] << 12;
      if ( v16 <= a2 )
        goto LABEL_23;
      v11 = 1;
      v9 = v16 - 1;
      if ( !v5 )
        goto LABEL_20;
      v10 = ((v5[4] << 12) | 0xFFF) + 1;
      if ( v10 >= v9 )
        goto LABEL_23;
      if ( v10 < a2 )
LABEL_20:
        v10 = a2;
    }
    else
    {
      v9 = MmHighestUserAddress;
      v10 = ((v5[4] << 12) | 0xFFF) + 1;
      if ( v10 >= MmHighestUserAddress )
        goto LABEL_24;
      v11 = 2;
      v12 = 0;
    }
    v17 = MiAllocateVad(v10, v9);
    if ( !v17 )
      break;
    *v17 = v2;
    v2 = (int)v17;
    if ( v11 == 2 )
    {
LABEL_24:
      MiInsertProcessVads(a1, v2);
      return v4;
    }
LABEL_23:
    v5 = v8;
    v8 = (_DWORD *)v12;
  }
  v4 = -1073741801;
  MiReturnProcessVads(v2);
  return v4;
}
