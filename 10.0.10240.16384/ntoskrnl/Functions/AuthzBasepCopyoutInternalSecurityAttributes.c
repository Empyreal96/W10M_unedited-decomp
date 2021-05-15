// AuthzBasepCopyoutInternalSecurityAttributes 
 
int __fastcall AuthzBasepCopyoutInternalSecurityAttributes(unsigned int *a1, unsigned int a2, int a3)
{
  unsigned int v5; // r9
  int v7; // r6
  unsigned int v8; // r8
  int v9; // r4
  char *v10; // r1
  int v11; // r10
  int v12; // r3
  int *v13; // r2
  char *v14; // r1
  int v15; // r2
  unsigned int v16; // r4
  int v17; // r3
  int v18; // [sp+8h] [bp-28h] BYREF
  unsigned int *v19; // [sp+Ch] [bp-24h]
  unsigned int *v20; // [sp+10h] [bp-20h]

  v19 = a1;
  if ( a2 && a3 )
  {
    v5 = a2 + a3;
    if ( a2 + a3 < a2 )
      return sub_7E5B68();
    memset((_BYTE *)a2, 0, a3);
    v7 = a2 + 24;
    v18 = 24;
    if ( a2 + 24 > v5 )
      goto LABEL_19;
    v8 = a2 + 4;
    *(_DWORD *)a2 = 0;
    *(_DWORD *)(a2 + 4) = a2 + 4;
    *(_DWORD *)(a2 + 8) = a2 + 4;
    *(_DWORD *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 16) = a2 + 16;
    *(_DWORD *)(a2 + 20) = a2 + 16;
    v9 = RtlULongLongToULong(*a1 << 6, (unsigned __int64)*a1 >> 26, &v18);
    if ( v9 < 0 || (v10 = (char *)(v18 + v7), v18 + v7 > v5) )
LABEL_19:
      JUMPOUT(0x7E5B6A);
    v11 = a1[1];
    v12 = (int)(v19 + 1);
    v20 = v19 + 1;
    while ( v11 != v12 )
    {
      v13 = *(int **)(a2 + 8);
      *(_DWORD *)v7 = v8;
      *(_DWORD *)(v7 + 4) = v13;
      if ( *v13 != v8 )
        __fastfail(3u);
      *v13 = v7;
      *(_DWORD *)(a2 + 8) = v7;
      ++*(_DWORD *)a2;
      v14 = v10 + 1;
      *(_WORD *)(v7 + 24) = *(_WORD *)(v11 + 24);
      *(_DWORD *)(v7 + 28) = *(_DWORD *)(v11 + 28);
      *(_DWORD *)(v7 + 32) = 0;
      *(_DWORD *)(v7 + 36) = 0;
      *(_DWORD *)(v7 + 40) = 0;
      *(_DWORD *)(v7 + 44) = v7 + 44;
      *(_DWORD *)(v7 + 48) = v7 + 44;
      *(_DWORD *)(v7 + 52) = 0;
      *(_DWORD *)(v7 + 56) = v7 + 56;
      *(_DWORD *)(v7 + 60) = v7 + 56;
      v15 = *(unsigned __int16 *)(v11 + 16);
      v18 = v15;
      v19 = (unsigned int *)v15;
      if ( ((unsigned int)v14 & 0xFFFFFFFE) + v15 > v5 )
        goto LABEL_19;
      v16 = (unsigned int)v14 & 0xFFFFFFFE;
      *(_WORD *)(v7 + 16) = 0;
      *(_DWORD *)(v7 + 20) = (unsigned int)v14 & 0xFFFFFFFE;
      *(_WORD *)(v7 + 18) = v15;
      RtlCopyUnicodeString((unsigned __int16 *)(v7 + 16), (unsigned __int16 *)(v11 + 16));
      v17 = v5 - ((_DWORD)v19 + v16);
      v19 = (unsigned int *)((char *)v19 + v16);
      v9 = AuthzBasepCopyoutInternalSecurityAttributeValues(v11, v7, (unsigned int)v19, v17, &v18);
      if ( v9 < 0 )
        goto LABEL_19;
      v11 = *(_DWORD *)v11;
      v10 = (char *)v19 + v18;
      v12 = (int)v20;
      v7 += 64;
    }
  }
  else
  {
    v9 = -1073741811;
  }
  if ( v9 < 0 )
    goto LABEL_19;
  return v9;
}
