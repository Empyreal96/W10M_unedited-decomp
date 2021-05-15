// PopFxAcpiValidateParameters 
 
int __fastcall PopFxAcpiValidateParameters(int *a1)
{
  int result; // r0
  __int64 v3; // kr00_8
  int v4; // r4
  int v5; // r3
  bool v6; // cf
  bool v7; // cf
  unsigned __int16 *v8; // r1
  unsigned int v9; // r3

  result = 0;
  if ( !a1 )
    return result;
  v3 = *((_QWORD *)a1 + 1);
  if ( !(_DWORD)v3 || !HIDWORD(v3) )
    return result;
  v4 = *a1;
  if ( *a1 == 1 )
  {
    v7 = HIDWORD(v3) >= 0x10;
LABEL_14:
    if ( !v7 )
      return result;
    v8 = *(unsigned __int16 **)v3;
    if ( !*(_DWORD *)v3 )
      return result;
    if ( !*((_DWORD *)v8 + 1) )
      return result;
    v9 = *v8;
    if ( v9 < 4 )
      return result;
    v6 = v8[1] >= v9 + 2;
    goto LABEL_20;
  }
  if ( v4 == 2 )
  {
    v7 = HIDWORD(v3) >= 8;
    goto LABEL_14;
  }
  if ( v4 == 3 )
  {
    v7 = HIDWORD(v3) >= 0x14;
    goto LABEL_14;
  }
  if ( v4 != 4 )
  {
    v5 = *(_DWORD *)(a1[1] + 384);
    __dmb(0xBu);
    if ( (v5 & 4) == 0 )
      return result;
    return 1;
  }
  v6 = HIDWORD(v3) >= 8;
LABEL_20:
  if ( v6 )
    return 1;
  return result;
}
