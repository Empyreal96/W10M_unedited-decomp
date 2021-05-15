// RtlDeleteElementGenericTable 
 
int __fastcall RtlDeleteElementGenericTable(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r5
  __int64 v7; // kr00_8
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v5 = sub_44CE2C(a1, a2, v9);
  if ( !v5 || v5 != 1 )
    return 0;
  v6 = v9[0];
  *(_DWORD *)a1 = RtlDelete(v9[0]);
  v7 = *(_QWORD *)(v6 + 12);
  if ( *(_DWORD *)(v7 + 4) != v6 + 12 || *(_DWORD *)HIDWORD(v7) != v6 + 12 )
    sub_51E048(HIDWORD(v7));
  *(_DWORD *)HIDWORD(v7) = v7;
  *(_DWORD *)(v7 + 4) = HIDWORD(v7);
  --*(_DWORD *)(a1 + 20);
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 12) = a1 + 4;
  (*(void (__fastcall **)(int, int))(a1 + 32))(a1, v6);
  return 1;
}
