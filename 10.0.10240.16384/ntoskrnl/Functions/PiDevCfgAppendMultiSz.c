// PiDevCfgAppendMultiSz 
 
int __fastcall PiDevCfgAppendMultiSz(unsigned __int16 *a1, unsigned __int16 *a2, unsigned __int16 *a3, int a4)
{
  int v5; // r4
  int v6; // r6
  unsigned int v9; // r0
  int v10; // r0
  unsigned __int16 v11; // r3
  int v12; // r0
  unsigned int v13; // r0
  int v14; // r0
  int v15; // r10
  unsigned int v16; // r2
  unsigned int v17; // r9
  unsigned __int16 *v18; // r4
  unsigned int v19; // r2
  unsigned __int16 *i; // r4
  unsigned int v21; // r0
  unsigned __int16 *v22; // r7
  unsigned int v23; // r8
  int v25[2]; // [sp+0h] [bp-38h] BYREF
  int v26; // [sp+8h] [bp-30h] BYREF
  int v27; // [sp+Ch] [bp-2Ch]
  unsigned __int16 v28[20]; // [sp+10h] [bp-28h] BYREF

  v5 = *((_DWORD *)a1 + 1);
  v25[0] = a4;
  v6 = 0;
  v26 = 0;
  v27 = 0;
  if ( !v5 )
  {
    if ( a2 )
    {
      v9 = *a2 + 4;
      if ( v9 > 0xFFFE )
      {
LABEL_4:
        v6 = -2147483643;
        goto LABEL_47;
      }
      v10 = ExpAllocateStringRoutine(v9);
      *((_DWORD *)a1 + 1) = v10;
      if ( !v10 )
      {
LABEL_6:
        v6 = -1073741670;
        goto LABEL_47;
      }
      *a1 = *a2;
      if ( *a2 )
      {
        memmove(v10, *((_DWORD *)a2 + 1), *a2);
        *(_WORD *)(*((_DWORD *)a1 + 1) + 2 * (*a1 >> 1)) = 0;
        *a1 += 2;
      }
      *(_WORD *)(*((_DWORD *)a1 + 1) + 2 * (*a1 >> 1)) = 0;
      v11 = *a1 + 2;
      *a1 = v11;
LABEL_10:
      a1[1] = v11;
      goto LABEL_47;
    }
    if ( a3 )
    {
      if ( *((_DWORD *)a3 + 1) )
      {
        v12 = ExpAllocateStringRoutine(a3[1]);
        *((_DWORD *)a1 + 1) = v12;
        if ( !v12 )
          goto LABEL_6;
        memmove(v12, *((_DWORD *)a3 + 1), a3[1]);
      }
      else
      {
        *((_DWORD *)a1 + 1) = 0;
      }
      *a1 = *a3;
      v11 = a3[1];
      goto LABEL_10;
    }
LABEL_46:
    v6 = -1073741811;
    goto LABEL_47;
  }
  if ( a2 )
  {
    v13 = *a2 + *a1 + 2;
  }
  else
  {
    if ( !a3 )
      goto LABEL_46;
    v13 = *a3 + *a1;
    if ( *a1 )
      v13 -= 2;
  }
  if ( v13 > 0xFFFE )
    goto LABEL_4;
  v14 = ExpAllocateStringRoutine(v13);
  v15 = v14;
  v27 = v14;
  if ( !v14 )
    goto LABEL_6;
  v16 = *a1;
  if ( v16 <= 2 )
  {
    v17 = 0;
  }
  else
  {
    memmove(v14, *((_DWORD *)a1 + 1), v16);
    v17 = (unsigned __int16)(*a1 - 2);
  }
  if ( a2 )
  {
    if ( !v25[0] )
    {
      v18 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
      RtlInitUnicodeString((unsigned int)v28, *((unsigned __int16 **)a2 + 1));
      while ( *v18 )
      {
        RtlInitUnicodeString((unsigned int)v25, v18);
        if ( RtlEqualUnicodeString(v28, (unsigned __int16 *)v25, 1) )
          goto LABEL_37;
        v18 += (LOWORD(v25[0]) >> 1) + 1;
      }
    }
    memmove(v17 + v15, *((_DWORD *)a2 + 1), *a2);
    v19 = (unsigned __int16)(*a2 + v17);
    *(_WORD *)(v15 + 2 * (v19 >> 1)) = 0;
    v17 = (unsigned __int16)(v19 + 2);
  }
  else if ( a3 )
  {
    if ( v25[0] )
    {
      memmove(v17 + v15, *((_DWORD *)a3 + 1), *a3);
      v17 = (unsigned __int16)(*a3 + v17 - 2);
    }
    else
    {
      for ( i = (unsigned __int16 *)*((_DWORD *)a3 + 1); *i; i += v23 >> 1 )
      {
        v21 = wcslen(i);
        v22 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
        v23 = 2 * (v21 + 1);
        RtlInitUnicodeString((unsigned int)v28, i);
        while ( *v22 )
        {
          RtlInitUnicodeString((unsigned int)v25, v22);
          if ( RtlEqualUnicodeString(v28, (unsigned __int16 *)v25, 1) )
            goto LABEL_45;
          v22 += (LOWORD(v25[0]) >> 1) + 1;
        }
        memmove(v17 + v15, (int)i, v23);
        v17 = (unsigned __int16)(v17 + v23);
LABEL_45:
        ;
      }
    }
  }
LABEL_37:
  *(_WORD *)(v15 + 2 * (v17 >> 1)) = 0;
  LOWORD(v26) = v17 + 2;
  HIWORD(v26) = v17 + 2;
  RtlFreeAnsiString(a1);
  *(_DWORD *)a1 = v26;
  *((_DWORD *)a1 + 1) = v15;
  v26 = 0;
  v27 = 0;
LABEL_47:
  RtlFreeAnsiString(&v26);
  return v6;
}
