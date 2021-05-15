// AlpcpAllocateFromBitmap 
 
unsigned int __fastcall AlpcpAllocateFromBitmap(unsigned int *a1, unsigned int *a2, int a3)
{
  unsigned int v4; // r4
  unsigned int result; // r0
  unsigned int *v6; // lr
  int v8; // r6
  unsigned int v9; // r7
  unsigned int v10; // t1
  unsigned int i; // r5
  unsigned int *v12; // r1
  int v13; // r2
  unsigned int v14; // r5
  unsigned int v15; // r7
  int v16; // lr
  unsigned int v17; // r6
  unsigned int v18; // r5
  unsigned int v19; // r2
  unsigned int v20; // r5
  int v21; // r7
  unsigned int v22; // r6

  v4 = 0;
  result = -1;
  v6 = a1;
  if ( a1 != a2 )
  {
    v8 = 0;
    while ( 2 )
    {
      v10 = *v6++;
      v9 = v10;
      for ( i = 0; i < 0x20; ++i )
      {
        if ( (v9 & 1) != 0 )
        {
          result = -1;
          v4 = 0;
        }
        else
        {
          if ( result == -1 )
            result = i + 32 * (v8 >> 2);
          if ( ++v4 == a3 )
          {
            v12 = &a1[result >> 5];
            v13 = result & 0x1F;
            if ( (result & 0x1F) == 0 )
              goto LABEL_33;
            v14 = 32 - v13;
            if ( v4 < 32 - v13 )
              v14 = v4;
            v15 = *v12;
            v16 = ((1 << v14) - 1) << v13;
            if ( (*v12 & v16) != 0 )
              return -2;
            while ( 1 )
            {
              __dmb(0xBu);
              do
                v17 = __ldrex(v12);
              while ( v17 == v15 && __strex(v15 | v16, v12) );
              __dmb(0xBu);
              if ( v17 == v15 )
                break;
              v15 = v17;
              if ( (v17 & v16) != 0 )
                return -2;
            }
            for ( v4 -= v14; ; v4 -= 32 )
            {
              ++v12;
LABEL_33:
              if ( v4 < 0x20 )
                break;
              v18 = *v12;
              if ( *v12 )
                goto LABEL_41;
              while ( 1 )
              {
                __dmb(0xBu);
                do
                  v19 = __ldrex(v12);
                while ( v19 == v18 && __strex(0xFFFFFFFF, v12) );
                __dmb(0xBu);
                if ( v19 == v18 )
                  break;
                v18 = v19;
                if ( v19 )
                  goto LABEL_41;
              }
            }
            if ( !v4 )
              return result;
            v20 = *v12;
            v21 = (1 << v4) - 1;
            if ( (*v12 & v21) != 0 )
            {
LABEL_41:
              if ( a3 != v4 )
                AlpcpFreeBitmap(a1, v12, result, a3 - v4);
              return -2;
            }
            while ( 1 )
            {
              __dmb(0xBu);
              do
                v22 = __ldrex(v12);
              while ( v22 == v20 && __strex(v20 | v21, v12) );
              __dmb(0xBu);
              if ( v22 == v20 )
                return result;
              v20 = v22;
              if ( (v22 & v21) != 0 )
                goto LABEL_41;
            }
          }
        }
        v9 >>= 1;
      }
      v8 += 4;
      if ( v6 != a2 )
        continue;
      break;
    }
  }
  return -1;
}
