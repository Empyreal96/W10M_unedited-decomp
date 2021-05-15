// RtlDuplicateUnicodeString 
 
int __fastcall RtlDuplicateUnicodeString(int a1, int a2, int a3)
{
  unsigned __int16 *v4; // r6
  char v5; // r5
  unsigned int v6; // r4
  int v7; // r9
  int v8; // r10
  int v10; // r5
  int v11; // r0
  int v13; // [sp+4h] [bp-2Ch]
  int v14; // [sp+Ch] [bp-24h]

  v4 = (unsigned __int16 *)a2;
  v5 = a1;
  v6 = 0;
  v7 = 0;
  if ( (a1 & 0xFFFFFFFC) != 0 )
    return -1073741811;
  if ( !a3 )
    return -1073741811;
  v14 = a1 & 2;
  if ( (a1 & 2) != 0 && (a1 & 1) == 0 )
    return -1073741811;
  v13 = RtlValidateUnicodeString(0, a2);
  if ( v13 >= 0 )
  {
    if ( v4 )
      v6 = *v4;
    v8 = v5 & 1;
    if ( (v5 & 1) != 0 && v6 == 65534 )
      return -1073741562;
    if ( (v5 & 1) != 0 )
      v10 = (unsigned __int16)(v6 + 2);
    else
      v10 = v6;
    if ( !v14 && !v6 )
      v10 = 0;
    if ( v10 )
    {
      v11 = ExpAllocateStringRoutine(v10);
      v7 = v11;
      if ( !v11 )
        return -1073741801;
      if ( v6 )
        memmove(v11, *(_DWORD *)(a2 + 4), v6);
      if ( v8 )
        *(_WORD *)(v7 + 2 * (v6 >> 1)) = 0;
    }
    *(_WORD *)(a3 + 2) = v10;
    *(_WORD *)a3 = v6;
    *(_DWORD *)(a3 + 4) = v7;
    v13 = 0;
  }
  return v13;
}
