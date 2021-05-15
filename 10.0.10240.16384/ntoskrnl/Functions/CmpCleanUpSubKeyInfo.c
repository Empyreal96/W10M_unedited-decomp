// CmpCleanUpSubKeyInfo 
 
int __fastcall CmpCleanUpSubKeyInfo(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r3
  int v6; // r1
  int v8; // r0
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v5 = a1[1];
  v9[0] = -1;
  if ( (v5 & 7) != 0 )
  {
    if ( (v5 & 4) != 0 )
      ExFreePoolWithTag(a1[15]);
    *((_WORD *)a1 + 2) = a1[1] & 0xFFF8;
  }
  v6 = a1[6];
  if ( v6 == -1 )
    return sub_805988();
  v8 = (*(int (__fastcall **)(_DWORD, int, int *))(a1[5] + 4))(a1[5], v6, v9);
  if ( !v8 )
    return sub_805988();
  *((_WORD *)a1 + 2) &= 0xFFBFu;
  a1[15] = *(_DWORD *)(v8 + 20) + *(_DWORD *)(v8 + 24);
  return (*(int (__fastcall **)(_DWORD, int *))(a1[5] + 8))(a1[5], v9);
}
