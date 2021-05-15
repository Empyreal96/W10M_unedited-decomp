// PiDqQueryEnumObject 
 
int __fastcall PiDqQueryEnumObject(int a1, int a2, int a3, int a4)
{
  int v5; // r2
  int v8; // r0
  int v9; // r2
  int v10; // r4
  int v11; // r3
  int v12; // [sp+0h] [bp-20h]
  int v13; // [sp+4h] [bp-1Ch]
  int v14; // [sp+8h] [bp-18h] BYREF
  int v15[5]; // [sp+Ch] [bp-14h] BYREF

  v12 = a1;
  v13 = a2;
  v14 = a3;
  v15[0] = a4;
  v5 = *(_DWORD *)(a1 + 12);
  LOBYTE(v14) = 1;
  if ( *(_DWORD *)(v5 + 20) )
    goto LABEL_12;
  if ( (unsigned int)(*(_DWORD *)(v5 + 16) - 1) > 2 )
    return sub_7C74B4();
  v8 = PiPnpRtlApplyMandatoryFilters(PiPnpRtlCtx, *(_DWORD *)(a2 + 12), *(_DWORD *)(a2 + 20), 0, a1 + 16, &v14);
  v9 = (unsigned __int8)v14;
  v10 = v8;
  if ( v8 == -1073741772 || v8 == -1073741275 )
  {
    v9 = 0;
    LOBYTE(v14) = 0;
    v10 = 0;
  }
  if ( v10 >= 0 && v9 )
  {
LABEL_12:
    if ( !*(_DWORD *)(*(_DWORD *)(a1 + 12) + 56)
      || ((v10 = PiDqQueryEvaluateFilter(a1, *(_DWORD *)(a2 + 12), &v14), v10 == -1073741772) ? (v11 = 0, v10 = 0) : (v11 = (unsigned __int8)v14),
          v11 && v10 >= 0) )
    {
      if ( (*(_DWORD *)(*(_DWORD *)(a1 + 12) + 32) & 1) == 0 || (v10 = PiDqQueryAddObjectToResultSet(a1, a2), v10 >= 0) )
      {
        v10 = PiDqQueryActionQueueEntryCreate(1, a2, 0, v15, v12, v13);
        if ( v10 >= 0 )
          PiDqQueryAppendActionEntry(a1, v15[0]);
      }
    }
  }
  return v10;
}
