// RtlUnicodeToUTF8N 
 
int __fastcall RtlUnicodeToUTF8N(_BYTE *a1, int a2, unsigned int *a3, unsigned int *a4, unsigned int a5)
{
  unsigned int *v5; // r4
  int v6; // r6
  unsigned int v7; // r5
  _BYTE *v9; // lr
  unsigned int *v11; // r9
  _BYTE *v12; // r2
  int v13; // r3
  unsigned int v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // t1
  unsigned int *i; // r5
  unsigned int v18; // r1
  unsigned int v19; // t1
  unsigned int v20; // r0
  int v21; // r1
  int v22; // r3
  int v23; // r3
  unsigned int v24; // r3
  unsigned int v25; // r3
  int v26; // r0
  _BYTE *v27; // [sp+0h] [bp-20h]

  v5 = a4;
  v6 = 0;
  v7 = 0;
  v9 = a1;
  if ( !a4 )
    return sub_815B2C();
  if ( a1 )
  {
    if ( (a5 & 1) == 0 )
    {
      v11 = (unsigned int *)((char *)a4 + 2 * (a5 >> 1));
      v12 = a1;
      v27 = &a1[a2];
      while ( v5 < v11 )
      {
        if ( v7 )
        {
          v21 = *(unsigned __int16 *)v5;
          if ( (unsigned int)(v21 - 56320) <= 0x3FF )
          {
            v7 = v21 + (v7 << 10) - 56613888;
            v5 = (unsigned int *)((char *)v5 + 2);
          }
          goto LABEL_10;
        }
        v7 = *(unsigned __int16 *)v5;
        v5 = (unsigned int *)((char *)v5 + 2);
LABEL_9:
        if ( v7 - 55296 > 0x3FF )
        {
LABEL_10:
          if ( v7 - 55296 <= 0x7FF )
          {
            v6 = 263;
            v7 = 65533;
          }
          v13 = 1;
          if ( v7 > 0x7F )
          {
            if ( v7 > 0x7FF )
            {
              if ( v7 > 0xFFFF )
                v13 = 2;
              ++v13;
            }
            ++v13;
          }
          if ( v12 > &v27[-v13] )
          {
            v6 = -1073741789;
            goto LABEL_21;
          }
          if ( v7 > 0x7F )
          {
            if ( v7 > 0x7FF )
            {
              if ( v7 > 0xFFFF )
              {
                *v12 = (v7 >> 18) | 0xF0;
                v23 = (v7 >> 12) & 0x3F | 0x80;
                ++v12;
              }
              else
              {
                LOBYTE(v23) = (v7 >> 12) | 0xE0;
              }
              *v12++ = v23;
              v22 = (v7 >> 6) & 0x3F | 0x80;
            }
            else
            {
              LOBYTE(v22) = (v7 >> 6) | 0xC0;
            }
            *v12++ = v22;
            *v12 = v7 & 0x3F | 0x80;
          }
          else
          {
            *v12 = v7;
          }
          ++v12;
          v14 = ((char *)v11 - (char *)v5) >> 1;
          v15 = v27 - v12;
          if ( v14 > 0xD )
          {
            if ( v15 < v14 )
              v14 = v27 - v12;
            for ( i = (unsigned int *)((char *)v5 + 2 * v14 - 10); ; i = (unsigned int *)((char *)i - 2) )
            {
LABEL_31:
              while ( 2 )
              {
                if ( v5 >= i )
                  goto LABEL_32;
                v19 = *(unsigned __int16 *)v5;
                v5 = (unsigned int *)((char *)v5 + 2);
                v18 = v19;
                if ( v19 <= 0x7F )
                {
                  *v12++ = v18;
                  if ( ((unsigned __int8)v5 & 2) != 0 )
                  {
                    v18 = *(unsigned __int16 *)v5;
                    v5 = (unsigned int *)((char *)v5 + 2);
                    if ( v18 > 0x7F )
                      break;
                    *v12++ = v18;
                  }
                  if ( v5 >= i )
                    goto LABEL_32;
                  while ( 1 )
                  {
                    v20 = v5[1];
                    v18 = *v5;
                    if ( ((v20 | *v5) & 0xFF80FF80) != 0 )
                      break;
                    v12[1] = BYTE2(v18);
                    v12[3] = BYTE2(v20);
                    *v12 = v18;
                    v5 += 2;
                    v12[2] = v20;
                    v12 += 4;
                    if ( v5 >= i )
                      goto LABEL_31;
                  }
                  v18 = (unsigned __int16)v18;
                  v5 = (unsigned int *)((char *)v5 + 2);
                  if ( (unsigned __int16)v18 <= 0x7Fu )
                  {
                    *v12++ = v18;
                    continue;
                  }
                }
                break;
              }
              if ( v18 > 0x7FF )
              {
                if ( v18 - 55296 <= 0x7FF )
                {
                  if ( v18 > 0xDBFF )
                  {
                    v5 = (unsigned int *)((char *)v5 - 2);
                    goto LABEL_32;
                  }
                  v26 = *(unsigned __int16 *)v5;
                  v5 = (unsigned int *)((char *)v5 + 2);
                  if ( (unsigned int)(v26 - 56320) > 0x3FF )
                  {
                    --v5;
                    goto LABEL_32;
                  }
                  v18 = v26 + (v18 << 10) - 56613888;
                  *v12 = (v18 >> 18) | 0xF0;
                  v25 = v18 & 0x3F000 | 0x80000;
                  ++v12;
                }
                else
                {
                  v25 = v18 | 0xE0000;
                }
                *v12++ = v25 >> 12;
                v24 = v18 & 0xFC0 | 0x2000;
                i = (unsigned int *)((char *)i - 2);
              }
              else
              {
                v24 = v18 | 0x3000;
              }
              *v12 = v24 >> 6;
              v12[1] = v18 & 0x3F | 0x80;
              v12 += 2;
            }
          }
          if ( v15 >= v14 )
          {
            while ( v5 < v11 )
            {
              v16 = *(unsigned __int16 *)v5;
              v5 = (unsigned int *)((char *)v5 + 2);
              v7 = v16;
              if ( v16 > 0x7F )
                goto LABEL_9;
              *v12++ = v7;
            }
LABEL_21:
            *a3 = v12 - v9;
            return v6;
          }
LABEL_32:
          v7 = 0;
        }
      }
      if ( !v7 )
        goto LABEL_21;
      goto LABEL_10;
    }
    v6 = -1073741581;
  }
  else if ( a3 )
  {
    v6 = CountUnicodeToUTF8(a4, a5, a3);
  }
  else
  {
    v6 = -1073741811;
  }
  return v6;
}
