// AuthzBasepDeleteSecurityAttributeValues 
 
int __fastcall AuthzBasepDeleteSecurityAttributeValues(int a1, int a2, _BYTE *a3)
{
  int v4; // r4
  _DWORD *v5; // r7
  int v6; // r6
  unsigned int v9; // r4
  int v10; // r9
  int v11; // r3
  __int64 v12; // r2
  int v13; // r3
  __int64 v14; // r2
  unsigned __int16 v16; // [sp+0h] [bp-28h]

  v4 = *(unsigned __int16 *)(a1 + 24);
  *a3 = 0;
  v5 = 0;
  v6 = 0;
  if ( v4 != *(unsigned __int16 *)(a2 + 8) )
    return -1073741811;
  v9 = 0;
  if ( *(_DWORD *)(a2 + 16) )
  {
    v10 = 0;
    do
    {
      v11 = *(unsigned __int16 *)(a1 + 24);
      if ( *(_WORD *)(a1 + 24) )
      {
        if ( *(unsigned __int16 *)(a1 + 24) <= 2u )
          goto LABEL_15;
        switch ( v11 )
        {
          case 3:
LABEL_12:
            v16 = *(_WORD *)(a1 + 24);
            LODWORD(v12) = *(_DWORD *)(a2 + 20) + 8 * v9;
LABEL_13:
            v12 = (int)v12;
LABEL_16:
            v5 = (_DWORD *)AuthzBasepFindSecurityAttributeValue(a1, 1, (__int64 *)v12, SHIDWORD(v12), v16);
            goto LABEL_18;
          case 4:
            v16 = 4;
            LODWORD(v12) = v10 + *(_DWORD *)(a2 + 20);
            goto LABEL_13;
          case 5:
            goto LABEL_12;
          case 6:
LABEL_15:
            v16 = *(_WORD *)(a1 + 24);
            v12 = *(_QWORD *)(*(_DWORD *)(a2 + 20) + 8 * v9);
            goto LABEL_16;
          case 16:
            goto LABEL_12;
        }
      }
      v6 = -1073741811;
LABEL_18:
      if ( v6 < 0 )
        return v6;
      if ( !v5 )
        return -1073741275;
      v13 = v5[4];
      if ( (v13 & 4) != 0 )
        return -1073741275;
      if ( (v13 & 1) != 0 )
      {
        v5[4] = v13 | 4;
        AuthzBasepAddSecurityAttributeValueToLists((_DWORD *)a1, v5, 0, 1);
        ++*(_DWORD *)(a1 + 40);
      }
      else
      {
        AuthzBasepRemoveSecurityAttributeValueFromLists(a1, v5, 0);
        ExFreePoolWithTag(v5);
      }
      ++v9;
      v10 += 16;
    }
    while ( v9 < *(_DWORD *)(a2 + 16) );
  }
  v14 = *(_QWORD *)(a1 + 36);
  if ( (_DWORD)v14 == HIDWORD(v14) && *(_DWORD *)(a1 + 52) <= (unsigned int)v14 )
    *a3 = 1;
  return v6;
}
