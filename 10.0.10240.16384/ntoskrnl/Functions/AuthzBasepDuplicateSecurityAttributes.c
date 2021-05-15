// AuthzBasepDuplicateSecurityAttributes 
 
int __fastcall AuthzBasepDuplicateSecurityAttributes(int a1, int a2, unsigned int a3)
{
  int *v3; // r8
  int v4; // r4
  int v6; // r4
  int v7; // r6
  int *v8; // r1
  int v9; // r2
  int v10; // r2
  int *v11; // r5
  int v12; // r7
  _BYTE *v13; // r0
  _DWORD *v14; // r4
  _DWORD *v15; // r1
  _DWORD *v16; // r2
  int v17; // r1
  unsigned int v19; // [sp+0h] [bp-28h]
  int *v20; // [sp+4h] [bp-24h]

  v3 = *(int **)(a1 + 4);
  v4 = 0;
  v19 = a3;
  v20 = (int *)(a1 + 4);
  if ( v3 == (int *)(a1 + 4) )
  {
LABEL_21:
    v17 = 1;
    goto LABEL_22;
  }
  v6 = a2 + 16;
  while ( a3 && (v3[7] & 1) != 0 )
  {
LABEL_19:
    v3 = (int *)*v3;
    if ( v3 == v20 )
    {
      v4 = 0;
      goto LABEL_21;
    }
  }
  v7 = AuthzBasepAllocateSecurityAttribute(v3 + 4);
  if ( !v7 )
LABEL_28:
    JUMPOUT(0x517E94);
  *(_DWORD *)(v7 + 28) = v3[7];
  *(_WORD *)(v7 + 24) = *((_WORD *)v3 + 12);
  if ( (*(_DWORD *)(v7 + 32) & 2) == 0 )
  {
    v8 = *(int **)(v6 + 4);
    v9 = v7 + 8;
    *(_DWORD *)(v7 + 8) = v6;
    *(_DWORD *)(v7 + 12) = v8;
    if ( *v8 != v6 )
      JUMPOUT(0x517E8C);
    *v8 = v9;
    *(_DWORD *)(v6 + 4) = v9;
    *(_DWORD *)(v7 + 32) |= 2u;
    ++*(_DWORD *)(a2 + 12);
  }
  v10 = *((unsigned __int16 *)v3 + 12);
  if ( v10 == 2 )
  {
    v11 = (int *)v3[11];
    if ( v11 != v3 + 11 )
    {
      v12 = v7 + 56;
      do
      {
        if ( (unsigned int)KeGetCurrentIrql() >= 2 )
          JUMPOUT(0x517E84);
        v13 = (_BYTE *)ExAllocatePoolWithTag(1, 40, 1950442835);
        v14 = v13;
        if ( !v13 )
          goto LABEL_28;
        memset(v13, 0, 40);
        v14[6] = v11[6];
        v14[7] = v11[7];
        if ( (v14[4] & 2) == 0 )
        {
          v15 = *(_DWORD **)(v7 + 60);
          v16 = v14 + 2;
          v14[2] = v12;
          v14[3] = v15;
          if ( *v15 != v12 )
            JUMPOUT(0x517E90);
          *v15 = v16;
          *(_DWORD *)(v7 + 60) = v16;
          v14[4] |= 2u;
          ++*(_DWORD *)(v7 + 52);
        }
        v11 = (int *)*v11;
      }
      while ( v11 != v3 + 11 );
      v6 = a2 + 16;
    }
    a3 = v19;
    goto LABEL_19;
  }
  a3 = v10 - 1;
  if ( a3 <= 0xF )
    __asm { ADD             PC, R3 }
  v4 = -1073741811;
  v17 = 0;
LABEL_22:
  AuthzBasepFinaliseSecurityAttributesList(a2, v17, a3);
  return v4;
}
