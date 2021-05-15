// FsFilterGetCallbacks 
 
int __fastcall FsFilterGetCallbacks(int result, int a2, unsigned int *a3, unsigned int *a4)
{
  int v6; // r1
  unsigned int v7; // r3
  unsigned int *v8; // r4
  unsigned int v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r3
  unsigned int v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r3
  unsigned int v20; // r3
  unsigned int v21; // r2
  unsigned int v22; // r3
  unsigned int v23; // r3
  unsigned int v24; // r2
  unsigned int v25; // r3

  v6 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 24);
  v7 = 0;
  *a3 = 0;
  v8 = *(unsigned int **)(v6 + 24);
  *a4 = 0;
  if ( v8 )
  {
    if ( result == 255 )
    {
      v12 = *v8;
      if ( *v8 >= 0xC )
      {
        v13 = v8[2];
        if ( v13 )
          *a3 = v13;
      }
      if ( v12 >= 0x10 )
      {
        v7 = v8[3];
        if ( v7 )
LABEL_15:
          *a4 = v7;
      }
    }
    else if ( result == 254 )
    {
      v9 = *v8;
      if ( *v8 >= 0x14 )
      {
        v10 = v8[4];
        if ( v10 )
          *a3 = v10;
      }
      if ( v9 >= 0x18 )
      {
        v11 = v8[5];
        if ( v11 )
          *a4 = v11;
      }
    }
    else
    {
      switch ( result )
      {
        case 250:
          v14 = *v8;
          if ( *v8 >= 0x24 )
          {
            v15 = v8[8];
            if ( v15 )
              *a3 = v15;
          }
          if ( v14 >= 0x28 )
          {
            v16 = v8[9];
            if ( v16 )
              *a4 = v16;
          }
          break;
        case 251:
          v17 = *v8;
          if ( *v8 >= 0x1C )
          {
            v18 = v8[6];
            if ( v18 )
              *a3 = v18;
          }
          if ( v17 >= 0x20 )
          {
            v19 = v8[7];
            if ( v19 )
              *a4 = v19;
          }
          break;
        case 252:
          v23 = *v8;
          if ( *v8 >= 0x34 )
          {
            v24 = v8[12];
            if ( v24 )
              *a3 = v24;
          }
          if ( v23 >= 0x38 )
          {
            v25 = v8[13];
            if ( v25 )
              *a4 = v25;
          }
          break;
        case 253:
          v20 = *v8;
          if ( *v8 >= 0x2C )
          {
            v21 = v8[10];
            if ( v21 )
              *a3 = v21;
          }
          if ( v20 >= 0x30 )
          {
            v22 = v8[11];
            if ( v22 )
              *a4 = v22;
          }
          break;
        default:
          *a3 = 0;
          goto LABEL_15;
      }
    }
  }
  return result;
}
