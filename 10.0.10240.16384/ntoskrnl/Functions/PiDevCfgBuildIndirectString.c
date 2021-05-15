// PiDevCfgBuildIndirectString 
 
int __fastcall PiDevCfgBuildIndirectString(int a1, unsigned __int16 *a2, int a3, _DWORD *a4)
{
  unsigned int v6; // r3
  int v7; // r7
  _WORD *v10; // r2
  __int16 v11; // r2
  unsigned int v12; // r7
  int v13; // r0
  unsigned __int16 *v14; // r4
  int v15; // r4
  unsigned int v16; // r0
  int v18; // r4
  __int16 v19; // r10
  int v20; // r4
  int v21; // r4
  int v22; // r0
  int v23; // [sp+Ch] [bp-5Ch] BYREF
  __int16 v24[2]; // [sp+10h] [bp-58h] BYREF
  int v25; // [sp+14h] [bp-54h]
  int v26; // [sp+18h] [bp-50h] BYREF
  int v27; // [sp+1Ch] [bp-4Ch]
  __int16 v28[2]; // [sp+20h] [bp-48h] BYREF
  const __int16 *v29; // [sp+24h] [bp-44h]
  _DWORD v30[16]; // [sp+28h] [bp-40h] BYREF

  v26 = 0;
  v27 = 0;
  v6 = *a2;
  v7 = 0;
  v23 = 0;
  if ( v6 <= 4 || (v10 = (_WORD *)*((_DWORD *)a2 + 1), *v10 != 37) || v10[(v6 >> 1) - 1] != 37 )
  {
    if ( *((_DWORD *)a2 + 1) )
    {
      v22 = ExpAllocateStringRoutine(a2[1]);
      *(_DWORD *)(a3 + 4) = v22;
      if ( !v22 )
        goto LABEL_19;
      memmove(v22, *((_DWORD *)a2 + 1), a2[1]);
    }
    else
    {
      *(_DWORD *)(a3 + 4) = 0;
    }
    *(_WORD *)a3 = *a2;
    *(_WORD *)(a3 + 2) = a2[1];
    if ( a4 )
    {
      *a4 = *(_DWORD *)a3;
      a4[1] = *(_DWORD *)(a3 + 4);
    }
    goto LABEL_18;
  }
  v24[1] = 0;
  v24[0] = 0;
  v25 = 0;
  v28[1] = 16;
  v28[0] = 14;
  v29 = L"Strings";
  v30[2] = 24;
  v30[3] = *(_DWORD *)(a1 + 8);
  v30[5] = 576;
  v30[4] = v28;
  v30[6] = 0;
  v30[7] = 0;
  if ( ZwOpenKey() < 0 )
    goto LABEL_8;
  v11 = *a2;
  v12 = (unsigned __int16)(*a2 - 4);
  HIWORD(v30[0]) = *a2 - 2;
  LOWORD(v30[0]) = v11 - 4;
  v13 = ExpAllocateStringRoutine(HIWORD(v30[0]));
  v14 = (unsigned __int16 *)v13;
  v30[1] = v13;
  if ( !v13 )
  {
LABEL_19:
    v7 = -1073741670;
    goto LABEL_18;
  }
  memmove(v13, *((_DWORD *)a2 + 1) + 2, v12);
  v14[v12 >> 1] = 0;
  v15 = IopGetRegistryValue(0, v14, 0, &v23);
  v16 = RtlFreeAnsiString(v30);
  if ( v15 >= 0 )
    return sub_7E2498(v16);
LABEL_8:
  v18 = *a2 + *(unsigned __int16 *)(a1 + 20) + 4;
  if ( v25 )
    v18 += (unsigned __int16)v24[0] + 2;
  if ( (unsigned int)(v18 + 2) > 0xFFFE )
  {
    v7 = -1073741562;
    goto LABEL_18;
  }
  HIWORD(v26) = v18 + 2;
  LOWORD(v26) = v18;
  v27 = ExpAllocateStringRoutine((unsigned __int16)(v18 + 2));
  if ( !v27 )
    goto LABEL_19;
  v7 = RtlUnicodeStringPrintfEx((unsigned __int16 *)&v26, (int)v28, 2048, L"@%wZ,%wZ");
  if ( v7 >= 0 )
  {
    v19 = v26;
    v20 = (unsigned __int16)v26 >> 1;
    if ( !v25 )
    {
      v21 = v20 - (*a2 >> 1);
LABEL_16:
      *(_DWORD *)a3 = v26;
      *(_DWORD *)(a3 + 4) = v27;
      v26 = 0;
      v27 = 0;
      if ( a4 )
        RtlInitUnicodeString((unsigned int)a4, (unsigned __int16 *)(*(_DWORD *)(a3 + 4) + 2 * v21));
      goto LABEL_18;
    }
    v7 = RtlUnicodeStringPrintf(v28, (int)L";%wZ", (int)v24, v25);
    if ( v7 >= 0 )
    {
      v21 = v20 + 1;
      LOWORD(v26) = v28[0] + v19;
      goto LABEL_16;
    }
  }
LABEL_18:
  RtlFreeAnsiString(&v26);
  return v7;
}
