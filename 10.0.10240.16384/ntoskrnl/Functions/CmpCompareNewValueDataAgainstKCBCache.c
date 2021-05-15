// CmpCompareNewValueDataAgainstKCBCache 
 
int __fastcall CmpCompareNewValueDataAgainstKCBCache(int a1, int a2, int a3, int a4, int a5)
{
  __int16 v5; // r4
  unsigned __int8 *v6; // r7
  int v10; // r9
  int v11; // r10
  int v12; // r0
  int v13; // r6
  unsigned int v14; // r2
  int v15; // r0
  int v16; // r4
  int v18; // r4
  char v19[4]; // [sp+8h] [bp-30h] BYREF
  int v20; // [sp+Ch] [bp-2Ch] BYREF
  int v21; // [sp+10h] [bp-28h] BYREF
  int v22; // [sp+14h] [bp-24h] BYREF
  int v23; // [sp+18h] [bp-20h]

  v5 = *(_WORD *)(a1 + 106);
  v23 = a4;
  v6 = 0;
  v20 = -1;
  v10 = 0;
  v19[0] = 0;
  v11 = 0;
  v22 = -1;
  if ( (v5 & 0x10) == 0 )
    goto LABEL_2;
  v21 = -1;
  if ( !CmpIsKcbLockedExclusive(a1) && !CmpTryConvertKcbLockSharedToExclusive(a1) )
    return 1;
  ExAcquireResourceSharedLite(*(_DWORD *)(*(_DWORD *)(a1 + 20) + 1872), 1);
  v18 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(*(_DWORD *)(a1 + 20) + 4))(
          *(_DWORD *)(a1 + 20),
          *(_DWORD *)(a1 + 24),
          &v21);
  if ( v18 )
  {
    CmpUpdateKeyNodeAccessBits(*(_DWORD *)(a1 + 20), v18, *(_DWORD *)(a1 + 24));
    ExReleaseResourceLite(*(_DWORD *)(*(_DWORD *)(a1 + 20) + 1872));
    CmpCleanUpKcbValueCache(a1);
    *(_DWORD *)(a1 + 52) = *(_DWORD *)(v18 + 36);
    *(_DWORD *)(a1 + 56) = *(_DWORD *)(v18 + 40);
    (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a1 + 20) + 8))(*(_DWORD *)(a1 + 20), &v21);
LABEL_2:
    v12 = CmpFindValueByNameFromCache(a1, a2, &v21, &v20);
    v13 = v12;
    if ( !v12 )
      goto LABEL_11;
    if ( a3 != *(_DWORD *)(v12 + 12) )
      goto LABEL_11;
    v14 = *(_DWORD *)(v12 + 4);
    if ( a5 != (v14 & 0x7FFFFFFF) )
      goto LABEL_11;
    if ( v14 >= 0x80000000 )
    {
      v6 = (unsigned __int8 *)(v12 + 8);
    }
    else
    {
      v11 = 1;
      v6 = (unsigned __int8 *)CmpGetValueDataFromCache(a1, v20, v12, v19, &v22);
      if ( !v6 )
      {
        v16 = 2;
LABEL_14:
        if ( v13 )
          (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a1 + 20) + 8))(*(_DWORD *)(a1 + 20), &v20);
        return v16;
      }
      v10 = (unsigned __int8)v19[0];
    }
    v15 = a5 ? RtlCompareMemory(v6, v23, a5 & 0x7FFFFFFF) : 0;
    if ( v15 == a5 )
      v16 = 0;
    else
LABEL_11:
      v16 = 2;
    if ( v6 && v11 )
    {
      if ( v10 == 1 )
        ExFreePoolWithTag((unsigned int)v6);
      else
        (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a1 + 20) + 8))(*(_DWORD *)(a1 + 20), &v22);
    }
    goto LABEL_14;
  }
  return sub_80453C();
}
