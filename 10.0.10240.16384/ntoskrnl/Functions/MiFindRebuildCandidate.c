// MiFindRebuildCandidate 
 
int __fastcall MiFindRebuildCandidate(unsigned __int16 *a1, int a2, int a3, int a4, int a5, int *a6)
{
  int v8; // r5
  int *v9; // r4
  char *v10; // r7
  int *v11; // r6
  int v12; // t1
  __int64 v13; // r2
  int v14; // r4
  unsigned int v15; // r0
  int v17; // [sp+8h] [bp-48h] BYREF
  int v18; // [sp+Ch] [bp-44h]
  unsigned int v19; // [sp+10h] [bp-40h] BYREF
  __int64 i; // [sp+18h] [bp-38h] BYREF
  int v21; // [sp+20h] [bp-30h]
  int v22; // [sp+24h] [bp-2Ch]
  int v23; // [sp+28h] [bp-28h]
  int v24; // [sp+2Ch] [bp-24h]

  v18 = *a1;
  v8 = *a6;
  v9 = &a6[2 * *a6 + 2];
  v21 = 0;
  v22 = a5;
  v23 = 1024;
  v24 = 1024;
  if ( v8 )
  {
    v10 = (char *)v9 + 2 * v8;
    v11 = &a6[2 * v8];
    do
    {
      v12 = (unsigned __int8)*(v10 - 2);
      v10 -= 2;
      --v8;
      v11 -= 2;
      if ( v12 == a2 && (unsigned __int8)v10[1] == a3 )
      {
        v13 = *((_QWORD *)v11 + 1);
        HIDWORD(v13) += v13;
        for ( i = v13; MiCollapseRunTopDown(&i); HIDWORD(i) = v14 )
        {
          v17 = 0;
          v14 = HIDWORD(i) - v24;
          v15 = MiPfnsWorthTrying(v18, MmPfnDatabase + 24 * (HIDWORD(i) - v24), v24, 50331648, &v17, &v19);
          if ( v15 )
          {
            if ( v15 > v14 - (int)i )
              break;
          }
          else if ( v19 && v19 >= 0x100 )
          {
            return v14;
          }
        }
      }
    }
    while ( v8 );
  }
  return -1;
}
