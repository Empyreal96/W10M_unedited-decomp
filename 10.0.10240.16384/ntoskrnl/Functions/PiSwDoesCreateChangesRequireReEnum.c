// PiSwDoesCreateChangesRequireReEnum 
 
int __fastcall PiSwDoesCreateChangesRequireReEnum(_DWORD *a1, int a2)
{
  unsigned int v4; // r0
  unsigned int v5; // r1
  int v6; // r0
  unsigned __int16 *v7; // r1
  int v8; // r0
  unsigned __int16 *v9; // r1
  int v10; // r2
  int v11; // r3
  unsigned __int16 *v12; // r0
  int v13; // r1
  unsigned __int16 *v14; // r0
  int v15; // r1
  int result; // r0

  if ( a1[9] != *(_DWORD *)(a2 + 32) )
    goto LABEL_27;
  v4 = a1[6];
  v5 = *(_DWORD *)(a2 + 28);
  if ( v4 != v5 && (!v4 || !v5 || memcmp(v4, v5, 16)) )
    goto LABEL_27;
  if ( wcsicmp(*(_DWORD *)(a1[15] + 4), *(unsigned __int16 **)(a2 + 4)) )
    goto LABEL_27;
  v6 = a1[7];
  v7 = *(unsigned __int16 **)(a2 + 36);
  if ( (unsigned __int16 *)v6 != v7 && (!v6 || !v7 || wcsicmp(v6, v7)) )
    goto LABEL_27;
  v8 = a1[8];
  v9 = *(unsigned __int16 **)(a2 + 40);
  if ( (unsigned __int16 *)v8 != v9 && (!v8 || !v9 || wcsicmp(v8, v9)) )
    goto LABEL_27;
  if ( (v10 = a1[21], v11 = *(_DWORD *)(a2 + 44), v10 == v11)
    && (!v10 || !memcmp(a1[20], *(_DWORD *)(a2 + 48), v10))
    && ((v12 = (unsigned __int16 *)a1[4], v13 = *(_DWORD *)(a2 + 16), v12 == (unsigned __int16 *)v13)
     || v12 && v13 && PnpCompareMultiSz(v12, v13, v10, v11))
    && ((v14 = (unsigned __int16 *)a1[5], v15 = *(_DWORD *)(a2 + 24), v14 == (unsigned __int16 *)v15)
     || v14 && v15 && PnpCompareMultiSz(v14, v15, v10, v11)) )
  {
    result = 0;
  }
  else
  {
LABEL_27:
    result = 1;
  }
  return result;
}
