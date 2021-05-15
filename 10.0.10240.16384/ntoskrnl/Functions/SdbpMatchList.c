// SdbpMatchList 
 
int __fastcall SdbpMatchList(int *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // r6
  int v10; // r4
  int (__fastcall *v11)(int *, int, int, int, int, int, int); // r6
  int result; // r0
  int v13; // r0
  int v14; // r3
  int v15; // [sp+10h] [bp-28h] BYREF
  int v16; // [sp+14h] [bp-24h]
  int v17[8]; // [sp+18h] [bp-20h] BYREF

  v7 = a2;
  v15 = 1;
  v16 = a2;
  v10 = SdbGetFirstChild(a3, a4, a3, 1);
  if ( v10 )
  {
    while ( 1 )
    {
      v11 = (int (__fastcall *)(int *, int, int, int, int, int, int))SdbpFindMatcher(v17, v7, a3, v10);
      if ( v11 )
      {
        result = v11(&v15, v16, a3, a4, v10, a5, v17[0]);
        if ( !result )
          return result;
        v13 = SdbFindFirstTag(a3, v10, 4099);
        v14 = v15;
        if ( v13 )
        {
          v14 = v15 == 0;
          v15 = v14;
        }
        if ( v14 == a6 )
          break;
      }
      v10 = SdbGetNextChild(a3, a4, v10);
      v7 = v16;
      if ( !v10 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    v14 = v15;
  }
  result = 1;
  *a1 = v14;
  return result;
}
