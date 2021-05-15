// RtlUnicodeStringToInteger 
 
int __fastcall RtlUnicodeStringToInteger(unsigned __int16 *a1, unsigned int a2, int *a3)
{
  unsigned int v4; // r5
  int v5; // r6
  int v6; // r8
  unsigned int v7; // r3
  unsigned __int16 *v8; // r4
  int v9; // r0
  unsigned int v10; // lr
  unsigned int v11; // t1
  unsigned int v12; // r3
  int v13; // r1
  int v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // t1

  v4 = a2;
  v5 = 0;
  v6 = 0;
  v7 = *a1;
  if ( !*a1 || (v7 & 1) != 0 )
    goto LABEL_52;
  v8 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
  v9 = v7 >> 1;
  v10 = 0;
  if ( v7 >> 1 )
  {
    while ( 1 )
    {
      --v9;
      v11 = *v8++;
      v10 = v11;
      if ( v11 > 0x20 )
        break;
      if ( !v9 )
      {
        v10 = 0;
        break;
      }
    }
  }
  else
  {
    v9 = -1;
  }
  v12 = v10;
  if ( v10 == 45 || v10 == 43 )
  {
    if ( v9 )
    {
      --v9;
      v12 = *v8++;
    }
    else
    {
      v12 = 0;
    }
  }
  switch ( a2 )
  {
    case 0u:
      v4 = 10;
      v13 = 0;
      if ( v12 == 48 )
      {
        if ( !v9 )
          goto LABEL_25;
        --v9;
        v14 = *v8++;
        switch ( v14 )
        {
          case 'x':
            v4 = 16;
            v13 = 4;
            break;
          case 'o':
            v4 = 8;
            v13 = 3;
            break;
          case 'b':
            v4 = 2;
            v13 = 1;
            break;
          default:
            ++v9;
            --v8;
            break;
        }
        if ( v9 )
        {
          --v9;
          v12 = *v8++;
        }
        else
        {
LABEL_25:
          v12 = 0;
        }
      }
      goto LABEL_34;
    case 0x10u:
      v13 = 4;
      goto LABEL_34;
    case 2u:
      v13 = 1;
      goto LABEL_34;
    case 8u:
      v13 = 3;
      goto LABEL_34;
  }
  if ( a2 != 10 )
  {
LABEL_52:
    v6 = -1073741811;
    goto LABEL_53;
  }
  v13 = 0;
LABEL_34:
  v5 = 0;
  if ( v12 )
  {
    do
    {
      if ( v12 < 0x30 || v12 > 0x39 )
      {
        if ( v12 < 0x41 || v12 > 0x46 )
        {
          if ( v12 < 0x61 || v12 > 0x66 )
            break;
          v15 = v12 - 87;
        }
        else
        {
          v15 = v12 - 55;
        }
      }
      else
      {
        v15 = v12 - 48;
      }
      if ( v15 >= v4 )
        break;
      v5 = v13 ? (v5 << v13) | v15 : v5 * v4 + v15;
      if ( !v9 )
        break;
      --v9;
      v16 = *v8++;
      v12 = v16;
    }
    while ( v16 );
  }
  if ( v10 == 45 )
    v5 = -v5;
LABEL_53:
  *a3 = v5;
  return v6;
}
