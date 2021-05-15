// CmpFindMatchingDescriptorCell 
 
int __fastcall CmpFindMatchingDescriptorCell(int a1, unsigned int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  unsigned int v5; // r4
  int v9; // r6
  int v10; // r0
  _DWORD *v11; // r7
  _DWORD *v12; // r5
  int v13; // r9
  _DWORD *v14; // r4

  v5 = a2;
  v9 = RtlLengthSecurityDescriptor(a2);
  v10 = CmpSecConvKey(v9, v5);
  v11 = (_DWORD *)(a1 + 8 * ((v10 & 0x3F) + 251));
  v12 = (_DWORD *)*v11;
  v13 = v10;
  while ( 1 )
  {
    if ( v12 == v11 )
      return 0;
    v14 = v12 - 2;
    if ( *(v12 - 1) == v13 && a3 == *v14 >> 31 && v9 == v12[2] && !memcmp(a2, (unsigned int)(v12 + 4), v9) )
      break;
    v12 = (_DWORD *)*v12;
  }
  *a4 = *v14;
  if ( a5 )
    *a5 = v14;
  return 1;
}
