// CmpInitializeKcbCache 
 
int __fastcall CmpInitializeKcbCache(_DWORD *a1, unsigned int a2)
{
  int v3; // r5
  _DWORD *v5; // r8
  _DWORD *v6; // r7
  int v7; // r9
  _BYTE *v8; // r0
  _BYTE *v9; // r0
  unsigned int v10; // r1
  _DWORD *v11; // r3
  unsigned int v12; // r2
  _DWORD *v13; // r3
  int v14; // r2

  v3 = -1073741670;
  v5 = 0;
  if ( ((a2 - 1) & a2) != 0 )
    return -1073741811;
  v6 = 0;
  if ( a2 > 0x15555555 )
  {
    v3 = -1073741811;
  }
  else
  {
    v7 = 3 * a2;
    v8 = (_BYTE *)ExAllocatePoolWithTag(1, 12 * a2, 1631800643);
    v5 = v8;
    if ( v8 )
    {
      memset(v8, 0, 4 * v7);
      v9 = (_BYTE *)ExAllocatePoolWithTag(1, 384, 1631800643);
      v6 = v9;
      if ( v9 )
      {
        memset(v9, 0, 384);
        v10 = 0;
        if ( a2 )
        {
          v11 = v5;
          v12 = a2;
          v10 = a2;
          do
          {
            *v11 = 0;
            v11 += 3;
            --v12;
          }
          while ( v12 );
        }
        if ( v10 == a2 )
        {
          v13 = v6;
          v14 = 32;
          do
          {
            *v13 = 0;
            v13 += 3;
            --v14;
          }
          while ( v14 );
          v3 = 0;
        }
      }
    }
  }
  a1[464] = 32;
  a1[461] = v5;
  a1[462] = a2;
  a1[463] = v6;
  if ( v3 >= 0 )
    return v3;
  return sub_7D2AE8();
}
