// SdbpBinarySearchFirst 
 
int __fastcall SdbpBinarySearchFirst(int a1, unsigned int a2, unsigned int a3, unsigned int a4, int *a5)
{
  unsigned int v6; // r2
  int v8; // r5
  int v9; // r1
  int v10; // r6
  int v11; // r7
  int v12; // r4
  int v13; // r9
  bool v14; // cf
  bool v15; // cc
  unsigned int v19; // [sp+8h] [bp-30h] BYREF
  unsigned int v20; // [sp+Ch] [bp-2Ch]
  int v21; // [sp+10h] [bp-28h] BYREF
  int v22; // [sp+14h] [bp-24h]

  v6 = a2;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v8 = 0;
  v9 = a1;
  v10 = a2 - 1;
  v11 = 0;
  *a5 = -1;
  if ( (int)(a2 - 1) >= 0 )
  {
    while ( 1 )
    {
      v12 = (v10 + v11) / 2;
      if ( v12 < 0 || v12 >= v6 )
        return 0;
      v13 = v9 + 12 * v12;
      memmove((int)&v19, v13, 8u);
      if ( a3 == v19 )
      {
        v14 = a4 >= v20;
        v15 = a4 > v20;
        if ( a4 == v20 )
        {
          if ( !v12 || (memmove((int)&v21, v13 - 12, 8u), v21 != a3) || v22 != a4 )
          {
            v8 = 1;
            *a5 = v12;
            return v8;
          }
LABEL_10:
          v10 = v12 - 1;
          goto LABEL_11;
        }
      }
      else
      {
        v14 = a4 >= v20;
        v15 = a4 > v20;
      }
      if ( !v15 && (!v14 || a3 < v19) )
        goto LABEL_10;
      v11 = v12 + 1;
LABEL_11:
      if ( v10 < v11 )
        return v8;
      v6 = a2;
      v9 = a1;
    }
  }
  return 0;
}
