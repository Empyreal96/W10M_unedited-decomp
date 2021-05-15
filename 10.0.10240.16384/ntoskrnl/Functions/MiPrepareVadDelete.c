// MiPrepareVadDelete 
 
int __fastcall MiPrepareVadDelete(int a1, _BYTE *a2, __int64 a3, int *a4)
{
  __int64 v6; // r0
  int result; // r0
  int v8; // r3

  v6 = *(_QWORD *)(a1 + 12);
  *a4 = 0;
  if ( a3 == v6 )
  {
    if ( *a2 == 1 )
      return sub_8061C0();
    return 0;
  }
  if ( (*(_DWORD *)(a1 + 28) & 7) != 0 && (*(_DWORD *)(a1 + 28) & 7) != 6 )
    return -1073741665;
  if ( (_DWORD)a3 == (_DWORD)v6 )
  {
    *a4 = 1;
  }
  else
  {
    if ( HIDWORD(a3) == HIDWORD(v6) )
      v8 = 2;
    else
      v8 = 3;
    *a4 = v8;
  }
  if ( *a2 )
    return 0;
  *a4 = 0;
  *a2 = 1;
  MiLockAddressSpaceToo(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), a1);
  if ( MiVadDeleted(a1) )
    result = -1073741664;
  else
    result = -1073741267;
  return result;
}
