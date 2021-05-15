// CountUnicodeToUTF8 
 
int __fastcall CountUnicodeToUTF8(unsigned int *a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v3; // r1
  unsigned int *v4; // r10
  int v5; // r8
  unsigned int v6; // r4
  int result; // r0
  unsigned int v8; // r3
  unsigned int *v9; // r6
  unsigned int v10; // r2
  unsigned int v11; // t1
  unsigned int v12; // r5
  unsigned int v13; // r5
  unsigned int v14; // t1

  v3 = a2 >> 1;
  v4 = (unsigned int *)((char *)a1 + 2 * v3);
  v5 = 0;
LABEL_2:
  while ( 2 )
  {
    v6 = 0;
    while ( a1 < v4 )
    {
      if ( v6 )
        return sub_552480();
      v6 = *(unsigned __int16 *)a1;
      a1 = (unsigned int *)((char *)a1 + 2);
LABEL_7:
      if ( v6 - 55296 > 0x3FF )
        goto LABEL_8;
      --v3;
    }
    if ( !v6 )
      goto LABEL_24;
    ++v3;
LABEL_8:
    if ( v6 - 55296 <= 0x7FF )
    {
      v5 = 263;
      v6 = 65533;
    }
    if ( v6 > 0x7F )
    {
      if ( v6 > 0x7FF )
        ++v3;
      ++v3;
    }
    v8 = ((char *)v4 - (char *)a1) >> 1;
    if ( v8 > 0xD )
    {
      v9 = (unsigned int *)((char *)a1 + 2 * v8 - 14);
      if ( a1 >= v9 )
        continue;
LABEL_13:
      v11 = *(unsigned __int16 *)a1;
      a1 = (unsigned int *)((char *)a1 + 2);
      v10 = v11;
      if ( v11 > 0x7F )
      {
        if ( v10 > 0x7FF )
        {
          if ( (v10 & 0xF800) == 55296 )
            goto LABEL_57;
          ++v3;
        }
        ++v3;
      }
      if ( ((unsigned __int8)a1 & 2) != 0 )
      {
        v10 = *(unsigned __int16 *)a1;
        a1 = (unsigned int *)((char *)a1 + 2);
        if ( v10 > 0x7F )
        {
          if ( v10 > 0x7FF )
          {
            if ( (v10 & 0xF800) == 55296 )
              goto LABEL_57;
            ++v3;
          }
          ++v3;
          goto LABEL_16;
        }
      }
      while ( 1 )
      {
LABEL_16:
        if ( a1 >= v9 )
          goto LABEL_2;
        v12 = a1[1];
        v10 = *a1;
        if ( ((v12 | *a1) & 0xFF80FF80) != 0 )
        {
          if ( ((v12 | v10) & 0xF800F800) != 0 )
            goto LABEL_56;
          if ( (v10 & 0xFF800000) != 0 )
            ++v3;
          if ( (v10 & 0xFF80) != 0 )
            ++v3;
          if ( (v12 & 0xFF800000) != 0 )
            ++v3;
          if ( (v12 & 0xFF80) != 0 )
            ++v3;
        }
        a1 += 2;
        v13 = a1[1];
        v10 = *a1;
        if ( ((v13 | *a1) & 0xFF80FF80) != 0 )
        {
          if ( ((v13 | v10) & 0xF800F800) != 0 )
          {
LABEL_56:
            v10 = (unsigned __int16)v10;
            a1 = (unsigned int *)((char *)a1 + 2);
            if ( (unsigned __int16)v10 <= 0x7Fu )
              goto LABEL_64;
LABEL_57:
            if ( v10 <= 0x7FF )
              goto LABEL_63;
            if ( v10 - 55296 > 0x7FF )
              goto LABEL_62;
            if ( v10 <= 0xDBFF && (unsigned int)*(unsigned __int16 *)a1 - 56320 <= 0x3FF )
            {
              a1 = (unsigned int *)((char *)a1 + 2);
LABEL_62:
              ++v3;
LABEL_63:
              ++v3;
LABEL_64:
              if ( a1 >= v9 )
                goto LABEL_2;
              goto LABEL_13;
            }
            a1 = (unsigned int *)((char *)a1 - 2);
            goto LABEL_2;
          }
          if ( (v10 & 0xFF800000) != 0 )
            ++v3;
          if ( (v10 & 0xFF80) != 0 )
            ++v3;
          if ( (v13 & 0xFF800000) != 0 )
            ++v3;
          if ( (v13 & 0xFF80) != 0 )
            ++v3;
        }
        a1 += 2;
      }
    }
    break;
  }
  while ( a1 < v4 )
  {
    v14 = *(unsigned __int16 *)a1;
    a1 = (unsigned int *)((char *)a1 + 2);
    v6 = v14;
    if ( v14 > 0x7F )
      goto LABEL_7;
  }
LABEL_24:
  result = v5;
  *a3 = v3;
  return result;
}
