// BiTranslateSymbolicLinkFile 
 
int __fastcall BiTranslateSymbolicLinkFile(unsigned __int16 *a1, int *a2, int a3, unsigned int a4)
{
  int v4; // r5
  unsigned __int16 *v6; // r9
  unsigned __int16 *v7; // r8
  int v8; // r10
  unsigned __int16 *v9; // r6
  unsigned __int16 *v10; // r0
  unsigned __int16 *v11; // r4
  int v12; // r0
  unsigned __int16 *v13; // r0
  unsigned int v14; // r8
  int v15; // r0
  int v16; // r4
  unsigned __int16 *v18; // [sp+0h] [bp-28h] BYREF
  int v19; // [sp+4h] [bp-24h]
  unsigned int v20; // [sp+8h] [bp-20h]

  v19 = a3;
  v20 = a4;
  v4 = 0;
  v18 = 0;
  v6 = a1;
  if ( a1 && a2 )
  {
    *a2 = 0;
    v7 = 0;
    v8 = 0;
    v9 = a1;
    while ( 1 )
    {
      v10 = wcsrchr(v9, 92);
      v11 = v10;
      if ( v7 )
        *v7 = 92;
      if ( !v10 )
        break;
      *v10 = 0;
      v12 = BiTranslateSymbolicLink(v9, &v18);
      v4 = (int)v18;
      if ( v12 >= 0 )
      {
        v13 = v18;
        *v11 = 92;
        v8 = 1;
        v14 = wcslen(v13);
        v20 = 2 * (wcslen(v11) + 1);
        v15 = ExAllocatePoolWithTag(1, v20 + 2 * v14, 1262764866);
        v19 = v15;
        *a2 = v15;
        if ( !v15 )
        {
          v16 = -1073741801;
          goto LABEL_18;
        }
        memmove(v15, v4, 2 * v14);
        memmove(v19 + 2 * v14, (int)v11, v20);
        if ( v9 != v6 )
          ExFreePoolWithTag((unsigned int)v9);
        v9 = (unsigned __int16 *)*a2;
        v11 = (unsigned __int16 *)(*a2 + 2 * v14);
        *v11 = 0;
      }
      v7 = v11;
    }
    if ( v8 )
      v16 = 0;
    else
      v16 = -1073741823;
  }
  else
  {
    v16 = -1073741811;
  }
LABEL_18:
  if ( v4 )
    ExFreePoolWithTag(v4);
  return v16;
}
