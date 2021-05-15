// PiSwAddPdoAssociation 
 
int __fastcall PiSwAddPdoAssociation(int a1, int a2, int a3)
{
  int v6; // r5
  _DWORD *v7; // r4
  signed int v8; // r0
  _DWORD *v9; // r1

  v6 = 0;
  v7 = (_DWORD *)ExAllocatePoolWithTag(1, 16, 1466986064);
  if ( !v7 )
    return -1073741670;
  ObfReferenceObject(a2);
  v8 = ObfReferenceObject(a3);
  v7[2] = a2;
  v7[3] = a3;
  v9 = *(_DWORD **)(a1 + 72);
  *v7 = a1 + 68;
  v7[1] = v9;
  if ( *v9 != a1 + 68 )
    sub_7EE360(v8);
  *v9 = v7;
  *(_DWORD *)(a1 + 72) = v7;
  return v6;
}
