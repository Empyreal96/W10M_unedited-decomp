// SeGetImageRequiredSigningLevel 
 
int __fastcall SeGetImageRequiredSigningLevel(int a1, int a2, int a3, int a4, _BYTE *a5)
{
  int v5; // r6
  _BYTE *v9; // r3
  _DWORD v10[6]; // [sp+8h] [bp-18h] BYREF

  v10[0] = a4;
  v5 = 0;
  if ( dword_61D8B8 )
    return sub_7D521C();
  if ( SeCompareSigningLevels(a4, a3)
    || (unsigned __int8)SeILSigningPolicy > 4u
    || (*(_BYTE *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 734) & 7) != 0
    || a3 != 6 )
  {
    goto LABEL_4;
  }
  if ( !dword_61D89C )
    return -1073741823;
  v5 = ((int (__fastcall *)(int, _DWORD *, char *))dword_61D89C)(a1, v10, (char *)v10 + 1);
  if ( v5 >= 0 )
  {
    if ( !LOBYTE(v10[0]) && !BYTE1(v10[0]) )
    {
      v5 = RtlIsUntrustedObject(0, a1, (_BYTE *)v10 + 2);
      if ( v5 < 0 )
        return v5;
      v9 = a5;
      if ( !BYTE2(v10[0]) )
      {
        *a5 = 0;
        return v5;
      }
      goto LABEL_5;
    }
LABEL_4:
    v9 = a5;
LABEL_5:
    *v9 = a3;
  }
  return v5;
}
