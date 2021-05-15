// SdbpFindNextIndexedWildCardTag 
 
int __fastcall SdbpFindNextIndexedWildCardTag(int a1, int a2)
{
  unsigned __int16 *v4; // r2
  int v5; // r1
  int v6; // r0
  unsigned int v7; // r8
  unsigned int v8; // r5
  int i; // r7
  int v10; // r3
  int v11; // r4
  int v12; // r0
  int v13; // r2
  int v14; // r3
  _WORD *v15; // r0
  unsigned int v17; // [sp+0h] [bp-138h] BYREF
  int v18; // [sp+4h] [bp-134h]
  _DWORD v19[2]; // [sp+8h] [bp-130h] BYREF
  __int16 v20; // [sp+10h] [bp-128h]
  char v21[288]; // [sp+18h] [bp-120h] BYREF

  memset(v21, 0, 260);
  v4 = *(unsigned __int16 **)(a2 + 32);
  v19[0] = 0;
  v19[1] = 0;
  v20 = 0;
  if ( AslStringUpcaseToMultiByteN((int)v21, v5, v4) < 0 )
    return 0;
  v6 = SdbpGetIndex(a1, *(_DWORD *)a2, &v17);
  if ( !v6 )
    return 0;
  v7 = v17;
  v8 = *(_DWORD *)(a2 + 16) + 1;
  if ( v8 >= v17 )
    return 0;
  for ( i = v6 + 12 * v8; ; i += 12 )
  {
    memmove((int)&v17, i, 8u);
    v10 = *(_DWORD *)(a2 + 20);
    if ( (v10 & 2) != 0 )
    {
      SdbpKeyToAnsiString(v17, v18, (int)v19 + 1, v10);
      LOBYTE(v19[0]) = 42;
    }
    else
    {
      SdbpKeyToAnsiString(v17, v18, (int)v19, v10);
      LOBYTE(v20) = 42;
    }
    if ( AslStringPatternMatchA((char *)v19, (int)v21) )
    {
      v11 = *(_DWORD *)(i + 8);
      v12 = SdbFindFirstTag(a1, v11, *(unsigned __int16 *)(a2 + 12));
      if ( v12 )
      {
        v15 = (_WORD *)SdbGetStringTagPtr(a1, v12, v13, v14);
        if ( v15 )
        {
          if ( AslStringPatternMatchW(v15, *(_WORD **)(a2 + 32)) )
            break;
        }
      }
    }
    if ( ++v8 >= v7 )
      return 0;
  }
  *(_DWORD *)(a2 + 16) = v8;
  return v11;
}
