// RtlAreNamesEqual 
 
int __fastcall RtlAreNamesEqual(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int a4)
{
  _DWORD *v4; // r6
  unsigned __int16 *v5; // r5
  unsigned int v6; // r0
  int v7; // r7
  BOOL v8; // r4
  unsigned int v10; // r0
  int v11; // r1
  unsigned __int16 *v12; // r4
  int v13; // r5
  int v14; // r2
  int v15; // t1
  int v16; // r4
  _DWORD v17[2]; // [sp+0h] [bp-20h] BYREF
  _DWORD v18[6]; // [sp+8h] [bp-18h] BYREF

  v17[0] = a1;
  v17[1] = a2;
  v18[0] = a3;
  v18[1] = a4;
  v4 = a2;
  v5 = a1;
  v6 = *a1;
  v7 = 0;
  if ( v6 != *a2 )
    return 0;
  v10 = v6 >> 1;
  if ( !a3 )
  {
LABEL_5:
    v8 = memcmp(*((_DWORD *)v5 + 1), v4[1], *v5) == 0;
    if ( v7 )
    {
      RtlFreeAnsiString(v17);
      RtlFreeAnsiString(v18);
    }
    return v8;
  }
  if ( !a4 )
  {
    if ( RtlpUpcaseUnicodeStringPrivate(v17, v5) < 0 )
      j_RtlRaiseStatus();
    v16 = RtlpUpcaseUnicodeStringPrivate(v18, v4);
    if ( v16 < 0 )
    {
      RtlFreeAnsiString(v17);
      RtlRaiseStatus(v16);
    }
    v5 = (unsigned __int16 *)v17;
    v4 = v18;
    v7 = 1;
    goto LABEL_5;
  }
  v11 = 0;
  if ( v10 )
  {
    v12 = (unsigned __int16 *)v4[1];
    v13 = *((_DWORD *)v5 + 1) - (_DWORD)v12;
    while ( 1 )
    {
      v14 = *(unsigned __int16 *)(a4 + 2 * *(unsigned __int16 *)((char *)v12 + v13));
      v15 = *v12++;
      if ( v14 != *(unsigned __int16 *)(a4 + 2 * v15) )
        break;
      if ( ++v11 >= v10 )
        return 1;
    }
    return 0;
  }
  return 1;
}
