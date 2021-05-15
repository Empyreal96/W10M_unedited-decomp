// SeTokenIsElevated 
 
int __fastcall SeTokenIsElevated(int a1, _BYTE *a2, int a3, int a4)
{
  int v4; // r3
  int v7; // r5
  unsigned int v8; // r0
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[1] = a4;
  v9[0] = 0;
  v4 = *(_DWORD *)(a1 + 168);
  *a2 = 0;
  if ( v4 == 2 && *(int *)(a1 + 172) < 2 )
    return sub_7F516C();
  v7 = SeQueryInformationToken(a1, 20, v9);
  v8 = v9[0];
  if ( v7 >= 0 && *(_DWORD *)v9[0] )
    *a2 = 1;
  if ( v8 )
    ExFreePoolWithTag(v8);
  return v7;
}
